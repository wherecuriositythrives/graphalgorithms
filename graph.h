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
void insert(int val, int num);
NodePtr arr(int val,int num);
void disconnecteg(int val);
int count=0;
#define MAXV 6
NodePtr array[MAXV];


