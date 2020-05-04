#pragma once
#include "Tariff.h"

class TariffCredit : public Tariff
{
private:
	double credit;
	static double price;

public:
	TariffCredit(int number, int clientId);
	~TariffCredit();

	void static SetPrice(double price);
	double static GetPrice();
	int GetPaidMinute();
	bool MakeCall(int callTime);
	void Payment(double ammount);
	double GetBalance();

};

