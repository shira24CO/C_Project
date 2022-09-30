//author: Shira Cohen  ID:211777834
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 10

void wordFrequency(char** words, int countWords);
char** textPreprocessing(char** text, int* countWords, char** stopwords, int countStopwords);

int main()
{
    int i, countWords, countStopWords;
    char** words = NULL, ** stopwords = NULL, ** text = NULL;
    char word[MAX];



    printf("Enter how many words:\n");
    scanf("%d", &countWords);
    getchar();

    words = (char*)malloc(countWords * sizeof(char));
    if (words == NULL)
    {
        printf("ERROR\n");
        exit(1);
    }

    printf("Enter words to array:\n");
    for (i = 0; i < countWords; i++)
    {
        scanf("%s", word);
        words[i] = (char*)malloc((strlen(word) + 1) * sizeof(char));

        if (words[i] == NULL)
        {
            printf("ERROR\n");
            exit(1);
        }
        strcpy(words[i], word);
    }


    printf("Enter how many stop words:\n");
    scanf("%d", &countStopWords);
    getchar();

    stopwords = (char*)malloc(countStopWords * sizeof(char));
    if (stopwords == NULL)
    {
        exit(1);
    }

    printf("Enter stopwords to array:\n");
    for (i = 0; i < countStopWords; i++)
    {
        scanf("%s", word);
        stopwords[i] = (char*)malloc((strlen(word) + 1) * sizeof(char));

        if (stopwords[i] == NULL)
        {
            printf("ERROR\n");
            exit(1);
        }
        strcpy(stopwords[i], word);
    }



    text = textPreprocessing(words, &countWords, stopwords, countStopWords);

    if (words == NULL)
    {
        printf("ERROR\n");
        exit(1);
    }

    printf("Text after update:\n");
    for (i = 0; i < countWords; i++)
    {
        printf("%s\n", words[i]);
    }
    printf("\n");

    printf("The word frequency is:\n");
    wordFrequency(words, countWords);


    for (i = 0; i < countWords; i++)
    {
        free(words[i]);
    }
    free(words);
    for (i = 0; i < countStopWords; i++)
    {
        free(stopwords[i]);
    }
    free(stopwords);
    return 0;

}

void wordFrequency(char** words, int countWords)
{
    int count = 0;
    char* word = NULL;
    int* correct = (int*)malloc(countWords * sizeof(int));

    if (correct == NULL)
    {
        exit(1);
    }



    for (int i = 0; i < countWords; i++)
        correct[i] = 1;
    for (int i = 0; i < countWords; i++)
    {
        word = (char*)malloc((strlen(words[i]) + 1) * sizeof(char));

        if (word == NULL)
        {
            exit(1);
        }

        strcpy(word, words[i]);
        for (int j = 0; j < countWords; j++)
        {
            if (strcmp(word, words[j]) == 0 && correct[j])
            {
                correct[j] = 0;
                count++;
            }
        }
        if (count != 0)
        {
            printf("%s: %d\n", word, count);
            count = 0;
        }
    }
}


char** textPreprocessing(char** text, int* countWords, char** stopwords, int countStopwords)
{
    int i, j, k;
    char** storage = NULL;


    for (i = 0; i < *countWords; i++)
    {
        for (j = 0; text[i][j] != '\0'; j++) // scan for big letters to convert them to small letters.
        {
            if (text[i][j] >= 'A' && text[i][j] <= 'Z')
            {
                text[i][j] = text[i][j] - 'A' + 'a';
            }
            if (text[i][j] >= '0' && text[i][j] <= '9') // scan for numbers in array and erase them.
            {
                {
                    for (k = i; k < *countWords; k++)
                    {
                        text[k] = NULL;
                        text[k] = text[k + 1];
                    }

                    text[k] = NULL;
                    *countWords -= 1;
                    j = -1;
                }
            }
        }
    }



    for (i = 0; i < *countWords; i++)
    {
        for (j = 0; j < countStopwords; j++)
        {
            if (strcmp(text[i], stopwords[j]) == 0)
            {
                for (k = i; k < *countWords; k++)
                {
                    text[k] = NULL;
                    text[k] = text[k + 1];
                }
                text[k] = NULL;
                *countWords -= 1;
                storage = (char*)realloc(text, *countWords * sizeof(char));

                if (storage == NULL)
                {
                    return NULL;
                }
                else
                    text = storage;
                j = -1;
            }
        }
    }

    return text;
}
