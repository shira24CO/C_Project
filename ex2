//author: Shira Cohen

#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main()
{
	double number1, number2;
	printf("enter a double number one: \n");
	scanf("%lf", &number1);
	printf("enter a double number two:  \n");
	scanf("%lf", &number2);
	if (number1 < 0 || number2 < 0)
		printf("eror");
	else
		if (number1 - ((int)number1 % 10) > number2 - ((int)number2 % 10))
			printf("%lf", number1);
		else
			if (number1 - ((int)number1 % 10) < number2 - ((int)number2 % 10))
				printf("%lf", number2);
	return 0;
}
