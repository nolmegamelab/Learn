namespace LearnExcelAddin
{
    partial class ControlTreeList
    {
        /// <summary> 
        /// 필수 디자이너 변수입니다.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

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
            this.m_tree_meta = new System.Windows.Forms.TreeView();
            this.m_group_control = new System.Windows.Forms.GroupBox();
            this.m_button_copy_insert = new System.Windows.Forms.Button();
            this.m_check_deep = new System.Windows.Forms.CheckBox();
            this.m_label_location = new System.Windows.Forms.Label();
            this.m_group_control.SuspendLayout();
            this.SuspendLayout();
            // 
            // m_tree_meta
            // 
            this.m_tree_meta.Dock = System.Windows.Forms.DockStyle.Top;
            this.m_tree_meta.Location = new System.Drawing.Point(0, 0);
            this.m_tree_meta.Name = "m_tree_meta";
            this.m_tree_meta.Size = new System.Drawing.Size(471, 709);
            this.m_tree_meta.TabIndex = 0;
            this.m_tree_meta.AfterSelect += new System.Windows.Forms.TreeViewEventHandler(this.m_tree_meta_AfterSelect);
            // 
            // m_group_control
            // 
            this.m_group_control.Controls.Add(this.m_label_location);
            this.m_group_control.Controls.Add(this.m_check_deep);
            this.m_group_control.Controls.Add(this.m_button_copy_insert);
            this.m_group_control.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.m_group_control.Location = new System.Drawing.Point(0, 700);
            this.m_group_control.Name = "m_group_control";
            this.m_group_control.Size = new System.Drawing.Size(471, 100);
            this.m_group_control.TabIndex = 1;
            this.m_group_control.TabStop = false;
            // 
            // m_button_copy_insert
            // 
            this.m_button_copy_insert.ForeColor = System.Drawing.SystemColors.HotTrack;
            this.m_button_copy_insert.Location = new System.Drawing.Point(17, 31);
            this.m_button_copy_insert.Name = "m_button_copy_insert";
            this.m_button_copy_insert.Size = new System.Drawing.Size(88, 23);
            this.m_button_copy_insert.TabIndex = 0;
            this.m_button_copy_insert.Text = "복사 && 추가";
            this.m_button_copy_insert.UseVisualStyleBackColor = true;
            // 
            // m_check_deep
            // 
            this.m_check_deep.AutoSize = true;
            this.m_check_deep.Checked = true;
            this.m_check_deep.CheckState = System.Windows.Forms.CheckState.Checked;
            this.m_check_deep.Location = new System.Drawing.Point(130, 37);
            this.m_check_deep.Name = "m_check_deep";
            this.m_check_deep.Size = new System.Drawing.Size(76, 16);
            this.m_check_deep.TabIndex = 1;
            this.m_check_deep.Text = "전체 계층";
            this.m_check_deep.UseVisualStyleBackColor = true;
            // 
            // m_label_location
            // 
            this.m_label_location.AutoSize = true;
            this.m_label_location.Location = new System.Drawing.Point(15, 67);
            this.m_label_location.Name = "m_label_location";
            this.m_label_location.Size = new System.Drawing.Size(71, 12);
            this.m_label_location.TabIndex = 2;
            this.m_label_location.Text = "Sheet1 - A1";
            // 
            // ControlTreeList
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.m_group_control);
            this.Controls.Add(this.m_tree_meta);
            this.Name = "ControlTreeList";
            this.Size = new System.Drawing.Size(471, 800);
            this.m_group_control.ResumeLayout(false);
            this.m_group_control.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.TreeView m_tree_meta;
        private System.Windows.Forms.GroupBox m_group_control;
        private System.Windows.Forms.Label m_label_location;
        private System.Windows.Forms.CheckBox m_check_deep;
        private System.Windows.Forms.Button m_button_copy_insert;
    }
}
