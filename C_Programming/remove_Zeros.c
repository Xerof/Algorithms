#include <stdio.h>
#include <string.h>

int main()
{
	int size;
	int begin = 0;
	int last;
	int array[] = {0,0,8,0,6,1,0,1,0,0,9};

	size = sizeof(array)/sizeof(array[0]);
	last = size-1;
	printf("size:  %d\n", size);
	while(begin < last){
		if(array[begin] == 0){
			begin++;
			continue;
		}

		if(array[last] == 0){
			int tmp= array[begin];
			array[begin++] = array[last];
			array[last] = tmp;
		}
		last--;
	}

	for(int i = 0; i < size; ++i)
		printf("%d ", array[i]);
	return 0;
}



