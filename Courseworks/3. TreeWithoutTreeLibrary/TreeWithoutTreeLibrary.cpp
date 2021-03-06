#include "stdafx.h"
#include<iostream>

using namespace std;

struct Element
{
	int key;
	Element *left;
	Element *right;
} *mainTree = NULL, *evenNumbers = NULL, *oddNumbers = NULL;

void Add(int number, Element* &t)
{
	if (t == NULL)
	{
		t = new Element;
		t->key = number;
		t->left = NULL;
		t->right = NULL;
	}

	else
	{
		if (t->key < number)
		{
			Add(number, t->right);
		}

		else
		{
			Add(number, t->left);
		}
	}
}

void PrintNode(int number)
{
	cout << number << " ";
}

void Show(Element *t)
{
	if (t == NULL)
	{
		return;
	}

	Show(t->right);
	PrintNode(t->key);
	Show(t->left);
}

void DividingATree(Element *t)
{
	if (t)
	{
		if (t->key % 2 == 1)
		{
			Add(t->key, oddNumbers);
		}

		else
		{
			Add(t->key, evenNumbers);
		}

		DividingATree(t->left);
		DividingATree(t->right);
	}
}

void main()
{
	cout << "Enter only integer numbers, please. The program will print: the main tree, even numbers and odd numbers." << endl;
	cout << "Enter oh to exit." << endl << endl;

	int number = 1;

	while (number != 0)
	{
		cout << "Enter an integer number: ";
		cin >> number;

		if (number != 0 && number > 0)
		{
			Add(number, mainTree);
		}
	}

	cout << endl << "The main tree looks like this:" << endl;

	Show(mainTree);
	DividingATree(mainTree);

	cout << endl << "Even numbers:" << endl;

	Show(evenNumbers);

	cout << endl << "Odd numbers:" << endl;

	Show(oddNumbers);

	cout << endl;
}
