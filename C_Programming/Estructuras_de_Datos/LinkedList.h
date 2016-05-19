#include <stdio.h>
#include <stdlib.h>

typedef struct list {
	int elemento;
	struct list *next;
}list,*link;

int insertarHead(list **l, int elemento);
int insertarTail(list **l, int elemento);
link buscar(list *l, int elemento);
int borrar(list **l, int elemento);
link predecesor(list *l, int elemento);
void imprimirLinkedList(list *l);
link revertir(list *l);
/* Lista Circular */
void insertarCircular(list **l, int elemento);
void imprimirListaCircular(list *l);
link buscarCircularList(list *l, int elemento);
