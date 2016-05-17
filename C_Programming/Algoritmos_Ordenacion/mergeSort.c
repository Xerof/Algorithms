#include <stdio.h>
#include <stdlib.h>

#define ARR_SIZE(name) sizeof(name)/sizeof(*name)

void merge(int arr[], int inicio, int mid, int final)
{
	int size_buff1 = mid - inicio + 1;
	int size_buff2 = final - mid;
	int i, j, k;

	int *buff1 = (int *)malloc(size_buff1 * sizeof(int));
	int *buff2 = (int *)malloc(size_buff2 * sizeof(int));

	for(i = 0; i < size_buff1; ++i){
		buff1[i] = arr[inicio + i];
	}
	for(j = 0; j < size_buff2; j++){
		buff2[j] = arr[mid + j + 1];
	}

	i = j = 0;
	k = inicio;
	while(i < size_buff1 && j < size_buff2) {
		if(buff1[i] <= buff2[j])
			arr[k++] = buff1[i++];
		else
			arr[k++] = buff2[j++];
	}

	while (i < size_buff1) arr[k++] = buff1[i++];
	while (j < size_buff2) arr[k++] = buff1[j++];

	free(buff1);
	free(buff2);
}


void mergeSort(int arr[], int inicio, int final)
{
	if(inicio < final) {
		int mid = inicio + (final -  inicio) / 2;
		mergeSort(arr, inicio, mid);
		mergeSort(arr, mid + 1, final);
		merge(arr, inicio, mid, final);
	}
}

void printBullshit(int arr[], int ArrSize)
{
	int i;
	for (i = 0; i < ArrSize; ++i)
		printf("%d ", arr[i]);
	printf("\n");
}
int main(int argc, char **argv)
{
	int i =0;
	int a[] = {5,4,3,2,1,0};
	printf("Input: \n\t");
	printBullshit(a, ARR_SIZE(a));
	mergeSort(a, 0, ARR_SIZE(a) - 1);

	printf("Output: \n\t");
	printBullshit(a, ARR_SIZE(a));
	return 0;
}
