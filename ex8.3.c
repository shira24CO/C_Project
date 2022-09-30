//author: Shira Cohen  ID:211777834
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>


int** BuildMatrix(int* pRow, int* pColumn)
{
	int i, j, ** matrix;

	printf("Enter size of rows: ");
	scanf("%d", pRow);
	printf("Enter size of column: ");
	scanf("%d", pColumn);
	matrix = (int**)malloc(*pRow * sizeof(int*));
	if (matrix == NULL)
		return 0;
	for (i = 0; i < *pRow; i++)
	{
		matrix[i] = (int*)malloc(*pColumn * sizeof(int*));
		if (matrix[i] == NULL)
			return 0;
	}
	printf("enter a matrix\n");
	for (i = 0; i < *pRow; i++)
	{
		for (j = 0; j < *pColumn; j++)
		{
			scanf("%d", &matrix[i][j]);
		}
	}
	return matrix;
}


void PrintMatrix(int** matrix, int row, int column) // פונקצית הדפסה למטריצה
{
	int i, j;
	printf("The matrix is: \n");
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < column; ++j)
		{
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}
}

int** TransposeMatrix(int** matrix, int row, int col)
{
	int** newMatrix, i, j;
	newMatrix = (int**)malloc(col * sizeof(int*));
	if (newMatrix == NULL)
		return 0;
	for (i = 0; i < col; i++)
	{
		newMatrix[i] = (int*)malloc(row * sizeof(int));
		if (newMatrix == NULL)
			return 0;
	}
	for (i = 0; i < col; i++)
	{
		for (j = 0; j < row; j++)
			newMatrix[i][j] = matrix[j][i];
	}
	return newMatrix;
}

int main()
{
	int** arr, row = 0, column = 0, ** transposArr, i, j;
	arr = BuildMatrix(&row, &column);
	PrintMatrix(arr, row, column);
	transposArr = TransposeMatrix(arr, row, column);
	PrintMatrix(transposArr, column, row);
	free(arr);
	free(transposArr);
	
	return 0;

}


