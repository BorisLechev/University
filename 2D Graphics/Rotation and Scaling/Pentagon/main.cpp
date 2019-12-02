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
  double sx = 1.4;
  double sy = 0.8;
  
  int cX = 500;
  int cY = 400;
  int dX = 400;
  int dY = 400;
  int aX = 400;
  int aY = 500;
  int bX = 500;
  int bY = 500;
  int mX = 450;
  int mY = 350;
  
  int n = 6;
  
  int points[n * 2] = { cX, cY, mX, mY, dX, dY, aX, aY, bX, bY, cX, cY };
  
  drawpoly(n, points);
  line(cX, cY, dX, dY);
  
  // mashtabirane
  // tockata spryamo koyato pravya proekciya (t. M)
  double xF = 450; // == mX
  double yF = 350; // == mY
  
  int aXprim = xF + (aX - xF) * sx;
  int aYprim = yF + (aY - yF) * sy;
  int bXprim = xF + (bX - xF) * sx;
  int bYprim = yF + (bY - yF) * sy;
  int cXprim = xF + (cX - xF) * sx;
  int cYprim = yF + (cY - yF) * sy;
  int dXprim = xF + (dX - xF) * sx;
  int dYprim = yF + (dY - yF) * sy;
  
  int pointsPrim[n * 2] = { cXprim, cYprim, mX, mY, dXprim, dYprim, aXprim, aYprim, bXprim, bYprim, cXprim, cYprim };
  
  drawpoly(n, pointsPrim);
  line(cXprim, cYprim, dXprim, dYprim);
  
  // rotaciya
  for (int i = 1; i <= 180; i += 5)
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
  	
  	int pointsPrim[n * 2] = { cXprim, cYprim, mX, mY, dXprim, dYprim, aXprim, aYprim, bXprim, bYprim, cXprim, cYprim };
  	
  	drawpoly(n, pointsPrim);
  	line(cXprim, cYprim, dXprim, dYprim);
  	delay(10);
  }
  
  getch();
  return 0;
}
