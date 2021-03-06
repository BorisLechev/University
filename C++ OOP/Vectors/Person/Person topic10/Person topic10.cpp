#include "pch.h"
#include <iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

const int numberOfInhabitants = 5;

class Person
{
protected:
	string name;

	string uniqueCitizenshipNumber;

public:
	Person(string uniqueCitizenshipNumberParam, string nameParam)
	{
		uniqueCitizenshipNumber = uniqueCitizenshipNumberParam;
		name = nameParam;
	}

	string GetName()
	{
		return name;
	}

	void SetName(string nameParam)
	{
		name = nameParam;
	}

	string GetUniqueCitizenshipNumber()
	{
		return uniqueCitizenshipNumber;
	}

	void SetUniqueCitizenshipNumber(string uniqueCitizenshipNumberParam)
	{
		uniqueCitizenshipNumber = uniqueCitizenshipNumberParam;
	}

	bool operator<(Person person)
	{
		int person1Year = atoi(uniqueCitizenshipNumber.substr(0, 2).c_str());
		int person1Month = atoi(uniqueCitizenshipNumber.substr(2, 2).c_str());
		int person1Day = atoi(uniqueCitizenshipNumber.substr(4, 2).c_str());

		int person2Year = atoi(uniqueCitizenshipNumber.substr(0, 2).c_str());
		int person2Month = atoi(uniqueCitizenshipNumber.substr(2, 2).c_str());
		int person2Day = atoi(uniqueCitizenshipNumber.substr(4, 2).c_str());

		if (person1Year < person2Year)
		{
			return true;
		}

		if (person1Month < person2Month)
		{
			return true;
		}

		if (person1Day < person2Day)
		{
			return true;
		}

		return false;
	}

	bool operator==(Person person)
	{
		return uniqueCitizenshipNumber == person.GetUniqueCitizenshipNumber();
	}

	friend ostream& operator<<(ostream& toStream, Person person)
	{
		toStream << "Name: " << person.GetName() << endl;
		toStream << "UniqueCitizenshipNumber: " << person.GetUniqueCitizenshipNumber() << endl;

		return toStream;
	}

	friend istream& operator>>(istream &stream, Person person)
	{
		string name;
		string uniqueCitizenshipNumber;

		stream >> name;
		stream >> uniqueCitizenshipNumber;

		person.SetName(name);
		person.SetUniqueCitizenshipNumber(uniqueCitizenshipNumber);

		return stream;
	}
};

class City
{
protected:
	string cityName;

	vector<Person> inhabitants;

public:
	City(string cityParam)
	{
		cityName = cityParam;
	}

	string GetCityName()
	{
		return cityName;
	}

	void SetCityName(string cityParam)
	{
		cityName = cityParam;
	}

	vector<Person> GetInhabitants()
	{
		return inhabitants;
	}

	int GetDuplicatesCount()
	{
		int occurences = 0;
		int duplicates = 0;

		for (int i = 0; i < inhabitants.size(); i++)
		{
			for (int j = i; j < inhabitants.size(); j++)
			{
				if (inhabitants[i] == inhabitants[j])
				{
					occurences++;
				}
			}

			if (occurences > 1)
			{
				duplicates++;
			}

			occurences = 0;
		}

		return duplicates;
	}

	void RemoveDuplicates()
	{
		inhabitants.erase(unique(inhabitants.begin(), inhabitants.end()), inhabitants.end());
	}

	void RemoveInhabitantsByUniqueCitizenshipNumber(string uniqueCitizenshipNumber)
	{
		for (int i = 0; i < inhabitants.size(); i++)
		{
			if (inhabitants[i].GetUniqueCitizenshipNumber() == uniqueCitizenshipNumber)
			{
				inhabitants.erase(inhabitants.begin() + i);
			}
		}
	}

	void AddInhabitant(Person person)
	{
		inhabitants.push_back(person);
	}

	friend ostream& operator<<(ostream &toStream, City city)
	{
		toStream << "City: " << city.GetCityName() << endl;
		cout << "Inhabitans: " << endl;


		for (int i = 0; i < city.GetInhabitants().size(); i++) {
			toStream << "#" << i + 1 << " ";
			toStream << city.GetInhabitants()[i] << endl;
		}
		return toStream;
	}

	friend istream& operator>>(istream &stream, City &city)
	{
		string cityNameInput;

		stream >> city;
		city.SetCityName(cityNameInput);

		for (int i = 0; i < numberOfInhabitants; i++)
		{
			string uniqueCitizenshipNumberInput;
			string nameInput;

			stream >> uniqueCitizenshipNumberInput;
			stream >> nameInput;
			uniqueCitizenshipNumberInput.erase(0, 3);

			Person person(uniqueCitizenshipNumberInput, nameInput);
			city.AddInhabitant(person);
		}

		return stream;
	}
};
void main()
{
	Person firstPerson("98098797", "Orlin");
	Person secondPerson("98098796", "Alen");
	Person thirdPerson("98098795", "Kitka");
	Person fourthPerson("98098795", "Lalka");

	City firstCity("Sofia");

	firstCity.AddInhabitant(firstPerson);
	firstCity.AddInhabitant(secondPerson);
	firstCity.AddInhabitant(thirdPerson);
	firstCity.AddInhabitant(fourthPerson);

	cout << "Number of duplicates: " << firstCity.GetDuplicatesCount() << endl;

	firstCity.RemoveInhabitantsByUniqueCitizenshipNumber("98098797");
	firstCity.RemoveDuplicates();

	cout << firstCity;
}