namespace WinFormsApp1
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            textBox1 = new TextBox();
            menuStrip1 = new MenuStrip();
            文件FToolStripMenuItem = new ToolStripMenuItem();
            新建NToolStripMenuItem = new ToolStripMenuItem();
            打开OToolStripMenuItem = new ToolStripMenuItem();
            toolStripSeparator2 = new ToolStripSeparator();
            保存SToolStripMenuItem = new ToolStripMenuItem();
            另存为AToolStripMenuItem = new ToolStripMenuItem();
            toolStripSeparator3 = new ToolStripSeparator();
            打印PToolStripMenuItem = new ToolStripMenuItem();
            打印预览VToolStripMenuItem = new ToolStripMenuItem();
            toolStripSeparator4 = new ToolStripSeparator();
            退出XToolStripMenuItem = new ToolStripMenuItem();
            编辑EToolStripMenuItem = new ToolStripMenuItem();
            撤消UToolStripMenuItem = new ToolStripMenuItem();
            重做RToolStripMenuItem = new ToolStripMenuItem();
            toolStripSeparator5 = new ToolStripSeparator();
            剪切TToolStripMenuItem = new ToolStripMenuItem();
            复制CToolStripMenuItem = new ToolStripMenuItem();
            粘贴PToolStripMenuItem = new ToolStripMenuItem();
            toolStripSeparator6 = new ToolStripSeparator();
            全选AToolStripMenuItem = new ToolStripMenuItem();
            工具TToolStripMenuItem = new ToolStripMenuItem();
            自定义CToolStripMenuItem = new ToolStripMenuItem();
            选项OToolStripMenuItem = new ToolStripMenuItem();
            帮助HToolStripMenuItem = new ToolStripMenuItem();
            内容CToolStripMenuItem = new ToolStripMenuItem();
            索引IToolStripMenuItem = new ToolStripMenuItem();
            搜索SToolStripMenuItem = new ToolStripMenuItem();
            toolStripSeparator7 = new ToolStripSeparator();
            关于AToolStripMenuItem = new ToolStripMenuItem();
            查找与替换ToolStripMenuItem = new ToolStripMenuItem();
            查找与替换ToolStripMenuItem1 = new ToolStripMenuItem();
            插入ToolStripMenuItem = new ToolStripMenuItem();
            图片ToolStripMenuItem = new ToolStripMenuItem();
            toolStrip1 = new ToolStrip();
            新建NToolStripButton = new ToolStripButton();
            打开OToolStripButton = new ToolStripButton();
            保存SToolStripButton = new ToolStripButton();
            打印PToolStripButton = new ToolStripButton();
            toolStripSeparator = new ToolStripSeparator();
            剪切UToolStripButton = new ToolStripButton();
            复制CToolStripButton = new ToolStripButton();
            粘贴PToolStripButton = new ToolStripButton();
            toolStripSeparator1 = new ToolStripSeparator();
            帮助LToolStripButton = new ToolStripButton();
            toolStripButton1 = new ToolStripButton();
            statusStrip1 = new StatusStrip();
            menuStrip1.SuspendLayout();
            toolStrip1.SuspendLayout();
            SuspendLayout();
            // 
            // textBox1
            // 
            textBox1.Location = new Point(0, 53);
            textBox1.Multiline = true;
            textBox1.Name = "textBox1";
            textBox1.Size = new Size(796, 372);
            textBox1.TabIndex = 0;
            textBox1.TextChanged += textBox1_TextChanged;
            // 
            // menuStrip1
            // 
            menuStrip1.Items.AddRange(new ToolStripItem[] { 文件FToolStripMenuItem, 编辑EToolStripMenuItem, 工具TToolStripMenuItem, 帮助HToolStripMenuItem, 查找与替换ToolStripMenuItem, 插入ToolStripMenuItem });
            menuStrip1.Location = new Point(0, 0);
            menuStrip1.Name = "menuStrip1";
            menuStrip1.Size = new Size(800, 25);
            menuStrip1.TabIndex = 1;
            menuStrip1.Text = "menuStrip1";
            // 
            // 文件FToolStripMenuItem
            // 
            文件FToolStripMenuItem.DropDownItems.AddRange(new ToolStripItem[] { 新建NToolStripMenuItem, 打开OToolStripMenuItem, toolStripSeparator2, 保存SToolStripMenuItem, 另存为AToolStripMenuItem, toolStripSeparator3, 打印PToolStripMenuItem, 打印预览VToolStripMenuItem, toolStripSeparator4, 退出XToolStripMenuItem });
            文件FToolStripMenuItem.Name = "文件FToolStripMenuItem";
            文件FToolStripMenuItem.Size = new Size(58, 21);
            文件FToolStripMenuItem.Text = "文件(&F)";
            // 
            // 新建NToolStripMenuItem
            // 
            新建NToolStripMenuItem.Image = (Image)resources.GetObject("新建NToolStripMenuItem.Image");
            新建NToolStripMenuItem.ImageTransparentColor = Color.Magenta;
            新建NToolStripMenuItem.Name = "新建NToolStripMenuItem";
            新建NToolStripMenuItem.ShortcutKeys = Keys.Control | Keys.N;
            新建NToolStripMenuItem.Size = new Size(180, 22);
            新建NToolStripMenuItem.Text = "新建(&N)";
            新建NToolStripMenuItem.Click += 新建NToolStripMenuItem_Click;
            // 
            // 打开OToolStripMenuItem
            // 
            打开OToolStripMenuItem.Image = (Image)resources.GetObject("打开OToolStripMenuItem.Image");
            打开OToolStripMenuItem.ImageTransparentColor = Color.Magenta;
            打开OToolStripMenuItem.Name = "打开OToolStripMenuItem";
            打开OToolStripMenuItem.ShortcutKeys = Keys.Control | Keys.O;
            打开OToolStripMenuItem.Size = new Size(180, 22);
            打开OToolStripMenuItem.Text = "打开(&O)";
            // 
            // toolStripSeparator2
            // 
            toolStripSeparator2.Name = "toolStripSeparator2";
            toolStripSeparator2.Size = new Size(177, 6);
            // 
            // 保存SToolStripMenuItem
            // 
            保存SToolStripMenuItem.Image = (Image)resources.GetObject("保存SToolStripMenuItem.Image");
            保存SToolStripMenuItem.ImageTransparentColor = Color.Magenta;
            保存SToolStripMenuItem.Name = "保存SToolStripMenuItem";
            保存SToolStripMenuItem.ShortcutKeys = Keys.Control | Keys.S;
            保存SToolStripMenuItem.Size = new Size(180, 22);
            保存SToolStripMenuItem.Text = "保存(&S)";
            // 
            // 另存为AToolStripMenuItem
            // 
            另存为AToolStripMenuItem.Name = "另存为AToolStripMenuItem";
            另存为AToolStripMenuItem.Size = new Size(180, 22);
            另存为AToolStripMenuItem.Text = "另存为(&A)";
            // 
            // toolStripSeparator3
            // 
            toolStripSeparator3.Name = "toolStripSeparator3";
            toolStripSeparator3.Size = new Size(177, 6);
            // 
            // 打印PToolStripMenuItem
            // 
            打印PToolStripMenuItem.Image = (Image)resources.GetObject("打印PToolStripMenuItem.Image");
            打印PToolStripMenuItem.ImageTransparentColor = Color.Magenta;
            打印PToolStripMenuItem.Name = "打印PToolStripMenuItem";
            打印PToolStripMenuItem.ShortcutKeys = Keys.Control | Keys.P;
            打印PToolStripMenuItem.Size = new Size(180, 22);
            打印PToolStripMenuItem.Text = "打印(&P)";
            // 
            // 打印预览VToolStripMenuItem
            // 
            打印预览VToolStripMenuItem.Image = (Image)resources.GetObject("打印预览VToolStripMenuItem.Image");
            打印预览VToolStripMenuItem.ImageTransparentColor = Color.Magenta;
            打印预览VToolStripMenuItem.Name = "打印预览VToolStripMenuItem";
            打印预览VToolStripMenuItem.Size = new Size(180, 22);
            打印预览VToolStripMenuItem.Text = "打印预览(&V)";
            // 
            // toolStripSeparator4
            // 
            toolStripSeparator4.Name = "toolStripSeparator4";
            toolStripSeparator4.Size = new Size(177, 6);
            // 
            // 退出XToolStripMenuItem
            // 
            退出XToolStripMenuItem.Name = "退出XToolStripMenuItem";
            退出XToolStripMenuItem.Size = new Size(180, 22);
            退出XToolStripMenuItem.Text = "退出(&X)";
            // 
            // 编辑EToolStripMenuItem
            // 
            编辑EToolStripMenuItem.DropDownItems.AddRange(new ToolStripItem[] { 撤消UToolStripMenuItem, 重做RToolStripMenuItem, toolStripSeparator5, 剪切TToolStripMenuItem, 复制CToolStripMenuItem, 粘贴PToolStripMenuItem, toolStripSeparator6, 全选AToolStripMenuItem });
            编辑EToolStripMenuItem.Name = "编辑EToolStripMenuItem";
            编辑EToolStripMenuItem.Size = new Size(59, 21);
            编辑EToolStripMenuItem.Text = "编辑(&E)";
            // 
            // 撤消UToolStripMenuItem
            // 
            撤消UToolStripMenuItem.Name = "撤消UToolStripMenuItem";
            撤消UToolStripMenuItem.ShortcutKeys = Keys.Control | Keys.Z;
            撤消UToolStripMenuItem.Size = new Size(161, 22);
            撤消UToolStripMenuItem.Text = "撤消(&U)";
            // 
            // 重做RToolStripMenuItem
            // 
            重做RToolStripMenuItem.Name = "重做RToolStripMenuItem";
            重做RToolStripMenuItem.ShortcutKeys = Keys.Control | Keys.Y;
            重做RToolStripMenuItem.Size = new Size(161, 22);
            重做RToolStripMenuItem.Text = "重做(&R)";
            // 
            // toolStripSeparator5
            // 
            toolStripSeparator5.Name = "toolStripSeparator5";
            toolStripSeparator5.Size = new Size(158, 6);
            // 
            // 剪切TToolStripMenuItem
            // 
            剪切TToolStripMenuItem.Image = (Image)resources.GetObject("剪切TToolStripMenuItem.Image");
            剪切TToolStripMenuItem.ImageTransparentColor = Color.Magenta;
            剪切TToolStripMenuItem.Name = "剪切TToolStripMenuItem";
            剪切TToolStripMenuItem.ShortcutKeys = Keys.Control | Keys.X;
            剪切TToolStripMenuItem.Size = new Size(161, 22);
            剪切TToolStripMenuItem.Text = "剪切(&T)";
            // 
            // 复制CToolStripMenuItem
            // 
            复制CToolStripMenuItem.Image = (Image)resources.GetObject("复制CToolStripMenuItem.Image");
            复制CToolStripMenuItem.ImageTransparentColor = Color.Magenta;
            复制CToolStripMenuItem.Name = "复制CToolStripMenuItem";
            复制CToolStripMenuItem.ShortcutKeys = Keys.Control | Keys.C;
            复制CToolStripMenuItem.Size = new Size(161, 22);
            复制CToolStripMenuItem.Text = "复制(&C)";
            // 
            // 粘贴PToolStripMenuItem
            // 
            粘贴PToolStripMenuItem.Image = (Image)resources.GetObject("粘贴PToolStripMenuItem.Image");
            粘贴PToolStripMenuItem.ImageTransparentColor = Color.Magenta;
            粘贴PToolStripMenuItem.Name = "粘贴PToolStripMenuItem";
            粘贴PToolStripMenuItem.ShortcutKeys = Keys.Control | Keys.V;
            粘贴PToolStripMenuItem.Size = new Size(161, 22);
            粘贴PToolStripMenuItem.Text = "粘贴(&P)";
            // 
            // toolStripSeparator6
            // 
            toolStripSeparator6.Name = "toolStripSeparator6";
            toolStripSeparator6.Size = new Size(158, 6);
            // 
            // 全选AToolStripMenuItem
            // 
            全选AToolStripMenuItem.Name = "全选AToolStripMenuItem";
            全选AToolStripMenuItem.Size = new Size(161, 22);
            全选AToolStripMenuItem.Text = "全选(&A)";
            // 
            // 工具TToolStripMenuItem
            // 
            工具TToolStripMenuItem.DropDownItems.AddRange(new ToolStripItem[] { 自定义CToolStripMenuItem, 选项OToolStripMenuItem });
            工具TToolStripMenuItem.Name = "工具TToolStripMenuItem";
            工具TToolStripMenuItem.Size = new Size(59, 21);
            工具TToolStripMenuItem.Text = "工具(&T)";
            // 
            // 自定义CToolStripMenuItem
            // 
            自定义CToolStripMenuItem.Name = "自定义CToolStripMenuItem";
            自定义CToolStripMenuItem.Size = new Size(128, 22);
            自定义CToolStripMenuItem.Text = "自定义(&C)";
            // 
            // 选项OToolStripMenuItem
            // 
            选项OToolStripMenuItem.Name = "选项OToolStripMenuItem";
            选项OToolStripMenuItem.Size = new Size(128, 22);
            选项OToolStripMenuItem.Text = "选项(&O)";
            // 
            // 帮助HToolStripMenuItem
            // 
            帮助HToolStripMenuItem.DropDownItems.AddRange(new ToolStripItem[] { 内容CToolStripMenuItem, 索引IToolStripMenuItem, 搜索SToolStripMenuItem, toolStripSeparator7, 关于AToolStripMenuItem });
            帮助HToolStripMenuItem.Name = "帮助HToolStripMenuItem";
            帮助HToolStripMenuItem.Size = new Size(61, 21);
            帮助HToolStripMenuItem.Text = "帮助(&H)";
            // 
            // 内容CToolStripMenuItem
            // 
            内容CToolStripMenuItem.Name = "内容CToolStripMenuItem";
            内容CToolStripMenuItem.Size = new Size(125, 22);
            内容CToolStripMenuItem.Text = "内容(&C)";
            // 
            // 索引IToolStripMenuItem
            // 
            索引IToolStripMenuItem.Name = "索引IToolStripMenuItem";
            索引IToolStripMenuItem.Size = new Size(125, 22);
            索引IToolStripMenuItem.Text = "索引(&I)";
            // 
            // 搜索SToolStripMenuItem
            // 
            搜索SToolStripMenuItem.Name = "搜索SToolStripMenuItem";
            搜索SToolStripMenuItem.Size = new Size(125, 22);
            搜索SToolStripMenuItem.Text = "搜索(&S)";
            // 
            // toolStripSeparator7
            // 
            toolStripSeparator7.Name = "toolStripSeparator7";
            toolStripSeparator7.Size = new Size(122, 6);
            // 
            // 关于AToolStripMenuItem
            // 
            关于AToolStripMenuItem.Name = "关于AToolStripMenuItem";
            关于AToolStripMenuItem.Size = new Size(125, 22);
            关于AToolStripMenuItem.Text = "关于(&A)...";
            // 
            // 查找与替换ToolStripMenuItem
            // 
            查找与替换ToolStripMenuItem.DropDownItems.AddRange(new ToolStripItem[] { 查找与替换ToolStripMenuItem1 });
            查找与替换ToolStripMenuItem.Name = "查找与替换ToolStripMenuItem";
            查找与替换ToolStripMenuItem.Size = new Size(80, 21);
            查找与替换ToolStripMenuItem.Text = "查找与替换";
            // 
            // 查找与替换ToolStripMenuItem1
            // 
            查找与替换ToolStripMenuItem1.Name = "查找与替换ToolStripMenuItem1";
            查找与替换ToolStripMenuItem1.Size = new Size(136, 22);
            查找与替换ToolStripMenuItem1.Text = "查找与替换";
            // 
            // 插入ToolStripMenuItem
            // 
            插入ToolStripMenuItem.DropDownItems.AddRange(new ToolStripItem[] { 图片ToolStripMenuItem });
            插入ToolStripMenuItem.Name = "插入ToolStripMenuItem";
            插入ToolStripMenuItem.Size = new Size(44, 21);
            插入ToolStripMenuItem.Text = "插入";
            // 
            // 图片ToolStripMenuItem
            // 
            图片ToolStripMenuItem.Name = "图片ToolStripMenuItem";
            图片ToolStripMenuItem.Size = new Size(100, 22);
            图片ToolStripMenuItem.Text = "图片";
            // 
            // toolStrip1
            // 
            toolStrip1.Items.AddRange(new ToolStripItem[] { 新建NToolStripButton, 打开OToolStripButton, 保存SToolStripButton, 打印PToolStripButton, toolStripSeparator, 剪切UToolStripButton, 复制CToolStripButton, 粘贴PToolStripButton, toolStripSeparator1, 帮助LToolStripButton, toolStripButton1 });
            toolStrip1.Location = new Point(0, 25);
            toolStrip1.Name = "toolStrip1";
            toolStrip1.Size = new Size(800, 25);
            toolStrip1.TabIndex = 2;
            toolStrip1.Text = "toolStrip1";
            // 
            // 新建NToolStripButton
            // 
            新建NToolStripButton.DisplayStyle = ToolStripItemDisplayStyle.Image;
            新建NToolStripButton.Image = (Image)resources.GetObject("新建NToolStripButton.Image");
            新建NToolStripButton.ImageTransparentColor = Color.Magenta;
            新建NToolStripButton.Name = "新建NToolStripButton";
            新建NToolStripButton.Size = new Size(23, 22);
            新建NToolStripButton.Text = "新建(&N)";
            // 
            // 打开OToolStripButton
            // 
            打开OToolStripButton.DisplayStyle = ToolStripItemDisplayStyle.Image;
            打开OToolStripButton.Image = (Image)resources.GetObject("打开OToolStripButton.Image");
            打开OToolStripButton.ImageTransparentColor = Color.Magenta;
            打开OToolStripButton.Name = "打开OToolStripButton";
            打开OToolStripButton.Size = new Size(23, 22);
            打开OToolStripButton.Text = "打开(&O)";
            // 
            // 保存SToolStripButton
            // 
            保存SToolStripButton.DisplayStyle = ToolStripItemDisplayStyle.Image;
            保存SToolStripButton.Image = (Image)resources.GetObject("保存SToolStripButton.Image");
            保存SToolStripButton.ImageTransparentColor = Color.Magenta;
            保存SToolStripButton.Name = "保存SToolStripButton";
            保存SToolStripButton.Size = new Size(23, 22);
            保存SToolStripButton.Text = "保存(&S)";
            // 
            // 打印PToolStripButton
            // 
            打印PToolStripButton.DisplayStyle = ToolStripItemDisplayStyle.Image;
            打印PToolStripButton.Image = (Image)resources.GetObject("打印PToolStripButton.Image");
            打印PToolStripButton.ImageTransparentColor = Color.Magenta;
            打印PToolStripButton.Name = "打印PToolStripButton";
            打印PToolStripButton.Size = new Size(23, 22);
            打印PToolStripButton.Text = "打印(&P)";
            // 
            // toolStripSeparator
            // 
            toolStripSeparator.Name = "toolStripSeparator";
            toolStripSeparator.Size = new Size(6, 25);
            // 
            // 剪切UToolStripButton
            // 
            剪切UToolStripButton.DisplayStyle = ToolStripItemDisplayStyle.Image;
            剪切UToolStripButton.Image = (Image)resources.GetObject("剪切UToolStripButton.Image");
            剪切UToolStripButton.ImageTransparentColor = Color.Magenta;
            剪切UToolStripButton.Name = "剪切UToolStripButton";
            剪切UToolStripButton.Size = new Size(23, 22);
            剪切UToolStripButton.Text = "剪切(&U)";
            // 
            // 复制CToolStripButton
            // 
            复制CToolStripButton.DisplayStyle = ToolStripItemDisplayStyle.Image;
            复制CToolStripButton.Image = (Image)resources.GetObject("复制CToolStripButton.Image");
            复制CToolStripButton.ImageTransparentColor = Color.Magenta;
            复制CToolStripButton.Name = "复制CToolStripButton";
            复制CToolStripButton.Size = new Size(23, 22);
            复制CToolStripButton.Text = "复制(&C)";
            // 
            // 粘贴PToolStripButton
            // 
            粘贴PToolStripButton.DisplayStyle = ToolStripItemDisplayStyle.Image;
            粘贴PToolStripButton.Image = (Image)resources.GetObject("粘贴PToolStripButton.Image");
            粘贴PToolStripButton.ImageTransparentColor = Color.Magenta;
            粘贴PToolStripButton.Name = "粘贴PToolStripButton";
            粘贴PToolStripButton.Size = new Size(23, 22);
            粘贴PToolStripButton.Text = "粘贴(&P)";
            // 
            // toolStripSeparator1
            // 
            toolStripSeparator1.Name = "toolStripSeparator1";
            toolStripSeparator1.Size = new Size(6, 25);
            // 
            // 帮助LToolStripButton
            // 
            帮助LToolStripButton.DisplayStyle = ToolStripItemDisplayStyle.Image;
            帮助LToolStripButton.Image = (Image)resources.GetObject("帮助LToolStripButton.Image");
            帮助LToolStripButton.ImageTransparentColor = Color.Magenta;
            帮助LToolStripButton.Name = "帮助LToolStripButton";
            帮助LToolStripButton.Size = new Size(23, 22);
            帮助LToolStripButton.Text = "帮助(&L)";
            // 
            // toolStripButton1
            // 
            toolStripButton1.DisplayStyle = ToolStripItemDisplayStyle.Image;
            toolStripButton1.Image = (Image)resources.GetObject("toolStripButton1.Image");
            toolStripButton1.ImageTransparentColor = Color.Magenta;
            toolStripButton1.Name = "toolStripButton1";
            toolStripButton1.Size = new Size(23, 22);
            toolStripButton1.Text = "toolStripButton1";
            // 
            // statusStrip1
            // 
            statusStrip1.Location = new Point(0, 428);
            statusStrip1.Name = "statusStrip1";
            statusStrip1.Size = new Size(800, 22);
            statusStrip1.TabIndex = 3;
            statusStrip1.Text = "statusStrip1";
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(7F, 17F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(800, 450);
            Controls.Add(statusStrip1);
            Controls.Add(toolStrip1);
            Controls.Add(textBox1);
            Controls.Add(menuStrip1);
            MainMenuStrip = menuStrip1;
            Name = "Form1";
            Text = "Form1";
            menuStrip1.ResumeLayout(false);
            menuStrip1.PerformLayout();
            toolStrip1.ResumeLayout(false);
            toolStrip1.PerformLayout();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private TextBox textBox1;
        private MenuStrip menuStrip1;
        private ToolStripMenuItem 文件FToolStripMenuItem;
        private ToolStripMenuItem 新建NToolStripMenuItem;
        private ToolStripMenuItem 打开OToolStripMenuItem;
        private ToolStripSeparator toolStripSeparator2;
        private ToolStripMenuItem 保存SToolStripMenuItem;
        private ToolStripMenuItem 另存为AToolStripMenuItem;
        private ToolStripSeparator toolStripSeparator3;
        private ToolStripMenuItem 打印PToolStripMenuItem;
        private ToolStripMenuItem 打印预览VToolStripMenuItem;
        private ToolStripSeparator toolStripSeparator4;
        private ToolStripMenuItem 退出XToolStripMenuItem;
        private ToolStripMenuItem 编辑EToolStripMenuItem;
        private ToolStripMenuItem 撤消UToolStripMenuItem;
        private ToolStripMenuItem 重做RToolStripMenuItem;
        private ToolStripSeparator toolStripSeparator5;
        private ToolStripMenuItem 剪切TToolStripMenuItem;
        private ToolStripMenuItem 复制CToolStripMenuItem;
        private ToolStripMenuItem 粘贴PToolStripMenuItem;
        private ToolStripSeparator toolStripSeparator6;
        private ToolStripMenuItem 全选AToolStripMenuItem;
        private ToolStripMenuItem 工具TToolStripMenuItem;
        private ToolStripMenuItem 自定义CToolStripMenuItem;
        private ToolStripMenuItem 选项OToolStripMenuItem;
        private ToolStripMenuItem 帮助HToolStripMenuItem;
        private ToolStripMenuItem 内容CToolStripMenuItem;
        private ToolStripMenuItem 索引IToolStripMenuItem;
        private ToolStripMenuItem 搜索SToolStripMenuItem;
        private ToolStripSeparator toolStripSeparator7;
        private ToolStripMenuItem 关于AToolStripMenuItem;
        private ToolStripMenuItem 查找与替换ToolStripMenuItem;
        private ToolStrip toolStrip1;
        private ToolStripButton 新建NToolStripButton;
        private ToolStripButton 打开OToolStripButton;
        private ToolStripButton 保存SToolStripButton;
        private ToolStripButton 打印PToolStripButton;
        private ToolStripSeparator toolStripSeparator;
        private ToolStripButton 剪切UToolStripButton;
        private ToolStripButton 复制CToolStripButton;
        private ToolStripButton 粘贴PToolStripButton;
        private ToolStripSeparator toolStripSeparator1;
        private ToolStripButton 帮助LToolStripButton;
        private StatusStrip statusStrip1;
        private ToolStripMenuItem 查找与替换ToolStripMenuItem1;
        private ToolStripMenuItem 插入ToolStripMenuItem;
        private ToolStripMenuItem 图片ToolStripMenuItem;
        private ToolStripButton toolStripButton1;
    }
}
