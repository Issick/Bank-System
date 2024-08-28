#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include <iomanip>

class clsAddNewClientScreen : protected clsScreen
{
private:

	static void _ReadClientInfo(clsBankClient& Client)
	{
		cout << "\nEnter FirstName: ";
		Client.FirstName = clsInputValidate<string>::ReadString();

		cout << "\nEnter LastName: ";
		Client.LastName = clsInputValidate<string>::ReadString();

		cout << "\nEnter Email: ";
		Client.Email = clsInputValidate<string>::ReadString();

		cout << "\nEnter Phone: ";
		Client.Phone = clsInputValidate<string>::ReadString();

		cout << "\nEnter PinCode: ";
		Client.PinCode = clsInputValidate<string>::ReadString();

		cout << "\nEnter Account Balance: ";
		Client.AccountBalance = clsInputValidate<float>::ReadNumber();
	}

	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n--------------------";
		cout << "\nFirstName      : " << Client.FirstName;
		cout << "\nLastName       : " << Client.LastName;
		cout << "\nFull Name      : " << Client.FullName();
		cout << "\nEmail          : " << Client.Email;
		cout << "\nPhone          : " << Client.Phone;
		cout << "\nAcc. Number    : " << Client.AccountNumber();
		cout << "\nPassword       : " << Client.PinCode;
		cout << "\nBalance        : " << Client.AccountBalance;
		cout << "\n--------------------\n";

	}

public:

	static void AddNewClient()
	{

		if (!_CheckAccessRights(clsUser::enPermissions::pAddNewClient))
		{
			return; //this will exit the function and it will not 
		}

		_DrawScreenHeader("\t  Add New Client Screen");

		string AccountNumber = "";

		cout << "\nEnter Account Number: ";
		AccountNumber = clsInputValidate<string>::ReadString();

		while (clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nThis Account Number is used, try another one: ";
			AccountNumber = clsInputValidate<string>::ReadString();
		}

		clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

		_ReadClientInfo(NewClient);

		clsBankClient::enSaveResults SaveResult;

		SaveResult = NewClient.Save();

		switch (SaveResult)
		{
		case clsBankClient::enSaveResults::svSucceeded:
		{
			cout << "\nAccount Added successfully :-)\n";
			_PrintClient(NewClient);
			break;
		}
		case clsBankClient::enSaveResults::svFaildEmptyobject:
		{
			cout << "\nErorr account was not saved because it's empty!\n";
			break;
		}
		case clsBankClient::enSaveResults::svFaildAccountNumberExist:
		{
			cout << "\nErorr account already in use!\n";
			break;
		}
		default:
			break;
		}
	}
};

