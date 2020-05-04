#pragma once
#include <iostream>

using namespace std;

class Client
{
private:
	string name;
	int id;
	bool active;

public:
	Client(string name, int id);
	~Client();

	string GetName();
	int GetId();


};

