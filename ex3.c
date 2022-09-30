//author: Shira Cohen  ID:211777834

#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>


int main()
{
	int Products;
	printf("enter amount of products between 0-3: \n");
	scanf("%d", &Products);
	float price1, price2, price3;




	switch (Products)
	{
	case 1:


		printf("Input one price: \n");
		scanf("%f", &price1);
		printf("total price is:   %.2f", price1);
		break;


	case 2:


		printf("Input two prices: \n");
		scanf("%f%f", &price1, &price2);

		if (price1 < price2)
			printf("total price is:   %.2f", (price1 * 0.7 + price2));
		else if (price1 > price2)
			printf("total price is:   %.2f", (price2 * 0.7 + price1));
		break;


	case 3:

		printf("input three prices: \n");
		scanf("%f%f%f", &price1, &price2, &price3);

		if (price1 < price2 && price1 < price3 && price2 < price3)// המחיר הראשון הזול ביותר ואחריו המחיר השני
			printf(" total price is:   %.2f", (price1 * 0.5 + price2 * 0.8 + price3));
		else if (price1 < price2 && price1 < price3 && price2 > price3)// המחיר הראשון הזול ביותר ואחריו המחיר השלישי
			printf(" total price is:   %.2f", (price1 * 0.5 + price3 * 0.8 + price2));
		else if (price2 < price1 && price2 < price3 && price1 < price3)// המחיר השני הזול ביותר ואחריו המחיר הראשון
			printf(" total price is:   %.2f", (price2 * 0.5 + price1 * 0.8 + price3));
		else if (price2 < price1 && price2 < price3 && price1 > price3)// המחיר השני הזול ביותר ואחריו המחיר השלישי
			printf(" total price is:   %.2f", (price2 * 0.5 + price3 * 0.8 + price2));
		else if (price3 < price1 && price3 < price2 && price1 < price2)// המחיר השלישי הזול ביותר ואחריו המחיר הראשון
			printf(" total price is:   %.2f", (price3 * 0.5 + price1 * 0.8 + price2));
		else if (price3 < price1 && price3 < price2 && price1 > price2)// המחיר השלישי הזול ביותר ואחריו המחיר השני
			printf(" total price is:   %.2f", (price3 * 0.5 + price2 * 0.8 + price1));
		break;


	}

	return 0;
}
