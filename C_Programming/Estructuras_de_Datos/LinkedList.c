#include "LinkedList.h"

link regresaElemento(list *l, int indice)
{
	link n1;
	link n2;
	n1 = n2 = l;

	for(;n2 != (void *) 0; n2 = n2->next) {
		if(indice) {
			indice--;
			continue;
		}
		n1=n1->next;
	}

	return n1;
}

void insertarCircular(list **l, int elemento)
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

void imprimirListaCircular(list *l)
{
	link tmp = l;
	printf("Lista Circular:\nInicio:");
	while (tmp->next != l )
	{
		printf("%d->",tmp->elemento);
		tmp = tmp->next;
	}
	printf("%d->End\n",tmp->elemento);
}

link buscarCircularList(list *l, int elemento)
{
	link x = l;
	while(x->next != l)
	{
		if(x->elemento == elemento)
			return x;
			x = x->next;
	}

	return NULL;
}
int printMenu()
{
	int opcion = 0;
	do{
		printf("======Listas Enlazadas=====\n");
		printf("\tMenu:\n");
		printf("\t1.- Lista Enlazada\n");
		printf("\t2.- Lista Enlazada Circular\n");
		printf("\t3.- Salir\n");
		printf("\t\t Opcion: ");
		scanf("%d", &opcion);
	}while(opcion <= 0 || opcion > 3);

	return opcion;
}
int printMenuLista(const char *titulo)
{
	int opcion;
	do{
		printf("====%s====\n",titulo);
		printf("\t 1.- Insertar Manualmente\n");
		printf("\t 2.- Insertar Aleatoriamente\n");
		printf("\t 3.- Buscar\n");
		printf("\t 4.- Imprimir\n");
		printf("\t 5.- Revertir\n");
		printf("\t\t Opcion: ");
		scanf("%d",&opcion);
	}while(opcion <= 0 || opcion > 6);

	return opcion;
}
int main (int argc, char **argv)
{
	int i;
	int opcion = printMenu();

	do
	{
		switch(opcion)
		{
			case 1:
			{
				opcion = 0;
				int opc = printMenuLista("Lista Ligada");
				switch(opc)
				{
					case 1:
					{
						printf("Insercion Manual\n");
					}break;
					case 2:
					{
						printf("Insercion Aleatoria\n");
					}break;
					case 3:
					{
						printf("Buscar\n");
					}break;
					case 4:
					{
						printf("Imprimir\n");
					}break;
					case 5:
					{
						printf("Revertir\n");
					}break;

					default:
						break;
				}
			}break;

			case 2:
			{
				printf("Lista Enlazada Circular\n");
			}break;

			default:
			{
				opcion = printMenu();
			}
		}
	}while(opcion != 3);

	list *myList = (list *) calloc(1,sizeof(list));
	list *CircleList = (list *) calloc(1,sizeof(list));
	CircleList->next = CircleList;
	//insertarCircular(&CircleList, 0);
	//insertar(&myList, 0);
	for (i = 1; i < 10; ++i) {
		insertar(&myList, i);
		insertarCircular(&CircleList,i);
	}

	imprimirListaCircular(CircleList);

	imprimirLinkedList(myList);
	return EXIT_SUCCESS;
}

void insertar(list **l, int elemento)
{
	link tmpList = (list *) malloc(sizeof(list));
	tmpList->elemento = elemento;
	tmpList->next = *l;
	*l = tmpList;
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

void imprimirLinkedList(list *l)
{
	link tmpList;
	int i = 0;
	printf("Inicio:");
	for (tmpList = l; tmpList != NULL; tmpList = tmpList->next)
		printf("%d->",tmpList->elemento);
	printf("Fin\n");
}


