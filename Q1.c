#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <ctype.h>

#define N 100


char** split(char letter, char* str, int* p_size);
void print_matrix(char** mat, int size);
void freeMat(char** mat,int n);

int main()
{
	int size;
	char string[N] = "Rony Goodman got a good mark";
	char letter = 'g';
	
	char** ress = split(letter,string, &size);

	print_matrix(ress, size);
	freeMat(ress,size);

	return 0;
}
void print_matrix(char** mat,int size) 
{
	int i;
	for (i = 0; i < size; i++) 
	{
		printf("%s\n", mat[i]);
	}
}
void freeMat(char** mat,int n) 
{
	for (int i = 0; i < n; i++) 
	{
		free(mat[i]);
	}
	free(mat);
}
char** split(char letter, char* str, int* p_size)
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
	char** arr = (char**)malloc(sizeof(char*) * count_siz);
	i = 0;
	while (i < count_siz) 
	{
		if ((start == 0 || str[start - 1] == ' ') && tolower(str[start]) == tolower(letter))
		{
			end = start;
			while (str[end] != ' ' && str[end] != '\0')
				end++;

			int size = end - start;
			arr[i] = (char*)malloc(sizeof(char) * (size+1));
			for (j = 0; j < size; j++)
			{
				arr[i][j] = str[start++];
			}
			arr[i][j] = '\0';
			start = end;
			while (str[start] == ' ') start++;
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