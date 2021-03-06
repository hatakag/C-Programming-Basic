#include <stdio.h>
#include <stdlib.h>

typedef struct element_t {
  int key;
}element;

void merge(element a[],int l,int m,int r) {
  int i=l,j=m+1,k;
  int ta[1000];
  for (k=l;k<=r;k++) {
    if (i>m) {
      ta[k]=a[j].key;j++;
    } else if (j>r) {
      ta[k]=a[i].key;i++;
    } else {
      if (a[i].key<a[j].key) {
	ta[k]=a[i].key;i++;
      } else {
	ta[k]=a[j].key;j++;
      }
    }
  }
  for (k=l;k<=r;k++) a[k].key=ta[k];
}

void mergesort(element a[],int l,int r) {
  if (l<r) {
    int m=(l+r)/2;
    mergesort(a,l,m);
    mergesort(a,m+1,r);
    merge(a,l,m,r);
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
  mergesort(a,0,n-1);
  printf("\nAfter sort: ");
  for (i=0;i<n;i++) printf("%d ",a[i].key);
  printf("\n");
  //free(a);
  return 0;
}
