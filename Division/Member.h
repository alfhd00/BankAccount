#ifndef __MEMBER_H__
#define __MEMBER_H__
#include <iostream>
#include <cstring>

using std::cout;
using std::cin;
using std::endl;

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

		//copy constructor
		Member(const Member& member)
		{
			account_signal_number = new char[strlen(account_signal_number)+1];
			strcpy(account_signal_number, member.account_signal_number);

			user_name = new char[strlen(user_name)+1];
			strcpy(user_name, member.user_name);

			account = member.account;
		}

		virtual void createBankAccount(void);

		~Member()
		{
			delete []account_signal_number;
			delete []user_name;
		}

		virtual Member& operator=(const Member& member);

		virtual bool input(int money);

		bool output(int money) const;

		void printMemberInfo() const;
		
		char * get_account_sign_number() const;

		char * get_user_name() const;
};
#endif
