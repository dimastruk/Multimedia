using System;
using System.Windows.Forms;

// для роботи з бібліотекою OpenGL 
using Tao.OpenGl;
// для роботи з бібліотекою FreeGLUT 
using Tao.FreeGlut;

namespace MMSP_Lab3
{
    public partial class Form1 : Form
    {
        const double Plane_Height = 20.0;
        const double Plane_Width = 20.0;
        int angle = 0;
        public Form1()
        {
            InitializeComponent();
            Display.InitializeContexts();

            ConstValue.Maximum = (decimal)Plane_Height/2;
            ConstValue.Minimum = 1;
        }

        public void ShowDisplay(double plane_height, double plane_width)
        {
            Glut.glutInit();
            Glut.glutInitDisplayMode(Glut.GLUT_RGB | Glut.GLUT_SINGLE);

            Gl.glClearColor(255, 255, 255, 1);

            Gl.glViewport(0, 0, Display.Width, Display.Height);

            Gl.glMatrixMode(Gl.GL_PROJECTION);
            Gl.glLoadIdentity();

            if ((float)Display.Width <= (float)Display.Height)
            {
                Glu.gluOrtho2D(0.0, plane_height * (float)Display.Height / (float)Display.Width, 0.0, plane_width);
            }
            else
            {
                Glu.gluOrtho2D(0.0, plane_width * (float)Display.Width / (float)Display.Height, 0.0, plane_height);
            }

            Gl.glMatrixMode(Gl.GL_MODELVIEW);
            Gl.glLoadIdentity();
        }

        private void Display_Load(object sender, EventArgs e)
        {
            ShowDisplay(Plane_Height, Plane_Width);   
        }

        private void StartButton_Click(object sender, EventArgs e)
        {
            BuildCartesianPlane();
        }

        public void BuildCartesianPlane()
        {
            Gl.glClear(Gl.GL_COLOR_BUFFER_BIT);
            Gl.glLoadIdentity();

            Gl.glColor3d(0.8, 0.8, 0.8);

            // Вертикальні лінії
            Gl.glLineWidth(1);
            for (int i = 0; i < Plane_Width; i++)
                DrawLine(i, 0, i, Plane_Height);

            // Горизонтальні лінії
            Gl.glLineWidth(1);
            for (int i = 0; i < Plane_Height; i++)
                DrawLine(0, i, Plane_Width, i);

            Gl.glColor3d(0.0, 0.0, 0.0);
            Gl.glLineWidth(2);

            // Вісь X
            DrawLine(0, Plane_Height / 2, Plane_Width, Plane_Height / 2);
            DrawLine(Plane_Width, Plane_Height / 2, Plane_Width - 0.5, (Plane_Height / 2) - 0.5);
            DrawLine(Plane_Width, Plane_Height / 2, Plane_Width - 0.5, (Plane_Height / 2) + 0.5);

            // Вісь Y
            DrawLine(Plane_Width / 2, Plane_Height, Plane_Width / 2, 0);
            DrawLine(Plane_Width / 2, Plane_Height, (Plane_Width / 2 - 0.5), Plane_Height - 0.5);
            DrawLine(Plane_Width / 2, Plane_Height, (Plane_Width / 2 + 0.5), Plane_Height - 0.5);

            // Підписи до осі X
            for (int i = 0, k = -(int)(Plane_Width / 2); i < Plane_Width; i++, k++)
                PrintText(i - 0.15, Plane_Height / 2 + 0.1, k.ToString());

            // Підписи до осі Y
            for (int i = 0, k = -(int)(Plane_Height / 2); i < Plane_Height; i++, k++)
            {
                if (k == 0) continue;
                if (k < 0)
                    PrintText(Plane_Width / 2, i - 0.15, k.ToString());
                else
                    PrintText(Plane_Width / 2 + 0.3, i - 0.15, k.ToString());
            }

            Gl.glFlush();
            Display.Invalidate();
        }

        public void BuildGraphic()
        {
            BuildCartesianPlane();

            Gl.glTranslated(Plane_Width / 2, Plane_Width / 2, 0);            
            
            Gl.glRotated(angle, 0.0, 0.0, 1.0);

            for (double i = 0; i < Plane_Width; i += 0.001)
                DrawPoint(i, (double)ConstValue.Value*Math.Sin(i));

            for (double i = 0; i < Plane_Width; i += 0.001)
                DrawPoint(-i, (double)ConstValue.Value*Math.Sin(-i));

            Gl.glFlush();
            Display.Invalidate();
        }

        public void DrawLine(double x1, double y1, double x2, double y2)
        {
            Gl.glBegin(Gl.GL_LINE_STRIP);
            Gl.glVertex2d(x1, y1);
            Gl.glVertex2d(x2, y2);
            Gl.glEnd();
        }

        public void DrawPoint(double x, double y)
        {
            Gl.glBegin(Gl.GL_POINTS);
            Gl.glVertex2d(x, y);
            Gl.glEnd();
        }

        public void PrintText(double x, double y, string text)
        {
            Gl.glRasterPos2f((float)x, (float)y);

            foreach (var my_char in text)
            { 
                Glut.glutBitmapCharacter(Glut.GLUT_BITMAP_8_BY_13, my_char);
            }
        }

        private void ConstValue_ValueChanged(object sender, EventArgs e)
        {
            BuildGraphic();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            BuildGraphic();
        }

        private void SinAngle_ValueChanged(object sender, EventArgs e)
        {
            if (SinAngle.Value == 361) SinAngle.Value = 0;
            if (SinAngle.Value == -1) SinAngle.Value = 360;
            angle = (int)SinAngle.Value;
            BuildGraphic();
        }
    }
}