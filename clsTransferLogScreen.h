#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>

class clsTransferLogScreen : protected clsScreen
{
private:

	static void _PrintLoginRegisterRecordLine(clsBankClient::stTransferLoginRecord TransferLoginRecord)
	{

		cout << setw(8) << left << "" << "| " << setw(25) << left << TransferLoginRecord.DateTime;
		cout << "| " << setw(15) << left << TransferLoginRecord.S_AccountNm;
		cout << "| " << setw(15) << left << TransferLoginRecord.D_AccountNm;
		cout << "| " << setw(15) << left << TransferLoginRecord.Amount;
		cout << "| " << setw(15) << left << TransferLoginRecord.S_Balance;
		cout << "| " << setw(15) << left << TransferLoginRecord.D_Balance;
		cout << "| " << setw(15) << left << TransferLoginRecord.Username;
	}

public:

	static void ShowTransferLogsScreen()
	{

		//if (!_CheckAccessRights(clsUser::enPermissions::pListClients))
		//{
		//	return; //this will exit the function and it will not 
		//}

		vector <clsBankClient::stTransferLoginRecord> vTransferRecords = clsBankClient::GetTransferLogsList();

		string Title = "\tTransfer Operations List Screen";
		string SubTitle = "\t\t(" + to_string(vTransferRecords.size()) + ") Record(s).";

		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "___________________________________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(25) << "Date/Time";
		cout << "| " << left << setw(15) << "S.AccountNum";
		cout << "| " << left << setw(15) << "D.AccountNum";
		cout << "| " << left << setw(15) << "Amount";
		cout << "| " << left << setw(15) << "S.Balance";
		cout << "| " << left << setw(15) << "D.Balance";
		cout << "| " << left << setw(15) << "Username";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "___________________________________________________________________\n" << endl;

		if (vTransferRecords.size() == 0)
			cout << "\t\t\t\tNo Transfer Operations Available In the System!";
		else

			for (clsBankClient::stTransferLoginRecord Record : vTransferRecords)
			{

				_PrintLoginRegisterRecordLine(Record);
				cout << endl;
			}

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "___________________________________________________________________\n" << endl;

	}

};

