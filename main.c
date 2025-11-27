#include "graph.h"

int main()
{
  count = 0;
  count1 = 0;
  
  for(int i = 0; i < MAXV; i++) {
    array[i] = NULL;
  }
   printf("Program starting\n");
    
  adjlist();
  printf("Program starting\n");
  adjmatrix();
  bfs();
  dfs();
  
}
