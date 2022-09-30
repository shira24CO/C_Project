//author: Shira Cohen  ID:211777834



#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


void theThreeMaxNumber() //#Function 1
{
    int firstMax, secondMax, number, thirdMax, number2;

    printf("Enter  a first positive number: \n ");
    scanf_s("%d", &firstMax);
    printf("Enter a second positive number: \n ");
    scanf_s("%d", &secondMax);

    if (firstMax < secondMax)
    {
        number = firstMax;
        firstMax = secondMax;
        secondMax = number;
    }

    printf("Enter a third positive number: \n ");
    scanf_s("%d", &thirdMax);

    if (firstMax < thirdMax)
    {
        number = firstMax;
        firstMax = thirdMax;
        thirdMax = secondMax;
        secondMax = number;
    }
    else if (secondMax < thirdMax)
    {
        number = secondMax;
        secondMax = thirdMax;
        thirdMax = number;

    }

    printf("Enter  a first positive number: \n ");
    scanf_s("%d", &number2);

    while (number2 >= 0)
    {
        if (number2 > firstMax)
        {
            number = firstMax;
            firstMax = number2;
            thirdMax = secondMax;
            secondMax = number;

        }

        else if (number2 > secondMax)
        {
            number = secondMax;
            secondMax = number2;
            thirdMax = number;

        }

        else if (number2 > thirdMax)
            thirdMax = number2;

        printf("Enter  a first positive number: \n ");
        scanf_s("%d", &number2);
    }
    printf("the first maximali number is:%d \n", firstMax);
    printf("the second maximali number is:%d \n ", secondMax);
    printf("the third maximali number is:%d \n ", thirdMax);
}

void isPrime(int number)//#Function 2
{
    int i, j, counter = 0;
    for (j = number; j > 0; j--)
    {
        if (number % j == 0)
            counter++;
    }
    if (counter == 2)
        printf("%d is prime", number);
    else
    {
        for (i = 2; number > 1; i++)
        {
            if (number % i == 0)
            {
                number /= i;
                if (number == 1)
                    printf("%d", i);
                else
                {
                    printf("%d*", i);
                    i = 1;
                }
            }

        }

    }
}

int isProperId(int id)//#Function 3
{
    int j, counter = 0, length = 0, sum = 0, copyId = id;
    while (copyId != 0)
    {
        length++;
        copyId /= 10;
    }
    if (length != 9)
        return 0;
    else
    {
        for (j = 9; j >= 1; j--, id /= 10)
        {
            if (j % 2 != 0)
                sum += (id % 10);
            else
            {
                if (id % 10 == 5)
                    sum += 1;
                if (id % 10 == 6)
                    sum += 3;
                if (id % 10 == 7)
                    sum += 5;
                if (id % 10 == 8)
                    sum += 7;
                if (id % 10 == 9)
                    sum += 9;
            }
        }
        if (sum % 10 == 0)
            return 1;
        else
            return 0;
    }
}

void drawDiamond(int number)//#Function 4
{

    int i, j;
    for (i = 1; i <= number * 2; i++)
    {
        for (j = 1; j <= number * 2; j++)
        {
            if (number % 2 == 0)
            {
                if (i <= number)
                    if (i + number == j)
                        printf("\\");
                    else if (j + i == number + 1)
                        printf("/");
                    else
                        printf(" ");
                else
                    if (i - j == number)
                        printf("\\");
                    else if (i + j == (number * 3) + 1)
                        printf("/");
                    else
                        printf(" ");
            }
            else
            {
                if (i <= number)
                    if (i + j == number + 1)
                        printf("/");
                    else if (j - i == number)
                        printf("\\");
                    else
                        printf(" ");
                else
                    if (i - j == number)
                        printf("\\");
                    else if (i + j == (number * 3) + 1)
                        printf("/");
                    else
                        printf(" ");
            }
        }
        printf("\n");
    }
    printf("\n");
}


int addingNumbers(int number1, int number2)//#Function 5
{

    int counter2 = 0;
    int num2 = number2;


    while (num2 != 0)
    {
        counter2++;
        num2 /= 10;
    }

    for (int i = 0; i < counter2; i++)
    {
        number1 *= 10;
    }

    return (number1 + number2);
}

int main()                                 //The main function of the program
{
    int choice;
    int number;  //for case 2
    int id; //for case 3
    int num;  //for case 4
    int number1, number2; //for case 5

    do       //the do while loop for checking the the numbers the user typed in the menu
    {
        printf("Choose one of the following options:\n");
        printf("1-Third\n");
        printf("2-Primes\n");
        printf("3-ID\n");
        printf("4-Diamond\n");
        printf("5-Compose\n");
        printf("6-Quit\n");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            theThreeMaxNumber();
            break;
        case 2:
            printf("Enter a number:\n");
            scanf("%d", &number);
            isPrime(number);

            break;

        case 3:
            printf("input id:\n");
            scanf("%d", &id);
            if (isProperId(id) == 0)
                printf("Invalid ID \n");
            else if (isProperId(id) == 1)
                printf("Proper ID \n");

            break;

        case 4:
            printf("Enter integer number");
            scanf("%d", &num);
            if (num >= 1 && num <= 10)
                drawDiamond(num);
            else printf("EROR");


            break;

        case 5:
            printf("Enter integer number");
            scanf("%d", &number1);
            printf("Enter integer number");
            scanf("%d", &number2);
            printf("%d", addingNumbers(number1, number2));
            break;

        case 6:               //Exit the program
            printf("Bye Bye\n");
            break;

        default:          //Error Message
            printf("EROOR! The number you selected is incorrect!\n");
        }

    } while (choice >= 1 && choice <= 5);  //As long as the user has entered a correct number, the loop continues repeatedly.

    return 0;
}
