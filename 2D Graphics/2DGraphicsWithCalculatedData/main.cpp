#include <iostream>
#include <graphics.h>

using namespace std;

int main()
{
	// n (po uslovie)
	const int firstDivisionsCount = 80;
	const int secondDivisionsCount = 100;
	
	double xArray[firstDivisionsCount];
	double yArray[firstDivisionsCount];
	
	// nachalo na prozoreca (po uslovie)
	int startPointX = 100;
	int startPointY = 600;
	
	// golemina na prozoreca (po uslovie)
	int windowSizeX = 600;
	int windowSizeY = 500;
	
	 // shirina na deleniata varhu osite (po uslovie)
	int dx = 60;
	int dy = 50;
	
	initwindow(800, 800);
	
	// po uslovie
	double xMin = -5;
	double xMax = 20;
	
	double step = (xMax - xMin) / (double)(firstDivisionsCount - 1); // deltax formula
	
	int index = 0;
	
	for(double i = xMin; i <= xMax; i += step)
	{
		double xi = i;
		
		xArray[index] = xi;
		yArray[index] = (xi * xi) - (3 * xi) + 10; // uravnenie po uslovie -> yi
		
		index++;
	}
	
	double yMin = yArray[0];
	double yMax = yArray[0];
	
	for(int i = 0; i < firstDivisionsCount; i++)
	{
		if(yMin > yArray[i])
		{
			yMin = yArray[i];
		}
		
		if(yMax < yArray[i])
		{
			yMax = yArray[i];
		}
	}
	
	// opredelane na mashtabnite elementi
    double scaleFactorX = (xMax - xMin) / windowSizeX;
    double scaleFactorY = (yMax - yMin) / windowSizeY;
    
    // linii za koordinatna sistema
    moveto(startPointX, startPointY); // da izpravi x os
    lineto(startPointX + windowSizeX, startPointY); // x e gore y e vlavo (vazi dokato nama moveto() predi lineto()) lineto chertae linia do tochkata
    moveto(startPointX, startPointY); // da izpravi y os
    lineto(startPointX, startPointY - windowSizeY);
    
    // namirane na koordinatite na pikselite i gi chertae
    for(int i = 0; i < firstDivisionsCount; i++) 
	{
    	double xiPixel = startPointX + (xArray[i] - xMin) / scaleFactorX; // prevrashtame v pikseli i pribavame startPointX (nachaloto)
    	double yiPixel = startPointY - (yArray[i] - yMin) / scaleFactorY;
    	
    	circle(xiPixel, yiPixel, 2); // 2 e radius na circle-a na tochkata
    	//lineto(xiPixel, yiPixel); // svarzva tochkite
	}
	
	// broi delenia
	double xPartitionsCount = windowSizeX / dx; // dalginata na X os / shirinata na deleniata
	double yPartitionsCount = windowSizeY/ dy;
	char text[10];
	
	// cikal za X os i postavaneto na stoinostite i chertite na deleniata
	for(int i = 0; i < xPartitionsCount; i++)
	{
		gcvt(xMin + i * dx * scaleFactorX, 5.2, text);
		outtextxy(startPointX + i * dx, startPointY + 10, text);
		line(startPointX + i * dx, startPointY, startPointX + i * dx, startPointY + 3);
	}
	
	// cikal za Y os i postavaneto na stoinostite i chertite na deleniata
	for(int i = 0; i < yPartitionsCount; i++)
	{
		gcvt(yMin + i * dy * scaleFactorY, 5.2, text);
        outtextxy(startPointX - 50, startPointY - i * dy, text);
        line(startPointX, startPointY - i * dy , startPointX - 3, startPointY - i * dy);
	}

    getch();
    return 0;
}
