#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define N 80


int min(int num1, int num2)
{
	if (num1 > num2)
		return num2;
	else
		return num1;
}
int stringLength(char str[])
{
	int count = 0, i = 0;
	while (str[i])
	{
		count++;
		i++;
	}
	return count;
}
double pow(int base, int exp)
{
	double result = 1;
	int i;
	if (exp > 0)
	{
		for (i = 0; i < exp; i++)
		{
			result *= base;
		}
		return result;
	}
	else if (exp < 0)
	{
		exp *= -1;
		for (i = 0; i < exp; i++)
		{
			result /= base;
		}
		return result;
	}
	else
	{
		return 1;

	}
}

double charToNum(char c) {//הפיכת תו למספר
	return c - '0';
}
int indexOfDot(char str[], int start, int end)
{//מיקום נקודה אם קיים נשלח האינדקס
	int i;
	for (i = start; i <= end; i++) {
		if (str[i] == '.')
			return i;
	}
	return -1;
}

int indexOfOperation(char str[])// האינדקס של הפעולה החשבונית
{
	int i;
	for (i = 0; stringLength(str); i++)
		if (str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '*')
			return i;
	return -1;
}



double stringToNum(char str[], int start, int end)
{//הפיכת מחרוזת למספר
	int dot = indexOfDot(str, start, end);
	double num = 0;
	int deg = 0, i;
	if (dot != -1)
	{
		for (i = dot - 1; i >= start; i--)
		{
			num += charToNum(str[i]) * pow(10, deg);
			deg++;
		}
		deg = -1;
		for (i = dot + 1; i <= end; i++)
		{
			num += charToNum(str[i]) * pow(10, deg);
			deg--;
		}
	}
	else
	{
		for (i = end; i >= start; i--)
		{
			num += charToNum(str[i]) * pow(10, deg);
			deg++;
		}
	}
	return num;
}

int digitsAfterDot(char str[], int start, int end)
{
	int dot = indexOfDot(str, start, end);// האינדקס של הנקודה
	if (dot == -1)
		return 0;
	return end - dot;
}
double calculate(double num1, double num2, char oper)
{//החישוב עצמו
	switch (oper)
	{
	case '+':
		return num1 + num2;
	case '-':
		return num1 - num2;
	case '*':
		return num1 * num2;
	case '/':
		return num1 / num2;
	default:
		return 0;
	}
}

void Calculator(char str[])
{
	int len = stringLength(str);// האורך של המחרוזת
	int operation = indexOfOperation(str);// האינדקס של הפעולה החשבונית
	char oper = str[operation];
	int start1 = 0, start2 = operation + 1, end1 = operation - 1, end2 = len - 1;//נק התחלה וסיום של כל מספר


	double num1 = stringToNum(str, start1, end1);
	double num2 = stringToNum(str, start2, end2);
	double result = calculate(num1, num2, oper);
	int num1DigitsAfterDot = digitsAfterDot(str, start1, end1);
	int num2DigitsAfterDot = digitsAfterDot(str, start2, end2);
	int digits;
	if (num1DigitsAfterDot == num2DigitsAfterDot && num1DigitsAfterDot == 0)
	{
		digits = 0;
	}
	else if (num1DigitsAfterDot == 0)
	{
		digits = num2DigitsAfterDot;
	}
	else if (num2DigitsAfterDot == 0)
	{
		digits = num1DigitsAfterDot;
	}
	else
	{
		digits = min(num1DigitsAfterDot, num2DigitsAfterDot);
	}
	printf("result: %.*lf", digits, result);//אופציית הדפסה לפי נק דיוק כמה להדפיס לאחר הנקודה

}

void WroteEncrypted(char String[N])
{
	int i, counter = 1;
	char TransStr[N] = { '0' };

	for (i = 0; String[i] != '\0'; i++)
	{
		if (String[i] != ' ')//כל עוד אין רווח
		{
			TransStr[i] = String[i] - counter;
			counter++;
		}

		else if (String[i] == ' ')// אם יש רווח
		{
			TransStr[i] = String[i];
			counter = 1;
		}

	}
	printf("\n%s", TransStr);
}


int main()
{
	char string[N], str[N];
	printf("please enter two numbers and mathematical expression\n");
	gets_s(string, N);
	Calculator(string);
	printf("\nplease enter Encrypted expression \n");
	gets_s(str, N);
	WroteEncrypted(str);
	return 0;
}


