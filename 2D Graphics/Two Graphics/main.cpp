#include <iostream>
#include <graphics.h>
#include <math.h>

using namespace std;

int main()
{
	const int n = 80;

    // stojnosti
    double xFirstArray[n];
    double yFirstArray[n];

    int startPointX = 100;
    int startPointY = 600;
    int windowSizeX = 600;
    int windowSizeY = 500;
    int dx = 60;
    int dy = 50;

    double step = (abs(-5) + abs(20)) / (double)(n - 1);
    int index = 0;

    initwindow(800, 800);

    for(double i = -5; i <= 20; i+= step) 
	{
        double x_otGraphica = i;

        xFirstArray[index] = i;
        yFirstArray[index] = (x_otGraphica * x_otGraphica - 3 * x_otGraphica + 10);

        index++;
    }
    
	cout << index << endl;
	
	double yMin = yFirstArray[0];
    double yMax = yFirstArray[0];

    for (int i = 0; i < n; i++)
    {
        if(yMin > yFirstArray[i]) 
		{
            yMin = yFirstArray[i];
        }

        if(yMax < yFirstArray[i]) 
		{
            yMax = yFirstArray[i];
        }
    }
    
 	cout << yMax << endl;
    cout << yMin << endl;

    const int n1 = 100;
    
    double xSecondArray[n1];
    double ySecondArray[n1];
    index = 0;

   	step = (-abs(2) + abs(25)) / (double)(n1 - 1);

    for(double i = 2; i <= 25; i+=step)
	{
        double xi = i;

        xSecondArray[index] = i;
        ySecondArray[index] = (3 * xi * xi + 5 * xi - 8);

        index++;
    }

 	cout << index << endl;

    double yMax2 = ySecondArray[0];
    double yMin2 = ySecondArray[0];
    
	cout << yMax2 << endl;
    cout << yMin2 << endl;

    for (int i = 0; i < n1; i++)
    {
         // za vtorata
	    if(yMin2 > ySecondArray[i]) 
		{
	        yMin2 = ySecondArray[i];
	    }
	
	    if(yMax2 < ySecondArray[i]) 
		{
	        yMax2 = ySecondArray[i];
	    }
    }

 	cout << yMax2 << endl;
    cout << yMin2 << endl;
    
   if(yMin2 < yMin) 
   {
       yMin = yMin2;
   }

   if(yMax2 > yMax) 
   {
       yMax = yMax2;
   }

    double xMin = -5;
    double xMax = 25;

    double scaleFactorX = (xMax - xMin) / windowSizeX;
    double scaleFactorY = (yMax - yMin) / windowSizeY;

    char text[10];

    // linii za koordinatna sistema
    moveto(startPointX, startPointY);
    lineto(startPointX + windowSizeX, startPointY);
    moveto(startPointX, startPointY);
    lineto(startPointX, startPointY - windowSizeY);

    for(int i = 0; i < n; i++)
	{
        double xi = startPointX + (xFirstArray[i] - xMin) / scaleFactorX;
        double yi = startPointY - (yFirstArray[i] - yMin) / scaleFactorY;

        circle(xi, yi, 2);
    }

    // za vtorata
	setcolor(2);
	
    for(int i = 0; i < n1; i++)
    {
        double xi = startPointX + (xSecondArray[i] - xMin) / scaleFactorX;
        double yi = startPointY - (ySecondArray[i] - yMin) / scaleFactorY;

        circle(xi, yi, 2);
    }
    
	setcolor(15);

    double xPartitionsCount = windowSizeX / dx;
    double yPartitionsCount = windowSizeY / dy;

    for(int i = 0; i <= xPartitionsCount; i++)
    {
        gcvt(xMin + i * dx * scaleFactorX, 5.2, text);
        outtextxy(startPointX + i * dx, startPointY + 10, text);
        line(startPointX + i * dx, startPointY , startPointX + i * dx, startPointY + 3);
    }


    for(int i = 0; i <= yPartitionsCount; i++)
    {
        gcvt(yMin + i * dy * scaleFactorY, 5.2, text);
        outtextxy(startPointX - 50, startPointY - i * dy, text);
        line(startPointX, startPointY - i * dy , startPointX -3, startPointY - i * dy);
    }

    getch();
    return 0;
}
