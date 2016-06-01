#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ToBinary(int x)
{
	int y = 0, z = 1;
	while(x) {
		if (x & 1)
			y += z;
		x = x >> 1;
		z *= 10;
	}
	return y;
}

int Multiplying( int x, int y)
{
	int res = 0;
	while(x > 0)
	{
		if(x&1) {
			res+=y;
		}
		x>>=1;
		y<<=1;
	}
	return res;
}

int PowerOf( int x, int n)
{
	int res = 1;
	while(n > 0)
	{
		if(n&1) {
			res*=x;
		}
		x*=x;
		n>>=1;
	}
	return res;
}



void adding(int *a, int *b, int n)
{
	int i;
	int *c = (int *) malloc(n * sizeof(int));
	for(i = 0; i < n; ++i) {
		c[i] = a[i] + b[i];
		c[i] = ToBinary(c[i]);
	}

	for(i = 0; i < n; ++i)
		printf("%d \n", c[i]);
	free(c);
}
void NonDecreasingInsertionSort(int *A, int sizeA)
{
	int i,j;
	for(j = 1; j < sizeA; ++j) {
		int key = A[j];
		i = j - 1;
		while(i >= 0 && A[i] > key) {
			A[i + 1] = A[i];
			--i;
			A[i + 1] = key;
		}
	}
}

void NonIncreasingInsertionSort(int *A, int sizeA)
{
	int i,j;
	for(j = 1; j < sizeA; ++j) {
		int key = A[j];
		i = j - 1;
		while(i >= 0 && A[i] < key) {
			A[i + 1] = A[i];
			--i;
			A[i + 1] = key;
		}
	}
}

int main(void)
{
	int a[10]= {};
	int b[10]= {};
	int i;

	for(i = 0; i < 10; ++i) {
		a[i] = rand()%10;
		b[i] = rand()%10;
	}
	printf("Input A \n");
	for(i = 0; i < 10; ++i)
		printf("%d ", a[i]);
	printf("\n");

	adding(a,b, 10);
	//NonIncreasingInsertionSort(a, 10);

	printf("Input B \n");
	for(i = 0; i < 10; ++i)
		printf("%d ", b[i]);
	printf("\n");

	return EXIT_SUCCESS;
}
