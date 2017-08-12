#include "BankHandler.h"
//accountHandler class definition

bool accountHandler::createBankAccount()
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
	cin >> choice;

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

bool accountHandler::accountInput()
{
	String accountNum;

	cout << "bank account sign number : ";
	cin >> accountNum;

	for(int i=0; i<count; i++)
	{
		if(list[i]->get_account_sign_number() == accountNum)
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

bool accountHandler::accountOutput()
{
	String accountNum;

	cout << "bank account sign number : ";
	cin >> accountNum;

	for(int i=0; i<count; i++)
	{
		if(list[i]->get_account_sign_number() == accountNum)
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

void accountHandler::printMembers()
{
	for(int i=0; i<count; i++) list[i]->printMemberInfo();
}


