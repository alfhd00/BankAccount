#include "BankHandler.h"
#include "Member.h"

int main(void)
{
	short choice = 1;
	accountHandler bankHandler;

	while(choice != 5)
	{
		cout << "--------",
		     cout << "MENU",
		     	cout << "--------" << endl;

		cout << "1. create an account" << endl;
		cout << "2. input money" << endl;
		cout << "3. output money" << endl;
		cout << "4. print member list" << endl;
		cout << "5. service exit" << endl;

		cout << "menu : ";
		cin >> choice;

		switch(choice)
		{
			case 1:
				bankHandler.createBankAccount();
				break;
			case 2:
				bankHandler.accountInput();
				break;
			case 3:
				bankHandler.accountOutput();
				break;
			case 4:
				bankHandler.printMembers();
				break;
			case 5:
				bankHandler.resourceTerminate();
				break;
			default:
				cout << "message : invalid menu number" << endl;
				break;
		}

	}

	return 0;
}
