#include <iostream>
#include <graphics.h>

using namespace std;

int main()
{
    int n = 12;

    const int sizeOFarrays = 12;

    double x[ sizeOFarrays] = {1, 5, 8,8, 8,8,8, 8, 9, 15, 60, 80};
    double y[ sizeOFarrays]= {4, 8, 120, 120, 120, 120, 120, 120, 5, 6, 100, 200};

    double PX[ sizeOFarrays];
    double PY[ sizeOFarrays];

    double RX[ sizeOFarrays];
    double RY[ sizeOFarrays];

    double QX[ sizeOFarrays];
    double QY[ sizeOFarrays];

    int m = n;

    initwindow(800, 800);

    double x0 = 100;
    double y0 = 500;

    double px = 500;
    double py = 400;

    double dx = 50;
    double dy = 80;

    // sortirovka
    double x_min = x[0];
    double y_min = 4;

    double x_max = x[n - 1];
    double y_max = 200;

    double SX = (x_max - x_min) / px;
    double SY = (y_max - y_min) / py;

     moveto(x0, y0);
     char text[10];

     // linii za koordinatna sistema
     lineto(x0 + px, y0);
     moveto(x0, y0);
     lineto(x0, y0 - py);
     moveto(x0, y0);

    for(int i = 0; i < n; i++)
    {
        double xi = x0 + (x[i] - x_min) / SX;
        double yi = y0 - (y[i] - y_min) / SY;

        circle(xi, yi, 2);
        PX[i] = xi;
        PY[i] = yi;

        lineto(xi, yi);
    }

    double T = px / dx;
    double J = py / dy;

    for(int i = 0; i <= T; i++)
    {
        gcvt(x_min + i * dx * SX, 5.2, text);
        outtextxy(x0 + i * dx, y0 + 10, text);
        line(x0 + i * dx, y0 , x0 + i * dx, y0 + 3);
    }

    for(int i = 0; i <= J; i++)
    {
        gcvt(y_min + i * dy * SY, 5.2, text);

        outtextxy(x0 - 50, y0 - i * dy, text);
        line(x0, y0 - i * dy , x0 -3, y0 - i * dy);
    }

    for(double t = 0; t <= 1; t += 0.0001)
    {
        for(int i = 0; i < m; i++)
        {
             RX[i] = PX[i];
             RY[i] = PY[i];
        }
        n = m;

        while(n > 0) {
            for(int i = 0; i < n - 1; i++) {
                QX[i] = RX[i] + (RX[i + 1] - RX[i]) * t;
                QY[i] = RY[i] + (RY[i + 1] - RY[i]) * t;
            }

            n--;

            for(int i = 0; i < n; i++) {
                RX[i] = QX[i];
                RY[i] = QY[i];
            }
        }
        putpixel(RX[0], RY[0], 2);
    }


    getch();
    return 0;
}
