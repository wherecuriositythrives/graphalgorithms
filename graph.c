#include "graph.h"
int **arr1 = NULL;
int **ar = NULL;
int count1 = 0;
int count = 0;
NodePtr array[MAXV];
void adjlist()
{
  printf("hi");
  insert(0,1);
  insert(1,2);
  insert(1,3);
  insert(2,3);
  insert(2,4);
  disconnecteg(5);
}

void adjmatrix()
{
    arr1=(int**)malloc(MAXV*sizeof(int*));
  for(int i=0; i<MAXV; i++)
    {
      arr1[i]=(int*)malloc(MAXV*sizeof(int));
    }
  for(int i=0; i<MAXV; i++)
    {
      for(int w=0;w<MAXV; w++)
	{ 
      arr1[i][w]= -1;
    }
    }
  
    ar=(int**)malloc(MAXV*sizeof(int*));
  for(int i=0; i<MAXV; i++)
    {
      ar[i]=(int*)calloc(MAXV,sizeof(int));
    }
 
  matrix(0,1);
  matrix(1,2);
  matrix(1,3);
  matrix(2,3);
  matrix(2,4);
  dismatrix(5);
  matrix2(0,1);
  matrix2(1,2);
  matrix2(1,3);
  matrix2(2,3);
  matrix2(2,4);
}


void insert(int val, int num)
{
  int i=0;
  NodePtr l=NULL;//checking if node present or not
  do
    {
      if(array[i]->val == val)
      {
	l=array[i];
      }
      i++;
  }while(i<count);
  
  if(l==NULL){      //creating new list if vertex doesn't exist
  l= (NodePtr) malloc(sizeof(Node));
  l->val = val;
  l->next = NULL;
  l->back = NULL;
  array[count]=l;  //store node in array
  count++;
  }
 printf("hi1"); 
	  
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
 printf("hi2\n"); 
}
 
void disconnecteg(int val) //for disconnected graphs
{
  NodePtr p=(NodePtr)malloc(sizeof(Node));
  p->val = val;
  p->next = NULL;
  p->back=NULL;
  array[count]=p;
  count++;
  printf("hi3\n"); 
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
 printf("hi4\n");
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
   printf("hi5\n");
}


void matrix(int q, int j)
{
  int n=0; 
  for(int i=0;i<=count1;i++) 
    {
      if(*arr1[i] == q)      //If first vertex exists then add the second vertex
	{
	  for(int w=0;w<MAXV; w++)
	    {
	      if(arr1[i][w] == -1)
		{
		  arr1[i][w]= j;
		  n++;
		}
	    }
	}
    }
  if(n == 0)  //If first vertex doesn't exist make one and store the second vertex
    {
	  *arr1[count1]= q;
	  arr1[count1][1]=j;
	  count1++;  
    }
  n=0;
  
 for(int i=0;i<=count1;i++) 
    {
      if(*arr1[i] == j)      //If second vertex exists then add the first vertex
	{
	  for(int w=0;w<MAXV; w++)
	    {
	      if(arr1[i][w] == -1)
		{
		  arr1[i][w]= j;
                  n++;
		}
	    }
	}
    }
      if(n == 0)  //If second vertex doesn't exist make one and store the first vertex
	{
	  *arr1[count1]= j;
	  arr1[count1][1]=q;
	  count1++;
	}
    }
  
void dismatrix(int val)
{
  *arr1[count1]= val;
    count1++;
}


void matrix2(int q,int j) //Deepseek wanted this. Here your rows and columns are the respective vertices.
{
  ar[q][j]=1;
  ar[j][q]=1;
}

        
void bfs()
{
  int n=1;
  int count=0;
  int arr[MAXV];
  NodePtr l;
  for(int i=0;i<MAXV-check; i++){arr[i]=0;}
  for(int i=MAXV-check; i<=MAXV-1; i++){arr[i]=-1;}
      l=array[0];
      while(l) //choosing the first vertex and storing its neighbours
	{
	  arr[count]=l->val;
	  l=l->next;
	  count++;
	}
      for(int i=0;i<=count;i++)
	{
      printf("The first vertex stored along with its neighbours %d\n", arr[i]);
	}
      while(n<MAXV && arr[n] != -1)
	{
      for(int i=0; i<MAXV; i++) //finding the location of where the vertex is stored
	{
	  if(arr[n]==array[i]->val)
	    {
	      l=array[i];
	      break;
	    }
	  l=l->next;
	}      
      while(l)  
	{
	  int q=0;
	  for(int i=0; i<=count; i++) //checking if neighbour is present. if yes move on to the next neighbour
	    {
	      if(l->val == arr[i])
		{
		  l=l->next;
		  q++;
		  break;
		}
	    }
	  if(q==0)
	    {
	      arr[count+1]=l->val;
	      l=l->next;
	      count++;
		}
	}
      n++;
	}
      l=array[0];
      for(int i=0; i<=MAXV; i++) //diconnected vertex of the graph
	{
	  if(l->next == NULL)
	    {
	      arr[count]=l->val;
	    }
	  l=l->next;
	 
	}
      for(int i=0;i<MAXV; i++)
	{
	  printf("The array is %d\n", arr[i]);
	}
}

void dfs()
{
  int n=1;
  int count=0;
  int q=count-1;
  int arr[MAXV];
  NodePtr l;
  for(int i=0;i<MAXV-check; i++){arr[i]=0;}
  for(int i=MAXV-check; i<=MAXV-1; i++){arr[i]=-1;}
      l=array[0];
      arr[0]= l->val; //choosing the first vertex and storing its first neighbour
      count++;
      arr[1]= l->next->val;
      count++;
      while(arr[n] != -1)
	{
           for(int i=0; i<MAXV; i++) //finding the location of where the vertex is stored
	{
	  if(arr[n]==array[i]->val)
	    {
	      l=array[i];
	      break;
	    }
	  l=l->next;
	}
	   l=l->next;
	   for(int i=0; i<=count; i++) //checking if its neighbour have been visited or not
	     {
	       if(l->val == arr[i])
	     {
	       l=l->next;
	     }
	     }
	   if(l != NULL) // if the neighbour is not visited then go to that neighbour
	     {
	       arr[count]= l->val;
		 count++;
	       n++;
	     }
	   if(l == NULL) //If yes start backtracking
	     {
	       for(int i=0; i<=count; i++) // backtrack and find the location of that node.
		     {
		   if(arr[q]==array[i]->val)
		     {
		       l=array[i];
		       break;
		     }
		   l=l->next;
		 }
	       l=l->next;
	       for(int i=0; i<=count; i++) // went to that node and checks whether all vertexes have been visited
	     {
	       if(l->val == arr[i])
		 {
	       l=l->next;
		 }
	     } 
	       if(l != NULL) //If no then go that neighbour
	     {
	       arr[count]= l->val;
		 count++;
	       n++;
	       break;
	     }
	       q--;
	       if(q == -1){break;}  
	     }
	  l=array[0];
	  for(int i=0; i<=MAXV; i++)
	    {
	      if(l->next == NULL)
		{
		  arr[count]=l->val;
		}
	      l=l->next;
	    }      
	   
	}
}
		 

