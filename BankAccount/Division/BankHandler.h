#ifndef __BANK_HANDLER_H__
#define __BANK_HANDLER_H__
#include "HighCreditMember.h"


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

		bool createBankAccount();

		bool accountInput();

		bool accountOutput();

		void printMembers();

		void resourceTerminate();
};
#endif
