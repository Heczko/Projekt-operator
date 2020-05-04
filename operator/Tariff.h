#pragma once

class Tariff
{
protected:
	int number;
	int clientId;
	bool active;

public:
	Tariff(int number, int clientId);
	~Tariff();

	int GetNumber();
	int GetClientId();
	int IsActive();
	void SetActive(bool active);

	virtual double GetBalance();

};

