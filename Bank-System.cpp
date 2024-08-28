#include <iostream>
//#include "clsCurrency.h"
#include "clsLoginScreen.h"

using namespace std;



int main()
{

	while (true)
	{

		if (!clsLoginScreen::ShowLoginScreen())
			break;
	}

	/*clsCurrency Currency1 = Currency1.FindByCode("jod");

	if (Currency1.IsEmpty())
	{
		cout << "\nCurrency is not found!\n";
	}
	else
	{
		_PrintCurrency(Currency1);
	}

	clsCurrency Currency2 = Currency2.FindByCountry("Syria");

	if (Currency2.IsEmpty())
	{
		cout << "\nCurrency is not found!\n";
	}
	else
	{
		_PrintCurrency(Currency2);
	}

	Currency2.UpdateRate(13000);
	_PrintCurrency(Currency2);*/

	return 0;
}

