#include "stdafx.h"
#include<iostream>

using namespace std;

const int number = 10;
int maxCountOutputLinks = 0;

struct Link
{
	int key;
	Link *next;
}*graph[number];

void Initialisation(Link *graph[number]);
int SearchNode(Link *graph[number], int peak);
int SearchArc(Link *graph[number], int peak1, int peak2);
void AddNode(Link *graph[number], int peak);
void AddArc(Link *graph[number], int peak1, int peak2);
void ObhogdaneNaGraph(Link *graph[number]);

void main()
{
	cout << "Enter only integer numbers, please. The program will print: the rang of the graph." << endl;
	cout << "Enter oh to exit." << endl << endl;

	Initialisation(graph);

	int firstElement = 0;
	int secondElement = 0;

	cout << "Enter link between firstElement and secondElement, please.:" << endl;

	cout << "First element: ";
	cin >> firstElement;

	cout << "Second element: ";
	cin >> secondElement;

	AddArc(graph, firstElement, secondElement);

	int answer = 0;

	while (true)
	{
		cout << "Enter oh to exit: ";
		cin >> answer;

		if (answer == 0)
		{
			break;
		}

		else
		{
			cout << "First element: ";
			cin >> firstElement;

			cout << "Second element: ";
			cin >> secondElement;

			AddArc(graph, firstElement, secondElement);

		}
	}

	ObhogdaneNaGraph(graph);

	cout << "The rang of the graph is: " << maxCountOutputLinks << endl;
}

void Initialisation(Link *graph[number])
{
	for (int i = 0; i < number; i++)
	{
		graph[i] = NULL;
	}
}


int SearchNode(Link *graph[number], int peak) 
{
	int flag = 0;

	for (int i = 0; i < number; i++)
	{
		if (graph[i])
		{
			if (graph[i]->key == peak)
			{
				flag = 1;
			}
		}
	}

	return flag;
}



int SearchArc(Link *graph[number], int peak1, int peak2) 
{
	int flag = 0;

	if (SearchNode(graph, peak1) && SearchNode(graph, peak2))
	{
		int i = 0;

		while (graph[i]->key != peak1)
		{
			i++;
		}

		Link *p = graph[i];

		while (p->key != peak2 && p->next != NULL)
		{
			p = p->next;
		}

		if (p->key == peak2)
		{
			flag = 1;
		}
	}

	return flag;
}



void AddNode(Link *graph[number], int peak) 
{
	if (SearchNode(graph, peak))
	{
		cout << "Exist peak with the same value. \n";
	}

	else
	{
		int i = 0;

		while (graph[i] && i < number)
		{
			i++;
		}

		if (graph[i] == NULL)
		{
			graph[i] = new Link();
			graph[i]->key = peak;
			graph[i]->next = NULL;
		}

		else
		{
			cout << "Prepalvane na strukturata" << endl;
		}
	}
}



void AddArc(Link *graph[number], int peak1, int peak2) 
{
	if (SearchArc(graph, peak1, peak2))
	{
		cout << "The arc already exists." << endl;
	}

	else
	{
		if (!SearchNode(graph, peak1))
		{
			AddNode(graph, peak1);
		}


		if (!SearchNode(graph, peak2))
		{
			AddNode(graph, peak2);
		}


		int i = 0;

		while (graph[i]->key != peak1)
		{
			i++;
		}

		Link *p = new Link;
		p->key = peak2;
		p->next = graph[i]->next;
		graph[i]->next = p;
	}
}



void ObhogdaneNaGraph(Link *graph[number]) 
{
	for (int i = 0; i < number; i++)
	{
		if (graph[i])
		{
			Link *p = graph[i];

			int linksCount = -1;

			while (p)
			{
				p = p->next;
				linksCount++;
			}

			if (linksCount > maxCountOutputLinks)
			{
				maxCountOutputLinks = linksCount;
			}

			linksCount = 0;
		}
	}
}
