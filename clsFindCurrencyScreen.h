#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

class clsFindCurrencyScreen : protected clsScreen
{
private:

	enum enFindOption { eCode = 1, eCountry = 2 };

	static short _ReadFindCurrencyOption()
	{
		cout << "\nDo you like to find Currncy By : [1] Code or [2] Country? ";
		short Choice = clsInputValidate<short>::ReadNumberBetween(1, 2, "Enter Number between 1 to 2? ");
		return Choice;
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

	static void _ShowResults(clsCurrency Currency)
	{
		if (!Currency.IsEmpty())
		{
			cout << "\n\nCurrency Found :-) \n";
			_PrintCurrency(Currency);
		}
		else
		{
			cout << "\n\nCurrency Not Found :-( \n\n";
		}
	}

public:


	static void ShowFindCurrencyScreen()
	{

		//if (!_CheckAccessRights(clsUser::enPermissions::pFindClient))
		//{
		//	return; //this will exit the function and it will not 
		//}

		_DrawScreenHeader("\t  Find Currency Screen");

		enFindOption Option = enFindOption(_ReadFindCurrencyOption());

		clsCurrency Currency = clsCurrency::GetEmptyCurrency();

		if (Option == enFindOption::eCode)
		{
			cout << "\nPlease Enter Currency Code : ";
			string Code = clsInputValidate<string>::ReadString();

			Currency = clsCurrency::FindByCode(Code);

		}
		else
		{
			cout << "\nPlease Enter Currency Country : ";
			string Country = clsInputValidate<string>::ReadString();

			Currency = clsCurrency::FindByCountry(Country);
		}

		_ShowResults(Currency);

	}
};

