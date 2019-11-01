using System;
using System.Collections.Generic;
using System.Linq;

namespace coursework
{
    public class Startup
    {
        public static int demandSum;
        public static int supplySum;
        public static bool isSupplySumBiggerThanDemandSum = false;
        public static int numToAddSecondMatrixRow = 0;
        public static int numToAddSecondMatrixCol = 0;

        public static void Main(string[] args)
        {
            Console.Write("Enter number of rows: ");
            int rows = int.Parse(Console.ReadLine());

            Console.Write("Enter number of columns: ");
            int cols = int.Parse(Console.ReadLine());

            rows += 1;
            cols += 1;

            int[,] firstMatrix = new int[rows, cols];

            int row = Int32.MinValue;
            int col = Int32.MinValue;
            List<int> coordinates = new List<int>();

            firstMatrix = InitializeFirstMatrix(firstMatrix);

            string[,] secondMatrix = new string[firstMatrix.GetLength(0), firstMatrix.GetLength(1)];

            secondMatrix = FillTheSecondMatrixWithHyphens(secondMatrix, firstMatrix);

            do
            {
                if (isSupplySumBiggerThanDemandSum == true)
                {
                    coordinates = FindTheCoordinatesOfTheMinNumberNotEqualDemandSupply(firstMatrix, secondMatrix, rows, cols);
                }
                else
                {
                    coordinates = FindTheCoordinatesOfTheMinNumberEqualDemandSupply(firstMatrix, secondMatrix, rows, cols);
                }

                row = coordinates[0];
                col = coordinates[1];

                if (row < 0 && col < 0)
                {
                    break;
                }

                PutTheMinNumberInTheSecondMatrix(firstMatrix, secondMatrix, row, col, firstMatrix.GetLength(0), firstMatrix.GetLength(1));
            } while (coordinates.Count == 2);

            string output = PrintResult(firstMatrix, secondMatrix);
            Console.WriteLine($"Result: {output}");
        }

        private static List<int> FindTheCoordinatesOfTheMinNumberNotEqualDemandSupply(int[,] firstMatrix, string[,] secondMatrix, int rows, int cols)
        {
            List<int> coordinates = new List<int>();
            int finalRow = Int32.MinValue;
            int finalCol = Int32.MinValue;
            int minValue = Int32.MaxValue;

            for (int row = firstMatrix.GetLength(0) - 2; row >= 0; row--)
            {
                for (int col = 0; col < firstMatrix.GetLength(1) - 1; col++)
                {
                    int currentNumber = firstMatrix[row, col];

                    if (secondMatrix[row, col] != "-" || firstMatrix[rows - 1, col + 1] < 0 || firstMatrix[row + 1, cols - 1] < 0 || (row == rows - 1 && col == cols - 1) || currentNumber <= 0)
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

        private static string PrintResult(int[,] firstMatrix, string[,] secondMatrix)
        {
            string result = "";
            int value = 0;

            for (int row = 0; row < firstMatrix.GetLength(0); row++)
            {
                for (int col = 0; col < firstMatrix.GetLength(1); col++)
                {
                    if (secondMatrix[row, col] == "-")
                    {
                        continue;
                    }

                    int currentNumberFirstMatrix = firstMatrix[row, col];
                    int currentNumberSecondMatrix = int.Parse(secondMatrix[row, col]);

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

        private static int[,] InitializeFirstMatrix(int[,] firstMatrix)
        {
            int[,] newMatrix = new int[firstMatrix.GetLength(0), firstMatrix.GetLength(1) + 1];

            for (int row = 0; row < firstMatrix.GetLength(0); row++)
            {
                int[] tokens =
                    Console.ReadLine()
                    .Split(" ", StringSplitOptions.RemoveEmptyEntries)
                    .Select(int.Parse)
                    .ToArray();

                for (int col = 0; col < firstMatrix.GetLength(1); col++)
                {
                    if (col == firstMatrix.GetLength(1) - 1)
                    {
                        supplySum += tokens[col];
                    }

                    if (row == firstMatrix.GetLength(0) - 1)
                    {
                        demandSum += tokens[col];
                    }

                    firstMatrix[row, col] = tokens[col];

                    if (col == firstMatrix.GetLength(1) - 1)
                    {
                        newMatrix[row, col + 1] = tokens[col];
                    }

                    else
                    {
                        newMatrix[row, col] = tokens[col];
                    }
                }
            }

            if (supplySum > demandSum)
            {
                isSupplySumBiggerThanDemandSum = true;
                int diff = supplySum - demandSum;

                for (int row = 0; row < newMatrix.GetLength(0); row++)
                {
                    for (int col = 0; col < newMatrix.GetLength(1); col++)
                    {
                        if (row == 0 && col == newMatrix.GetLength(1) - 2)
                        {
                            newMatrix[row, col] = 0;
                            numToAddSecondMatrixRow = row;
                            numToAddSecondMatrixCol = col;
                            newMatrix[row, col + 1] -= diff;
                        }

                        if (row == newMatrix.GetLength(0) - 1 && col == newMatrix.GetLength(1) - 2)
                        {
                            newMatrix[row, col] = diff;
                        }
                    }
                }

                return newMatrix;
            }

            return firstMatrix;
        }

        private static void PutTheMinNumberInTheSecondMatrix(int[,] firstMatrix, string[,] secondMatrix, int row, int col, int rows, int cols)
        {
            int minNumber = Math.Min(firstMatrix[rows - 1, col], firstMatrix[row, cols - 1]);

            secondMatrix[row, col] = minNumber.ToString();

            firstMatrix[rows - 1, col] -= minNumber;
            firstMatrix[row, cols - 1] -= minNumber;
        }

        private static List<int> FindTheCoordinatesOfTheMinNumberEqualDemandSupply(int[,] firstMatrix, string[,] secondMatrix, int rows, int cols)
        {
            List<int> coordinates = new List<int>();
            int finalRow = Int32.MinValue;
            int finalCol = Int32.MinValue;
            int minValue = Int32.MaxValue;

            for (int row = 0; row < firstMatrix.GetLength(0) - 1; row++)
            {
                for (int col = 0; col < firstMatrix.GetLength(1) - 1; col++)
                {
                    int currentNumber = firstMatrix[row, col];

                    if (secondMatrix[row, col] != "-" || firstMatrix[rows - 1, col + 1] < 0 || firstMatrix[row + 1, cols - 1] < 0 || (row == rows - 1 && col == cols - 1) || currentNumber <= 0)
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

        private static string[,] FillTheSecondMatrixWithHyphens(string[,] secondMatrix, int[,] matrix)
        {
            for (int row = 0; row < matrix.GetLength(0); row++)
            {
                for (int col = 0; col < matrix.GetLength(1); col++)
                {
                    if (row == numToAddSecondMatrixRow && col == numToAddSecondMatrixCol)
                    {
                        secondMatrix[row, col] = (supplySum - demandSum).ToString();
                    }

                    else
                    {
                        secondMatrix[row, col] = "-";
                    }
                }
            }

            return secondMatrix;
        }
    }
}
