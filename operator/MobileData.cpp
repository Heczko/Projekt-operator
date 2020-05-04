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
	this->consumed -= consumed;
	if (this->consumed < 0) this->consumed = 0;
}

double MobileData::GetFreeMB()
{
	return (this->limit - this->consumed);
}

void MobileData::SetConsumed(double consumed)
{
	this->consumed = consumed;
}
