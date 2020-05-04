#include "Tariff.h"

Tariff::Tariff(int number, int clientId)
{
	this->number = number;
	this->clientId = clientId;
	this->active = true;
}

Tariff::~Tariff()
{

}

int Tariff::GetNumber()
{
	return this->number;
}

int Tariff::GetClientId()
{
	return this->clientId;
}



int Tariff::IsActive()
{
	return this->active;
}

void Tariff::SetActive(bool active)
{
	this->active = active;
}

double Tariff::GetBalance()
{
	return 0.0;
}
