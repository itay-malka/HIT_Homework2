/*
    Assigned by:
    Itay Malka #ID 315402891
    Felix Melamed #ID 328652789
*/

#define _CRT_SECURE_NO_WARNINGS 

/* Libraries */

#include <stdio.h>
#include <malloc.h>
#include <ctype.h>      // Character handling functions (e.g., isalpha, toupper)

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
    char letter;

    printf("Please enter a letter to use for split:\n");
    rewind(stdin);  // Clear input buffer
    letter = getchar();

    printf("Please enter a sentence to split:\n");
    rewind(stdin);
    gets(string);  // Read input sentence

    // Split words and print result
    char **ress = split(letter, string, &size);
    printStringsArray(ress, size);
    freeMatrix(ress, size);
}

/* -------------------------------
   Exercise 2:
   Create a file from user input and find the most common letter.
---------------------------------*/
void Ex2()
{
    char path[100] = ".\\input.txt";
    createFile(path);  // Create file with user input
    char commonRes = commonestLetter(path);  // Find commonest letter
    isalpha(commonRes) ? printf("Common charecter from file is %c.", commonRes) : printf("No letters found in file.");
}

/* -------------------------------
   Exercise 3:
   Decode a simple encrypted string.
---------------------------------*/
void Ex3()
{
    char str[100] = "Btwlzx Dqqes Eq|pj2 Tjhvqujs Iqoqjy bpg Eqfxtx Xcwwtt";

    printf("the string : %s\n", str);
    decode(str);  // Decode message
    printf("the decoded massege : %s\n", str);
}

/* -------------------------------
   Splits the string into an array of words starting with the given letter.
---------------------------------*/
char **split(char letter, char *str, int *p_size)
{
    int count_siz = 0;
    int i = 0, j = 0;
    int start = 0, end = 0;

    // Count number of words that start with the given letter (case-insensitive)
    if (tolower(str[i]) == tolower(letter))
    {
        count_siz++;
        i++;
    }
    while (str[i] != '\0')
    {
        if (tolower(str[i]) == tolower(letter) && str[i - 1] == ' ')
            count_siz++;
        i++;
    }

    *p_size = count_siz;
    char **arr = (char **)malloc(sizeof(char *) * count_siz);  // Allocate array of string pointers

    i = 0;
    while (i < count_siz)
    {
        if ((start == 0 || str[start - 1] == ' ') && tolower(str[start]) == tolower(letter))
        {
            end = start;
            // Find end of the word
            while (str[end] != ' ' && str[end] != '\0')
                end++;

            int size = end - start;
            arr[i] = (char *)malloc(sizeof(char) * (size + 1));  // Allocate space for each word

            // Copy the word
            for (j = 0; j < size; j++)
            {
                arr[i][j] = str[start++];
            }
            arr[i][j] = '\0';  // Null-terminate the string

            // Move to the start of the next word
            start = end;
            while (str[start] == ' ')
                start++;
            i++;
        }
        else
        {
            start++;
        }
    }

    return arr;
}

/* -------------------------------
   Creates a text file with content entered by the user.
---------------------------------*/
void createFile(char *filename)
{
    FILE *file = fopen(filename, "w");  // Open the file for writing
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    printf("Enter text to write to the file (press Ctrl+Z to end input):\n");

    char ch;
    while ((ch = getchar()) != EOF)
    {
        fputc(ch, file);  // Write each character to file
    }

    fclose(file);  // Close the file
    printf("File written successfully.\n");
}

/* -------------------------------
   Returns the most common letter (case-insensitive) in the file.
---------------------------------*/
char commonestLetter(char *filename)
{
    int lettersCount[26] = {0};  // Counter for each letter A-Z
    char c;
    int max_index = -1;

    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return 0;
    }

    // Count letters
    while ((c = fgetc(file)) != EOF)
    {
        if (isalpha(c))
            lettersCount[toupper(c) - 'A']++;
    }

    // Find index of most common letter
    for (int i = 0; i < 26; i++)
    {
        if (lettersCount[i] != 0 && (max_index == -1 || lettersCount[i] >= lettersCount[max_index]))
            max_index = i;
    }

    fclose(file);
    return (max_index >= 0) ? ('A' + max_index) : 0;
}

/* -------------------------------
   Decodes an encrypted message where each letter is shifted by a growing amount.
---------------------------------*/
void decode(char *text)
{
    int i = 0, k = 1;

    while (text[i] != '\0')
    {
        if (text[i] != ' ')
            text[i] -= k;  // Shift character back by k
        else
            k = 0;  // Reset counter at each space
        i++;
        k++;
    }
}

/* Definitions of auxiliary functions */
void printStringsArray(char **str_arr, int size)
{
    for (int i = 0; i < size; i++)
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
