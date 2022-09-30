//author: Shira Cohen  ID:211777834

#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main()
{
	int number;
	printf("Enter a 5-digit number : \n");
	scanf("%d", &number);
	if (number > 9999 && number < 100000)
	{
		if (number % 10 % 2 == 0 && number / 10 % 10 % 2 == 1 && number / 100 % 10 % 2 == 0 && number / 1000 % 10 % 2 == 1 && number / 10000 % 2 == 0)
			printf("Altenate");
		else if (number % 10 % 2 == 1 && number / 10 % 10 % 2 == 0 && number / 100 % 10 % 2 == 1 && number / 1000 % 10 % 2 == 0 && number / 10000 % 2 == 1)
			printf("Altenate");
		else printf("Not Altenate");
	}
	else printf("Eror");
	return 0;
}
