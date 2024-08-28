#pragma once
#include "clsScreen.h"
#include "clsUser.h"
#include "clsMainScreen.h"
#include "clsGlobal.h"

class clsLoginScreen : protected clsScreen
{
private:



	static bool _Login()
	{
		bool LoginFailed = false;

		string Username, Password;
		short LoginFailedtimes = 0;

		do {

			if (LoginFailed)
			{
				LoginFailedtimes++;
				cout << "\nInvalid Username/Password\n";
				cout << "You have " << (3 - LoginFailedtimes) << " Trial(s) to login\n\n";
			}

			if (LoginFailedtimes == 3)
			{
				cout << "\n\nYou have locked after 3 failed trials\n\n\n";
				return false;
			}

			cout << "\nEnter Username : ";
			cin >> Username;

			cout << "Enter Password : ";
			cin >> Password;

			CurrentUser = clsUser::Find(Username, Password);

			LoginFailed = CurrentUser.IsEmpty();

		} while (LoginFailed);

		CurrentUser.RegisterLogIn();
		clsMainScreen::ShowMainMenue();
		return true;
	}

public:

	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t  Login Screen");
		return _Login();
	}

};

