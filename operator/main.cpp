#include <iostream>
#include "Operator.h"

using namespace std;

int main()
{
	TariffCredit* tarif1;
	TariffFixed* tarif2;

	Operator* o = new Operator();
	
	o->CreateClient("Novak");
	o->CreateClient("Klasova");
	o->CreateClient("Svoboda");
	o->CreateClient("Sikora");


	o->CreateTariffCredit(602333444, o->GetClient("Svoboda")->GetId());
	o->CreateTariffFixed(724777888, o->GetClient("Sikora")->GetId(), 150.0, 50);
	o->CreateTariffFixed(724777999, o->GetClient("Novak")->GetId(), 150.0, 50, 1500, 100.0);

	printf("602333444 - tariff credit\n");
	if (o->GetTariffType(602333444) == 1)
	{
		tarif1 = o->GetTariffCredit(602333444);
		tarif1->Payment(100);
		printf("new credit after payment: %1.2f\n",tarif1->GetBalance());
		printf("new free minutes for calling: %d\n",tarif1->GetPaidMinute());
		bool stat = tarif1->MakeCall(10);
		//if(stat == false) tato situace by nemìla nastat, délka hovoru by nemìla být delši než tarif1->GetPaidMinute()
		printf("new credit after call: %1.2f\n", tarif1->GetBalance());
		printf("new free minutes for calling: %d\n", tarif1->GetPaidMinute());
	}
	printf("\n");

	printf("724777888 - tariff fixed\n");
	if (o->GetTariffType(724777888) == 2)
	{
		tarif2 = o->GetTariffFixed(724777888);
		printf("initial account: %1.2f\n", tarif2->GetBalance());
		tarif2->MakeCall(20);
		tarif2->MakeCall(30);
		tarif2->MakeCall(5);
		double sum = tarif2->Billing();
		printf("month bill: %1.2f\n", sum);
		printf("actual account: %1.2f\n", tarif2->GetBalance());
		tarif2->Payment(sum);
		printf("account after payment: %1.2f\n", tarif2->GetBalance());
	}
	printf("\n");

	printf("724777999 - tariff fixed and mobile data\n");
	if (o->GetTariffType(724777999) == 2)
	{
		tarif2 = o->GetTariffFixed(724777999);
		printf("initial account: %1.2f\n", tarif2->GetBalance());
		tarif2->MakeCall(20);
		if (tarif2->mData != nullptr)
		{
			double freeMB = tarif2->mData->GetFreeMB();
			// nesmi cerpat vic nez freeMB
			tarif2->mData->UseData(100);
		}
		double sum = tarif2->Billing();
		printf("month bill: %1.2f\n", sum);
		printf("actual account: %1.2f\n", tarif2->GetBalance());
		tarif2->Payment(sum);
		printf("account after payment: %1.2f\n", tarif2->GetBalance());
	}

	delete o;

}
