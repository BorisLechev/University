using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Lab2
{
    public partial class Form1 : Form
    {



        public Form1()
        {
            InitializeComponent();

            comboBox1.Items.Add("C");
            comboBox1.Items.Add("F");

        }

        private void label7_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            double a = Double.Parse(textBox1.Text);
            double b = Double.Parse(textBox2.Text);
            double c = Double.Parse(textBox3.Text);

            double x1 = 0;
            double x2 = 0;

       
            double d = b * b - 4 * a * c;

            if (d == 0)
            {
                x1 =  -b /(2 * a);
                x2 = x1;
            }
            else if (d > 0)
            {
                x1 = (-b + Math.Sqrt(d)) / (2 * a);
                x2 = (-b - Math.Sqrt(d)) / (2 * a);
            }
            label6.Text = (x1).ToString();
            label7.Text = (x2).ToString();

            button1.Visible = false;

        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void domainUpDown1_SelectedItemChanged(object sender, EventArgs e)
        {

        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            double num = Double.Parse(textBox4.Text);

            ComboBox cmb = (ComboBox)sender;
            String s = comboBox1.SelectedItem.ToString();

            //double value = 1234;

            if (s == "C")
            {
                num = num * 9 / 5 + 32;
            }
            else
            {
                num = (num - 32) * 5 / 9;
            }

            textBox5.Text = num.ToString();
        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {
            double a = Double.Parse(textBox1.Text);
            double b = Double.Parse(textBox2.Text);
            double c = Double.Parse(textBox3.Text);

            double x1 = 0;
            double x2 = 0;


            double d = b * b - 4 * a * c;

            if (d == 0)
            {
                x1 = -b / (2 * a);
                x2 = x1;
            }
            else if (d > 0)
            {
                x1 = (-b + Math.Sqrt(d)) / (2 * a);
                x2 = (-b - Math.Sqrt(d)) / (2 * a);
            }
            label6.Text = (x1).ToString();
            label7.Text = (x2).ToString();
        }

        private void vScrollBar1_Scroll(object sender, ScrollEventArgs e)
        {

        }

        private void tableLayoutPanel1_Paint(object sender, PaintEventArgs e)
        {

        }
    }
}
