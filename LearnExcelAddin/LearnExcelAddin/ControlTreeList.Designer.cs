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
            this.m_fix_current = new System.Windows.Forms.CheckBox();
            this.m_label_location = new System.Windows.Forms.Label();
            this.m_button_copy_insert = new System.Windows.Forms.Button();
            this.m_convert_tree = new System.Windows.Forms.Button();
            this.m_message = new System.Windows.Forms.Label();
            this.m_group_control.SuspendLayout();
            this.SuspendLayout();
            // 
            // m_tree_meta
            // 
            this.m_tree_meta.Dock = System.Windows.Forms.DockStyle.Top;
            this.m_tree_meta.Font = new System.Drawing.Font("Consolas", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.m_tree_meta.Location = new System.Drawing.Point(0, 0);
            this.m_tree_meta.Name = "m_tree_meta";
            this.m_tree_meta.Size = new System.Drawing.Size(471, 481);
            this.m_tree_meta.TabIndex = 0;
            this.m_tree_meta.DoubleClick += new System.EventHandler(this.m_tree_meta_DoubleClick);
            // 
            // m_group_control
            // 
            this.m_group_control.Controls.Add(this.m_message);
            this.m_group_control.Controls.Add(this.m_convert_tree);
            this.m_group_control.Controls.Add(this.m_fix_current);
            this.m_group_control.Controls.Add(this.m_label_location);
            this.m_group_control.Controls.Add(this.m_button_copy_insert);
            this.m_group_control.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.m_group_control.Location = new System.Drawing.Point(0, 487);
            this.m_group_control.Name = "m_group_control";
            this.m_group_control.Size = new System.Drawing.Size(471, 103);
            this.m_group_control.TabIndex = 1;
            this.m_group_control.TabStop = false;
            // 
            // m_fix_current
            // 
            this.m_fix_current.AutoSize = true;
            this.m_fix_current.Location = new System.Drawing.Point(151, 35);
            this.m_fix_current.Name = "m_fix_current";
            this.m_fix_current.Size = new System.Drawing.Size(132, 16);
            this.m_fix_current.TabIndex = 3;
            this.m_fix_current.Text = "현재 항목 고정 편집";
            this.m_fix_current.UseVisualStyleBackColor = true;
            this.m_fix_current.CheckedChanged += new System.EventHandler(this.m_fix_current_CheckedChanged);
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
            // m_convert_tree
            // 
            this.m_convert_tree.ForeColor = System.Drawing.SystemColors.HotTrack;
            this.m_convert_tree.Location = new System.Drawing.Point(339, 31);
            this.m_convert_tree.Name = "m_convert_tree";
            this.m_convert_tree.Size = new System.Drawing.Size(75, 23);
            this.m_convert_tree.TabIndex = 4;
            this.m_convert_tree.Text = "구조 변경";
            this.m_convert_tree.UseVisualStyleBackColor = true;
            this.m_convert_tree.Click += new System.EventHandler(this.m_convert_tree_Click);
            // 
            // m_message
            // 
            this.m_message.AutoSize = true;
            this.m_message.Location = new System.Drawing.Point(151, 67);
            this.m_message.Name = "m_message";
            this.m_message.Size = new System.Drawing.Size(29, 12);
            this.m_message.TabIndex = 5;
            this.m_message.Text = "상태";
            // 
            // ControlTreeList
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.m_group_control);
            this.Controls.Add(this.m_tree_meta);
            this.Name = "ControlTreeList";
            this.Size = new System.Drawing.Size(471, 590);
            this.Resize += new System.EventHandler(this.ControlTreeList_Resize);
            this.m_group_control.ResumeLayout(false);
            this.m_group_control.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.TreeView m_tree_meta;
        private System.Windows.Forms.GroupBox m_group_control;
        private System.Windows.Forms.Label m_label_location;
        private System.Windows.Forms.Button m_button_copy_insert;
        private System.Windows.Forms.CheckBox m_fix_current;
        private System.Windows.Forms.Button m_convert_tree;
        private System.Windows.Forms.Label m_message;
    }
}
