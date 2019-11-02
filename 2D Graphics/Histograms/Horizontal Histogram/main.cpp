#include <iostream>
#include <graphics.h>

using namespace std;

int main()
{
    const int columnsCount = 4;
    
    // nachalo na prozoreca (po uslovie)
    double x0 = 100;
    double y0 = 600;
    
    // golemina na prozoreca (po uslovie)
    double px = 600;
    double py = 500;
    
    // shirina na deleniata po skalata sas stoinostite (po uslovie)
    double d = 50;
    
    // shirina na stalbovete (po uslovie)
    double ds = 60;
    
    // razstoyaniyata megdu stalbovete (po uslovie)
    double dc = 60;
    
    initwindow(800, 800);
    
    double data[columnsCount] = {10, 50, 30, 20};
    
    double minValue = data[0];
    double maxValue = data[1];
    
    for(int i = 0; i < columnsCount; i++)
	{
    	double currentValue = data[i];
    	
    	if(currentValue < minValue)
    	{
    		minValue = currentValue;
		}
		
		if(currentValue > maxValue)
		{
			maxValue = currentValue;
		}
	}
	
	// mashtaben koeficent
	double s = (maxValue - minValue) / py; // py za horizontalni stalbove
	
	for(int i = 1; i <= columnsCount; i++)
	{
		double labelY = py - (i - 1) * (ds + dc);
		outtextxy(x0 - 30, labelY, "ss");
		
		// horizontalni stalbove
		double topLeftX = x0;
		double topLeftY = y0 - i * (dc + ds); 
		
		double bottomRightX = x0 + (data[i - 1] / s); // x0 + i * ds   moe
		double bottomRightY = y0 - i * (ds + dc) + ds;
		
		rectangle(topLeftX, topLeftY, bottomRightX, bottomRightY);
	}
	
	// dopalnenie kam zadachata
	// broi delenia po x
	double xPartitionsCount = px / dc;
	char text[10];
	
	// cikal za X os i postavaneto na stoinostite i chertite na deleniata
	for(int i = 0; i < xPartitionsCount; i++)
	{
		gcvt(minValue + i * dc * s, 5.2, text);
		outtextxy(x0 + i * dc, y0 + 10, text);
		line(x0 + i * dc, y0 , x0 + i * dc, y0 + 3);
	}
    
   moveto(x0, y0);
   lineto(x0 + px, y0);
   moveto(x0, y0);
   lineto(x0, y0 - py);
    
    getch();
}

