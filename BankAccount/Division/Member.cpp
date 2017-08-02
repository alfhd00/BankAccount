//Member class definition
#include "Member.h"

void Member::createBankAccount(void)
{
	int len;

	char account_signal_number[30];
	cout << "[Create account]" << endl;
	cout << "1. account signal number: ";
	cin >> account_signal_number;

	len = strlen(account_signal_number)+1;
	this->account_signal_number = new char[len];
	strcpy(this->account_signal_number, account_signal_number);

	char user_name[30];
	cout << "2. user name : ";
	cin >>  user_name;

	len = strlen(user_name)+1;
	this->user_name = new char[len];
	strcpy(this->user_name, user_name);

	cout <<"3. account : ";
	cin >> this->account;
}

bool Member::input(int money)
{
	if(money < 0) return false;
	else
		account += money;

	return true;
}

bool Member::output(int money) const
{
	if(money > account) return false;
	else
		return account;
}


void Member::printMemberInfo() const
{
	cout << "[Account number] : " << account_signal_number << endl;
	cout << "[User name] : " << user_name << endl;
	cout << "[Account] : " << account << endl;

	cout << endl;
}

//getter, setter method
char * Member::get_account_sign_number() const
{
	return account_signal_number;
}

char * Member::get_user_name() const
{
	return user_name;
}

