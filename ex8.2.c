//author: Shira Cohen  ID:211777834
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>


int* symmetricDiff(int* one, int sizeOne, int* two, int sizeTwo, int* pNewSize)
{
	int* newString = NULL;
	int flag = 0;
	int counter = 0, index = 0;
	for (int i = 0; i < sizeOne; i++)
	{
		flag = 0;
		for (int j = 0; j < sizeTwo; j++)
		{
			if (one[i] == two[j])  //אם הם שווים אני לא רוצה אותו
				flag = 1;
		}
		if (flag == 0)  //אם הפלאג נשאר אפס סימן שהמספרים לא היו שווים,לכן אקצה לו מקום ואדפיס אותו
		{
			(*pNewSize)++;
			newString = (int*)realloc(newString, (*pNewSize) * sizeof(int));
			if (newString == NULL)
			{
				printf("error");
				return 0;
			}
			newString[index] = one[i];
			index++;
		}
	}
	for (int i = 0; i < sizeTwo; i++)
	{
		flag = 0;
		for (int j = 0; j < sizeOne; j++)
		{
			if (two[i] == one[j])  //אם הם שווים אני לא רוצה אותו
				flag = 1;
		}
		if (flag == 0)  //אם הפלאג נשאר אפס סימן שהמספרים לא היו שווים,לכן אקצה לו מקום ואדפיס אותו
		{
			(*pNewSize)++;
			newString = (int*)realloc(newString, (*pNewSize) * sizeof(int));
			if (newString == NULL)
			{
				printf("error");
				return 0;
			}
			newString[index] = two[i];
			index++;
		}
	}
	return newString;
}

int main()
{
	int i, sizeOne, sizeTwo;
	int* one = NULL;
	int* two = NULL;
	int pNewSize = 0;
	int* res = NULL;
	printf("Enter the size of the first array: ");
	scanf("%d", &sizeOne);
	printf("Enter the size of the second array: ");
	scanf("%d", &sizeTwo);
	one = (int*)malloc(sizeOne * sizeof(int));
	two = (int*)malloc(sizeTwo * sizeof(int));
	if (one == NULL || two == NULL)
	{
		printf("error");
		return 0;
	}
	printf("Enter %d numbers of the first array.\n", sizeOne);
	for (i = 0; i < sizeOne; i++)
	{
		printf("%d =>  ", i + 1);
		scanf("%d", one + i);
	}
	printf("Enter %d numbers of the second array.\n", sizeTwo);
	for (i = 0; i < sizeTwo; i++)
	{
		printf("%d =>  ", i + 1);
		scanf("%d", two + i);
	}
	res = symmetricDiff(one, sizeOne, two, sizeTwo, &pNewSize);
	if (res != 0)
	{
		printf("\nThe symmetrical relation: ");
		for (i = 0; i < pNewSize; i++)
		{
			printf("%d ,", res[i]);
		}
	}
	else
		printf("\nThe symmetrical relation is empty");
	free(one);
	free(two);
	free(res);
	return 0;
}
