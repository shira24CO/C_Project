//author: Shira Cohen  ID:211777834

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>
#define MAX 50

char* newString(char* str)
{
	char* newstring = NULL;
	int sizeStr = strlen(str);
	newstring = (char*)malloc(MAX * sizeof(char));
	int i, x;
	if (newstring == NULL)
	{
		printf("ERROR. \n");
		return 0;

	}

	for (i = 0, x = 0; i < strlen(str); x++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			for (int j = 0; j < str[i] - '0'; j++, x++)
				newstring[x] = str[i];
			i++, x--;
		}

		else if (str[i] >= 'a' && str[i] <= 'z')
		{
			while (str[i] >= 'a' && str[i] <= 'z')
				i++;
			newstring[x] = '*';
		}

		else if (str[i] == ' ')
		{
			while (str[i] == ' ')
				i++;
			newstring[x] = '-';
		}

	}

	for (i = x; i < MAX; i++)
	{
		newstring[i] = 0;

	}

	strcpy(str, newstring);
	free(newstring);
	return str;
}

int main()
{
	char* str = NULL;
	str = (char*)malloc(MAX * sizeof(char));
	if (str == NULL)
	{
		printf("ERROR. \n");
		return 0;

	}

	printf("Enter somthing please: ");
	gets_s(str, MAX);
	printf("\n%s\n", newString(str));

}
