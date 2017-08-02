#ifndef __HIGH_CREDIT_MEMBER_H__
#define __HIGH_CREDIT_MEMBER_H__
#include "NormalMember.h"

class HighCreditMember : public NormalMember
{
	private:
		double gradeCredit;
	public:
		HighCreditMember()
		{
			createBankAccount();
		}

		//overriding
		virtual void createBankAccount()
		{
			cout << "5. Credit grade : ";
			
			char grade;

			cin >> grade;

			switch(grade)
			{
				case 'A': gradeCredit = 0.07;
					  break;
				case 'B': gradeCredit = 0.04;
					  break;
				case 'C': gradeCredit = 0.02;
					  break;
				default:
					  gradeCredit = 0.0;

			}
		}

		//overriding
		virtual bool input(int money)
		{
			setInterestRatio(gradeCredit);
			NormalMember::input(money);
			return true;
		}		
};
#endif

