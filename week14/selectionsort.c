#include <stdio.h>
#include <stdlib.h>

typedef struct element_t {
  int key;
}element;

void selectionsort(element a[],int n) {
  int i,j,min,tmp;
  for (i=0;i<n-1;i++) {
    min=i;
    for (j=i+1;j<=n-1;j++)
      if (a[j].key<a[min].key) min=j;
    tmp=a[i].key;
    a[i].key=a[min].key;
    a[min].key=tmp;
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
  selectionsort(a,n);
  printf("\nAfter sort: ");
  for (i=0;i<n;i++) printf("%d ",a[i].key);
  printf("\n");
  //free(a);
  return 0;
}
