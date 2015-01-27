#define INVALID -1

struct node {
  int y; // Vecino
  struct node *next_node;
};

  typedef struct node Node;
  typedef Node *ptr_node;
  typedef unsigned char uint8;

  int insert(ptr_node ptrG, int x, int y);
  int initG(ptr_node *ptrG, uint8 **G_State, unsigned int vertices);
  void dfs(ptr_node G, uint8 *G_State, unsigned int source);
