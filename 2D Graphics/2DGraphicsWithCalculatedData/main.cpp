#include <iostream>
#include <graphics.h>

using namespace std;

int main()
{
		// n (po uslovie)
	const int firstDivisionsCount = 80;
	const int secondDivisionsCount = 100;
	
	double firstXArray[firstDivisionsCount];
	double firstYArray[firstDivisionsCount];
	
	// nachalo na prozoreca (po uslovie)
	int x0 = 100;
	int y0 = 600;
	
	// golemina na prozoreca (po uslovie)
	int px = 600;
	int py = 500;
	
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
		double xFromGraphic = i;
		
		firstXArray[index] = xFromGraphic;
		firstYArray[index] = (xFromGraphic * xFromGraphic) - (3 * xFromGraphic) + 10; // uravnenie po uslovie -> yi
		
		index++;
	}
	
	double firstYMin = firstYArray[0];
	double firstYMax = firstYArray[0];
	
	for(int i = 0; i < firstDivisionsCount; i++)
	{
		if(firstYMin > firstYArray[i])
		{
			firstYMin = firstYArray[i];
		}
		
		if(firstYMax < firstYArray[i])
		{
			firstYMax = firstYArray[i];
		}
	}
	
	// opredelane na mashtabnite elementi
    double sx = (xMax - xMin) / px;
    double sy = (firstYMax - firstYMin) / py;
    
    // linii za koordinatna sistema
    moveto(x0, y0); // da izpravi x os
    lineto(x0 + px, y0); // x e gore y e vlavo (vazi dokato nama moveto() predi lineto()) lineto chertae linia do tochkata
    moveto(x0, y0); // da izpravi y os
    lineto(x0, y0 - py);
    
    // namirane na koordinatite na pikselite i gi chertae
    for(int i = 0; i < firstDivisionsCount; i++) 
	{
    	double xiPixel = x0 + (firstXArray[i] - xMin) / sx; // prevrashtame v pikseli i pribavame x0 (nachaloto)
    	double yiPixel = y0 - (firstYArray[i] - firstYMin) / sy;
    	
    	circle(xiPixel, yiPixel, 2); // 2 e radius na circle-a na tochkata
    	//lineto(xiPixel, yiPixel); // svarzva tochkite
	}
	
	// broi delenia
	double xPartitionsCount = px / dx; // dalginata na X os / shirinata na deleniata
	double yPartitionsCount = py/ dy;
	char text[10];
	
	// cikal za X os i postavaneto na stoinostite i chertite na deleniata
	for(int i = 0; i < xPartitionsCount; i++)
	{
		gcvt(xMin + i * dx * sx, 5.2, text);
		outtextxy(x0 + i * dx, y0 + 10, text);
		line(x0 + i * dx, y0 , x0 + i * dx, y0 + 3);
	}
	
	// cikal za Y os i postavaneto na stoinostite i chertite na deleniata
	for(int i = 0; i < yPartitionsCount; i++)
	{
		gcvt(firstYMin + i * dy * sy, 5.2, text);
        outtextxy(x0 - 50, y0 - i * dy, text);
        line(x0, y0 - i * dy , x0 -3, y0 - i * dy);
	}

    getch();
    return 0;
}
