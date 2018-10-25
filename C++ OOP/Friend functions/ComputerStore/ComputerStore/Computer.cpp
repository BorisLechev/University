#include "pch.h"
#include "Computer.h"

Computer::Computer()
{
	speed = 0;

	ram = 0;

	hdd = 0;
}

Computer::Computer(float Speed, int Ram, int Hdd)
{
	SetSpeed(Speed);

	SetRam(Ram);

	SetHdd(Hdd);
}

void Computer::SetSpeed(float Speed)
{
	speed = Speed;
}

void Computer::SetRam(int Ram)
{
	ram = Ram;
}

void Computer::SetHdd(int Hdd)
{
	hdd = Hdd;
}