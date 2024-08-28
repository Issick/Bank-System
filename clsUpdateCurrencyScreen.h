#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

class clsUpdateCurrencyScreen : protected clsScreen
{
private:

	static float _ReadRate()
	{
		cout << "\nEnter New Rate : ";
		float NewRate = clsInputValidate<float>::ReadNumber();

		return NewRate;
	}

	static void _PrintCurrency(clsCurrency Currency)
	{
		cout << "\nCurrency Card:\n";
		cout << "______________________________\n";
		cout << "\nCountry      : " << Currency.Country();
		cout << "\nCode         : " << Currency.CurrencyCode();
		cout << "\nName         : " << Currency.CurrencyName();
		cout << "\nRate(1$)     : " << Currency.Rate();

		cout << "\n______________________________\n";
	}


public:

	static void ShowUpdateCurrencyScreen()
	{
		_DrawScreenHeader("\t  Update Currency Screen");

		string CurrencyCode = "";

		cout << "\nPlease Enter Currency Code : ";
		CurrencyCode = clsInputValidate<string>::ReadString();

		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\n\nCurrency Not Found :-( \n\n";

			cout << "\nPlease Enter Currency Code : ";
			CurrencyCode = clsInputValidate<string>::ReadString();
		}

		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		_PrintCurrency(Currency);

		char Answer = 'n';
		cout << "\n\nAre you sure you want to Update this Currency? y/n?";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			cout << "\nUpdate Currency Rate:\n";
			cout << "______________________________\n";
			Currency.UpdateRate(_ReadRate());

			cout << "\n\nCurrency Rate updated successfully :-)\n";
			_PrintCurrency(Currency);
		}

	}

};

