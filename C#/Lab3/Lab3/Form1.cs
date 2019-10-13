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
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void toolStripMenuItem1_Click(object sender, EventArgs e)
        {

        }

        private void алгебраToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }

        private void класToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }

        private void степенуванеToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Form2 frm = new Form2();
            frm.Show();
        }

        private void stepenuvaneToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Form3 frm = new Form3();
            frm.Show();
        }

        private void izchisliToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Form4 frm = new Form4();
            frm.Show();
        }

        private void calendarToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Form5 frm = new Form5();
            frm.Show();
        }

        private void calculateAgeToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Form6 frm = new Form6();

            frm.Show();
        }

        private void lotteryToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Form7 frm = new Form7();

            frm.Show();
        }

        private void guessTheNumberToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Form8 frm = new Form8();

            frm.Show();
        }
    }
}
