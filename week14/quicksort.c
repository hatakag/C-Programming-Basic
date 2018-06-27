#include <stdio.h>
#include <stdlib.h>

typedef struct element_t {
  int key;
}element;

void swap(element *a,element *b,element *tmp) {
  tmp->key=a->key;
  a->key=b->key;
  b->key=tmp->key;
}

void quicksort(element list[],int left,int right) {
  int pivot,i,j;
  element temp;
  if (left<right) {
    i=left;
    j=right+1;
    pivot=list[left].key;
    do {
      do i++; while(list[i].key<pivot);  //change direction to reverse
      do j--; while(list[j].key>pivot);  //
      if (i<j) swap(&list[i],&list[j],&temp);
    } while(i<j);
    swap(&list[left],&list[j],&temp);
    quicksort(list,left,j-1);
    quicksort(list,j+1,right);
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
  quicksort(a,0,n-1);
  printf("\nAfter sort: ");
  for (i=0;i<n;i++) printf("%d ",a[i].key);
  printf("\n");
  //free(a);
  return 0;
}
