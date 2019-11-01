using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Lab3
{
    public partial class Form6 : Form
    {
        public Form6()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            int inputYear = int.Parse(textBox3.Text);
            int inputMonth = int.Parse(textBox1.Text);

            int year = DateTime.Today.Year - inputYear;
            int month = DateTime.Today.Month - inputMonth;

            if (inputMonth < 1 || inputMonth > 12 || (inputMonth > DateTime.Now.Month && inputYear == DateTime.Now.Year))
            {
                MessageBox.Show("Invalid Month");
                return;
            }

            if (inputYear > DateTime.Now.Year)
            {
                MessageBox.Show("Invalid Year");
                return;
            }

            MessageBox.Show($"{year} Years and {month} Months");
        }
    }
}
