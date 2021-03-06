#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <list>
#include <algorithm>

using namespace std;

static const string socialGroupStatic = "Radikal BG";

class SocialNetworkUser
{
private:
	string identificator;

	string socialGroupName;

	string subSocialGroupName;

public:
	SocialNetworkUser()
	{
		identificator = "";
		socialGroupName = "";
		subSocialGroupName = "";
	}

	SocialNetworkUser(string identificatorParam, string socialCroupNameParam, string subSocialGroupNameParam)
	{
		identificator = identificatorParam;
		socialGroupName = socialCroupNameParam;
		subSocialGroupName = subSocialGroupNameParam;
	}

	SocialNetworkUser(const SocialNetworkUser& socialNetworkUserParam)
	{
		identificator = socialNetworkUserParam.identificator;
		socialGroupName = socialNetworkUserParam.socialGroupName;
		subSocialGroupName = socialNetworkUserParam.subSocialGroupName;
	}

	string GetIdentificator()
	{
		return identificator;
	}

	void SetIdentificator(string identificatorParam)
	{
		identificator = identificatorParam;
	}

	string GetSocialGroupName()
	{
		return socialGroupName;
	}

	void SetSocialGroupName(string socialGroupNameParam)
	{
		socialGroupName = socialGroupNameParam;
	}

	string GetSubSocialGroupName()
	{
		return subSocialGroupName;
	}

	void SetSubSocialGroupName(string subSocialGroupNameParam)
	{
		subSocialGroupName = subSocialGroupNameParam;
	}

	bool operator==(SocialNetworkUser socialNetworkUserParam)
	{
		return identificator == socialNetworkUserParam.identificator;
	}
};

istream& operator>>(istream &stream, SocialNetworkUser socialNetworkUserParam)
{
	string identificatorParam;
	string socialGroupNameParam;
	string subSocialGroupNameParam;

	stream >> identificatorParam;
	stream >> socialGroupNameParam;
	stream >> subSocialGroupNameParam;

	socialNetworkUserParam.SetIdentificator(identificatorParam);
	socialNetworkUserParam.SetSocialGroupName(socialGroupNameParam);
	socialNetworkUserParam.SetSubSocialGroupName(subSocialGroupNameParam);

	return stream;
}

ostream& operator<<(ostream &toStream, SocialNetworkUser socialNetworkUserParam)
{
	toStream << "Identificator: " << socialNetworkUserParam.GetIdentificator() << endl;
	toStream << "Social Group name: " << socialNetworkUserParam.GetSocialGroupName() << endl;
	toStream << "Subsocial group name: " << socialNetworkUserParam.GetSubSocialGroupName() << endl;

	return toStream;
}

class SocialNetwork
{
private:
	string name;

	vector<SocialNetworkUser> users;

public:
	SocialNetwork(string fileName)
	{
		ifstream readFile;
		readFile.open(fileName);

		if (!readFile)
		{
			cout << "File not found." << endl;
		}

		//else
		//{
		//	fileName >> *this;
		//}
	}

	SocialNetwork()
	{
		name = "";
	}

	string GetName()
	{
		return name;
	}

	void SetName(string nameParam)
	{
		name = nameParam;
	}

	vector<SocialNetworkUser> GetSocialNetworkUsers()
	{
		return users;
	}

	void SetSocialNetworkUsers(vector<SocialNetworkUser> usersParam)
	{
		users = usersParam;
	}

	list<string> UniqueGroupNames()
	{
		list<string> uniqueGroupNames;

		for (int i = 0; i < users.size(); i++)
		{
			string groupName = users[i].GetSocialGroupName();
			bool alreadyAdded = find(begin(uniqueGroupNames), end(uniqueGroupNames), groupName) != end(uniqueGroupNames);

			if (alreadyAdded == false)
			{
				uniqueGroupNames.push_back(groupName);
			}
		}

		return uniqueGroupNames;
	}
};

istream& operator>>(istream &stream, SocialNetwork &socialNetworkParam)
{
	vector<SocialNetworkUser> newCollection;

	string nameParam;
	stream >> nameParam;
	socialNetworkParam.SetName(nameParam);


	for (int i = 0; i < 3; i++)
	{
		SocialNetworkUser socialNetworkUserParam;
		stream >> socialNetworkUserParam;
		newCollection.push_back(socialNetworkUserParam);
	}

	socialNetworkParam.SetSocialNetworkUsers(newCollection);

	return stream;
}

ostream& operator<<(ostream &toStream, SocialNetwork  &socialNetworkParam)
{
	toStream << "Name: " << socialNetworkParam.GetName() << endl;

	for (int i = 0; i < socialNetworkParam.GetSocialNetworkUsers().size(); i++)
	{
		toStream << socialNetworkParam.GetSocialNetworkUsers()[i] << endl;
	}

	return toStream;
}

void main()
{
	try {
		//SocialNetwork socialNetworkTest("testName");
		//cout << socialNetworkTest;

		SocialNetwork socialNetworkParam;
		cin >> socialNetworkParam;
		cout << "- - - - - - - - - - - - - -" << endl;
		cout << socialNetworkParam;

		list<string> uniqueGroupNames = socialNetworkParam.UniqueGroupNames();
	}
	catch (exception error)
	{
		cout << error.what() << endl;
	}
}