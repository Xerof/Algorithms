#include <stdio.h>
#include <string.h>

void invertString(char *str, size_t begin, size_t end);

int main(int arg, char **argv)
{
	char str[] = "HolaMundo";
	invertString(str, 0, strlen(str)-1);

	printf("Inverted String: %s \n", str);

	return 0;
}

void invertString(char *str, size_t begin, size_t end)
{
	char c_tmp = *(str+begin);

	*(str+begin) = *(str+end);
	*(str+end) = c_tmp;

	if(end <= begin)
		return;

	invertString(str, ++begin, --end);
}
