#include<string>

class CAddress
{
public:
	std::string Street;

	long PostalCode;

	std::string Town;

public:
	CAddress();

	CAddress(std::string Street, long PostalCode, std::string Town);

	CAddress(const CAddress& param);

	void SetStreet(std::string);
	void SetPostalCode(long);
	void SetTown(std::string);

	std::string GetStreet() const
	{
		return Street;
	}

	long GetPostalCode() const
	{
		return PostalCode;
	}

	std::string GetTown() const
	{
		return Town;
	}

	//ostream& Output(ostream& toStream);
};