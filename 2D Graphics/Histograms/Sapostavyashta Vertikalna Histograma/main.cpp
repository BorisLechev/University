#include <iostream>
#include <graphics.h>

using namespace std;

int main()
{
   initwindow(800, 800);
   
	double startPointX = 100;
	double startPointY = 600;
	
	double windowSizeX = 600;
	double windowSizeY = 500;
	
	double columnWidth = 70;
	double distanceBetweenColumns = 70;
	double D = 60;
	
	double bi[] = {5, 26};
	double ai[] = {15, 20};
	double mi[] = {10, 12};
	
	double amin = ai[0];
	double amax = ai[0];
	
	double bmin = bi[0];
	double bmax = bi[0];
	
	double sum[4];
	double maxSum;
	
	for(int i = 0; i < 2; i++)
	{
	   sum[i] = ai[i] + bi[i] + mi[i];
	}
	
	maxSum = sum[0];
	
	for(int i = 1; i < 3; i++)
	{
	  if (sum[i] > maxSum)
	  {
	  	maxSum = sum[i];
	  }
	}

	float scaleFactor = maxSum / windowSizeY;
	
	// koordinatna sistema
	line(startPointX, startPointY, startPointX + windowSizeX, startPointY);
	line(startPointX, startPointY, startPointX, startPointY - windowSizeY);
	
	// chertite na deleniyata
//	double value;
//	
//	for(p = 1; p < windowSizeY / D; p++)
//	{
//		line(startPointX, startPointY - p * D, startPointX - 3, startPointY - p * D);
//		value = p * D * scaleFactor;
//		cout << value << endl;
//	}

	for(int i = 1; i <= 2; i++)
	{
	    bar(startPointX + i * (columnWidth + distanceBetweenColumns) - columnWidth,
	              startPointY - ai[i - 1] / scaleFactor,
	              startPointX + i * (columnWidth + distanceBetweenColumns),
	              startPointY);
	              setfillstyle(i, i);
	              
	    bar(startPointX + i * (columnWidth + distanceBetweenColumns) - columnWidth,
	              startPointY - (ai[i - 1] + bi[i - 1]) / scaleFactor,
	              startPointX + i * (columnWidth + distanceBetweenColumns),
	              startPointY - ai[i - 1] / scaleFactor);
	            	setfillstyle(i + 1, i + 1);
	     bar(startPointX + i * (columnWidth + distanceBetweenColumns) - columnWidth,
	              startPointY - (ai[i - 1] + bi[i - 1] + mi[i - 1]) / scaleFactor,
	              startPointX + i * (columnWidth + distanceBetweenColumns),
	              startPointY - (ai[i - 1] + bi[i - 1]) / scaleFactor);
	              setfillstyle(i + 2, i + 2);
	}
	
    getch();
    return 0;
}
