#include "Member_3_0.h"
bool createBankAccount(Member * list[], int * count);
bool accountInput(Member * list[], int * count);
bool accountOutput(Member * list[], int * count);
void printMembers(Member * list[], int * count);
void resourceTerminate(Member * list[], int * count);

int main(void)
{
	short choice = 1;
	int count = 0;
	Member * list[20];

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

		char accountNum[30];
		switch(choice)
		{
			case 1:
				createBankAccount(list, &count);
				break;
			case 2:
				accountInput(list, &count);
				break;
			case 3:
				accountOutput(list, &count);
				break;
			case 4:
				printMembers(list, &count);
				break;
			case 5:
				resourceTerminate(list, &count);
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

bool createBankAccount(Member * list[], int * count)
{
	if(*count > 20)
	{
       		cout << "message : list is full state" << endl;
      	 	return false;
	}

	list[(*count)++] = new Member();
	return true;	
}

bool accountInput(Member * list[], int * count)
{
	char accountNum[30];

	cout << "bank account sign number : ";
	cin >> accountNum;

	for(int i=0; i<*count; i++)
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

bool accountOutput(Member * list[], int * count)
{
	char accountNum[30];

	cout << "bank account sign number : ";
	cin >> accountNum;

	for(int i=0; i<*count; i++)
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

void printMembers(Member * list[], int * count)
{
	for(int i=0; i<*count; i++) list[i]->printMemberInfo();
}

void resourceTerminate(Member * list[], int *count)
{
	for(int i=0; i<*count; i++)
	{
		delete list[i]->get_account_signal_number();
		delete list[i]->get_user_name();
	}
}
