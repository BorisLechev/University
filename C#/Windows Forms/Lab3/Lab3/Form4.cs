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
    public partial class Form4 : Form
    {
        public Form4()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            decimal salary = decimal.Parse(textBox1.Text);

            decimal doo;
            decimal dzpo;
            decimal zdravni = salary * 0.032M;


            if (radioButton1.Checked)
            {
                doo = salary * 0.089M;
                dzpo = 0;

                label7.Text = doo.ToString();
                label8.Text = doo.ToString();
                label9.Text = zdravni.ToString();
                label10.Text = String.Format("{0:0.00}", Math.Floor(doo + dzpo + zdravni));
            }

            else if (radioButton2.Checked)
            {
                doo = salary * 0.067M;
                dzpo = salary * 0.022M;

                label7.Text = doo.ToString();
                label8.Text = doo.ToString();
                label9.Text = zdravni.ToString();
                label10.Text = String.Format("{0:0.00}", Math.Floor(doo + dzpo + zdravni));
            }
        }
    }
}
