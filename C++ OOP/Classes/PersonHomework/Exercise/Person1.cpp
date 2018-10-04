#include "pch.h"
#include "Person1.h"
#include<iostream>
#include<string>
#include<regex>

using namespace std;

Person1::Person1()
{
	Name = "";
	Gender = "";
	UniqueCitizenshipNumber = 0;
}

Person1::Person1(std::string name, std::string gender, long long uniqueCitizenshipNumber)
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

void Person1::SetGender(std::string gender)
{
	if (gender == "male" || gender == "female")
	{
		Gender = gender;
	}

	else
	{
		cout << "Invalid gender.";
		exit(EXIT_FAILURE);
	}
}

void Person1::SetUniqueCitizenshipNumber(long long uniqueCitizenshipNumber, std::string gender)
{
	if (std::to_string(uniqueCitizenshipNumber).length() != 10)
	{
		cout << "Invalid unique citizenship number.";
		exit(EXIT_FAILURE);
	}

	else
	{
		if (gender == "male" && ((uniqueCitizenshipNumber - (uniqueCitizenshipNumber % 10)) % 100) / 10 % 2 == 0)
		{
			UniqueCitizenshipNumber = uniqueCitizenshipNumber;
		}

		else if (gender == "female" && ((uniqueCitizenshipNumber - (uniqueCitizenshipNumber % 10)) % 100) / 10 % 2 == 1)
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