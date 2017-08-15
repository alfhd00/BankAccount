#ifndef __BANK_HANDLER_H__
#define __BANK_HANDLER_H__
//#include "HighCreditMember.h
#include "Array.h"

typedef Member * MEM_PTR;

class accountHandler
{
	private:
		Array<MEM_PTR> list;
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

		Array<MEM_PTR>& operator=(Member* member)
		{
			list[count++] = member;
			return list;
		}

		bool createBankAccount();

		bool accountInput();

		bool accountOutput();

		void printMembers();

};
#endif
