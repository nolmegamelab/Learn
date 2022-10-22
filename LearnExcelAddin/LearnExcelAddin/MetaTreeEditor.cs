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
    public enum MetaType
    {
        i32,
        dbl,
        tf,         // bool
        str,
        enm,
        list
    }

    public class MetaTypeInfo
    {
        public string Index { get; set; }

        public string Name { get; set; }

        public MetaType Type { get; set; }

        public MetaTypeNode Owner { get; set; }
    }

    public class MetaTypeNode
    {
        public List<MetaTypeInfo> Types { get; private set; }

        public string Sheet { get; set; }

        public List<MetaTypeNode> Children { get; private set; }

        public MetaTypeNode Parent { get; set; }

        public MetaTypeNode()
        {
            Types = new List<MetaTypeInfo>();
            Children = new List<MetaTypeNode>();
        }
    }

    public class MetaValueNode
    {
        public List<string> Values{ get; set; }

        public string Value { get; set; }

        public List<MetaValueNode> Children { get; set; }

        public MetaValueNode Parent { get; set; }
    }

    public class MetaValueTag
    {
        public string SheetName { get; set; }   

        public uint Row { get; set; }

        public uint Column { get; set; }    
    }

    public class MetaTreeEditor
    {
        private MetaTypeNode m_tree_head = new MetaTypeNode();
        private Dictionary<string, MetaTypeInfo> m_types = new Dictionary<string, MetaTypeInfo>();
        private string m_value_tree_index = "";
        private bool m_fix_current_node = false;
        private bool m_type_tree_built = false;

        public MetaTypeNode buildTypeTree(Excel.Workbook wb)
        {
            if ( m_type_tree_built )
            {
                return null;
            }

            var worksheet = wb.Worksheets.Item["meta_data"];
            buildTypeTreeIn(worksheet, m_tree_head);
            m_type_tree_built = true;
            return m_tree_head;
        }

        public void buildValueTree(ControlTreeList tree, Excel.Range target)
        {
            if ( m_fix_current_node )
            {
                return;
            }

            var cell = target.Cells[0];
            var addr = cell.Address.ToString();
            var row = getRowFromAddresss(addr)+1;

            var current_value_tree_index = $"{target.Worksheet.Name}:{row}";
            if (current_value_tree_index == m_value_tree_index)
            {
                return;
            }
            m_value_tree_index = current_value_tree_index;

            var tree_root = new TreeNode($"현재 노드 - {current_value_tree_index}");
            tree_root.Tag = new MetaValueTag() { 
                Column = getColFromAddress(addr), 
                Row = row, 
                SheetName = target.Worksheet.Name 
            };  

            tree.MetaTree.Nodes.Clear();
            tree.MetaTree.Nodes.Add(tree_root);

            buildValueTreeAt(target.Worksheet, tree_root, row);

            tree.MetaTree.ExpandAll();
        }

        public void activateNode(TreeNode node)
        {
            if (node.Tag is MetaValueTag)
            {
                var tag = (MetaValueTag)node.Tag;
                var sheet = Globals.ThisAddIn.Application.ActiveWorkbook.Worksheets[tag.SheetName];
                sheet.Activate();

                var col = convertColumnIndexToColumnAddress(tag.Column);

                var range = sheet.Range($"{col}{tag.Row}", $"{col}{tag.Row}");
                range.Select();
            }
        }

        public void convertValueTree()
        {
            var converter = new MetaTreeConverter();
            converter.convertValueTree();
        }


        public MetaTypeNode getTypeTree()
        {
            return m_tree_head;
        }

        public void setFixCurrentNode(bool set)
        {
            m_fix_current_node = set;
        }

        public MetaTypeInfo getMetaTypeInfo(Excel.Worksheet ws, uint col)
        {
            var index_cell = ws.Cells[2, col];
            var index = index_cell.Text;
            var key = getTypeKey(ws, index);

            if (m_types.ContainsKey(key))
            {
                return m_types[key];
            }
            return null;
        }

        // address는 $A$17 형식이다. 
        public uint getColFromAddress(string address)
        {
            var args = address.Split('$');
            var col = args[1];

            return convertColumnAddressToColumnIndex(col);
        }

        public uint getRowFromAddresss(string address)
        {
            var args = address.Split('$');
            var val = args[2];

            return uint.Parse(val);
        }

        public Excel.Worksheet getWorksheetFromTypeInfo(MetaTypeInfo info)
        {
            var sheetName = getSheetNameFromTypeName(info.Name);
            var cws = Globals.ThisAddIn.Application.ActiveWorkbook.Worksheets[sheetName];
            return cws;
        }

        // 컬럼 1이 항상 키를 갖고 있다.  
        public string getWorksheetKey(Excel.Worksheet ws, uint row)
        {
            return getTextAt(ws, row, 1);
        }

        public List<Excel.Range> findCells(Excel.Worksheet ws, string pattern, Excel.Range range)
        {
            Excel.Range currentFind = null;
            Excel.Range firstFind = null;

            Excel.Range cells = range;

            List<Excel.Range> list = new List<Excel.Range>();

            currentFind = cells.Find(pattern, System.Type.Missing,
                Excel.XlFindLookIn.xlValues, Excel.XlLookAt.xlPart,
                Excel.XlSearchOrder.xlByRows, Excel.XlSearchDirection.xlNext, false,
                System.Type.Missing, System.Type.Missing);

            while (currentFind != null)
            {
                // Keep track of the first range you find. 
                if (firstFind == null)
                {
                    firstFind = currentFind;
                }
                // If you didn't move to a new range, you are done.
                else if (currentFind.get_Address(Excel.XlReferenceStyle.xlA1) == firstFind.get_Address(Excel.XlReferenceStyle.xlA1))
                {
                    break;
                }

                list.Add(currentFind);
                currentFind = cells.FindNext(currentFind);
            }

            return list;
        }

        public string getArrayIndexFromValue(string value)
        {
            var builder = new StringBuilder();

            bool left_bracket_found = false;

            for (int i = 0; i < value.Length; i++)
            {
                if (value[i] == '[')
                {
                    left_bracket_found = true;
                }

                if (left_bracket_found)
                {
                    builder.Append(value[i]);
                }
            }
            return builder.ToString();
        }

        public string getTextAt(Excel.Worksheet ws, uint row, uint col)
        {
            var value_cell = ws.Cells[row, col];
            var value = value_cell.Text.ToString();
            return value;
        }

        public void setTextAt(Excel.Worksheet ws, uint row, uint col, string value)
        {
            var range = ws.Cells[row, col];
            range.Value = value;
        }

        private void buildValueTreeAt(Excel.Worksheet ws, TreeNode parent, uint row)
        {
            for (uint col = 1; col < ws.Columns.Count; col++)
            {
                var info = getMetaTypeInfo(ws, col);
                if ( info == null )
                {
                    break;
                }

                var value = getTextAt(ws, row, col);

                var node = new TreeNode($"{info.Name} : {value}");
                parent.Nodes.Add(node);
                node.Tag = new MetaValueTag()
                {
                    Column = col,
                    Row = row,
                    SheetName = ws.Name
                };

                if (col > 1)
                {
                    if (info.Type == MetaType.list)
                    {
                        var sheetName = getSheetNameFromTypeName(info.Name);
                        var cws = Globals.ThisAddIn.Application.ActiveWorkbook.Worksheets[sheetName];
                        if (cws != null)
                        {
                            buildValueTreeForList(cws, node, info, value);
                        }
                    }
                }
            }
        }

        private void buildValueTreeForList(Excel.Worksheet ws, TreeNode node, MetaTypeInfo info, string value)
        {
            var array_index_str = getArrayIndexFromValue(value);

            if (array_index_str.Length == 0)
            {
                return;
            }

            Excel.Range range = ws.Range["A1", "A100000"]; // XX: find a better way to specify the range.

            var list = findCells(ws, array_index_str, range);

            foreach ( var target in list )
            {
                var cell = target.Cells[0];
                var addr = cell.Address.ToString();
                var row = getRowFromAddresss(addr);
                var text = getTextAt(ws, row+1, 1);

                //  한번 더 필터링 
                if (text.StartsWith(array_index_str))
                {
                    var cnode = new TreeNode($"{text}");
                    node.Nodes.Add(cnode);
                    cnode.Tag = new MetaValueTag()
                    {
                        Column = getColFromAddress(addr),
                        Row = row,
                        SheetName = ws.Name
                    };
                    buildValueTreeAt(target.Worksheet, cnode, row);
                }
            }
        }

        private void buildTypeTreeIn(Excel.Worksheet ws, MetaTypeNode parent)
        {
            var node = new MetaTypeNode() { Parent = parent, Sheet = ws.Name };
            parent.Children.Add(node);

            for ( uint col = 1; col < ws.Columns.Count; col++ )
            {
                var index_cell = ws.Cells[2, col];
                var index = index_cell.Text;
                
                if ( index == null || index == string.Empty )
                {
                    break;
                }

                var type_cell = ws.Cells[3, col];
                var type_name = type_cell.Text;
                var type = getMetaTypeFromName(type_name);

                var name_cell = ws.Cells[4, col];
                var name = name_cell.Text;

                var info = new MetaTypeInfo() { Index = getTypeKey(ws, index), Type= type, Name = name, Owner = node };
                node.Types.Add(info);

                m_types.Add(getTypeKey(ws, index), info);

                //  첫 컬럼은 lst 타잎이더라도 이 시트에서 모두 정의된다.
                if (col > 1)
                {
                    if (info.Type == MetaType.list)
                    {
                        var sheetName = getSheetNameFromTypeName(info.Name);
                        var cws = Globals.ThisAddIn.Application.ActiveWorkbook.Worksheets[sheetName];
                        if (cws != null)
                        {
                            buildTypeTreeIn(cws, node);
                        }
                    }
                }
            }
        }

        private string getSheetNameFromTypeName(string name)
        {
            return name.Split('.')[0];
        }

        private string getTypeKey(Excel.Worksheet ws, string index)
        {
            return $"{ws.Name}.{index}";
        }

        private void expandTreeNodes(TreeNodeCollection nodes, int level)
        {
            if (level == 0)
            {
                return;
            }

            foreach (TreeNode node in nodes)
            {
                node.Expand();
                expandTreeNodes(node.Nodes, --level);
            }
        }

        private uint convertColumnAddressToColumnIndex(string address)
        {
            uint num = 0;
            int len = address.Length;
            for ( int i = len- 1; i >= 0; --i)
            {
                char c = address[i];
                uint v = (uint)((int)c - (int)'A');
                num += v;
            }
            return num;
        }

        private string convertColumnIndexToColumnAddress(uint num)
        {
            var current = num;
            var remainder = current % 26;
            var quotient = current / 26;
            var builder = new StringBuilder();

            do
            {
                builder.Append(getAlphabet(remainder - 1));

                remainder = current % 26;
                quotient = current / 26;
                current = quotient;
            }
            while (current > 0);

            return builder.ToString();
        }

        private char getAlphabet(uint index)
        {
            return (char)((int)'A' + index);
        }

        private MetaType getMetaTypeFromName(string name)
        {
            if (name.StartsWith("lst"))
            {
                return MetaType.list;
            }

            if (name.StartsWith("enum"))
            {
                return MetaType.enm;
            }

            foreach (MetaType type in Enum.GetValues(typeof(MetaType)))
            {
                if ( type.ToString() == name )
                {
                    return type;
                }
            }

            return MetaType.i32;
        }
    }
}
