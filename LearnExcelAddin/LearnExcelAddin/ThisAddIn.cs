using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Xml.Linq;
using Excel = Microsoft.Office.Interop.Excel;
using Office = Microsoft.Office.Core;
using Microsoft.Office.Tools.Excel;
using Microsoft.Office.Tools;
using System.Windows.Forms;

namespace LearnExcelAddin
{
    public partial class ThisAddIn
    {
        ControlTreeList m_tree_list;
        CustomTaskPane m_pane_tree_list;
        Excel.Workbook m_current_workbook;

        public CustomTaskPane TreeListPane { get { return m_pane_tree_list; } }

        private void ThisAddIn_Startup(object sender, System.EventArgs e)
        {
            CreateTreeTaskPane();

            Application.WorkbookActivate += on_Application_WorkbookActivate;
        }

        private void Application_WorkbookOpen(Excel.Workbook Wb)
        {
            Wb.SheetSelectionChange += on_Wb_SheetSelectionChange;
        }

        private void on_Application_WorkbookActivate(Excel.Workbook Wb)
        {
            Wb.SheetSelectionChange += on_Wb_SheetSelectionChange;
            m_current_workbook = Wb;
        }

        private void on_Wb_SheetSelectionChange(object Sh, Excel.Range Target)
        {
            var ws = Target.Worksheet;

            if ( Target.Count > 0 )
            {
                try
                {
                    var cell = Target.Cells[0];
                    // m_tree_list.MetaLocation.Text = cell.Text?.ToString();
                    m_tree_list.MetaLocation.Text = $"{ws.Name}/{cell.Address}";
                    //m_tree_list.MetaLocation.Text = cell.Value?.ToString();
                    // 문자열일 경우 Text 값, 수일 경우 Value가 지정됨 
                    // 이전 셀로 Target이 설정된다.  
                    // var ncell = cell.Next; // Next는 다음 컬럼의 값을 가져온다.  
                    // m_tree_list.MetaLocation.Text = ncell.Text?.ToString();
                }
                finally
                {

                }
            }
        }

        private void ThisAddIn_Shutdown(object sender, System.EventArgs e)
        {
        }

        private void CreateTreeTaskPane()
        {
            m_tree_list = new ControlTreeList();
            m_pane_tree_list = this.CustomTaskPanes.Add(m_tree_list, "메타 편집"); 
            m_pane_tree_list.Visible = true;
        }

        #region VSTO에서 생성한 코드

        /// <summary>
        /// 디자이너 지원에 필요한 메서드입니다. 
        /// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
        /// </summary>
        private void InternalStartup()
        {
            this.Startup += new System.EventHandler(ThisAddIn_Startup);
            this.Shutdown += new System.EventHandler(ThisAddIn_Shutdown);
        }

        #endregion
    }
}
