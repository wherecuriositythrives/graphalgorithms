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
NodePtr *arr=(NodePtr)calloc(MAXV,sizeof(NodePtr));

void main()
{
  adjlist();
  matrix();
}

void adjlist()
{
  matrix(0,1);
  matrix(1,2);
  matrix(1,3);
  matrix(2,3);
  matrix(2,4);
  disconnecteg(5);
}


void insert(int val, int num)
{
  int i=0;
  NodePtr l=NULL;//checking if node present or not
  do{
    if(matrix[i]->val == val)
    {
      l=matrix[i];
     }
      i++;
  }while(i<count);
  
  if(l==NULL){      //creating new list if vertex doesn't exist
  l= (NodePtr)malloc(sizeof(Node));
  l->val = val;
  l->next = NULL;
  l->back = NULL;
  *(arr+count)=l;
    for(int i=0;i<=count; i++) //store node in array
      {
	arr[i]=(NodePtr)malloc(MAXV*sizeof(NodePtr));
  }
 
	  
  NodePtr p=(NodePtr)malloc(sizeof(Node)); //create for storing second node
  p->val = num;
  p->next = NULL;
  p->back=NULL;
   
  NodePtr l1=l;
 
   while(l->next !=NULL)
  {
    l = l->next;
  }
  l->next=p;
  p->back=l;
  l1->next->back=NULL;
  arr(val,num); //for checking the second node

  }

void disconnecteg(int val) //for disconnected graphs
{
  NodePtr p=(NodePtr)malloc(sizeof(Node));
  p->val = val;
  p->next = NULL;
  p->back=NULL;
  array[count]=p;
  count++;
}
  
  NodePtr arr(int val,int num)
{
  NodePtr n=NULL;
  for(int i=0;i<count;i++) // checking if second node exists
    {
      if(array[i]->val == num)
	{
	  n=array[i];
	}
    }

  if(n != NULL) //if the second node exists then storing the value
    {
  NodePtr p=(NodePtr)malloc(sizeof(Node));
  p->val = val;
  p->next = NULL;
  p->back=NULL;
  NodePtr n1=n;
   while(n->next !=NULL)
  {
    n = n->next;
  }
  n->next=p;
  n1->back=p;
  p->back=n;
  return n1;
    }
  else // second node doesn't exist then create and store the swap
    {
       NodePtr l1= (NodePtr)malloc(sizeof(Node));
           l1->val = num;
           l1->next = NULL;
           l1->back = NULL;
	   NodePtr p1=(NodePtr)malloc(sizeof(Node));
	   p1->val = val;
	   p1->next = NULL;
	   p1->back=l1;
	   
           l1->next=p1;
           l1->next->back=NULL;	      
           array[count]=l1;
           count++;
	  
    }
}

void matrix()  
{
  int rows= MAXV;
  NodePtr *arr = (NodePtr)malloc(rows*sizeof(NodePtr));
  for(int i=0; i<=rows; i++)
    {
      arr[i]=(NodePtr)malloc(rows*sizeof(NodePtr));
    }
        
