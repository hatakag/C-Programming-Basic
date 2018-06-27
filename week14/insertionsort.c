#include <stdio.h>
#include <stdlib.h>

typedef struct element_t {
  int key;
}element;

void insertionsort(element list[],int n) {
  int i,j;
  element next;
  for (i=1;i<n;i++) {
    next=list[i];
    for (j=i-1;j>=0 && next.key < list[j].key;j--) 
      list[j+1]=list[j];
    list[j+1]=next;
  }
}

int main() {
  int n,i;
  printf("Enter n: ");scanf("%d",&n);__fpurge(stdin);
  element a[n];
  //a=(element*)malloc(n*(sizeof(element)));
  for (i=0;i<n;i++) {
    printf("a[%d].key= ",i);scanf("%d",&a[i].key);__fpurge(stdin);
  }
  printf("\nBefore sort: ");
  for (i=0;i<n;i++) printf("%d ",a[i].key);
  insertionsort(a,n);
  printf("\nAfter sort: ");
  for (i=0;i<n;i++) printf("%d ",a[i].key);
  printf("\n");
  //free(a);
  return 0;
}
