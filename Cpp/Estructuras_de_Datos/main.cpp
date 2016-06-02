#include <stdio.h>
#include "LinkedList_core.h"

int main()
{
	LinkedList<int> l;
	for(int i =0; i < 10; ++i) {
		l.push_front(rand()%100);
	}
	std::cout << l;
}
