using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace LearnExcelAddin
{
    public partial class ControlTreeList : UserControl
    {
        public ControlTreeList()
        {
            InitializeComponent();
        }

        public TreeView MetaTree { get { return m_tree_meta; } }

        public Label MetaLocation { get { return m_label_location; } }

        private void ControlTreeList_Resize(object sender, EventArgs e)
        {
            m_tree_meta.Size = this.ClientSize - m_group_control.Size;
        }

        private void m_tree_meta_DoubleClick(object sender, EventArgs e)
        {
            Globals.ThisAddIn.Editor.activateNode(m_tree_meta.SelectedNode);
        }

        private void m_fix_current_CheckedChanged(object sender, EventArgs e)
        {
            Globals.ThisAddIn.Editor.setFixCurrentNode(m_fix_current.Checked);
        }
    }
}
