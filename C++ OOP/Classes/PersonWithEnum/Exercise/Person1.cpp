#include "pch.h"
#include "Person1.h"
#include<iostream>
#include<string>
#include<regex>
#include<math.h>

using namespace std;

Person1::Person1()
{
	Name = "";
	Gender = eUnknown;
	UniqueCitizenshipNumber = 0;
}

Person1::Person1(std::string name, enGender gender, long long uniqueCitizenshipNumber)
{
	SetName(name);
	SetGender(gender);
	SetUniqueCitizenshipNumber(uniqueCitizenshipNumber, gender);
}

void Person1::SetName(std::string name)
{
	regex pattern("[A-Z][a-z]+");

	bool match = regex_match(name, pattern);

	if (match)
	{
		Name = name;
	}

	else
	{
		cout << "Invalid name.";
		exit(EXIT_FAILURE);
	}
}

void Person1::SetGender(enGender gender)
{
	if (gender == eMale || gender == eFemale)
	{
		Gender = gender;
	}

	else
	{
		cout << "Invalid gender.";
		exit(EXIT_FAILURE);
	}
}

void Person1::SetUniqueCitizenshipNumber(long long uniqueCitizenshipNumber, enGender gender)
{
	if (std::to_string(uniqueCitizenshipNumber).length() != 10)
	{
		cout << "Invalid unique citizenship number.";
		exit(EXIT_FAILURE);
	}

	else
	{
		if (gender == eMale && ((uniqueCitizenshipNumber - (uniqueCitizenshipNumber % 10)) % 100) / 10 % 2 == 0
			&& floor(100000000 % 10000) >= 00 && floor(100000000 % 10000) <= 18
			&& floor(uniqueCitizenshipNumber / 1000000 % 100) >= 41 && floor(uniqueCitizenshipNumber / 1000000 % 100) <= 53
			&& floor(uniqueCitizenshipNumber / 10000 % 100) >= 1 && floor(uniqueCitizenshipNumber / 10000 % 100) <= 31)
		{
			UniqueCitizenshipNumber = uniqueCitizenshipNumber;

		}

		if (gender == eMale && ((uniqueCitizenshipNumber - (uniqueCitizenshipNumber % 10)) % 100) / 10 % 2 == 0
			&& floor(uniqueCitizenshipNumber / 10000 % 100) >= 1 && floor(uniqueCitizenshipNumber / 10000 % 100) <= 31
			&& floor(uniqueCitizenshipNumber / 1000000 % 100) >= 1 && floor(uniqueCitizenshipNumber / 1000000 % 100) <= 12)
		{
			UniqueCitizenshipNumber = uniqueCitizenshipNumber;
		}

		else if (gender == eFemale && ((uniqueCitizenshipNumber - (uniqueCitizenshipNumber % 10)) % 100) / 10 % 2 == 1
			&& floor(100000000 % 10000) >= 00 && floor(100000000 % 10000) <= 18
			&& floor(uniqueCitizenshipNumber / 1000000 % 100) >= 41 && floor(uniqueCitizenshipNumber / 1000000 % 100) <= 53
			&& floor(uniqueCitizenshipNumber / 10000 % 100) >= 1 && floor(uniqueCitizenshipNumber / 10000 % 100) <= 31)
		{
			UniqueCitizenshipNumber = uniqueCitizenshipNumber;
		}

		else if (gender == eFemale && ((uniqueCitizenshipNumber - (uniqueCitizenshipNumber % 10)) % 100) / 10 % 2 == 1
			&& floor(uniqueCitizenshipNumber / 10000 % 100) >= 1 && floor(uniqueCitizenshipNumber / 10000 % 100) <= 31
			&& floor(uniqueCitizenshipNumber / 1000000 % 100) >= 1 && floor(uniqueCitizenshipNumber / 1000000 % 100) <= 12)
		{
			UniqueCitizenshipNumber = uniqueCitizenshipNumber;
		}

		else
		{
			cout << "Invalid unique citizenship number.";
			exit(EXIT_FAILURE);
		}
	}
}