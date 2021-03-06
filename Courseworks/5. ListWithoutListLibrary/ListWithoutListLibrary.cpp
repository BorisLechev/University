#include "stdafx.h"
#include<iostream>

using namespace std;

void Add(double number);
void PrintList();
void DeleteNegativeNumber();

struct Element 
{
	double key;
	Element *next;
} *start = NULL;

void main()
{
	cout << "Enter only numbers, please." << endl;
	cout << "Enter oh to exit." << endl << endl;

	double number;

	do
	{
		cout << "Enter a number, please: ";
		cin >> number;
		Add(number);
		DeleteNegativeNumber();

	} while (number != 0);

	PrintList();
}

void Add(double number)
{
	if (number != 0)
	{
		Element *p = start; 
 		start = new Element; 
		start->key = number; 
		start->next = p; 
	}
}

void PrintList()
{
	Element *p = start;

	if (p == NULL)
	{
		cout << "The list is empty." << endl;
		return;
	}

	cout << "Content of the list: ";
	
	while (p)
	{
		cout << p->key << ' ';
		p = p->next;
	}

	cout << endl;
}

void DeleteNegativeNumber()
{
	Element *p;

	while ((p = start) && (p->key < 0))
	{
		start = p->next; //приема стойността на предходното въведено
		delete p;
	}
}
