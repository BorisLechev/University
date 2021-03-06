#include "pch.h"
#include <iostream>
#include<string>

using namespace std;

class AbstractVehicle
{
protected:
	int power;

	string model;

public:
	AbstractVehicle()
	{
		power = 0;

		model = "";
	}

	AbstractVehicle(int powerParam, string modelParam)
	{
		power = powerParam;

		model = modelParam;
	}

	int GetPower()
	{
		return power;
	}

	void SetPower(int powerParam)
	{
		power = powerParam;
	}

	string GetModel()
	{
		return model;
	}

	void SetModel(string modelParam)
	{
		model = modelParam;
	}

	virtual string GetCarNumber() = 0;

	virtual string GetOwner() = 0;
};

class RealVehicle :public AbstractVehicle
{
private:
	string carNumber;

	string owner;

public:
	RealVehicle()
	{
		carNumber = "";

		owner = "";
	}

	RealVehicle(string carNumberParam, string ownerParam, int power, string model) :AbstractVehicle(power, model)
	{
		carNumber = carNumberParam;

		owner = ownerParam;
	}

	virtual string GetCarNumber()
	{
		return carNumber;
	}

	void SetCarNumber(string carNumberParam)
	{
		carNumber = carNumberParam;
	}

	virtual string GetOwner()
	{
		return owner;
	}

	void SetOwner(string ownerParam)
	{
		owner = ownerParam;
	}

	friend istream & operator>>(istream& fromStream, RealVehicle &realVehicle)
	{
		string carNumberInput;
		string ownerInput;

		fromStream >> carNumberInput;
		fromStream >> ownerInput;

		realVehicle.SetCarNumber(carNumberInput);
		realVehicle.SetOwner(ownerInput);

		return fromStream;
	}

	friend ostream &operator<<(ostream& toStream, RealVehicle &realVehicle)
	{
		toStream << "Car number: " << realVehicle.carNumber << endl;
		toStream << "Car owner: " << realVehicle.owner << endl;
		toStream << "Car power: " << realVehicle.GetPower() << endl;
		toStream << "Car model: " << realVehicle.GetModel() << endl << endl;

		return toStream;
	}

	bool operator<(const RealVehicle &realVehicle)
	{
		return power < realVehicle.power;
	}

	bool operator==(const RealVehicle &realVehicle)
	{
		return owner == realVehicle.owner;
	}
};

void main()
{
	RealVehicle vehicle1("318732", "Peshoslav", 149, "Astra");
	RealVehicle vehicle2("45454", "Mimi", 150, "A50");

	cout << vehicle1;
	cout << vehicle2;

	if (vehicle1.GetPower() > vehicle2.GetPower())
	{
		cout << "Second vehicle power is lower." << endl;
	}

	else
	{
		cout << "First vehicle power is lower." << endl;
	}

	if (vehicle1.GetOwner() == vehicle2.GetOwner())
	{
		cout << "Owners have same names." << endl;
	}

	else
	{
		cout << "Different names." << endl;
	}
}