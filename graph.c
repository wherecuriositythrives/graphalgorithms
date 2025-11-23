void adjlist()
{
  insert(0,1);
  insert(1,2);
  insert(1,3);
  insert(2,3);
  insert(2,4);
}


void insert(int val, int num)
{
  NodePtr l;
  if(c != val){
  l= (NodePtr) malloc(sizeof(Node));
  l->val = val;
  l->next = NULL;
  l->back = NULL;
  c=val;
  g++;
  }
  else
    {
      NodePtr *hd = array;
      for(int i =0; i<=g; i++)
	{
	  if((*hd)->val == val)
	    {l=*hd;}
	  hd++;
	}
    }
	  

  NodePtr p=(NodePtr)malloc(sizeof(Node));
  p->val = num;
  p->next = NULL;
  p->back=NULL;
  
 
  NodePtr l1=l;
 
   while(l->next !=NULL)
  {
    l = l->next;
  }
  l->next=p;
  l->back=p;
  p->back=l;
  arr(l1,val,num);
    }

  void arr (NodePtr l,int val,int num)
{
  
  NodePtr n; 
  if(l->next != NULL)
    {
      l->next->back=NULL;
    }
  
  NodePtr *pt= array;
  for(int i=0; i<=g++; i++)
    {
      if((*pt)->val == num)
	{
	  n=*pt;
	}
      else
	n=NULL;
        pt++; 
    }
  
  if((*pt)->next==NULL)
    {
	  NodePtr l1= (NodePtr) malloc(sizeof(Node));
           l1->val = num;
           l1->next = NULL;
           l1->back = NULL;
	   NodePtr p1=(NodePtr)malloc(sizeof(Node));
	   p1->val = val;
	   p1->next = NULL;
	   p1->back=NULL;

	   while(l1->next !=NULL)
	      {
		l1 = l1->next;
	      }
	       l1->next=p1;
	       l1->back=p1;
	       p1->back=l1;
	       array[++g]=l1;
	       c=num;
	       
      }
            
}












/* void printlst(NodePtr l)
{
  printf("The first number is the vertex and the following are the vertex connected\n");
  NodePtr l1=l;
  l=l->next;
  l1=l1->back;
  while(l)
  {
    printf("%d\n", l->val);
    l=l->next;
    printf("a%d\n", l1->val);
    l1=l1->back;
    }

void matrix()
{
  int *(*a)=(int*(*))malloc(o*sizeof(int*));
  for(int i=0; i<o; i++)
    {
      a[i]=malloc(io*sizeof(int));
    }
   
  void matrix()
{
  int **ar=NULL;
  int *s=NULL;
  int i=0;
  int j=0;
  int *(*a)=(int*(*))realloc(ar,(i+1)*sizeof(int *));
  for(int i=0; i<count; i++)
    {
      *(a+i)=malloc(counti*sizeof(int));
    }
  for(int k=0; k<i; k++)
    {
      for(int q=0; q<j; k++)
	{
	  *(*(a+i)+j)=
   int count=0;
  long*ar= NULL;
  long*allocate=(long*) realloc(ar,(count+1)*sizeof(long));
  ar=allocate;
  *(ar + count)=l;
  count++; */
