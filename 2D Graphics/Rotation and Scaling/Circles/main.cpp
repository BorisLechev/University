#include <iostream>
#include <graphics.h>
#include <math.h>

using namespace std;

int main()
{
    double r = 50;
    double xc = 60;
    double yc = 60;

    // mashtaben koef
    double sy = 1.2;

    initwindow(800, 800);

    // zasilva, premestva
    while( xc < 800 / 2)\
	{
        cleardevice();
        
    	circle(xc, yc, r);
    	xc+= 1;
    	
    	delay(1);
    }

    double yf = abs(yc - r);
    double rPrim = r;

    // mashtabirane - mnogoto okraznosti
    while(yc <= 800 -500) 
	{
        rPrim = (yc - yf) * sy;
        
        cleardevice();
        
        yc = yf + rPrim;
        circle(xc, yc,rPrim);

        yc+= 10;
        delay(10);
    }

    // rotaciq
    double x = 400;
    double y = 60;
    double alpha = 0;

    double xr = xc;
    double yr = yc + 10;

    delay(100);
    
    while(alpha <= 360) 
	{
        double newX;
        double newY;

        newX = xr + (x - xr) * cos(alpha * (3.14 / 180)) - (y - yr) * sin(alpha * (3.14 / 180));
        newY = yr + (x - xr) * sin(alpha * (3.14 / 180)) + (y - yr) * cos(alpha * (3.14 / 180));

        circle(newX, newY, r);

        alpha += 1;
        delay(10);
    }

    getch();
}
