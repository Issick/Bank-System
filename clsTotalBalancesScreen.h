#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "ClsUtil.h"
#include <string>
#include <iomanip>
class clsTotalBalancesScreen : protected clsScreen
{
private:

	static void _PrintClientRecordBalanceLine(clsBankClient Client)
	{
		cout << setw(20) << "" << "| " << left << setw(15) << Client.AccountNumber();
		cout << "| " << left << setw(40) << Client.FullName();
		cout << "| " << left << setw(12) << Client.AccountBalance;
	}

public:

	static void ShowTotalBalances()
	{
		vector <clsBankClient> vClients = clsBankClient::GetClientList();

		string Title = "\t     Balances Screen";
		string SubTitle = "\tClients List (" + to_string(vClients.size()) + ") Clients";

		_DrawScreenHeader(Title, SubTitle);

		cout << setw(20) << left << "" << "_________________________________________________________";
		cout << "_________________________\n\n";

		cout << setw(20) << "" << "| " << left << setw(15) << "Account Number";
		cout << "| " << left << setw(40) << "Client Name";
		cout << "| " << left << setw(12) << "Balance" << endl;
		cout << setw(20) << left << "" << "_________________________________________________________";
		cout << "_________________________\n";

		double TotalBalances = clsBankClient::GetTotalBalances();

		if (vClients.size() == 0)
		{
			cout << "\t\t\tNo Clients Available In The System!";
		}
		else
		{
			for (clsBankClient Client : vClients)
			{
				_PrintClientRecordBalanceLine(Client);
				cout << endl;
			}
		}
		cout << setw(20) << left << "" << "_________________________________________________________";
		cout << "_________________________\n";
		cout << "\t\t\t\t\t    Total Balances = " << TotalBalances << endl;
		cout << "\t\t\t\t\t    ( " << clsUtil::NumberToText(TotalBalances) << " )" << endl;
	}
};

