#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsMainScreen.h"
#include "clsShowDepositScreen.h"
#include "clsShowWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h"
#include "clsInputValidate.h"
#include <iomanip>

using namespace std;

class clsShowTransationsScreen : protected clsScreen
{
private:

	enum enTransactionsOption
	{
		eDeposit = 1, eWithdraw = 2, eTotalBalances = 3,
		eTransfer = 4, eTransferLogs = 5, eMainMenue = 6
	};

	static short _ReadTransactionsMenueOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
		short Choice = clsInputValidate<short>::ReadNumberBetween(1, 6, "Enter Number between 1 to 6? ");
		return Choice;
	}

	static void _ShowDepositScreen()
	{
		//cout << "\n Here Deposit Screen";
		clsShowDepositScreen::ShowDepositScreen();
	}

	static void _ShowWithdrawScreen()
	{
		//cout << "\n Here Withdraw Screen";
		clsShowWithdrawScreen::ShowWithdrawScreen();
	}

	static void _ShowTotalBalancesScreen()
	{
		//cout << "\n Here TotalBalances Screen";
		clsTotalBalancesScreen::ShowTotalBalances();
	}

	static void _ShowTransferScreen()
	{
		//cout << "\nTransfer Screen will be here\n\n";
		clsTransferScreen::ShowTransferScreen();
	}

	static void _ShowTransferLogsScreen()
	{
		clsTransferLogScreen::ShowTransferLogsScreen();
	}

	static void _GoBackToTransactionsMenue()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

		system("pause>0");
		ShowTransactionsMenue();
	}

	static void _PerfromTransactionsMenueOption(enTransactionsOption TransactionsOption)
	{
		switch (TransactionsOption)
		{
		case clsShowTransationsScreen::eDeposit:
			system("cls");
			_ShowDepositScreen();
			_GoBackToTransactionsMenue();
			break;
		case clsShowTransationsScreen::eWithdraw:
			system("cls");
			_ShowWithdrawScreen();
			_GoBackToTransactionsMenue();
			break;
		case clsShowTransationsScreen::eTotalBalances:
			system("cls");
			_ShowTotalBalancesScreen();
			_GoBackToTransactionsMenue();
			break;
		case clsShowTransationsScreen::eTransfer:
			system("cls");
			_ShowTransferScreen();
			_GoBackToTransactionsMenue();
			break;
		case clsShowTransationsScreen::eTransferLogs:
			system("cls");
			_ShowTransferLogsScreen();
			_GoBackToTransactionsMenue();
			break;
		case clsShowTransationsScreen::eMainMenue:
			break;
		default:
			break;
		}
	}

public:

	static void ShowTransactionsMenue()
	{

		if (!_CheckAccessRights(clsUser::enPermissions::pTransactions))
		{
			return; //this will exit the function and it will not 
		}

		system("cls");
		_DrawScreenHeader("\tTransaction Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\tTransaction Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Deposit.\n";
		cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
		cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
		cout << setw(37) << left << "" << "\t[4] Transfer.\n";
		cout << setw(37) << left << "" << "\t[5] Transfer Logs.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerfromTransactionsMenueOption((enTransactionsOption)_ReadTransactionsMenueOption());
	}
};

