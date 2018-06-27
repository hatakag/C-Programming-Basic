#include <stdio.h>
#include <stdlib.h>
#define n 10

int main() {
  int *arr,i;
  arr=(int*)malloc(n*sizeof(int));
  for (i=0;i<n+2;i++) {
    printf("arr[%d]= ",i);scanf("%d",&arr[i]);__fpurge(stdin);
  }
  for (i=0;i<n+2;i++) {
    printf("arr[%d]=%d\n",i,arr[i]);
  }
  return 0;
  free(arr);
}
