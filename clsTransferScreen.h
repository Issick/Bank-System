#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsTransferScreen : protected clsScreen
{
private:

	static string _ReadClientAccountNumber(string FromOrTo)
	{
		string AccountNumber = "";

		cout << "\n\nPlease Enter Account Number To Transfer " << FromOrTo << " : ";
		AccountNumber = clsInputValidate<string>::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount number is not found, choose another one: ";
			AccountNumber = clsInputValidate<string>::ReadString();
		}

		return AccountNumber;
	}

	static float _ReadAmount(clsBankClient SourceClient)
	{
		float Amount = 0;
		cout << "\n\nEnter Transfer Amount?  ";
		cin >> Amount;

		while (Amount > SourceClient.AccountBalance)
		{
			cout << "\n\nAmount Exceeds the available Balance, Enter another Amount ?";
			cin >> Amount;
		}
		return Amount;
	}

	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n--------------------";
		cout << "\nFull Name      : " << Client.FullName();
		cout << "\nAcc. Number    : " << Client.AccountNumber();
		cout << "\nBalance        : " << Client.AccountBalance;
		cout << "\n--------------------\n\n";

	}

public:

	static void ShowTransferScreen()
	{
		_DrawScreenHeader("\t  Transfer Screen");

		string AccoutNumber = _ReadClientAccountNumber("From");
		clsBankClient SourceClient = clsBankClient::Find(AccoutNumber);
		_PrintClient(SourceClient);

		AccoutNumber = _ReadClientAccountNumber("To");
		clsBankClient DestinationClient = clsBankClient::Find(AccoutNumber);
		_PrintClient(DestinationClient);


		float Amount = _ReadAmount(SourceClient);

		cout << "\n\nAre you sure you want to perform this operation? y/n?";
		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			if (SourceClient.Transfer(Amount, DestinationClient, CurrentUser.UserName))
			{
				//SourceClient.RegisterTransfer(DestinationClient, Amount);
				cout << "\n\nTransfer done successfully\n\n";
				_PrintClient(SourceClient);
				_PrintClient(DestinationClient);
			}
			else
				cout << "\n\nTransfer Failed\n\n";

		}


	}
};

