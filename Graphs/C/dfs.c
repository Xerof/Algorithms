#include <stdio.h>
#include <stdlib.h>
#include "Grafos.h"
#include <string.h>

#define FALSE 0
#define TRUE 1

int main (int carg, char **argv)
{
  Node *G;
  unsigned int v; // Vertice
  unsigned int e; // Edge
  unsigned int x,y;
  unsigned int i; 
  uint8 *G_State; // Graph State (Visited)

  printf(" Grafos everywhere \n");
  printf(" Insert the number of vertices  \n");
  scanf("%u", &v);

  if(v >= -1)
    return -1;

  printf("Initializing G \n");
  if(initG(&G,&G_State,v) == -1 )
    return -1;

  printf(" Insert the number of edges \n");
  scanf("%u",&e);

  for( i=0; i < e ; i++)
  {
    printf(" Insert X \n");
    scanf("%u",&x);
    printf(" Insert Y \n");
    scanf("%u",&y);
    if(insert(G,x,y) == -1)
       return -1;
  }

  printf("DFS\n");
  dfs(G, G_State, 0);
}

int initG(ptr_node *G, uint8 **G_State,unsigned int vertices)
{
    int i;
    *G =  malloc(sizeof(Node) * vertices);
    if(*G == NULL){
        printf("Can't allocate memory \n");
        return -1;
    }

    *G_State = malloc(sizeof(Node) * vertices);
    if(*G_State == NULL){
        printf("Can't allocate memory \n");
        return -1;
    }

    for(i=0; i <  vertices; i++)
    {
        (*G+i)->y = INVALID;
        (*G+i)->next_node = NULL;
        *(*G_State+i) = FALSE;
    }

    return 0; 
}

int insert(ptr_node ptrG, int x, int y)
{
    if(INVALID != (ptrG +x)->y)
    {
        ptr_node tmp = malloc(sizeof(Node));
        if(tmp == NULL){
            printf("Can't allocate memory \n");
            return -1;
        }
        *tmp = *(ptrG+x);

        (ptrG+x)->y = y;
        (ptrG+x)->next_node = tmp;
    }else
        (ptrG+x)->y = y;

    return 0;
}

void dfs(ptr_node G, uint8 *G_State, unsigned int source)
{
   printf("Source %d \n",source);
   ptr_node tmp = G+source;
   *(G_State+source) = TRUE;

   while(NULL != tmp)
   {
      if(INVALID != tmp->y && !*(G_State+tmp->y))
          dfs(G, G_State, tmp->y);

      tmp= tmp->next_node;
   }

}
 
