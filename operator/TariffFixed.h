#pragma once
#include "Tariff.h"
#include "MobileData.h"

class TariffFixed : public Tariff
{
private:

	double fixedFee;
	int freeMin;
	double account;
	static double price;
	int callTime;
	MobileData* mData;


public:
	TariffFixed(int number, int clientId, double fixedFee, int freeMin);
	TariffFixed(int number, int clientId, double fixedFee, int freeMin, double mDatalimit, double mDataFixedPrice);
	~TariffFixed();

	void static SetPrice(double price);
	void MakeCall(int callTime);
	double Billing();
	void Payment(double ammount);
	double BillingMobData();
	double GetBalance();

};

