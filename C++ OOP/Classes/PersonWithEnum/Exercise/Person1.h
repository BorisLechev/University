#include<string>

enum enGender
{
	eUnknown,
	eMale,
	eFemale
};

class Person1
{
private:
	std::string Name;

	enGender Gender;

	long long UniqueCitizenshipNumber;

public:
	Person1();

	Person1(std::string Name, enGender Gender, long long UniqueCitizenshipNumber);

	void SetName(std::string);
	void SetGender(enGender);
	void SetUniqueCitizenshipNumber(long long, enGender);

	std::string GetName() const
	{
		return Name;
	}

	enGender GetGender() const
	{
		return Gender;
	}

	long long GetUniqueCitizenshipNumber() const
	{
		return UniqueCitizenshipNumber;
	}
};