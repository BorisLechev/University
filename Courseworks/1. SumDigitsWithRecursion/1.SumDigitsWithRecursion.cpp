#include "stdafx.h"
#include<iostream>

using namespace std;

void SumOfDigitsOfNaturalNumber(int n, int sum);

void main()
{
	int n;

	while (true)
	{
		cout << "Enter natural number, please: ";
		cin >> n;

		if (n > 0)
		{
			break;
		}

		cout << "It's not a natural number." << endl;
	}

	int sum = 0;
	SumOfDigitsOfNaturalNumber(n, sum);
}

void SumOfDigitsOfNaturalNumber(int n, int sum)
{
	if (n > 0)
	{
		sum += n % 10;
		n /= 10;
		SumOfDigitsOfNaturalNumber(n, sum);
	}

	else
	{
		cout << "The sum of digits of the natural number is: " << sum << endl;
	}
}
