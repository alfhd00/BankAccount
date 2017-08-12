#include "Member.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


extern int count;

void createBankAccount(Member members[])
{
	Member newMember;
	printf("[계좌 개설]\n");

	printf("Account id : ");
	scanf("%s", newMember.bankNumber);

	printf("User name : ");
	scanf("%s", newMember.userName);

	printf("input : ");
	scanf("%d", &newMember.account);

	//copy member info
	strcpy(members[count].bankNumber, newMember.bankNumber);
	strcpy(members[count].userName, newMember.userName);
	members[count++]].account = newMember.account;

	//printf("success function\n");
}

void input(Member members[])
{
	char bankNumber[15];
	int inputMoney = 0;

	printf("Account id : ");
	scanf("%s", bankNumber);

	printf("input : ");
	scanf("%d", &inputMoney);

	for(int i=0; i<count; i++)
	{
		if(strcmp(bankNumber, members[i].bankNumber) == 0)
		{
			members[i].account += inputMoney;
			break;
		}
	}

}

void output(Member members[])
{
	char bankNumber[15];
	int outputMoney = 0;

	printf("Account id : ");
	scanf("%s", bankNumber);

	printf("output : ");
	scanf("%d", &outputMoney);

	for(int i=0; i<count; i++)
	{
		if(strcmp(bankNumber, members[i].bankNumber) == 0)
		{
			members[i].account -= outputMoney;
			break;
		}
	}

}

void printAllMemberInfo(Member members[])
{
	for(int i=0; i<count; i++)
	{
		printf("Account id : %s\n", members[i].bankNumber);
		printf("User name : %s\n", members[i].userName);
		printf("Account : %d\n", members[i].account);

		printf("\n");
	}
}
