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
    public partial class Form7 : Form
    {
        public Form7()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            HashSet<int> numbers = new HashSet<int>();
            Random rnd = new Random();

            while (numbers.Count < 6)
            {
                numbers.Add(rnd.Next(1, 49));
            }

            List<int> list = numbers.ToList();

            label1.Text = list[0].ToString();
            label2.Text = list[1].ToString();
            label3.Text = list[2].ToString();
            label4.Text = list[3].ToString();
            label5.Text = list[4].ToString();
            label6.Text = list[5].ToString();
        }
    }
}
