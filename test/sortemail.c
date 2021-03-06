#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

typedef struct phoneaddress_t{
  char name[40];
  char tel[12];
  char email[25];
}element;

void copy(element *tmp,element *a) {
  strcpy(tmp->name,a->name);
  strcpy(tmp->tel,a->tel);
  strcpy(tmp->email,a->email);
}

void swap(element *a,element *b,element *tmp) {
  //tmp=a;
  strcpy(tmp->name,a->name);
  strcpy(tmp->tel,a->tel);
  strcpy(tmp->email,a->email);
  //a=b;
  strcpy(a->name,b->name);
  strcpy(a->tel,b->tel);
  strcpy(a->email,b->email);
  //b=tmp;
  strcpy(b->name,tmp->name);
  strcpy(b->tel,tmp->tel);
  strcpy(b->email,tmp->email);
}

void heapify(element list[],int i,int n) {
  int max=i;
  int l=2*i+1;
  int r=2*i+2;
  element temp;
  if (l<n && strcmp(list[l].email,list[max].email)>0) max=l;
  if (r<n && strcmp(list[r].email,list[max].email)>0) max=r;
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

void quicksort(element list[],int left,int right) {
  int i,j;
  char pivot[25];
  element temp;
  if (left<right) {
    i=left;
    j=right+1;
    strcpy(pivot,list[left].email);
    do {
      do i++; while(strcmp(list[i].email,pivot)<0);
      do j--; while(strcmp(list[j].email,pivot)>0);
      if (i<j) swap(&list[i],&list[j],&temp);
    } while(i<j);
    swap(&list[left],&list[j],&temp);
    quicksort(list,left,j-1);
    quicksort(list,j+1,right);
  }
}


int main(int argc,char * argv[]) {
  if (argc!=2) {
    printf("Wrong number of input\n");
    return 0;
  }
  FILE *fp;
  element *phonearr;
  int i,n,irc;
  n=10;
  phonearr=(element*)malloc(n*sizeof(element));
  if ((fp=fopen(argv[1],"rb"))==NULL) {
    printf("Cannot open %s file\n",argv[1]);
    return 0;
  }
  irc=fread(phonearr,sizeof(element),n,fp);
  printf("fread return code %d\n",irc);
  fclose(fp);
  printf("\nBefore sort: ");
  for (i=0;i<n;i++) printf("%s ",phonearr[i].name);
  heapsort(phonearr,n);
  printf("\nAfter sort: ");
  for (i=0;i<n;i++) printf("%s ",phonearr[i].name);
  printf("\n");
  free(phonearr);
  return 0;
}
  
