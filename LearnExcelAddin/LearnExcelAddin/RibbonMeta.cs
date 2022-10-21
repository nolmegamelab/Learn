using Microsoft.Office.Tools.Ribbon;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace LearnExcelAddin
{
    public partial class RibbonMeta
    {
        private void RibbonMeta_Load(object sender, RibbonUIEventArgs e)
        {

        }

        private void buttonFirstAccounter_Click(object sender, RibbonControlEventArgs e)
        {
            Globals.ThisAddIn.TreeListPane.Visible = true;
            MessageBox.Show("Pane should visiable");
        }
    }
}
