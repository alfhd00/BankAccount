//bank system version 6.0
#ifndef __MEMBER_V6_H__
#define __MEMBER_V6_H__
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
		Member(char * account_signal_number, char * user_name, int account)
		{
			this->account_signal_number = new char[strlen(account_signal_number)+1];
			strcpy(this->account_signal_number, account_signal_number);

			this->user_name = new char[strlen(user_name)+1];
			strcpy(this->user_name, user_name);

			this->account = account;
		}

		//cp constructor
		Member(const Member &member)
		{
			account_signal_number = new char[strlen(member.account_signal_number)+1];
			strcpy(account_signal_number, member.account_signal_number);

			user_name = new char[strlen(member.user_name)+1];
			strcpy(user_name, member.user_name);

			account = member.account;
		}
		
		Member()
		{
			createBankAccount();
		}

		virtual void createBankAccount(void)
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

		virtual bool input(int money)
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

		void printMemberInfo() const
		{
			cout << "[Account number] : " << account_signal_number << endl;
			cout << "[User name] : " << user_name << endl;
			cout << "[Account] : " << account << endl;

			cout << endl;
		}
		
		//getter, setter method
		char * get_account_signal_number() const
		{
			return account_signal_number;
		}

		char * get_user_name() const
		{
			return user_name;
		}


};

class NormalMember : public Member
{
	private:
		double interestRatio;
	public:
		NormalMember(char * sign_number, char * member, int money, double ratio)
			: Member(sign_number, member, money), interestRatio(ratio)
		{}

		NormalMember()
		{
			createBankAccount();
		}

		//overriding
		virtual void createBankAccount()
		{
			cout << "4. Interest ratio : ";
			cin >> interestRatio;
		}

		//overriding
		virtual bool input(int money)
		{
			if(money < 0) return false;

			int process = (int)(money * (1+interestRatio));
			Member::input(process);
			return true;
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

class HighCreditMember : public NormalMember
{
	private:
		double gradeCredit;
	public:
		HighCreditMember(char * sign_number, char * member, int money, double ratio, char grade) : NormalMember(sign_number, member, money, ratio)
	{
		switch(grade)
		{
			case 'A': gradeCredit = 0.07;
			case 'B': gradeCredit = 0.04;
			case 'C': gradeCredit = 0.02;
			default:
				  gradeCredit = 0.0;

		}
	}

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
