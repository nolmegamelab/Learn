using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Excel = Microsoft.Office.Interop.Excel;
using System.Windows.Forms;
using Office = Microsoft.Office.Core;
using Microsoft.Office.Tools.Excel;
using Microsoft.Office.Tools;

namespace LearnExcelAddin
{
    // Convert the hierarchy link cell values to a hierarchy index
    public class MetaTreeConverter
    {
        public MetaTreeConverter()
        {

        }

        public void convertValueTree()
        {
            var addin = Globals.ThisAddIn;
            var wb = addin.CurrentWorkbook;
            var ws = wb.Worksheets.Item["meta_data"];

            // iterate over the rows and call conversion
            // one row at a time to the end of the hierarchy

            //  XXX: 적절한 개수를 찾는 방법?
            for (uint row = 5; row < ws.Rows.Count; row++)
            {
                var current_key = addin.Editor.getWorksheetKey(ws, row);
                if (current_key == null || current_key.Length == 0)
                {
                    break;
                }

                addin.showMessage($"row: {row}");

                for (uint col = 1; col < 64; col++)
                {
                    try
                    {
                        convertValueTreeAt(ws, row, col);
                    }
                    catch (Exception ex)
                    {
                        addin.showPopup(ex.ToString());
                    }
                }

                if ( row % 100 == 0 )
                {
                    wb.Save();
                }
            } 
        }

        private void convertValueTreeAt(Excel.Worksheet ws, uint row, uint col)
        {
            var addin = Globals.ThisAddIn;
            var type_info = Globals.ThisAddIn.Editor.getMetaTypeInfo(ws, col);

            if (type_info != null)
            {
                if (type_info.Type == MetaType.list)
                {
                    var value = addin.Editor.getTextAt(ws, row, col);
                    if (value != null && value.Length > 0)
                    {
                        var next_ws = addin.Editor.getWorksheetFromTypeInfo(type_info);
                        var sheet_key = addin.Editor.getWorksheetKey(ws, row);
                        var array_index = addin.Editor.getArrayIndexFromValue(value);

                        addin.Editor.setTextAt(ws, row, col, "_>_");

                        convertValueTreeLinked(next_ws, sheet_key, array_index);
                    }
                }
            }
        } 

        // 상위 연결에서 자신의 키를 포함하여 array_index에 해당하는 셀들에 대해 링크를 바꾸고 
        // 하위 셀들에 대한 처리를 진행한다. 
        public void convertValueTreeLinked(Excel.Worksheet ws, string parent_key, string array_index)
        {
            if ( array_index == null || array_index.Length == 0 )
            {
                return;
            }

            var editor = Globals.ThisAddIn.Editor;
            Excel.Range range = ws.Range["A1", "A100000"]; // XX: find a better way to specify the range.

            var search_text = $"{array_index}["; // [3][  와 같은 문자열 검색

            var list = editor.findCells(ws, search_text, range);

            uint key = 0;

            foreach (var target in list)
            {
                var cell = target.Cells[0];
                var addr = cell.Address.ToString();
                var row = editor.getRowFromAddresss(addr); //  XXX: 왜 찾은 행 다음일까?
                var fixed_row = row + 1;
                var text = editor.getTextAt(ws, fixed_row, 1);

                //  연결 셀에서 찾은 [32]와 같은 키로 시작하는 항목들이 대상
                if (text.StartsWith(array_index))
                {
                    var skey = $"_>_{parent_key}.{key}";
                    if ( parent_key.StartsWith("_>_"))
                    {
                        skey = $"{parent_key}.{key}";
                    }

                    editor.setTextAt(ws, fixed_row, 1, skey); // 나의 키를 변경하고 나의 셀들 변경을 시작 

                    // 상위 키로 찾은 열들에 대해서만 변경을 진행한다. col 1은 키 변경으로 끝난다. 
                    for (uint col = 2; col < 64; col++)
                    {
                        convertValueTreeAt(ws, fixed_row, col);
                    }
                }

                ++key;
            } 
        }
    }
}
