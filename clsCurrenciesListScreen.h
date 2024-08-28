#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"
#include <iomanip>


class clsCurrenciesListScreen : protected clsScreen
{
private:

	static void PrintCurrencyRecordLine(clsCurrency Currency)
	{
		cout << setw(8) << left << "| " << setw(35) << left << Currency.Country();
		cout << setw(2) << left << "| " << setw(5) << left << Currency.CurrencyCode();
		cout << setw(2) << left << "| " << setw(40) << left << Currency.CurrencyName();
		cout << setw(2) << left << "| " << setw(10) << left << Currency.Rate();
	}

public:

	static void ShowCurrenciesList()
	{

		//if (!_CheckAccessRights(clsUser::enPermissions::pListClients))
		//{
		//	return; //this will exit the function and it will not 
		//}


		vector <clsCurrency> vCurrencies = clsCurrency::GetCurrenciesList();

		string Title = "\t  Currencies List Screen";
		string SubTitle = "\t    (" + to_string(vCurrencies.size()) + ") Currency(s).";

		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "\n\t______________________________________________________";
		cout << "___________________________________________________________________\n" << endl;

		cout << setw(8) << left << "| " << left << setw(35) << "Country";
		cout << setw(2) << left << "| " << left << setw(5) << "Code";
		cout << setw(2) << left << "| " << left << setw(40) << "Currency Name";
		cout << setw(2) << left << "| " << left << setw(10) << "Rate/(1$)";
		cout << setw(2) << left << "" << "\n\t______________________________________________________";
		cout << "___________________________________________________________________\n" << endl;

		if (vCurrencies.size() == 0)
		{
			cout << "\t\t\tNo Currencies Available In The System!";
		}
		else
		{
			for (clsCurrency Client : vCurrencies)
			{
				PrintCurrencyRecordLine(Client);
				cout << endl;
			}
		}
		cout << setw(8) << left << "" << "\n\t______________________________________________________";
		cout << "___________________________________________________________________\n" << endl;
	}

};

