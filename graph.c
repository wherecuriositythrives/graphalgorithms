void adjlist(NodePtr hd)
{
  char done;
  int c;
  while(1>0){
  do
  {
    scanf("%d",&c);
    insert(hd,c);
    io++;
  }while(c != -1);
  arr(hd);
  o++;
  printf("Are you done? (Y/N)");
    scanf("%c", &done);
  if(done == 'Y'){break};
}
}


void insert(NodePtr l, int val)
{
  if(val != -1)
    {
  NodePtr p=(NodePtr)malloc(sizeof(Node));
  p->val = val;
  p->next = NULL;
  p->back=NULL;
  while(l->next !=NULL)
  {
    l = l->next;
  }
  l->next=p;
  l1->back=p;
  p->back=l;
    }}

  void arr (Nodeptr l)
{
  NodePtr ll=l;
  if(l->next != NULL){l->next->back=NULL;}
  int count=0;
  long*ar= NULL;
  long*allocate=(long*) realloc(ar,(count+1)*sizeof(long));
  ar=allocate;
  *(ar + count)=l;
  count++;
  printlst(ll);
}

 void printlst(NodePtr l)
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
