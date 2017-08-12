//Member class definition
#include "Member.h"

void Member::createBankAccount(void)
{
	cout << "[Create account]" << endl;
	cout << "1. account signal number: ";
	cin >> this->account_signal_number;

	cout << "2. user name : ";
	cin >>  this->user_name;

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

bool Member::output(int money)
{
	if(money > account) return false;
	
	account -= money;
	return true;
}


void Member::printMemberInfo() 
{
	cout << "[Account number] : ";
	cout << account_signal_number << endl;
	cout << "[User name] : ";
	cout << user_name << endl;
	cout << "[Account] : ";
	cout << account << endl;

	cout << endl;
}

//getter, setter method
String& Member::get_account_sign_number() 
{
	return account_signal_number;
}

String& Member::get_user_name() 
{
	return user_name;
}

