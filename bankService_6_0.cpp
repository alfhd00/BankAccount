#include "Member_6_0.h"

class accountHandler
{
	private:
		Member * list[50];
		int count;

	public:
		accountHandler()
		{
			count = 0;
		}

		bool createBankAccount()
		{
			if(count > 50)
			{
				cout << "message : list is full state" << endl;
				return false;
			}

			int choice = 3;

			cout << "[Account type]" << endl;
			cout << "1. Normal account 2. High credit account 3. Default account" << endl;
			
			cout << "choice : ";
			std::cin >> choice;

			switch(choice)
			{
				case 1:
					list[count++] = new NormalMember();
					break;
				case 2:
					list[count++] = new HighCreditMember();
					break;
				case 3:
				default:
					list[count++] = new Member();
			}
			
			return true;	
		}

		bool accountInput()
		{
			char accountNum[30];

			cout << "bank account sign number : ";
			cin >> accountNum;

			for(int i=0; i<count; i++)
			{
				if(strcmp(list[i]->get_account_signal_number(), accountNum) == 0)
				{
					int money = 0;

					cout << "input money : ";
					cin >> money;

					list[i]->input(money);
					return true;
				}
			}


			cout << "message : didn't match the member to signal number" << endl;
			return false;
		}

		bool accountOutput()
		{
			char accountNum[30];

			cout << "bank account sign number : ";
			cin >> accountNum;

			for(int i=0; i<count; i++)
			{
				if(strcmp(list[i]->get_account_signal_number(), accountNum) == 0)
				{
					int money = 0;

				cout << "output money : ";
					cin >> money;

					list[i]->output(money);

					return true;
				}
			}


			cout << "message : didn't match the member to signal number" << endl;
			return false;
		}

		void printMembers()
		{
			for(int i=0; i<count; i++) list[i]->printMemberInfo();
		}

		void resourceTerminate()
		{
			for(int i=0; i<count; i++)
			{
				delete list[i]->get_account_signal_number();
				delete list[i]->get_user_name();
			}
		}
};

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

	//	for(int i=0; i<count; i++)
	//		list[i]->printMemberInfo();
	}

	return 0;
}
