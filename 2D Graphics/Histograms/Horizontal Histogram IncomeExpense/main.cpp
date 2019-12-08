#include <iostream>
#include <graphics.h>

using namespace std;

int main()
{
    const int columnsCount = 5;
    
	double startPointX = 100;
	double startPointY = 600;
	
	double sizeOfTheWindowX = 600;
	double sizeOfTheWindowY = 500;
	
	double d = 40;
	
	double columnWidth = 50;
	double distanceBetweenColumns = 50;
	
	initwindow(800, 800);
	
	double incomes[] = {10, 30, 10, 20, 40};
	double expenses[] = {15, 10, 2, 1, 30};
	
	double maxIncome = incomes[0];
	double maxExpense = expenses[0];
	
	for (int i = 0; i < columnsCount; i++)
	{
		if(maxIncome < incomes[i])
		{
			maxIncome = incomes[i];
		}
		
		if(maxExpense < expenses[i]){
			maxExpense = expenses[i];
		}
	}
	
	double scaleFactor = (maxIncome + maxExpense) / sizeOfTheWindowX;
	double delimiter = startPointX + (maxExpense / scaleFactor);
	
	line(delimiter, startPointY, delimiter, startPointY - sizeOfTheWindowY);
	
	for (int i = 1; i< columnsCount; i++)
	{
		bar(delimiter - (expenses[i - 1] / scaleFactor), startPointY - i * (distanceBetweenColumns + columnWidth), delimiter + (incomes[i - 1] / scaleFactor), startPointY - i * (distanceBetweenColumns + columnWidth) + columnWidth);
	}
	
	char text[10];

    // labels
    for(int i = 0; i <= (maxIncome / scaleFactor) / d; i++)
    {
        line(delimiter - i * d, startPointY, delimiter - i * d, startPointY - 3);
        gcvt(i * d * scaleFactor, 5.2, text);
        outtextxy(delimiter - i * d, startPointY + 20, text);
    }

    for(int i = 0; i <= (maxExpense / scaleFactor) / d; i++) 
	{
        line(delimiter + i * d, startPointY, delimiter + i * d, startPointY - 3);
        gcvt(i * d * scaleFactor, 5.2, text);
        outtextxy(delimiter + i * d, startPointY + 20, text);
    }
	
	moveto(startPointX, startPointY);
	lineto(startPointX + sizeOfTheWindowX, startPointY);
	moveto(startPointX, startPointY);
	lineto(startPointX, startPointY - sizeOfTheWindowY);
	
    getch();
}
