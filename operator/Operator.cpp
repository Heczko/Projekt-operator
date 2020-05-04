#include "Operator.h"
#include "MobileData.h"

Operator::Operator()
{
	this->clients = (Client**)malloc(sizeof(Client));
	this->clientsCount = 0;

	this->tariffsCredit = (TariffCredit**)malloc(sizeof(TariffCredit));
	this->tariffsCreditCount = 0;

	this->tariffsFixed = (TariffFixed**)malloc(sizeof(TariffFixed));
	this->tariffsFixedCount = 0;
}

Operator::~Operator()
{
	int i;
	for (i = 0; i < this->clientsCount; i++)
	{
		free(this->clients[i]);
	}

	for (i = 0; i < this->tariffsCreditCount; i++)
	{
		free(this->tariffsCredit[i]);
	}

	for (i = 0; i < this->tariffsFixedCount; i++)
	{
		free(this->tariffsFixed[i]);
	}

}

Client* Operator::GetClient(int id)
{
	for (int i = 0; i < this->clientsCount; i++)
	{
		if (this->clients[i]->GetId() == id)
		{
			return this->clients[i];
		}
	}
	cout << "Client with id " << id << " not found" << endl;
	return NULL;
}

Client* Operator::GetClient(string name)
{
	for (int i = 0; i < this->clientsCount; i++)
	{
		if (this->clients[i]->GetName() == name)
		{
			return this->clients[i];
		}
	}
	cout << "Client with name " << name << " not found" << endl;
	return NULL;
}

Client* Operator::CreateClient(string name)
{	
	//this->clients = (Client**)realloc(this->clients, sizeof(Client) * (this->clientsCount + 1));
	Client** x = (Client**)realloc(this->clients, sizeof(Client) * (this->clientsCount + 1));
	if (x == NULL)
	{
		return NULL;
	}
	else this->clients = x;

	this->clients[this->clientsCount] = new Client(name, this->clientsCount);
	this->clientsCount++;
	
	return this->clients[clientsCount-1];
}

TariffCredit* Operator::GetTariffCredit(int number)
{
	for (int i = 0; i < this->tariffsCreditCount; i++)
	{
		if (this->tariffsCredit[i]->GetNumber() == number)
		{
			return this->tariffsCredit[i];
		}
	}
	cout << "TariffCredit with number " << number << " not found" << endl;
	return NULL;
}

TariffCredit* Operator::CreateTariffCredit(int number, int clientId)
{
	TariffCredit** x = (TariffCredit**)realloc(this->tariffsCredit, sizeof(TariffCredit) * (this->tariffsCreditCount + 1));
	if (x == NULL)
	{
		return NULL;
	}
	else this->tariffsCredit = x;
	this->tariffsCredit[this->tariffsCreditCount] = new TariffCredit(number, clientId);
	this->tariffsCreditCount++;

	return this->tariffsCredit[tariffsCreditCount - 1];
}

TariffFixed* Operator::GetTariffFixed(int number)
{
	for (int i = 0; i < this->tariffsFixedCount; i++)
	{
		if (this->tariffsFixed[i]->GetNumber() == number)
		{
			return this->tariffsFixed[i];
		}
	}
	cout << "TariffFixed with number " << number << " not found" << endl;
	return NULL;
}

TariffFixed* Operator::CreateTariffFixed(int number, int clientId, double fixedFee, int freeMin)
{
	TariffFixed** x = (TariffFixed**)realloc(this->tariffsFixed, sizeof(TariffFixed) * (this->tariffsFixedCount + 1));
	if (x == NULL)
	{
		return NULL;
	}
	else this->tariffsFixed = x;

	this->tariffsFixed[this->tariffsFixedCount] = new TariffFixed(number, clientId, fixedFee, freeMin);
	this->tariffsFixedCount++;

	return this->tariffsFixed[tariffsFixedCount - 1];
}

TariffFixed* Operator::CreateTariffFixed(int number, int clientId, double fixedFee, int freeMin, double mDataLimit, double mDataFixedFee)
{
	TariffFixed** x = (TariffFixed**)realloc(this->tariffsFixed, sizeof(TariffFixed) * (this->tariffsFixedCount + 1));
	if (x == NULL)
	{
		return NULL;
	}
	else this->tariffsFixed = x;

	this->tariffsFixed[this->tariffsFixedCount] = new TariffFixed(number, clientId, fixedFee, freeMin, mDataLimit, mDataFixedFee);
	this->tariffsFixedCount++;

	return this->tariffsFixed[tariffsFixedCount - 1];
}

int Operator::GetTariffType(int number)
{
	for (int i = 0; i < this->tariffsCreditCount; i++)
	{
		if (this->tariffsCredit[i]->GetNumber() == number)
		{
			return 1;
		}
	}

	for (int i = 0; i < this->tariffsFixedCount; i++)
	{
		if (this->tariffsFixed[i]->GetNumber() == number)
		{
			return 2;
		}
	}
	
	return 0;
}
