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
    
    double incomes[columnsCount] = {10, 20, 30, 20};
    double expenses[columnsCount] = {15, 15, 1, 2};
    
    double maxIncome = incomes[0];
    double maxExpense = expenses[0];
    
    for(int i = 0; i < columnsCount; i++)
	{
    	double currentIncome = incomes[i];
    	double currentExpense = expenses[i];
    	
    	if(currentIncome > maxIncome)
    	{
    		maxIncome = currentIncome;
		}
		
		if(currentExpense > maxExpense)
		{
			maxExpense = currentExpense;
		}
	}
	
	// mashtaben koeficent
	double s = (maxIncome + maxExpense) / py; // px za vertikalni stalbove
	double delimiter = y0 - (maxExpense / s);
	
	line(x0, delimiter, x0 + px, delimiter); 
	
	for(int i = 1; i <= columnsCount; i++)
	{
        bar(x0 + i * (ds + dc) - dc, delimiter  - incomes[i - 1] / s, x0 + i * (ds + dc), delimiter);

        bar(x0 + i * (ds + dc) - dc, delimiter  + expenses[i - 1] / s, x0 + i * (ds + dc), delimiter);
	}
    
  	char text[10];

    // labels
    for(int i = 0; i <= (maxIncome / s) / d; i++)
    {
        line(x0, delimiter - i * d, x0 - 3, delimiter - i * d);
        gcvt(i * d * s, 5.2, text);
        outtextxy(x0 - 20, delimiter - i * d, text);
    }

    for(int i = 0; i <= (maxExpense / s) / d; i++) 
	{
        line(x0, delimiter + i * d, x0 - 3, delimiter + i * d);
        gcvt(i * d * s, 5.2, text);
        outtextxy(x0 - 20, delimiter + i * d, text);
    }


     // linii za koordinatna sistema
     moveto(x0, y0);
     lineto(x0 + px, y0);
     moveto(x0, y0);
     lineto(x0, y0 - py);


    getch();
}
