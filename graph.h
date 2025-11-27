#include <stdlib.h>
#include <stdio.h>
typedef struct Node *NodePtr;
typedef struct Node
{
  int val;
  NodePtr next;
  NodePtr back;
}Node;
//This is for adjacency list
void adjlist();
void insert(int val, int num);
NodePtr arr(int val,int num);
void disconnecteg(int val);
//matrix representation for graph
void adjmatrix();
void matrix(int val, int num);
void matrix2(int val, int num);
void dismatrix(int val);
//bfs and dfs
void bfs();
void dfs();
int**arr1;
int**ar;
int count1;
int count;
#define MAXV 6
#define check 2 //This is 1+1  = (the first one is constant because I have made by array MAXV; the second one is fir checking disconnected vertex. If you have more than one disconnected vertices add one;
NodePtr array[MAXV];


