#pragma once
class Computer
{
private:
	float speed;

	int ram;

	int hdd;

public:
	Computer();

	Computer(float Speed, int Ram, int Hdd);

	void SetSpeed(float);

	void SetRam(int);

	void SetHdd(int);

	float GetSpeed() const
	{
		return speed;
	}

	int GetRam() const
	{
		return ram;
	}

	int GetHdd() const
	{
		return hdd;
	}
};