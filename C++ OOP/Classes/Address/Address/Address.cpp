#include "pch.h"
#include "CAddress.h"
#include <iostream>

using namespace std;

void main()
{
	std::string Street = "";
	long PostalCode = 0;
	std::string Town = "";

	cout << "Enter a street: ";
	std::getline(std::cin, Street);

	cout << "Enter a postal code: ";
	cin >> PostalCode;

	cout << "Enter a town: ";
	cin >> Town;

	CAddress firstObject(Street, PostalCode, Town);

	CAddress secondObject(firstObject);

	//firstObject.Output( cout );
	//secondObject.Output(cout);
	cout << firstObject.GetStreet() << endl;
	cout << firstObject.GetPostalCode() << endl;
	cout << firstObject.GetTown() << endl;

	cout << secondObject.GetStreet() << endl;
	cout << secondObject.GetPostalCode() << endl;
	cout << secondObject.GetTown() << endl;
}