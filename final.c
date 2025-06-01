/*
    Assigned by:
    Itay Malka #ID 315402891
    Felix Melamed #ID 328652789
*/

#define _CRT_SECURE_NO_WARNINGS

/* Libraries */

#include <stdio.h>
#include <malloc.h>
#include <ctype.h>

/* Constant definitions */

#define N 3

/* Function declarations */

void Ex1();
void Ex2();
void Ex3();

char **split(char letter, char *str, int *p_size);
void createFile(char *filename);
char commonestLetter(char *filename);
void decode(char *text);

/* Declarations of auxiliary functions */

void printStringsArray(char **str_arr, int size);
void freeMatrix(void **A, int rows);

/* ------------------------------- */

int main()
{
    int select = 0, i, all_Ex_in_loop = 0;
    printf("Run menu once or cyclically?\n(Once - enter 0, cyclically - enter other number) ");
    if (scanf("%d", &all_Ex_in_loop) == 1)
        do
        {
            for (i = 1; i <= N; i++)
                printf("Ex%d--->%d\n", i, i);
            printf("EXIT-->0\n");
            do
            {
                select = 0;
                printf("please select 0-%d : ", N);
                scanf("%d", &select);
            } while ((select < 0) || (select > N));
            switch (select)
            {
            case 1:
                Ex1();
                break;
            case 2:
                Ex2();
                break;
            case 3:
                Ex3();
                break;
            }
        } while (all_Ex_in_loop && select);
    return 0;
}

/* Function definitions */

void Ex1()
{
    int size;
    char string[100];
    char letter ;

    printf("Please enter a letter to use for split:\n");
    rewind(stdin);
    letter = getchar();

    printf("Please enter a sentence to split:\n");
    rewind(stdin);
    gets(string);

    char **ress = split(letter, string, &size);

    printStringsArray(ress, size);
    freeMatrix(ress, size);
}

void Ex2()
{
    char path[100] = ".\\input.txt";
    createFile(path);
    char commonRes = commonestLetter(path);
    isalpha(commonRes) ? printf("Common charecter from file is %c.", commonRes) : printf("No letters found in file.");
}

void Ex3()
{
    char str[100] = "Btwlzx Dqqes Eq|pj2 Tjhvqujs Iqoqjy bpg Eqfxtx Xcwwtt";

    printf("the string : %s\n", str);
    decode(str);
    printf("the decoded massege : %s\n", str);
}

char **split(char letter, char *str, int *p_size)
{
    int count_siz = 0;
    int i = 0, j = 0;
    int start = 0, end = 0;
    if (tolower(str[i]) == tolower(letter))
    {
        count_siz++;
        i++;
    }
    while (str[i] != '\0')
    {

        if (tolower(str[i]) == tolower(letter))
        {
            if (str[i - 1] == ' ')
                count_siz++;
        }
        i++;
    }
    *p_size = count_siz;
    char **arr = (char **)malloc(sizeof(char *) * count_siz);
    i = 0;
    while (i < count_siz)
    {
        if ((start == 0 || str[start - 1] == ' ') && tolower(str[start]) == tolower(letter))
        {
            end = start;
            while (str[end] != ' ' && str[end] != '\0')
                end++;

            int size = end - start;
            arr[i] = (char *)malloc(sizeof(char) * (size + 1));
            for (j = 0; j < size; j++)
            {
                arr[i][j] = str[start++];
            }
            arr[i][j] = '\0';
            start = end;
            while (str[start] == ' ')
                start++;
            size = 0;
            i++;
        }
        else
        {
            start++;
        }
    }

    return arr;
}

void createFile(char *filename)
{
    FILE *file = fopen(filename, "w"); // Open the file for writing
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    printf("Enter text to write to the file (press Ctrl+Z to end input):\n");

    char ch;
    while ((ch = getchar()) != EOF)
    {
        fputc(ch, file); // Write character to the file
    }

    fclose(file); // Close the file
    printf("File written successfully.\n");
}
char commonestLetter(char *filename)
{
    int lettersCount[26] = {0};
    char c;
    int max_index = -1;
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return 0;
    }
    while ((c = fgetc(file)) != EOF)
    {
        if (isalpha(c))
            lettersCount[toupper(c) - 'A']++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (lettersCount[i] != 0 && lettersCount[i] >= lettersCount[max_index])
            max_index = i;
    }
    fclose(file);
    return 'A' + max_index;
}

void decode(char *text)
{
    int i = 0, k = 1;
    while (text[i] != '\0')
    {
        if (text[i] != ' ')
            text[i] -= k;
        else
            k = 0;
        i++;
        k++;
    }
}

/* Definitions of auxiliary functions */

void printStringsArray(char **str_arr, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%s\n", str_arr[i]);
    }
}

void freeMatrix(void **A, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        free(A[i]);
    }
    free(A);
}

/* ------------------- */