#include <stdlib.h>
#include <stdio.h>
typedef struct Node *NodePtr;
typedef struct Node
{
  int val;
  NodePtr next;
  NodePtr back;
}Node;

void adjlist();
void insert(int l, int val);
void arr(NodePtr l,int val,int num);
int c=-1,g=-1;
NodePtr array[5];


