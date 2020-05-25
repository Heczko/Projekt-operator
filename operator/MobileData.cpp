#include "MobileData.h"

MobileData::MobileData(double limit, double fixedPrice)
{
	this->limit = limit;
	this->fixedPrice = fixedPrice;
	this->consumed = 0;
}

MobileData::~MobileData()
{
}

double MobileData::GetfixedPrice()
{
	return this->fixedPrice;
}

void MobileData::UseData(double consumed)
{
	this->consumed += consumed;
}

double MobileData::GetFreeMB()
{
	return (this->limit - this->consumed);
}

double MobileData::BillingMobileData()
{
	this->consumed = 0;
	return GetfixedPrice();
}
