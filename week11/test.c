#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "binarySearch.h"

int main(int argc,char * argv[]) {
  if (argc!=2) {
    printf("Wrong number of input\n");
    return 0;
  }
  N=atoi(argv[1]);
  int *a;
  a=(int*)malloc(N*sizeof(int));
  int i,x;
  for (i=0;i<N;i++) {
    a[i]=i;
  }
  printf("Search: ");scanf("%d",&x);__fpurge(stdin);
  clock_t start1=clock();
  binSearch(x,a,N);
  clock_t finish1=clock();
  double duration1=(double)(finish1-start1)/CLOCKS_PER_SEC;
  printf("binSearch: %d in %f\n",binSearch(x,a,N),duration1);o
  clock_t start2=clock();
  binRecSearch(x,a,0,N-1);
  clock_t finish2=clock();
  double duration2=(double)(finish2-start2)/CLOCKS_PER_SEC;
  printf("binRecSearch: %d in %f\n",binRecSearch(x,a,0,N-1),duration2);
  free(a);
  return 0;
}
