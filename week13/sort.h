
void insertionSort(element list[],int n) {
  int i,j;
  element next;
  for (i=1;i<n;i++) {
    next=list[i];
    for (j==i-1;j>0 && next.key<list[j].key;j--) 
      list[j+1]=list[j];
    list[j+1]=next;
  }
}

void selectionSort(element list[],int n) {
  int i,j,min,tmp;
  for (i=0;i<n-1;i++) {
    min=i;
    for (j=i+1;j<=n-1;j++)
      if (a[j].key<a[min].key)
	min=j;
    tmp=a[i];
    a[i]=a[min];
    a[min]=tmp;
  }
}

void adjust(element list[],int root,int n) {
  int child, rootkey;
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

void heapSort(element list[],int n) {
  int i,j;
  element temp;
  for (i=n/2;i>0;i--) adjust(list,i,n);
  for (i=n-1;i>0;i--) {
    temp=list[1];
    list[1]=list[i+1];
    list[i+1]=temp;
    adjust(list,1,i);
  }
}
