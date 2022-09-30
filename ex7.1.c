//author: Shira Cohen  ID:211777834

#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#define N 10
#define M 5

void polynom(int one[], int two[], int sizeOne, int sizeTwo)//function 1
{
	int i, j;
	long sum = 0;
	for (i = 0; i < sizeTwo; i++)
	{
		for (j = 0; j < sizeOne; j++)
		{
			sum += one[j] * (two[i] ^ j);

		}

		printf("The value of the polynom for x= %d  is %d", two[i], sum);
		sum = 0;
	}

}

int SubArr(int arr1[], int arr2[], int size1, int size2)//function 2
{
	int i, j, counter = 0;
	for (i = 0; i < size1; i++)
	{
		if (arr2[0] == arr1[i])
		{
			for (j = 1; j < size2; j++)
			{
				if (arr2[j] == arr1[i + j])
					counter++;
			}
		}

		if (counter == size2 - 1)
			return i;
		return -1;
	}

}


int seriesOfNumbers(int arr[], int size)
{
	int seriesCounter = 0;//counting number of series
	int index = 0, max = 0, maxLength = 0, length = 0, stop = 0, j = 0;
	int i = 0;
	for (i = 0; i < size; ++i)//runnig on the array
	{
		if (arr[i + 1] > arr[i])//If a sequence exists
		{
			index++;
			if (index > max)
			{
				max = index;//Maximum sequence length
				stop = length;//Index where the sequence was interrupted
			}

		}
		else//sequence was interrupted
		{
			if (index > 0)//Increase the number of sequences
				seriesCounter++;
			length = i + 1;//Go to the next index
			index = 0;
			j = 0;

		}

	}
	for (j = stop; j < size; j++)//Print the maximum sequence
		if (arr[j] < arr[j + 1])
			printf("%d ", arr[j]);
		else
			break;
	printf("%d", arr[j]);

	return seriesCounter;//return number of series

}



int main()
{
	int One[N], Two[M], menu, result = 0;
	printf("Please choose a functions:\n1-Polynom.\n2-Sub Array.\n3-Series.\n");
	scanf_s("%d", &menu);
	while (menu < 1 || menu > 3)
	{
		printf("Error! Please choose only number between 1-3 is allowed.\nPlease choose a functions:\n1-Polynom.\n2-Sub Array.\n3- \n");
		scanf_s("%d", &menu);
	}
	printf("Enter numbers for first array:\n");
	for (int i = 0; i < N; i++)
	{
		printf("a1,%d= ", i);
		scanf_s("%d", &One[i]);
	}
	if (menu != 3)
	{
		printf("Enter numbers for second array:\n");
		for (int j = 0; j < M; j++)
		{
			printf("a2,%d= ", j);
			scanf_s("%d", &Two[j]);
		}
	}
	switch (menu)
	{
	case 1:
	{
		polynom(One, Two, N, M);
		break;
	}
	case 2:
	{
		result = SubArr(One, Two, N, M);
		if (result != -1)
			printf("The sub-array starts at index %d.\n", result);
		else
			printf("The sub-array is not contained in the array.\n");
		break;
	}
	case 3:
	{
		int number = 0;
		number = seriesOfNumbers(One, N);
		break;
	}
	}
}
