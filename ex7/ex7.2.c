/// author: Shira Cohen  ID : 211777834

#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
typedef int bool;
#define true 1
#define false 0

void  multiplesAndDivisors(int arr[4][4], int row, int column)  //function 4
{
    int counterMultiples = 0, counterDivisors = 0;

    while (column < 0 || column>3)
    {
        printf("Invalid column index, try again!");
        scanf_s("enter a column between 0-3 %d", &column);
    }
    while (row < 0 || row>3)
    {
        printf("Invalid row index, try again!");
        scanf_s("enter a row between 0-3 %d", &row);
    }
    int num = arr[row][column];

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (num % arr[i][j] == 0)
                counterDivisors++;
            if (arr[i][j] % num == 0)
                counterMultiples++;

        }
    }

    printf("Number of multiples: %d\n", counterMultiples);
    printf("Number of divisors: %d", counterDivisors);
}

void findLargestSymmetricMatrix(int matr[][8]) //function 5
{
    int largestSymmetricMatrix = 0;//גודל התת מטריצה המקסימאלית
    int iSymmetric = 0;
    int jSymmetric = 0;

    for (int matrixSize = 1; matrixSize <= 5; matrixSize++)
    {

        for (int startingRow = 0; startingRow + matrixSize <= 5; startingRow++)
        {
            for (int startingCol = 0; startingCol + matrixSize <= 8; startingCol++)
            {

                int tempMatrix[5][5];
                bool isSymmteric = true;
                for (int i = startingRow, iTempMatrix = 0; i < startingRow + matrixSize && i < 5; i++, iTempMatrix++)
                {
                    for (int j = startingCol, jTempMatrix = 0; j < startingCol + matrixSize && j < 8; j++, jTempMatrix++)
                    {
                        tempMatrix[iTempMatrix][jTempMatrix] = matr[i][j];
                    }

                }

                for (int a = 0; a < matrixSize; a++)
                {
                    for (int b = 0; b < matrixSize; b++)
                    {
                        if (tempMatrix[a][b] != tempMatrix[b][a])
                        {

                            isSymmteric = false;
                        }
                    }

                }
                if (isSymmteric)
                {

                    if (matrixSize > largestSymmetricMatrix)
                    {
                        largestSymmetricMatrix = matrixSize;
                        iSymmetric = startingRow;
                        jSymmetric = startingCol;
                    }
                }
            }

        }

    }

    printf("The Max symmetric sub-matrix starts at indeces [%d][%d] and its size is %d x %d \n",
        iSymmetric, jSymmetric, largestSymmetricMatrix, largestSymmetricMatrix);

}

int main()
{
    // int matr[5][8] = {
   //     { 1, 2, 0, 3, 2, 1, 0, 7 },
   //     { 2, 3, 4, 1, 2, 3, 4, 5 },
   //     { 3, 4, 6, 2, 5, 6, 7, 6 },
   //     { 4, 5, 7, 3, 6, 8, 9, 8 },
   //     { 6, 7, 1, 4, 7, 9, 0, 9 }
   // };   

    int matr1[4][4];
    int matr2[5][8];

    printf("Please enter matrix #1: ");
    for (int i = 0; i < 4; i++)
    {
        printf("\nRow #%d: ", i + 1);
        for (int j = 0; j < 4; j++)
        {
            printf("\nColumn #%d: ", j + 1);
            scanf("%d", &matr1[i][j]);

        }
    }



    printf("Please enter matrix #2: ");
    for (int i = 0; i < 5; i++) {
        printf("\nRow #%d:", i + 1);
        for (int j = 0; j < 8; j++) {
            printf("\nColumn #%d: ", j + 1);
            scanf("%d", &matr2[i][j]);
        }
    }


    printf("\n");
    int row, column;
    printf(" enter row : ");
    scanf("%d", &row);
    printf(" enter column: ");
    scanf("%d", &column);
    multiplesAndDivisors(matr1, row, column);
    findLargestSymmetricMatrix(matr2);
    return 0;
}
