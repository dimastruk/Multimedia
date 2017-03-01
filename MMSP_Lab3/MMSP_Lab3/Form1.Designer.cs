namespace MMSP_Lab3
{
    partial class Form1
    {
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.Display = new Tao.Platform.Windows.SimpleOpenGlControl();
            this.label1 = new System.Windows.Forms.Label();
            this.ConstValue = new System.Windows.Forms.NumericUpDown();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.SinAngle = new System.Windows.Forms.NumericUpDown();
            ((System.ComponentModel.ISupportInitialize)(this.ConstValue)).BeginInit();
            this.groupBox1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.SinAngle)).BeginInit();
            this.SuspendLayout();
            // 
            // Display
            // 
            this.Display.AccumBits = ((byte)(0));
            this.Display.AutoCheckErrors = false;
            this.Display.AutoFinish = false;
            this.Display.AutoMakeCurrent = true;
            this.Display.AutoSwapBuffers = true;
            this.Display.BackColor = System.Drawing.Color.Black;
            this.Display.ColorBits = ((byte)(32));
            this.Display.DepthBits = ((byte)(16));
            this.Display.Location = new System.Drawing.Point(-1, 0);
            this.Display.Name = "Display";
            this.Display.Size = new System.Drawing.Size(480, 480);
            this.Display.StencilBits = ((byte)(0));
            this.Display.TabIndex = 0;
            this.Display.Load += new System.EventHandler(this.Display_Load);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(485, 9);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(77, 13);
            this.label1.TabIndex = 4;
            this.label1.Text = "Коефіцієнт \'a\':";
            // 
            // ConstValue
            // 
            this.ConstValue.Location = new System.Drawing.Point(487, 28);
            this.ConstValue.Name = "ConstValue";
            this.ConstValue.Size = new System.Drawing.Size(154, 20);
            this.ConstValue.TabIndex = 5;
            this.ConstValue.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.ConstValue.ValueChanged += new System.EventHandler(this.ConstValue_ValueChanged);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.SinAngle);
            this.groupBox1.Location = new System.Drawing.Point(487, 54);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(154, 51);
            this.groupBox1.TabIndex = 6;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Кут повороту:";
            // 
            // SinAngle
            // 
            this.SinAngle.Location = new System.Drawing.Point(6, 19);
            this.SinAngle.Maximum = new decimal(new int[] {
            361,
            0,
            0,
            0});
            this.SinAngle.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            -2147483648});
            this.SinAngle.Name = "SinAngle";
            this.SinAngle.Size = new System.Drawing.Size(142, 20);
            this.SinAngle.TabIndex = 7;
            this.SinAngle.ValueChanged += new System.EventHandler(this.SinAngle_ValueChanged);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(648, 478);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.ConstValue);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.Display);
            this.Name = "Form1";
            this.Text = "y = a*sin(x)";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.ConstValue)).EndInit();
            this.groupBox1.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.SinAngle)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private Tao.Platform.Windows.SimpleOpenGlControl Display;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.NumericUpDown ConstValue;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.NumericUpDown SinAngle;
    }
}

