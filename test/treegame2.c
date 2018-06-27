#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define COUNT 6

typedef struct node node;
typedef struct {
  int k;
  char name[40];
} Eltype;
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
  if (0+rand()%2==1) {  // trinh dieu kien thang thua o day (random)
    x->key=u;
  }
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
  printf("%s \n",(root->key).name);
  print2D(root->left, space);
}

int main(int argc,char * argv[]) {
  if (argc!=2) {
    printf("Wrong number of input\n");
    return 0;
  }
  FILE *fp1,*fp2;
  int i,n,irc;
  n=16;
  if ((fp1=fopen("USopen.txt","r"))==NULL) {
    printf("Cannot open %s file\n","USopen.txt");
    return 0;
  }
  Eltype *m;
  m=(Eltype*)malloc(n*sizeof(Eltype));
  for (i=0;i<n;i++) {
    m[i].k=i;
    fscanf(fp1,"%[^,]s",m[i].name);
    fscanf(fp1,"%*c");
    printf("%s(%d) ",m[i].name,m[i].k);
  }
  printf("\n");
  fclose(fp1);
  treetype t;
  makeNullTree(&t);
  srand(time(NULL));
  t=buildTree(m,0,n-1);
  print2D(t,0);
  free(m);
  return 0;
}

  
