#pragma once
#include "clsScreen.h"
#include "clsUser.h"
#include <vector>
#include <iomanip>



class clsListUsers : protected clsScreen
{
private:

	static void _PrintUserRecordLine(clsUser User)
	{
		cout << setw(8) << left << "| " << setw(12) << left << User.UserName;
		cout << setw(8) << left << "| " << setw(15) << left << User.FullName();
		cout << setw(8) << left << "| " << setw(20) << left << User.Phone;
		cout << setw(8) << left << "| " << setw(20) << left << User.Email;
		cout << setw(8) << left << "| " << setw(10) << left << User.Password;
		cout << setw(8) << left << "| " << setw(12) << left << User.Permissions;
	}

public:

	static void ShowUsersList()
	{
		vector <clsUser> vUsers = clsUser::GetUsersList();

		string Title = "\t  User List Screen";
		string SubTitle = "\t    (" + to_string(vUsers.size()) + ") User(s).";

		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "\n\t______________________________________________________";
		cout << "________________________________________________________________________\n" << endl;

		cout << setw(8) << left << "| " << left << setw(12) << "UserName";
		cout << setw(8) << left << "| " << left << setw(15) << "Full Name";
		cout << setw(8) << left << "| " << left << setw(20) << "Phone";
		cout << setw(8) << left << "| " << left << setw(20) << "Email";
		cout << setw(8) << left << "| " << left << setw(10) << "Password";
		cout << setw(8) << left << "| " << left << setw(12) << "Permissions";
		cout << setw(8) << left << "" << "\n\t______________________________________________________";
		cout << "________________________________________________________________________\n" << endl;

		if (vUsers.size() == 0)
		{
			cout << "\t\t\tNo Users Available In The System!";
		}
		else
		{
			for (clsUser User : vUsers)
			{
				_PrintUserRecordLine(User);
				cout << endl;
			}
		}
		cout << setw(8) << left << "" << "\n\t______________________________________________________";
		cout << "_________________________________________________________________________\n" << endl;
	}
};

