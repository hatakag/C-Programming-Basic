#include <stdio.h>
#include <stdlib.h>

typedef struct element_t {
  int key;
}element;

void bubblesort(element a[],int n) {
  int swap,i,tmp;
  do {
    swap=0;
    for (i=0;i<n;i++)
      if (a[i].key>a[i+1].key) {
	tmp=a[i].key;
	a[i].key=a[i+1].key;
	a[i+1].key=tmp;
	swap=1;
      }
  } while (swap==1);
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
  bubblesort(a,n);
  printf("\nAfter sort: ");
  for (i=0;i<n;i++) printf("%d ",a[i].key);
  printf("\n");
  //free(a);
  return 0;
}
