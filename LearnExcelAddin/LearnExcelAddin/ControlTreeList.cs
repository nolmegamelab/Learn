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

        private void m_tree_meta_AfterSelect(object sender, TreeViewEventArgs e)
        {

        }
    }
}
