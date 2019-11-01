using System;
using System.Collections.Generic;
using System.Windows.Forms;

namespace Coursework
{
    public partial class Calculator : Form
    {
        public string[,] secondMatrix;

        public Calculator()
        {
            InitializeComponent();
        }

        private void Calculator_Load(object sender, EventArgs e)
        {

        }

        private void textBox4_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            int firstRowFirstCol = int.Parse(textBox1.Text);
            int firstRowSecondCol = int.Parse(textBox2.Text);
            int firstRowThirdCol = int.Parse(textBox3.Text);
            int firstRowFourthCol = int.Parse(textBox4.Text);
            int secondRowFirstCol = int.Parse(textBox5.Text);
            int secondRowSecondCol = int.Parse(textBox6.Text);
            int secondRowThirdCol = int.Parse(textBox7.Text);
            int secondRowFourthCol = int.Parse(textBox8.Text);
            int thirdRowFirstCol = int.Parse(textBox9.Text);
            int thirdRowSecondCol = int.Parse(textBox10.Text);
            int thirdRowThirdCol = int.Parse(textBox11.Text);
            int thirdRowFourthCol = int.Parse(textBox12.Text);
            int fourthRowFirstCol = int.Parse(textBox13.Text);
            int fourthRowSecondCol = int.Parse(textBox14.Text);
            int fourthRowThirdCol = int.Parse(textBox15.Text);
            int fourthRowFourthCol = 0;

            int[,] firstMatrix = new int[,]
            {
                { firstRowFirstCol, firstRowSecondCol, firstRowThirdCol, firstRowFourthCol },
                { secondRowFirstCol, secondRowSecondCol, secondRowThirdCol, secondRowFourthCol },
                { thirdRowFirstCol, thirdRowSecondCol, thirdRowThirdCol, thirdRowFourthCol },
                { fourthRowFirstCol, fourthRowSecondCol, fourthRowThirdCol, fourthRowFourthCol }
            };

            this.secondMatrix = new string[,]
            {
                { "-", "-", "-", "-" },
                { "-", "-", "-", "-" },
                { "-", "-", "-", "-" },
                { "-", "-", "-", "-" }
            };

            int row = Int32.MinValue;
            int col = Int32.MinValue;
            List<int> coordinates = new List<int>();

            do
            {
                coordinates = FindTheCoordinatesOfTheMinNumber(firstMatrix);
                row = coordinates[0];
                col = coordinates[1];

                if (row < 0 && col < 0)
                {
                    break;
                }

                PutTheMinNumberInTheMatrix(firstMatrix, row, col);
            } while (coordinates.Count == 2);

            textBox16.Text = PrintResult(firstMatrix);
        }

        private List<int> FindTheCoordinatesOfTheMinNumber(int[,] matrix)
        {
            List<int> coordinates = new List<int>();
            int finalRow = Int32.MinValue;
            int finalCol = Int32.MinValue;
            int minValue = Int32.MaxValue;

            for (int row = 0; row < matrix.GetLength(0) - 1; row++)
            {
                for (int col = 0; col < matrix.GetLength(1) - 1; col++)
                {
                    int currentNumber = matrix[row, col];

                    if (this.secondMatrix[row, col] != "-" || matrix[3, col + 1] < 0 || matrix[row + 1, 3] < 0 || (row == 3 && col == 3))
                    {
                        continue;
                    }

                    if (currentNumber < minValue)
                    {
                        minValue = currentNumber;
                        finalRow = row;
                        finalCol = col;
                    }
                }
            }

            coordinates.Add(finalRow);
            coordinates.Add(finalCol);

            return coordinates;
        }

        private void PutTheMinNumberInTheMatrix(int[,] matrix, int row, int col)
        {
            int minNumber = Math.Min(matrix[3, col], matrix[row, 3]);

            this.secondMatrix[row, col] = minNumber.ToString();

            matrix[3, col] -= minNumber;
            matrix[row, 3] -= minNumber;
        }

        private string PrintResult(int[,] firstMatrix)
        {
            string result = "";
            int value = 0;

            for (int row = 0; row < firstMatrix.GetLength(0); row++)
            {
                for (int col = 0; col < firstMatrix.GetLength(1); col++)
                {
                    if (this.secondMatrix[row, col] == "-")
                    {
                        continue;
                    }

                    int currentNumberFirstMatrix = firstMatrix[row, col];
                    int currentNumberSecondMatrix = int.Parse(this.secondMatrix[row, col]);

                    if (currentNumberSecondMatrix <= 0)
                    {
                        continue;
                    }

                    value += currentNumberFirstMatrix * currentNumberSecondMatrix;
                    result += $"({currentNumberFirstMatrix} x {currentNumberSecondMatrix}) + ";
                }
            }

            result = result.Substring(0, result.Length - 3);
            result += $" = {value}";

            return result;
        }
    }
}
