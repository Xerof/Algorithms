#include <stdio.h>
#include <stdlib.h>

typedef struct list {
	int elemento;
	struct list *next;
}list,*link;

void insertar(list **l, int elemento);
link buscar(list *l, int elemento);
void borrar(list **l, int elemento);
link predecesor(list *l, int elemento);

