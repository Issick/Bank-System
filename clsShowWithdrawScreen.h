#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsShowWithdrawScreen : protected clsScreen
{
private:

	static string _ReadAccountNumber()
	{
		string AccountNumber = "";

		cout << "\nPlease Enter client Account Number: ";
		AccountNumber = clsInputValidate<string>::ReadString();

		return AccountNumber;
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

	static void ShowWithdrawScreen()
	{
		_DrawScreenHeader("\t  Withdraw Screen");

		string AccountNumber = _ReadAccountNumber();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount number is not found, choose another one: ";
			AccountNumber = _ReadAccountNumber();
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_PrintClient(Client1);

		double Amount = 0;
		cout << "\nPlease enter withdraw amount?\n";
		Amount = clsInputValidate<double>::ReadNumber();

		while (!clsInputValidate<double>::IsPosetiveNumber(Amount))
		{
			cout << "\nPlease enter a poseive number : ";
			Amount = clsInputValidate<double>::ReadNumber();
		}

		cout << "\nAre you sure to perform this operation? y/n :\n";
		char Choice = 'n';
		cin >> Choice;

		if (Choice == 'y' || Choice == 'Y')
		{
			if (Client1.Withdraw(Amount))
			{
				cout << "\nAmount withdrawed successfully.\n";
				cout << "\nNew balance is :" << Client1.AccountBalance;
			}
			else
			{
				cout << "\nCannot withdraw, insuffecint balance!\n";
				cout << "\nAccount to withdraw is : " << Amount;
				cout << "\nYour balance is : " << Client1.AccountBalance << endl;
			}
		}
		else
		{
			cout << "\nOperation was cancelled.\n";
		}
	}
};

