#include <stdio.h>
#include <stdlib.h>

int fibonacci(int a)
{
	static int fib[100] = {};
	if(a < 2)
		return a;

	if(fib[a])
		return fib[a];

	return (fib[a] = fibonacci(a-1) + fibonacci(a-2));
}

int main(int argc, char **argv)
{
	int fib = fibonacci(atoi(*(argv+1)));

	printf("Fibonacci %d \n", fib);

	return 0;
}
