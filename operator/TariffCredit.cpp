#include "TariffCredit.h"

double TariffCredit::price = 1.5;

TariffCredit::TariffCredit(int number, int clientId) : Tariff(number, clientId)
{
	this->credit = 0;
}

TariffCredit::~TariffCredit()
{

}

void TariffCredit::SetPrice(double price)
{
	TariffCredit::price = price;
}

double TariffCredit::GetPrice()
{
	return TariffCredit::price;
}

int TariffCredit::GetPaidMinute()
{
	return (int)(this->credit / TariffCredit::price);
}

bool TariffCredit::MakeCall(int callTime)
{
	double callPrice = callTime * TariffCredit::price;

	if(callTime <= this->GetPaidMinute())
	{
		this->credit -= callPrice;
		return true;
	}
	else
	{
		this->credit = 0;
		return false;
	}
}

void TariffCredit::Payment(double ammount)
{
	this->credit += ammount;
}

double TariffCredit::GetBalance()
{
	return this->credit;
}
