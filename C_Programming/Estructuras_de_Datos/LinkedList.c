#include "LinkedList.h"
#define MAX_BUFFER 100

char buffer[MAX_BUFFER];

int validarEntrada(const char *input)
{
	for(; *input != '\0'; input++) {
		if(*input == '\n')
			continue;
		if(*input < 48  || *input > 57)
			return 1;
	}
	return 0;
}

void Clean(list *l)
{
	link tmp = l;

	if(tmp->next != NULL){
		Clean(tmp->next);
		free(tmp);
	}
}

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
	int opcion = -1;
	do{
		printf("======Listas Enlazadas=====\n");
		printf("\tMenu:\n");
		printf("\t1.- Lista Enlazada\n");
		printf("\t2.- Lista Enlazada Circular\n");
		printf("\t3.- Salir\n");
		printf("\t\t Opcion: ");
		fgets(buffer,MAX_BUFFER, stdin);
		if(!validarEntrada(buffer))
			opcion = atoi(buffer);
	}while(opcion <= 0 || opcion > 4);

	return opcion;
}
int printMenuLista(const char *titulo)
{
	int opcion = -1;
	do{
		printf("====%s====\n",titulo);
		printf("\t 1.- Insertar Manualmente\n");
		printf("\t 2.- Insertar Aleatoriamente\n");
		printf("\t 3.- Buscar\n");
		printf("\t 4.- Imprimir\n");
		printf("\t 5.- Revertir\n");
		printf("\t 6.- Regresar\n");
		printf("\t\t Opcion: ");
		fgets(buffer,MAX_BUFFER, stdin);
		if(!validarEntrada(buffer))
			opcion = atoi(buffer);

	}while(opcion <= 0 || opcion > 6);

	return opcion;
}
int main (int argc, char **argv)
{
	int i;
	int opcion;
	do
	{
		opcion = printMenu();
		switch(opcion)
		{
			case 1:
			{
				int opc = printMenuLista("Lista Ligada");
				switch(opc)
				{
					case 1:
					{
						int numElements;
						printf("Numeros de Elementos a insertar: ");
						fgets(buffer,MAX_BUFFER,stdin);
						if(!validarEntrada(buffer)) {
							numElements = atoi(buffer);
							printf("Insercion Manual\n");
							list *myList = NULL;
							for (i = 0; i < numElements; ++i){
								int elem = 0;
								fgets(buffer,MAX_BUFFER,stdin);
								if(!validarEntrada(buffer))
									elem = atoi(buffer);
								insertarHead(&myList,elem);
							}
						}
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
					case 6:
					{
						printf("Regresar\n");
					}break;

					default:
						break;
				}
			}break;

			case 2:
			{
				printf("Lista Enlazada Circular\n");
			}break;

			case 3:
			{
				printf("===================Saliendo==================\n");
			}break;
			default:
			{
				opcion = printMenu();
			}
		}
	}while(opcion != 3);

	list *myList = NULL;
	list *CircleList = (list *) calloc(1,sizeof(list));
	CircleList->next = CircleList;
	//insertarCircular(&CircleList, 0);
	//insertar(&myList, 0);
	for (i = 1; i < 10; ++i) {
		insertarHead(&myList, i);
		insertarCircular(&CircleList,i);
	}

	imprimirListaCircular(CircleList);

	imprimirLinkedList(myList);
	borrar(&myList, 20);
	insertarTail(&myList, 55);
	insertarHead(&myList, 99);
	imprimirLinkedList(myList);
	return EXIT_SUCCESS;
}
/*==============================================
 | FUNCION: insertarHead                        |
 | ARGUMENTOS:                                  |
 |            list *l - Lista en la cual insetar|
 |            int elemento - elemento a insertar|
 | DESCRIPCION:                                 |
 |             Inserta el elemento al inicio de |
 |             la lista *l                      |
 | RETURN:                                      |
 |        Direccion del elemento encontrado o   |
 |        o si no lo encontro NULL              |
 ===============================================*/
int insertarHead(list **l, int elemento)
{
	link tmpList = (list *) malloc(sizeof(list));
	if(tmpList == NULL)
		return 1;

	tmpList->elemento = elemento;
	tmpList->next = *l;
	*l = tmpList;

	return 0;
}
/*==============================================
 | FUNCION: insertarTail                        |
 | ARGUMENTOS:                                  |
 |            list *l - Lista en la cual buscar |
 |            int elemento - elemento a insertar|
 | DESCRIPCION:                                 |
 |             Inserta el elemento en la cola   |
 |             de la lista *l                   |
 | RETURN:                                      |
 |        Direccion del elemento encontrado o   |
 |        o si no lo encontro NULL              |
 ===============================================*/
int insertarTail(list **l, int elemento)
{
	link indice = NULL;

	if(*l == NULL)
		return 1;

	for(indice = *l; indice->next != NULL; indice = indice->next)
		;

	link tmpList = (list *) malloc(sizeof(list));
	tmpList->elemento = elemento;
	tmpList->next = indice->next;
	indice->next = tmpList;
}
/*==============================================
 | FUNCION: buscar                              |
 | ARGUMENTOS:                                  |
 |            list *l - Lista en la cual buscar |
 |            int elemento - elemento a buscar  |
 | DESCRIPCION:                                 |
 |             Busca el elemento en la lista *l |
 | RETURN:                                      |
 |        Direccion del elemento encontrado o   |
 |        o si no lo encontro NULL              |
 ===============================================*/
link buscar(list *l, int elemento)
{
	printf("%s\n",__func__);
	if(l == NULL) {
		return(NULL);
	}

	if(l->elemento == elemento) {
		return l;
	}
	else{
		return buscar(l->next, elemento);
	}

}
/*==============================================
 | FUNCION: borrar                              |
 | ARGUMENTOS:                                  |
 |            list *l - Lista en la cual buscar |
 |            int elemento - elemento a eliminar|
 | DESCRIPCION:                                 |
 |             Borra el elemento de la lista *l |
 | RETURN:                                      |
 |        0 - Se elimino correctamente          |
 |        1 - Se encontro un error              |
 ===============================================*/
int borrar(list **l, int elemento)
{
	list *pred = NULL;
	list *p = NULL;

	if (*l == NULL){
		return 1;
	}

	p = buscar(*l, elemento);
	if(p != NULL){
		pred = predecesor(*l, elemento);
		if(pred == NULL)
			*l = p->next;
		else
			pred->next = p->next;

	printf("Elemento a borrar %d\n", p->elemento);

	free(p);
}

	return 0;
}

/*==============================================
 | FUNCION: predecesor                          |
 | ARGUMENTOS:                                  |
 |            list *l - Lista en la cual buscar |
 |            int elemento - elemento a buscar  |
 |                           su predecesor      |
 | DESCRIPCION:                                 |
 |             Busca el predecesor del elemento |
 |             en la lista                      |
 | RETURN:                                      |
 |        Direccion del elemento encontrado o   |
 |        o si no lo encontro NULL              |
 ===============================================*/
link predecesor(list *l, int elemento)
{
	link indice;
	printf("%s\n",__func__);

	if(l == NULL)
		return NULL;

	indice = l;
	while(indice->next != NULL) {
		if(indice->next->elemento == elemento)
			return indice;

		indice = indice->next;
	}

	return NULL;
}
/*==============================================
 | FUNCION:                                     |
 |         IMPRIMIRLINKEDLIST                   |
 | ARGUMENTOS:                                  |
 |            list *l - Lista a imprimir        |
 | DESCRIPCION:                                 |
 |             Imprime la lista *l              |
 | RETURN:                                      |
 |        NONE                                  |
 ===============================================*/
void imprimirLinkedList(list *l)
{
	if(l) {
		link tmpList;
		int i = 0;
		printf("Inicio:");
		for (tmpList = l; tmpList != NULL; tmpList = tmpList->next)
		printf("%d->",tmpList->elemento);
		printf("Fin\n");
	} else {
		printf("NULL\n");
	}
}
