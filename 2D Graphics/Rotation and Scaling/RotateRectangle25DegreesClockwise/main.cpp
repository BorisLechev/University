#include <iostream>
#include <graphics.h>
#include <math.h>

using namespace std;

const double PI = 3.1415;

int main()
{
	initwindow(800, 800);
	
  	int startPointX = 400;
  	int startPointY = 400;
  	int a = 100;
  	double sx = 2;
  	double sy = 0.8;
  	
  	double mX = 500;
  	double mY = 400;
  	double nX = 400;
  	double nY = 350;
  	
  	double aX = nX;
  	double aY = mY;
  	double bX = nX + (mX - nX) * 2;
  	double bY = mY;
  	double cX = bX;
  	double cY = mY - (mY - nY) * 2;
  	double dX = nX;
  	double dY = cY;
  	
  	int n = 5;
  	
  	int points[n * 2] = { aX, aY, bX, bY, cX, cY, dX, dY, aX, aY };
  	
  	drawpoly(n, points);
  	
  	// mashtabirane
  	// tockata spryamo koyato pravya proekciya (t. M)
  	double xF = 400;
  	double yF = 400;
  	
  	int aXprim = xF + (aX - xF) * sx;
  	int aYprim = yF + (aY - yF) * sy;
  	int bXprim = xF + (bX - xF) * sx;
  	int bYprim = yF + (bY - yF) * sy;
  	int cXprim = xF + (cX - xF) * sx;
  	int cYprim = yF + (cY - yF) * sy;
  	int dXprim = xF + (dX - xF) * sx;
  	int dYprim = yF + (dY - yF) * sy;
  	
  	int pointsPrim[n * 2] = { aXprim, aYprim, dXprim, dYprim, bXprim, bYprim, cXprim, cYprim, aXprim, aYprim };
  
  	drawpoly(n, pointsPrim);
  	
  	// rotaciya
  	for (int i = 1; i <= 25; i++)
  	{
  		cleardevice();
  	
  		aYprim = yF + (aX - xF) * sin(i * (PI / 180)) + (aY - yF) * cos(i * (PI / 180));
  		aXprim = xF + (aX - xF) * cos(i * (PI / 180)) - (aY - yF) * sin(i * (PI / 180));
  		bXprim = xF + (bX - xF) * cos(i * (PI / 180)) - (bY - yF) * sin(i * (PI / 180));
  		bYprim = yF + (bX - xF) * sin(i * (PI / 180)) + (bY - yF) * cos(i * (PI / 180));
  		cXprim = xF + (cX - xF) * cos(i * (PI / 180)) - (cY - yF) * sin(i * (PI / 180));
  		cYprim = yF + (cX - xF) * sin(i * (PI / 180)) + (cY - yF) * cos(i * (PI / 180));
  		dXprim = xF + (dX - xF) * cos(i * (PI / 180)) - (dY - yF) * sin(i * (PI / 180));
  		dYprim = yF + (dX - xF) * sin(i * (PI / 180)) + (dY - yF) * cos(i * (PI / 180));
  	
  		int pointsPrim[n * 2] = { aXprim, aYprim, bXprim, bYprim, cXprim, cYprim, dXprim, dYprim, aXprim, aYprim };
  	
  		drawpoly(n, pointsPrim);
  		delay(100);
  	}
	
    getch();
    return 0;
}