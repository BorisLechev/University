#include <iostream>
#include <graphics.h>
//#include <bits/stdc++.h>

using namespace std;

int main()
{
	double xArray[7] = {1, 5, 8, 9, 15, 60, 80};
    double yArray[7]= {4, 8, 120, 5, 6, 100, 200};

    initwindow(800, 800);
    
    // nachalo na prozoreca (po uslovie)
    double startPointX = 100;
    double startPointY = 500;
    
    // golemina na prozoreca (po uslovie)
    double windowSizeX = 500;
    double windowSizeY = 400;
    
    // shirina na deleniata varhu osite (po uslovie)
    double delimiterWidthX = 50;
    double delimiterWidthY = 80;
	
    double xMax = x[0];
	double xMin = x[0];
	
	double yMax = y[0];
	double yMin = y[0];
	
	for(int i = 0; i < 7; i++)
	{
		if(xMax < x[i])
		{
			xMax = x[i];
		}
		
		if(xMin > x[i])
		{
			xMin = x[i];
		}
		
		if(yMax < y[i])
		{
			yMax = y[i];
		}
		
		if(yMin > y[i])
		{
			yMin = y[i];
		}
	}
    
    // opredelane na mashtabnite elementi
    double scaleFactorX = (xMax - xMin) / windowSizeX;
	double scaleFactorY = (yMax - yMin) / windowSizeY;
	
	// broi delenia
	double xPartitionsCount = windowSizeX / delimiterWidthX; // dalginata na X os / shirinata na deleniata
	double yPartitionsCount = windowSizeY/ delimiterWidthY;
	char text[10];
	
	// linii za koordinatna sistema
    moveto(startPointX, startPointY); // da izpravi x os
    lineto(startPointX + windowSizeX, startPointY); // x e gore y e vlavo (vazi dokato nama moveto() predi lineto()) lineto chertae linia do tochkata
    moveto(startPointX, startPointY); // da izpravi y os
    lineto(startPointX, startPointY - windowSizeY);
	
	// cikal za X os i postavaneto na stoinostite i chertite na deleniata
	for(int i = 0; i < xPartitionsCount; i++)
	{
		gcvt(xMin + i * delimiterWidthX * scaleFactorX, 5.2, text);
		outtextxy(startPointX + i * delimiterWidthX, startPointY + 10, text);
		line(startPointX + i * delimiterWidthX, startPointY , startPointX + i * delimiterWidthX, startPointY + 3);
	}
	
	// cikal za Y os i postavaneto na stoinostite i chertite na deleniata
	for(int i = 0; i < yPartitionsCount; i++)
	{
		gcvt(yMin + i * delimiterWidthY * scaleFactorY, 5.2, text);
        outtextxy(startPointX - 50, startPointY - i * delimiterWidthY, text);
        line(startPointX, startPointY - i * delimiterWidthY , startPointX -3, startPointY - i * delimiterWidthY);
	}
	
	// namirane na koordinatite na pikselite i gi chertae
    for(int i = 0; i < 7; i++) 
	{
    	double xiPixel = startPointX + (xArray[i] - xMin) / scaleFactorX; // prevrashtame v pikseli i pribavame startPointX (nachaloto)
    	double yiPixel = startPointY - (yArray[i] - yMin) / scaleFactorY;
    	
    	circle(xiPixel, yiPixel, 2); // 2 e radius na circle-a na tochkata
    	lineto(xiPixel, yiPixel); // svarzva tochkite
	}

    getch();
    return 0;
}
