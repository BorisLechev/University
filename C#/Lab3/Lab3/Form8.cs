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
    public partial class Form8 : Form
    {
        private Random rnd;

        private int randomNumber;

        public Form8()
        {
            InitializeComponent();
            this.rnd = new Random();
            this.randomNumber = rnd.Next(1, 100);
        }

        private void button1_Click(object sender, EventArgs e)
        {

            int enteredNumber = int.Parse(textBox1.Text);

            if (enteredNumber == this.randomNumber)
            {
                MessageBox.Show("Congratulation, you have guessed the number.");
            }

            else if (enteredNumber > randomNumber)
            {
                MessageBox.Show($"The number is smaller than {enteredNumber}");
            }

            else
            {
                MessageBox.Show($"The number is bigger than {enteredNumber}");
            }
        }
    }
}
