#include <stdio.h>
#include <string.h>

int removeCharacter(char *str);

int main(int argc, char **argv)
{
	char string[] = "aabccd";

	removeCharacter(string);

	printf("String %s \n", string);

	return 0;

}

int removeCharacter(char *str)
{
	if(strlen(str) < 2 || str == NULL)
		return 1;

	int i,j;
	int pivot = 1;

	for( i = 1; str[i] != '\0'; ++i)
	{
		for(j = 0; j < pivot; ++j)
		{
			printf("comparing [%d] %c != [%d]%c\n", i,str[i],j,str[j]);
			if(str[i] == str[j]){
				printf("Break \n");
				break;
			}
		}
		if(j == pivot){
			printf("reached adding \n");
			str[pivot++] = str[i];
		}
	}

	if(pivot < strlen(str))
		str[pivot] = '\0';
	return 0;
}
