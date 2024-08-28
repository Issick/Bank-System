#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrency.h"


class clsCurrencyCalculatorScreen : protected clsScreen
{
private:

	static clsCurrency _GetCurrency(string CodeOrder)
	{
		string CurrencyCode = "";

		cout << "\n\nPlease Enter Currency" << CodeOrder << " Code : \n";
		CurrencyCode = clsInputValidate<string>::ReadString();

		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\n\nCurrency Not Found :-( \n";

			cout << "\nPlease Enter Currency" << CodeOrder << " Code : \n";
			CurrencyCode = clsInputValidate<string>::ReadString();
		}

		return clsCurrency::FindByCode(CurrencyCode);
	}

	static float _ReadAmount()
	{
		float Amount;

		cout << "\nEnter amount to Exhange : ";
		Amount = clsInputValidate<float>::ReadNumber();

		return Amount;
	}

	static void _PrintCurrency(clsCurrency Currency, string Title = "Currency Card")
	{
		cout << endl << endl << Title << endl;
		cout << "______________________________\n";
		cout << "\nCountry      : " << Currency.Country();
		cout << "\nCode         : " << Currency.CurrencyCode();
		cout << "\nName         : " << Currency.CurrencyName();
		cout << "\nRate(1$)     : " << Currency.Rate();
		cout << "\n______________________________\n";
	}

	static void _PrintCalculationsResults(clsCurrency CurrencyFrom, clsCurrency CurrencyTo, float Amount)
	{
		_PrintCurrency(CurrencyFrom, "Convert From:");

		float AmountInUSD = CurrencyFrom.ConvertToUSD(Amount);

		cout << "\n" << Amount << " " << CurrencyFrom.CurrencyCode();
		cout << " = " << AmountInUSD << " USD \n";

		if (CurrencyTo.CurrencyCode() == "USD")
		{
			return;
		}

		cout << "\n\nConverting from USD to :";

		_PrintCurrency(CurrencyTo, "To:");

		float AmountInCurrency2 = CurrencyFrom.ConverToOtherCurrency(Amount, CurrencyTo);

		cout << "\n" << Amount << " " << CurrencyFrom.CurrencyCode();
		cout << " = " << AmountInCurrency2 << " " << CurrencyTo.CurrencyCode() << endl;

	}

public:

	static void ShowCurrencyCalculatorScreen()
	{
		char Continue = 'y';

		while (Continue == 'y' || Continue == 'Y')
		{
			system("cls");

			_DrawScreenHeader("\t Currency Calculator Screen");

			clsCurrency CurrencyFrom = _GetCurrency("1");
			clsCurrency CurrencyTo = _GetCurrency("2");
			float Amount = _ReadAmount();

			_PrintCalculationsResults(CurrencyFrom, CurrencyTo, Amount);

			cout << "\n\nDo you want to perform another calculation? y/n?";
			cin >> Continue;

		};

	}
};

