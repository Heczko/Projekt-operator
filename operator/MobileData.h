#pragma once

class MobileData
{
private:
	double limit;
	double fixedPrice;
	double consumed;

public:
	MobileData(double limit, double fixedPrice);
	~MobileData();

	double GetfixedPrice();
	void UseData(double consumed);
	double GetFreeMB();
	void SetConsumed(double consumed);

};
