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
//
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
//
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
      do i++; while(list[i].key<pivot); //change direction to reverse
      do j--; while(list[j].key>pivot); //
      if (i<j) swap(&list[i],&list[j],&temp);
    } while(i<j);
    swap(&list[left],&list[j],&temp);
    quicksort(list,left,j-1);
    quicksort(list,j+1,right);
  }
}
//
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
//
