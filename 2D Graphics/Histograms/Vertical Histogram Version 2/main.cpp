#include <iostream>
#include <graphics.h>

using namespace std;

int main()
{
   const int columnsCount = 5;
    
    double points[] = {10, 20, 50, 20, 30};
    
    double startPointX = 100;
    double startPointY = 600;
    
    double sizeOfTheWindowX = 600; //px
    double sizeOfTheWindowY = 500;
    
    double columnWidth = 50;
    double distanceBetweenColumns = 50;
    
    initwindow(800, 800);
    
    double minValue = points[0];
    double maxValue = points[0];
    
    for (int i = 0; i < columnsCount; i++)
    {
    	double currentPoint = points[i];
    	
    	if (minValue > currentPoint)
    	{
    		minValue = currentPoint;
		}
		
		if (maxValue < currentPoint)
		{
			maxValue = currentPoint;
		}
	}
	
	double scaleFactor = (maxValue - minValue) / sizeOfTheWindowX;
	char text[10];
	
	for (int i = 1; i <= columnsCount; i++)
	{
		double labelX = startPointX + (i - 1) * (columnWidth + distanceBetweenColumns) + columnWidth;
		outtextxy(labelX, startPointY + 10, itoa(points[i - 1], text, 10));
		
		double columnTopLeftX = startPointX + i * (columnWidth + distanceBetweenColumns) - columnWidth;
		double columnTopLeftY = startPointY - points[i - 1] / scaleFactor;
		
		double columnBottomRightX = startPointX + i * (columnWidth + distanceBetweenColumns);
		double columnBottomRightY = startPointY;
		
		rectangle(columnTopLeftX, columnTopLeftY, columnBottomRightX, columnBottomRightY);
	}
	
	moveto(startPointX, startPointY);
	lineto(startPointX + sizeOfTheWindowX, startPointY);
	moveto(startPointX, startPointY);
	lineto(startPointX, startPointY - sizeOfTheWindowY);
    
    getch();
}
