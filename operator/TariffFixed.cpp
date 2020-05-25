#include "TariffFixed.h"
#include <iostream>

double TariffFixed::price = 1.5;

TariffFixed::TariffFixed(int number, int clientId, double fixedFee, int freeMin) : Tariff(number, clientId)
{
	this->account = 0;
	this->callTime = 0;
	this->fixedFee = fixedFee;
	this->freeMin = freeMin;
	this->mData = nullptr;
}

TariffFixed::TariffFixed(int number, int clientId, double fixedFee, int freeMin, double mDatalimit, double mDataFixedPrice) : Tariff(number, clientId)
{
	this->account = 0;
	this->callTime = 0;
	this->fixedFee = fixedFee;
	this->freeMin = freeMin;
	this->mData = new MobileData(mDatalimit, mDataFixedPrice);
}

TariffFixed::~TariffFixed()
{
	if (this->mData != nullptr) delete this->mData;
}

void TariffFixed::SetPrice(double price)
{
	TariffFixed::price = price;
}

double TariffFixed::GetBalance()
{
	return this->account;
}

void TariffFixed::MakeCall(int callTime)
{
	this->callTime += callTime;
}

double TariffFixed::Billing()
{
	double res = 0;
	if (this->callTime > this->freeMin)
	{
		res = this->fixedFee + ((double)this->callTime - (double)this->freeMin) * TariffFixed::price;
	}
	else res = this->fixedFee;
	if (this->mData != nullptr) res += this->mData->BillingMobileData();
	this->callTime = 0;
	this->account -= res;
	return res;
}

void TariffFixed::Payment(double ammount)
{
	this->account += ammount;
}

