#include<string>

class Person1
{
private:
	std::string Name;

	std::string Gender;

	long long UniqueCitizenshipNumber;

public:
	Person1();

	Person1(std::string Name, std::string Gender, long long UniqueCitizenshipNumber);

	void SetName(std::string);
	void SetGender(std::string);
	void SetUniqueCitizenshipNumber(long long, std::string);

	std::string GetName() const
	{
		return Name;
	}

	std::string GetGender() const
	{
		return Gender;
	}

	long long GetUniqueCitizenshipNumber() const
	{
		return UniqueCitizenshipNumber;
	}
};

