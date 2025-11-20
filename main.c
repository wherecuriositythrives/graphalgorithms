void main()
{ 
  NodePtr hd= (NodePtr) malloc(sizeof(Node));
  hd->val = -1;
  hd->next = NULL;
  hd->back = NULL;
  adjlist(hd);
 }
