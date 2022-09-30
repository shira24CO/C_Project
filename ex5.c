//author: Shira Cohen  ID:211777834

#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main()
{
	int number1, number2, number3, number4, number5;
	int moneOdd = 0;
	int moneEven = 0;
	double averageOdd = 0;
	double averageEven = 0;
	printf("input five numbers \n");
	scanf("%d%d%d%d%d", &number1, &number2, &number3, &number4, &number5);
	if (number1 % 2 == 0)
	{
		averageEven += number1;
		moneEven++;

	}
	else
	{
		averageOdd += number1;
		moneOdd++;

	}

	if (number2 % 2 == 0)
	{
		averageEven += number2;
		moneEven++;

	}
	else
	{
		averageOdd += number2;
		moneOdd++;
	}

	if (number3 % 2 == 0)
	{
		averageEven += number3;
		moneEven++;

	}
	else
	{
		averageOdd += number3;
		moneOdd++;
	}

	if (number4 % 2 == 0)
	{
		averageEven += number4;
		moneEven++;

	}
	else
	{
		averageOdd += number4;
		moneOdd++;
	}

	if (number5 % 2 == 0)
	{
		averageEven += number5;
		moneEven++;

	}
	else
	{
		averageOdd += number5;
		moneOdd++;
	}

	if (moneEven == 0) printf("No even numbers \n");
	else printf("\nThe average of the even numbers is %lf", (averageEven / moneEven));
	if (moneOdd == 0) printf("No odd numbers \n");
	else printf("\nThe average of the odd numbers is %lf", (averageOdd / moneOdd));
	return 0;
}



