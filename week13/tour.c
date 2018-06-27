#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define COUNT 6

typedef struct node node;
typedef int Eltype;
struct node {
  Eltype key;
  node *left,*right;
};
typedef node * treetype;

treetype createFrom2(Eltype e,treetype l,treetype r) {
  treetype x;
  x=(node*)malloc(sizeof(node));
  x->key=e;x->left=l;x->right=r;
  return x;
}
 
treetype buildTree(Eltype a[],int l,int r) {
  int m=(l+r)/2;
  Eltype u,v;
  treetype x=createFrom2(a[m],NULL,NULL);
  if (l==r) return x;
  x->left=buildTree(a,l,m);
  x->right=buildTree(a,m+1,r);
  u=x->left->key;v=x->right->key;
  if (u>v) 
    x->key=u;
  else x->key=v;
  return x;
}
 
void makeNullTree(treetype *T) {
  (*T)=NULL;
}

void print2D(treetype root, int space)
{
  if (root == NULL)
    return;
  space += COUNT;
  print2D(root->right, space);
  printf("\n");
  int i;
  for (i = COUNT; i < space; i++)
    printf(" ");
  printf("%d\n", root->key);
  print2D(root->left, space);
}


int main() {
  int n,i;
  printf("Number of element: ");scanf("%d",&n);__fpurge(stdin);
  int a[n];
  for (i=0;i<n;i++) {
    printf("a[%d]= ",i);scanf("%d",&a[i]);__fpurge(stdin);
  }
  treetype t;
  makeNullTree(&t);
  t=buildTree(a,0,n-1);
  print2D(t,0);
  return 0;
}
