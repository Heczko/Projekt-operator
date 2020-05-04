#include "Client.h"

Client::Client(string name, int id)
{
	this->name = name;
	this->id = id;
	this->active = true;
}

Client::~Client()
{

}

string Client::GetName()
{
	return this->name;
}

int Client::GetId()
{
	return this->id;
}

