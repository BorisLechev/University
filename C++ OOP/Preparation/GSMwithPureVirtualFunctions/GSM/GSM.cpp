#include "pch.h"
#include <string>
#include <iostream>

using namespace std;

class GSM
{
private:
	string model;

	int plan;

public:
	void SetModel(string modelParam)
	{
		model = modelParam;
	}

	string GetModel()
	{
		return model;
	}

	void SetPlan(int planParam)
	{
		plan = planParam;
	}

	int GetPlan()
	{
		return plan;
	}

	virtual istream &inputGSM(istream &fromStream, GSM &gsm) = 0;
	
	virtual ostream &outputGSM(ostream& toStream,  GSM &gsm)const = 0; // const &
	
	GSM()
	{
		model = "Huawei P10 lite";

		plan = 24;
	}

	GSM(string modelParam, int planParam)
	{
		model = modelParam;

		plan = planParam;
	}
};

class Student :public GSM
{
private:
	string name;

	string facultyNumber;

	string mobilePhoneNumber;

public:
	void SetName(string nameParam)
	{
		name = nameParam;
	}

	string GetName()
	{
		return name;
	}

	void SetFacultyNumber(string facultyNumberParam)
	{
		facultyNumber = facultyNumberParam;
	}

	string GetFacultyNumber()
	{
		return facultyNumber;
	}

	void SetMobilePhoneNumber(string mobilePhoneNumberParam)
	{
		mobilePhoneNumber = mobilePhoneNumberParam;
	}

	string GetMobilePhoneNumber()
	{
		return mobilePhoneNumber;
	}

	Student()
	{
		name = "Boris";

		facultyNumber = "17621337";

		mobilePhoneNumber = "0882762666";
	}

	Student(string nameParam, string facultyNumberParam, string phoneParam)
	{
		name = nameParam;

		facultyNumber = facultyNumberParam;

		mobilePhoneNumber = phoneParam;
	}

	virtual istream &inputGSM(istream &fromStream, GSM &gsm)
	{
		string modelInput;
		int planInput;

		fromStream >> modelInput;
		fromStream >> planInput;

		gsm.SetModel(modelInput);
		gsm.SetPlan(planInput);

		return fromStream;
	}

	virtual ostream &outputGSM(ostream& toStream,  GSM &gsm)const  // const &
	{
		toStream << "Model: " << gsm.GetModel() << endl;
		toStream << "Plan: " << gsm.GetPlan() << endl;

		return toStream;
	}

	friend istream & operator>>(istream &fromStream, Student &student)     // vatre friend >> ime
	{
		string name;
		string facultyNumber;
		string phoneNumber;

		fromStream >> name;
		fromStream >> facultyNumber;
		fromStream >> phoneNumber;

		student.name = name;
		student.facultyNumber = facultyNumber;
		student.mobilePhoneNumber = phoneNumber;

		return fromStream;
	}

	virtual ostream &outputStudent(ostream& toStream, const Student &student)
	{
		toStream << "Name: " << student.name << endl;
		toStream << "Faculty number: " << student.facultyNumber << endl;
		toStream << "Mobile phone: " << student.mobilePhoneNumber << endl;

		return toStream;
	}

	bool operator>(const Student &stud)
	{
		return name.length() > stud.name.length();
	}

	bool operator<(const Student &stud)
	{
		return name.length() < stud.name.length();
	}

	bool operator==(const Student &stud)
	{
		return name.length() == stud.name.length();
	}
};

int main()
{
	GSM *smartphone_address; //* е указател, за да ползваме outputGSM функцията ни трябва адреса, тъй като outputGSM e virtual (Пълна глупост)
	Student student;

	smartphone_address = &student;
	smartphone_address->inputGSM(cin, student); //въвеждаме
	smartphone_address->outputGSM(cout, student);

	//Student student; //празен констр. GSM -> празен Student
	cin >> student; // istream & operator>>
	Student *student_address; //* е указател, за да ползваме outputGSM функцията ни трябва адреса, тъй като outputGSM e virtual (Пълна глупост)

	student_address = &student; //& за да вземем адреса
	student_address->outputStudent(cout, student);

	Student otherStudent; //празен констр. GSM -> празен Student
	otherStudent.SetName("Ani");

	if (student > otherStudent)
	{
		cout << "First student has longer name." << endl;
	}

	else if (student == otherStudent)
	{
		cout << "Length of the names are equal." << endl;
	}

	else
	{
		cout << "First student has shorter name." << endl;
	}

	return 0;
}