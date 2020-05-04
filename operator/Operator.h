#pragma once
#include "Client.h"
#include "TariffCredit.h"
#include "TariffFixed.h"

class Operator
{
private:
	Client** clients;
	int clientsCount;

	TariffCredit** tariffsCredit;
	int tariffsCreditCount;

	TariffFixed** tariffsFixed;
	int tariffsFixedCount;

public:
	Operator();
	~Operator();

	Client* GetClient(int id);
	Client* GetClient(string name);
	Client* CreateClient(string name);

	TariffCredit* GetTariffCredit(int number);
	TariffCredit* CreateTariffCredit(int number, int clientId);

	TariffFixed* GetTariffFixed(int number);
	TariffFixed* CreateTariffFixed(int number, int clientId, double fixedFee, int freeMin);
	TariffFixed* CreateTariffFixed(int number, int clientId, double fixedFee, int freeMin, double mDataLimit, double mDataFixedFee);

	int GetTariffType(int number);
};