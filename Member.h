/* this is a c language style
#ifndef __MEMBER_H__
#define __MEMBER_H__
typedef struct {
	char bankNumber[15];
	char userName[30];
	unsigned int account;
} Member;

void createBankAccount(Member members[]);
void input(Member members[]);
void output(Member members[]);
void printAllMemberInfo(Member members[]);
#endif
*/

//c++ language style
#ifndef __MEMBER_H__
#define __MMEMBER_H__
#include <iostream>
#include <cstring>

using namespace std;

class Member
{
	private:
		char * account_signal_number;
		char * user_name;
		unsigned int account;

	public:
		Member()
		{
			createBankAccount();
		}

		void createBankAccount(void)
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

		~Member()
		{
			delete []account_signal_number;
			delete []user_name;
		}

		bool input(int money)
		{
			if(money < 0) return false;
			else
				account += money;

			return true;
		}

		bool output(int money)
		{
			if(money > account) return false;
			else
				account -= money;

			return true;
		}

		void printMemberInfo()
		{
			cout << "[Account number] : " << account_signal_number << endl;
			cout << "[User name] : " << user_name << endl;
			cout << "[Account] : " << account << endl;

			cout << endl;
		}
		
		//getter, setter method
		char * get_account_signal_number()
		{
			return account_signal_number;
		}

		char * get_user_name()
		{
			return user_name;
		}


};
#endif
