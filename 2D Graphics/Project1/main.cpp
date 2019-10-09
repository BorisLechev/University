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
    double x0 = 100;
    double y0 = 500;
    
    // golemina na prozoreca (po uslovie)
    double px = 500;
    double py = 400;
    
    // shirina na deleniata varhu osite (po uslovie)
    double dx = 50;
    double dy = 80;
	
    // sortirovka
    double xMin = xArray[0];
    double yMin = yArray[0];
    
    double xMax = xArray[6];
    double yMax = yArray[6];
    
    // opredelane na mashtabnite elementi
    double sx = (xMax - xMin) / px;
    double sy = (yMax - yMin) / py;
    
    // linii za koordinatna sistema
    moveto(x0, y0); // da izpravi x os
    lineto(x0 + px, y0); // x e gore y e vlavo (vazi dokato nama moveto() predi lineto()) lineto chertae linia do tochkata
    moveto(x0, y0); // da izpravi y os
    lineto(x0, y0 - py);
    
    // namirane na koordinatite na pikselite i gi chertae
    for(int i = 0; i < 7; i++) 
	{
    	double xiPixel = x0 + (xArray[i] - xMin) / sx; // prevrashtame v pikseli i pribavame x0 (nachaloto)
    	double yiPixel = y0 - (yArray[i] - yMin) / sy;
    	
    	circle(xiPixel, yiPixel, 2); // 2 e radius na circle-a na tochkata
    	lineto(xiPixel, yiPixel); // svarzva tochkite
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
		gcvt(yMin + i * dy * sy, 5.2, text);
        outtextxy(x0 - 50, y0 - i * dy, text);
        line(x0, y0 - i * dy , x0 -3, y0 - i * dy);
	}
    
    //    int arr[] = {1, 5, 8, 9, 6, 7, 3, 4, 2, 0, 10, -1}; 
	//    int n = sizeof(arr)/sizeof(arr[0]); 
	//    int test[n] = {};
	//    sort(arr, arr+n); 
	//    cout << "\nArray after sorting using default sort is : \n"; 
	//	for (int i = 0; i < n; ++i) {
	//    	test[i] = arr[i];
	//        cout << test[i] << " ";
	//	}

    getch();
    return 0;
}
