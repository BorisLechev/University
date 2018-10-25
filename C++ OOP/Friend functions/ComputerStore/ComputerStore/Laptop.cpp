#include "pch.h"
#include "Laptop.h"
#include<iostream>

using namespace std;

Laptop::Laptop() : Computer()
{
	batteryTime = 0;

	weight = 0;
}

Laptop::Laptop(float _speed, int _ram, int _hdd, int BatteryTime, float Weight)
	: Computer(_speed, _ram, _hdd)
{
	SetBatteryTime(BatteryTime);

	SetWeight(Weight);
}

void Laptop::SetBatteryTime(int BatteryTime)
{
	batteryTime = BatteryTime;
}

void Laptop::SetWeight(float Weight)
{
	weight = Weight;
}

void Compare(Computer computer1, Laptop laptop1)
{
	if (computer1.GetSpeed() > laptop1.GetSpeed())
	{
		cout << "The speed of the computer is bigger." << endl;
	}

	else
	{
		cout << "The speed of the laptop is bigger." << endl;
	}
}