#include "LinkedList.h"

void imprimirLinkedList(list *l)
{
	link tmpList;
	int i = 0;
	for (tmpList = l; tmpList != NULL; tmpList = tmpList->next)
		printf("%d - %d \n",i++, tmpList->elemento);
}

void imprimirListaCircular(list *l)
{
	link tmp = l->next;
	while (tmp != l )
	{
		printf("- %d \n",tmp->elemento);
		tmp = tmp->next;
	}
}
int main (int argc, char **argv)
{
	int i;
	list *myList = (list *) calloc(1,sizeof(list));
	list *CircleList = (list *) calloc(1,sizeof(list));
	CircleList->next = CircleList;
	link x = CircleList;
	insertar(&CircleList, 0);
	//insertar(&myList, 0);
	for (i = 1; i < 10; ++i) {
		//insertar(&myList, i);
		insertar(&CircleList,i);
	}

	imprimirListaCircular(CircleList);
	link l = buscar(myList, 5);
	if(l)
		printf("Lo encontre %d\n ", l->elemento);

	//imprimirLinkedList(myList);

	return EXIT_SUCCESS;
}
// C-> B -> A
void insertar(list **l, int elemento)
{
	link inicio  = (*l);
	while(inicio->next != (*l))
		inicio = inicio->next;

	link tmpList;
	tmpList = (list *) malloc(sizeof(list));
	tmpList->elemento = elemento;
	tmpList->next = *l;
	inicio->next = tmpList;
}

link buscar(list *l, int elemento)
{
	if(l == NULL)
		return(NULL);

	if(l->elemento == elemento)
		return l;
	else
		return buscar(l->next, elemento);
}

void borrar(list **l, int elemento)
{
}

link predecesor(list *l, int elemento)
{
}

