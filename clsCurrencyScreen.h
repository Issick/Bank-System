#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyScreen.h"
#include "clsCurrencyCalculatorScreen.h"
#include <iomanip>

class clsCurrencyScreen : protected clsScreen
{
private:

	enum enCurrenciesOption
	{
		eListCurrencies = 1, eFindCurrency = 2, eUpdateRate = 3,
		eCurrencyCalculator = 4, eMainMenue = 5
	};

	static short _ReadCurrencyMenueOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
		short Choice = clsInputValidate<short>::ReadNumberBetween(1, 5, "Enter Number between 1 to 5? ");
		return Choice;
	}

	static void _ShowListCurrenciesScreen()
	{
		//cout << "\n Here will be List Currencies Screen\n\n";
		clsCurrenciesListScreen::ShowCurrenciesList();
	}

	static void _ShowFindCurrencyScreen()
	{
		//cout << "\n Here will be Find Currency Screen\n\n";
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}

	static void _ShowUpdateRateScreen()
	{
		//cout << "\n Here will be Update Rate Screen\n\n";
		clsUpdateCurrencyScreen::ShowUpdateCurrencyScreen();
	}

	static void _ShowCurrencyCalculatorScreen()
	{
		//cout << "\n Here will be Currency Calculator Screen\n\n";
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
	}

	static void _GoBackToCurrenciesMenue()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

		system("pause>0");
		ShowCurrenciesMenue();
	}

	static void _PerfromCurrenciesMenueOption(enCurrenciesOption CurrenciesOption)
	{
		switch (CurrenciesOption)
		{
		case enCurrenciesOption::eListCurrencies:
			system("cls");
			_ShowListCurrenciesScreen();
			_GoBackToCurrenciesMenue();
			break;

		case enCurrenciesOption::eFindCurrency:
			system("cls");
			_ShowFindCurrencyScreen();
			_GoBackToCurrenciesMenue();
			break;

		case enCurrenciesOption::eUpdateRate:
			system("cls");
			_ShowUpdateRateScreen();
			_GoBackToCurrenciesMenue();
			break;

		case enCurrenciesOption::eCurrencyCalculator:
			system("cls");
			_ShowCurrencyCalculatorScreen();
			_GoBackToCurrenciesMenue();
			break;

		case enCurrenciesOption::eMainMenue:
			break;
		default:
			break;
		}
	}

public:

	static void ShowCurrenciesMenue()
	{

		//if (!_CheckAccessRights(clsUser::enPermissions::pTransactions))
		//{
		//	return; //this will exit the function and it will not 
		//}

		system("cls");
		_DrawScreenHeader("\tCurrency Exhange Main Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\tCurrency Exhange Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerfromCurrenciesMenueOption((enCurrenciesOption)_ReadCurrencyMenueOption());
	}

};

