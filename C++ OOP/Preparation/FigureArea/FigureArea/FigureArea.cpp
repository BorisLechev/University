#include "pch.h"
#include <iostream>
#include<string>

using namespace std;

class Figure
{
private:
	double x;

	double y;

public:
	void SetX(double xParam)
	{
		x = xParam;
	}

	double GetX()
	{
		return x;
	}

	void SetY(double yParam)
	{
		y = yParam;
	}

	double GetY()
	{
		return y;
	}

	Figure()
	{
		x = 0;

		y = 0;
	}

	Figure(double xParam, double yParam)
	{
		x = xParam;

		y = yParam;
	}

	//virtual double area();
	//virtual double perimeter();
};

class Circle :public Figure
{
protected:
	double radius;

public:
	Circle()
	{
		radius = 1;
	}

	Circle(double radiusParam)
	{
		radius = radiusParam;
	}

	void SetRadius(double radiusParam)
	{
		radius = radiusParam;
	}

	double GetRadius()
	{
		return radius;
	}

	virtual double perimeter()
	{
		return 2 * 3.14*radius;
	}

	virtual double area()
	{
		return 3.14*radius*radius;
	}

	bool operator>(Circle& other)
	{
		return radius > other.GetRadius();
	}

	ostream &operator<<(ostream& toStream)
	{
		//if (radius > circle.radius)
		//{
		//	toStream << "the figure with lower radius: " << circle.radius << endl;
		//}


		toStream << "the figure with lower radius: " << radius << endl;
		return toStream;
	}

	friend ostream &output(ostream& toStream, const Circle &circle)
	{
		toStream << "radius = " << circle.radius << endl;
		toStream << "Area = " << (circle.radius * circle.radius) * 3.14 << endl;
		toStream << "Perimeter = " << 2 * 3.14*circle.radius << endl;

		return toStream;
	}
};

int main()
{
	Circle firstCircle(2);
	Circle secondCircle(4);
	Circle thirdCircle(6);

	Circle arr[] = { firstCircle,secondCircle,thirdCircle };

	double perimeterSum = 0;
	double areaSum = 0;

	for (int i = 0; i < 3; i++)
	{
		perimeterSum += arr[i].perimeter();
		areaSum += arr[i].area();

		//cout << arr[i];
	}

	cout << "Sum P = " << perimeterSum << endl;
	cout << "Sum Area = " << areaSum << endl;

	if (firstCircle > secondCircle)
		cout << "First";
	else
		cout << "Second";
}