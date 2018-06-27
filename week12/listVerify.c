#include <stdio.h>
#include <string.h>
#define MAXSIZE 1000
typedef struct {
  int key;
  char value[30];
}element;
//element list[MAXSIZE];

int seqsearch(element list[],int size,int key) {
  int k=0;
  while (list[k].key!=key && k<size)
    k++;
  if (k<size) return k;
  return -1;
}

int binSearch(element list[],int searchnum, int n) {
  int left=0,right=n-1,middle;
  while (left<=right) {
    middle=(left+right)/2;
    switch (/*COMPARE*/(list[middle].key-searchnum)) {
    case -1: left=middle+1;
    case 0: {return middle;break;}
    case 1: right=middle-1;
    }
  }
  return -1;
}

void verify1(element list1[],element list2[],int n,int m) {
  int i,j;
  int mark[MAXSIZE];
  for (i=0;i<n;i++) 
    mark[i]=0;
  for (i=0;i<n;i++) {
    if ((j=seqsearch(list2,m,list1[i].key))<0)
      printf("%d is not in list 2\n",list1[i].key);
    else {
      if (strcmp(list1[i].value,list2[j].value)!=0) {
	printf("%d is in both list 1 and list 2 but have different value\n",list1[i].key);
      }
      mark[j]=1;
    }
  }
  for (i=0;i<m;i++) 
    if (!mark[i])
      printf("%d is not in list 1\n",list2[i].key);
}

void sort(element list[],int n) {
  int i,j;
  element tmp;
  for (i=0;i<n;i++) {
    for (j=i;j<n;j++) {
      if (list[i].key<list[j].key) {
	tmp=list[j];
	list[j]=list[i];
	list[i]=tmp;
      }
    }
  }
}

void verify2(element list1[],element list2[],int n,int m) {
  int i,j;
  sort(list1,n);
  sort(list2,n);
  i=j=0;
  while (i<n && j<m) {
    if (list1[i].key<list2[j].key) {
      printf("%d is not in list 2\n",list1[i].key);
      i++;
    }
    else if (list1[i].key==list2[j].key) {
      if (strcmp(list1[i].value,list2[j].value)!=0) {
	printf("%d is in both list 1 and list 2 but have different value\n",list1[i].key);
      }
      i++;j++;
    }
    else {
      printf("%d is not in list 1\n",list2[j].key);
      j++;
    }
  }
  for (;i<n;i++)
    printf("%d is not in list 2\n",list1[i].key);
  for (;j<m;j++)
    printf("%d is not in list 1\n",list2[j].key);
}

int main() {
  int n,m,i;
  printf("Size of list 1 and list 2: ");
  scanf("%d %d",&n,&m);__fpurge(stdin);
  element list1[n],list2[m];
  for (i=0;i<n;i++) {
    printf("Key and value of element %d in list 1: ",i);
    scanf("%d %s",&list1[i].key,list1[i].value);__fpurge(stdin);
  }
  for (i=0;i<m;i++) {
    printf("Key and value of element %d in list 2: ",i);
    scanf("%d %s",&list2[i].key,list2[i].value);__fpurge(stdin);
  }
  printf("\n___LIST VERIFICATION___\n");
  printf("\n");
  verify1(list1,list2,n,m);
  printf("________________________\n\n");
  verify2(list1,list2,n,m);
  return 0;
}
