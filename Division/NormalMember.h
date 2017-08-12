#ifndef __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__
#include "Member.h"

class NormalMember : public Member
{
	private:
		double interestRatio;
	public:
		NormalMember()
		{
			createBankAccount();
		}

		//copy constructor
		NormalMember(const NormalMember& nm)
		{
			//auto parent copy constructor call?
			//Member(nm);
			interestRatio = nm.interestRatio;
		}

		//overriding
		virtual void createBankAccount()
		{
			cout << "4. interest ratio : ";
			cin >> interestRatio;
		}

		//overriding
		virtual bool input(int money)
		{
			if(money < 0) return false;

			int process = (int)(money * (1+interestRatio));
			
			return Member::input(process);
			
		}

		double getInterestRatio()
		{
			return interestRatio;
		}

		void setInterestRatio(double ratio)
		{
			if(ratio < 0) return;

			interestRatio += ratio;
		}
};
#endif
