namespace LearnExcelAddin
{
    partial class RibbonMeta : Microsoft.Office.Tools.Ribbon.RibbonBase
    {
        /// <summary>
        /// 필수 디자이너 변수입니다.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        public RibbonMeta()
            : base(Globals.Factory.GetRibbonFactory())
        {
            InitializeComponent();
        }

        /// <summary> 
        /// 사용 중인 모든 리소스를 정리합니다.
        /// </summary>
        /// <param name="disposing">관리되는 리소스를 삭제해야 하면 true이고, 그렇지 않으면 false입니다.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region 구성 요소 디자이너에서 생성한 코드

        /// <summary>
        /// 디자이너 지원에 필요한 메서드입니다. 
        /// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
        /// </summary>
        private void InitializeComponent()
        {
            this.tab1 = this.Factory.CreateRibbonTab();
            this.group1 = this.Factory.CreateRibbonGroup();
            this.MetaTab = this.Factory.CreateRibbonTab();
            this.RibbonGroupTestPage = this.Factory.CreateRibbonGroup();
            this.buttonFirstAccounter = this.Factory.CreateRibbonButton();
            this.tab1.SuspendLayout();
            this.MetaTab.SuspendLayout();
            this.RibbonGroupTestPage.SuspendLayout();
            this.SuspendLayout();
            // 
            // tab1
            // 
            this.tab1.ControlId.ControlIdType = Microsoft.Office.Tools.Ribbon.RibbonControlIdType.Office;
            this.tab1.Groups.Add(this.group1);
            this.tab1.Label = "TabAddIns";
            this.tab1.Name = "tab1";
            // 
            // group1
            // 
            this.group1.Label = "group1";
            this.group1.Name = "group1";
            // 
            // MetaTab
            // 
            this.MetaTab.Groups.Add(this.RibbonGroupTestPage);
            this.MetaTab.Label = "메타";
            this.MetaTab.Name = "MetaTab";
            // 
            // RibbonGroupTestPage
            // 
            this.RibbonGroupTestPage.Items.Add(this.buttonFirstAccounter);
            this.RibbonGroupTestPage.Label = "테스트 페이지";
            this.RibbonGroupTestPage.Name = "RibbonGroupTestPage";
            // 
            // buttonFirstAccounter
            // 
            this.buttonFirstAccounter.Label = "첫 대면";
            this.buttonFirstAccounter.Name = "buttonFirstAccounter";
            this.buttonFirstAccounter.Click += new Microsoft.Office.Tools.Ribbon.RibbonControlEventHandler(this.buttonFirstAccounter_Click);
            // 
            // RibbonMeta
            // 
            this.Name = "RibbonMeta";
            this.RibbonType = "Microsoft.Excel.Workbook";
            this.Tabs.Add(this.tab1);
            this.Tabs.Add(this.MetaTab);
            this.Load += new Microsoft.Office.Tools.Ribbon.RibbonUIEventHandler(this.RibbonMeta_Load);
            this.tab1.ResumeLayout(false);
            this.tab1.PerformLayout();
            this.MetaTab.ResumeLayout(false);
            this.MetaTab.PerformLayout();
            this.RibbonGroupTestPage.ResumeLayout(false);
            this.RibbonGroupTestPage.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        internal Microsoft.Office.Tools.Ribbon.RibbonTab tab1;
        internal Microsoft.Office.Tools.Ribbon.RibbonGroup group1;
        internal Microsoft.Office.Tools.Ribbon.RibbonTab MetaTab;
        internal Microsoft.Office.Tools.Ribbon.RibbonGroup RibbonGroupTestPage;
        internal Microsoft.Office.Tools.Ribbon.RibbonButton buttonFirstAccounter;
    }

    partial class ThisRibbonCollection
    {
        internal RibbonMeta RibbonMeta
        {
            get { return this.GetRibbon<RibbonMeta>(); }
        }
    }
}
