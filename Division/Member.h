#ifndef __MEMBER_H__
#define __MEMBER_H__
#include "String.h"


using std::cout;
using std::cin;
using std::endl;

class Member
{
	private:
		String account_signal_number;
		String user_name;
		unsigned int account;

	public:
		Member()
		{
			createBankAccount();
		}

		virtual void createBankAccount(void);

		virtual bool input(int money);

		bool output(int money);

		void printMemberInfo();
		
		String& get_account_sign_number();

		String& get_user_name();
};
#endif
