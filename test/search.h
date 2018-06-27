int selfOrgSeqSearch (int key,int r[],int n) { //transpose
  int i;
  int tempr;
  for (i=0;i<n-1 && r[i]!=key;i++);
  if (key==r[i]) {
    if (i>0) {
      //Transpose with predecessor
      tempr=r[i];
      r[i]=r[i-1];
      r[--i]=tempr;
    }
    return (i);
  } else return (-1);
}

int selfOrgSearch (int key,int r[],int n) { //move to front
  int i,j;
  int tempr;
  for (i=0;i<n-1 && r[i]!=key;i++) ;
  if (key==r[i]) {
    if (i>0) {
      tempr=r[i];
      for (j=i;j>0;j--) r[j]=r[j-1];
      r[0]=tempr;
    }
    return (i);
  } else return (-1);
}

#include "LinkedList.h"

int movetofront(char *model,node** r) {
  node *p=r,*c;
  int i=0;
  while (p!=NULL && strcmp((p->element).model,model)!=0) {
    p=p->next;
    i++;
  }
  if (p!=NULL) {
    elementtype tmp=p->element;
    deleteAtk(i,r,*c);
    insertAtHead(tmp,r,*c);
    return i;
  }
  else return -1;
}

int transpose(char *model,node** r) {
  node *p=r,*c;
  int i=0;
  while (p!=NULL && strcmp(((p->next)->element).model,model)!=0) {
    p=p->next;
    i++;
  }
  if (p!=NULL) {
    swapNode(p,p->next);
    return i+1;
  }
  else return -1;
}

typedef int type;
typedef struct {
  type el;
  int count;
}Eltypes;

int countSearch(type x,Eltypes a[],int N){
  int i,j,k=-1;
  for (i=0;i<N;i++) {
    if (a[i].el==x) {a[i].count++;k=i;}
  }
  for (i=0;i<N;i++) {
    for (j=i;j<N;j++) {
      if (a[j].count>a[i].count) {
	Eltypes tmp;
	tmp.el=a[i].el;tmp.count=a[i].count;
	a[i].el=a[j].el;a[i].count=a[j].count;
	a[j].el=tmp.el;a[j].count=tmp.count;
      }
    }
  }
  return k;
}

typedef int Eltypeb;

int binSearch(Eltypeb target,Eltypeb list[],int size) {
  int mid,lo=0,hi=size-1;
  while (lo<=hi) {
    mid=(lo+hi)/2;
    if (list[mid]==target)
      return mid;
    else if (target<list[mid])
      hi=mid-1;
    else lo=mid+1;
  }
  return -1;
}

int binRecSearch(Eltypeb target,Eltypeb list[],int lo,int hi) {
  if (lo>hi) return -1;
  int mid=(lo+hi)/2;
  if (list[mid]<target) return binRecSearch(target,list,mid+1,hi);
  else if (list[mid]>target) return binRecSearch(target,list,lo,mid-1);
  else return mid;
  return -1;
}
