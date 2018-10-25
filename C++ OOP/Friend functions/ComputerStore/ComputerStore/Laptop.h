#pragma once
#include "Computer.h"
class Laptop :
	public Computer
{
private:
	int batteryTime;

	float weight;

public:
	Laptop();

	Laptop(float _speed, int _ram, int _hdd, int BatteryTime, float Weight);

	void SetBatteryTime(int);

	void SetWeight(float);

	int GetBatteryTime() const
	{
		return batteryTime;
	}

	float GetWeight() const
	{
		return weight;
	}

	friend void Compare(Computer computer1, Laptop laptop1);
};