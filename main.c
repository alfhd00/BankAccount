#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Member.h"

int count = 0;

int main(void)
{
	short choice = 1;
	Member * members = (Member *)malloc(sizeof(Member)*20);
	//Member members[20];

	while(choice != 5)
	{
		printf("----------MENU-----------\n");
		printf("1. create an acoount\n");
		printf("2. input money\n");
		printf("3. output money\n");
		printf("4. print all memebers info\n");
		printf("5. terminate service\n");


		printf("\nchoice : ");
		scanf("%d", &choice);

		switch(choice)
		{
		case 1:
			createBankAccount(members);
			break;
		case 2:
			input(members);
			break;
		case 3:
			output(members);
			break;
		case 4:
			printAllMemberInfo(members);
			break;
		case 5:
			free(members);
			printf("service terminate\n");
			break;
		}
	}
}

