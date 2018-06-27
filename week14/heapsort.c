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

/*
void adjust(element list[],int root,int n) {
  int child,rootkey;
  element temp;
  temp=list[root];
  rootkey=list[root].key;
  child=2*root;
  while (child<=n) {
    if ((child<n) && (list[child].key<list[child+1].key))
      child++;
    if (rootkey>list[child].key) break;
    else {
      list[child/2]=list[child];
      child*=2;
    }
  }
  list[child/2]=temp;
}
*/

void heapify(element list[],int i,int n) {
  int max=i;
  int l=2*i+1;
  int r=2*i+2;
  element temp;
  if (l<n && list[l].key>list[max].key) max=l; //change direction to reverse
  if (r<n && list[r].key>list[max].key) max=r; //
  if (max!=i) {
    swap(&list[i],&list[max],&temp);
    heapify(list,max,n);
  }
}

void heapsort(element list[],int n) {
  int i,j;
  element temp;
  for (i=n/2;i>=0;i--) heapify(list,i,n);
  for (i=n-1;i>=0;i--) {
    swap(&list[0],&list[i],&temp);
    heapify(list,0,i);
  }
}

int main() {
  int n,i;
  printf("Enter n: ");scanf("%d",&n);__fpurge(stdin);
  element *a;
  a=(element*)malloc(n*(sizeof(element)));
  for (i=0;i<n;i++) {
    printf("a[%d].key= ",i);scanf("%d",&a[i].key);__fpurge(stdin);
  }
  printf("\nBefore sort: ");
  for (i=0;i<n;i++) printf("%d ",a[i].key);
  heapsort(a,n);
  printf("\nAfter sort: ");
  for (i=0;i<n;i++) printf("%d ",a[i].key);
  printf("\n");
  free(a);
  return 0;
}
