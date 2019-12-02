#include <iostream>
#include <graphics.h>
#include <math.h>

using namespace std;

const double PI = 3.141592653589793;

int main()
{
    const int n = 10;

    double startPointX = 400;
    double startPointY = 400;

    double rx = 150;
    double ry = 100;

    double points[n] = {10, 50, 30, 20, 80, 40, 90, 45, 12, 22};
    double sum = 0;

    int maxValueIndex = 0;
    double maxValue = points[0];

    for(int i = 0; i < n; i++)
    {
    	double currentValue = points[i];
    	
        if(maxValue < currentValue) 
		{
            maxValue = currentValue;
            maxValueIndex = i;
        }

        sum += currentValue;
    }

    initwindow(800, 800);

    double firstAngle = 0;
    
    for(int i = 0; i < n; i++)
    {
        double gamma = points[i] / sum * 360;
        double lastAngle = firstAngle + gamma;
        
        setcolor(i + 1);
        setfillstyle(i + 1, i + 1);

        double captionX = startPointX + 1.2 * rx * cos((firstAngle + gamma / 2) * PI / 180);
        double captionY = startPointY - 1.2 * ry * sin((firstAngle + gamma / 2) * PI / 180);

        char text[10];
        //gcvt(points[i], 5.2, text);
        outtextxy(captionX, captionY, itoa(points[i], text, 10));

        if(i == maxValueIndex) 
		{
            sector(captionX, captionY, firstAngle, lastAngle, rx, ry);
        }
        else 
		{
            sector(startPointX, startPointY, firstAngle, lastAngle, rx, ry);
        }
       
        firstAngle = lastAngle;
    }
    
    getch();
}
