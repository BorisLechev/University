#include "pch.h"
#include "CAddress.h"
#include<iostream>

using namespace std;

CAddress::CAddress()
{
	Street = "";
	PostalCode = 0;
	Town = "";
}

CAddress::CAddress(std::string street, long postalCode, std::string town)
{
	Street = street;
	PostalCode = postalCode;
	Town = town;
}

CAddress::CAddress(const CAddress& param)
{
	Street = param.Street;
	PostalCode = param.PostalCode;
	Town = param.Town;
}

/*
ostream& CAddress::Output(ostream& toStream)
{
	toStream << GetStreet() << endl;
	toStream << GetPostalCode() << endl;
	toStream << GetTown() << endl;

	return toStream;
}
*/