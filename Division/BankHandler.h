#ifndef __BANK_HANDLER_H__
#define __BANK_HANDLER_H__
//#include "HighCreditMember.h"
#include "Array.h"

class accountHandler
{
	private:
		Array list;
		int count;

	public:
		accountHandler() : list()
		{
			count = 0;
		}

		MEM_PTR& operator[](int idx)
		{
			return list.operator[](idx);
		}

		Array& operator=(Member* member)
		{
			list[count++] = member;
			return list;
		}

		bool createBankAccount();

		bool accountInput();

		bool accountOutput();

		void printMembers();

		void resourceTerminate();
};
#endif
