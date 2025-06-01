#include <stdio.h>
#include <string.h>

#define N 100

void decode(char* text);

int main() 
{
	char str[N] = "Btwlzx Dqqes Eq|pj2 Tjhvqujs Iqoqjy bpg Eqfxtx Xcwwtt";

	printf("the string : %s\n", str);
	decode(str);
	printf("the decoded massege : %s\n", str);

	return 0;
}
void decode(char* text) 
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