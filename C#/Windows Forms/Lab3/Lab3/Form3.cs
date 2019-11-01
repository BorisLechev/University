using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Lab3
{
    public partial class Form3 : Form
    {
        public Form3()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            double a = double.Parse(textBox1.Text);
            double b = double.Parse(textBox2.Text);
            double result = 0;
            

            if (radioButton1.Checked)
            {
                result = Math.Pow(a + b, 2);

                textBox3.Text = result.ToString();
            }

            else if (radioButton2.Checked)
            {
                result = Math.Pow(a - b, 2);

                textBox3.Text = result.ToString();
            }

            else if (radioButton3.Checked)
            {
                result = (a+b) * (a-b);

                textBox3.Text = result.ToString();
            }

            else if (radioButton4.Checked)
            {
                result = Math.Pow(a + b, 3);

                textBox3.Text = result.ToString();
            }

            else if (radioButton5.Checked)
            {
                result = Math.Pow(a - b, 3);

                textBox3.Text = result.ToString();
            }

            else if (radioButton6.Checked)
            {
                result = Math.Pow(a, 3) + Math.Pow(b, 3);

                textBox3.Text = result.ToString();
            }

            else if (radioButton6.Checked)
            {
                result = Math.Pow(a, 3) - Math.Pow(b, 3);

                textBox3.Text = result.ToString();
            }
        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {
            
        }

        private void button2_Click(object sender, EventArgs e)
        {
            textBox1.Text = "";
            textBox2.Text = "";
            textBox3.Text = "";
        }

        private void button3_Click(object sender, EventArgs e)
        {
            this.Hide();
        }
    }
}
