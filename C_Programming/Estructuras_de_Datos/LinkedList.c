#include "LinkedList.h"

#ifdef _WIN32
#define CLEAR_SCREEN system("cls")
#else
#define CLEAR_SCREEN system("clear")
#endif

#define MAX_BUFFER 100
typedef unsigned char bool;
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
		CLEAR_SCREEN;
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
		CLEAR_SCREEN;
		system("clear");
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
void MostrarMenuListaEnlazada(int Circular, const char *Title)
{
	int opc;
	list *LinkedList = NULL;
	do
	{
		int i;
		opc = printMenuLista(Title);
		switch(opc)
		{
			case 1:
			{
				int numElements;
				bool InsTail = 0;
				printf("=========Insercion Manual=========\n");
				printf("Numeros de Elementos a insertar: ");
				fgets(buffer,MAX_BUFFER,stdin);
				if(!validarEntrada(buffer)) {
					numElements = atoi(buffer);
					printf("Insertar atras de la lista:[1]Yes [2]No \n");
					fgets(buffer,MAX_BUFFER,stdin);
					if(!validarEntrada(buffer))
						InsTail = atoi(buffer) == 1 ? 1 : 0;
					for (i = 0; i < numElements; ++i){
						int elem = 0;
						printf("Captura el %d elemento: ", i +1);
						fgets(buffer,MAX_BUFFER,stdin);
						if(!validarEntrada(buffer)) {
							elem = atoi(buffer);
							if(InsTail)
								insertarTail(&LinkedList, elem, Circular);
							else
								insertarHead(&LinkedList, elem, Circular);
						}
					}
				}
			}break;

			case 2:
			{
				int numElements;
				printf("========Insercion Aleatoria========\n");
				printf("Numeros de Elementos a insertar: ");
				fgets(buffer,MAX_BUFFER,stdin);
				if(!validarEntrada(buffer)) {
					numElements = atoi(buffer);
					for(i = 0; i < numElements; ++i) {
						int ramdomNumber = rand() % 1000;
						printf("Insertando %d\n",ramdomNumber);
						insertarHead(&LinkedList, ramdomNumber, Circular);
					}
					printf("\nPresione cualquier tecla para continuar \n");
					getchar();
				}
			}break;

			case 3:
			{
				printf("=================Buscar=================\n");
				fgets(buffer,MAX_BUFFER,stdin);
				if(!validarEntrada(buffer)) {
					list *l = buscar(LinkedList, atoi(buffer));
					if(l)
						printf("Elemento encontrado %d\n", l->elemento);
					else
						printf("Elemento no encontrado\n");
				}else {
					printf("Dato invalido\n");
				}
				printf("Presiona cualquier tecla para continuar\n");
				getchar();
			}break;

			case 4:
			{
				printf("============Imprimir=============\n\n");
				imprimirLinkedList(LinkedList);
				printf("\nPresione cualquier tecla para continuar \n");
				getchar();
			}break;

			case 5:
			{
				printf("==============Revertir===================\n");
				printf("Lista antes de revertir: \n");
				imprimirLinkedList(LinkedList);
				LinkedList = revertir(LinkedList);
				printf("Lista despues de revertir: \n");
				imprimirLinkedList(LinkedList);
				printf("\nPresione cualquier tecla para continuar \n");
				getchar();
			}break;

			case 6:
			{
				printf("Regresar\n");
			}break;

			default:
				break;
		}
	}while(opc != 6);

	free(LinkedList);
}

int main (int argc, char **argv)
{
	int opcion;
	do
	{
		opcion = printMenu();
		switch(opcion)
		{
			case 1: //Lista Enlazada
			{
				MostrarMenuListaEnlazada(0, "Lista Enlazada");
			}break;

			case 2:
			{
				printf("Lista Enlazada Circular\n");
				MostrarMenuListaEnlazada(1, "Lista Circular");
			}break;

			case 3:
			{
				printf("===================Saliendo==================\n");
			}break;
			default:
			{
				printf("Opcion Incorrecta\n");
			}
		}
	}while(opcion != 3);

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
int insertarHead(list **l, int elemento, int Circular)
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
 |            list *l - Lista a la cual insertar|
 |            int elemento - elemento a insertar|
 | DESCRIPCION:                                 |
 |             Inserta el elemento en la cola   |
 |             de la lista *l                   |
 | RETURN:                                      |
 |        Direccion del elemento encontrado o   |
 |        o si no lo encontro NULL              |
 ===============================================*/
int insertarTail(list **l, int elemento, int Circular)
{
	link indice = NULL;

	if(*l == NULL)
		return insertarHead(l, elemento, Circular);

	for(indice = *l; indice->next != NULL; indice = indice->next)
		;

	link tmpList = (list *) malloc(sizeof(list));
	if (tmpList == NULL)
		return 1;

	tmpList->elemento = elemento;
	tmpList->next = indice->next;
	indice->next = tmpList;

	return 0;
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
 |         REVERTIR                             |
 | ARGUMENTOS:                                  |
 |            list *l - Lista a invertir        |
 | DESCRIPCION:                                 |
 |             Invierte los links de la lista   |
 | RETURN:                                      |
 |        NONE                                  |
 ===============================================*/
link revertir(list *l)
{
	link tmp, y = l, r = 0;

	while(y != NULL)
	{
		tmp = y->next;
		y->next = r;
		r = y;
		y = tmp;
	}

	return r;
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
		printf("INICIO:");
		for (tmpList = l; tmpList != NULL; tmpList = tmpList->next)
			printf("%d->",tmpList->elemento);
		printf("FINAL\n");
	} else {
		printf("NULL\n");
	}
}
