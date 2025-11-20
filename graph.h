#include <stdlib.h>
#include <stdio.h>
typedef struct Node *NodePtr;
typedef struct Node
{
  int val;
  NodePtr next;
  NodePtr back;
}Node;

void adjlist(NodePtr hd);
void insert(NodePtr l, int val);
void printlst(NodePtr l);
void arr(Nodeptr l);

