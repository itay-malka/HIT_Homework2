#include <stdio.h>
#include <ctype.h>

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

int main()
{
    char path[100] = "C:\\Users\\itaym\\Documents\\git\\hit_cs_intro\\practice\\test.txt";
    createFile(path);
    char commonRes = commonestLetter(path);
    isalpha(commonRes) ? printf("Common charecter from file is %c.", commonRes) : printf("No letters found in file.");
}