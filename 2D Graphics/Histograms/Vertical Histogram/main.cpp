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
    double d = 60;
    
    // shirina na stalbovete (po uslovie)
    double ds = 70;
    
    // razstoyaniyata megdu stalbovete (po uslovie)
    double dc = 70;
    
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
	double s = (maxValue - minValue) / px; // px za vertikalni stalbove
	
	for(int i = 1; i <= columnsCount; i++)
	{
		double labelX = x0 + (i - 1) * (ds + dc);
		outtextxy(labelX + 100, y0 + 10, "ss");
		
		// vertikalni stalbove
		double topLeftX = x0 + i * (ds + dc) - ds;
		double topLeftY = y0 - (data[i - 1] / s); 
		
		double bottomRightX = x0 + i * (ds + dc);
		double bottomRightY = y0;
		
		rectangle(topLeftX, topLeftY, bottomRightX, bottomRightY);
	}
    
   moveto(x0, y0);
   lineto(x0 + px, y0);
   moveto(x0, y0);
   lineto(x0, y0 - py);
    
    getch();
}
