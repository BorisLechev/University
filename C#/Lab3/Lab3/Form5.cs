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
    public partial class Form5 : Form
    {
        public Form5()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            bool isLeapYear = false;

            int year = int.Parse(textBox1.Text);

            if (DateTime.IsLeapYear(year))
            {
                isLeapYear = true;
            }

            int month = int.Parse(textBox2.Text);

            DateTimeFormatInfo format = new DateTimeFormatInfo();
            string monthName = format.GetMonthName(month).ToString();

            int daysCount = DateTime.DaysInMonth(year, month);

            string result = isLeapYear
                ? $"{year} is a leap year. Count of days: {daysCount}"
                : $"{year} is not a leap year. {monthName} has count of days: {daysCount}";

            MessageBox.Show(result);
        }
    }
}
