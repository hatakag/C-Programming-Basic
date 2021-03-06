#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20
#define COUNT 10
typedef struct phoneaddress_t{
  char name[40];
  char tel[12];
  char email[25];
}phoneaddress;
typedef struct Node{
  phoneaddress key;
  struct Node *left,*right;
}Node;
typedef Node* treetype;

treetype search(char *email,treetype root) {
  if (root==NULL) return NULL;
  else if (strcmp((root->key).email,email)==0)
    return root;
  else if (strcmp((root->key).email,email)<0) 
    return search(email,root->right);
  else 
    return search(email,root->left);
}

void makeNullTree(treetype *t) {
  (*t)=NULL;
}

void insertNode(phoneaddress x,treetype *root) {
  if (*root==NULL) {
    *root=(Node*)malloc(sizeof(Node));
    (*root)->key=x;
    (*root)->left=NULL;
    (*root)->right=NULL;
  }
  else if (strcmp(((*root)->key).email,x.email)>0) 
    insertNode(x,&(*root)->left);
  else if (strcmp(((*root)->key).email,x.email)<0) 
    insertNode(x,&(*root)->right);
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
  printf("%s", (root->key).name);
  print2D(root->left, space);
}

void printTree(treetype t) {
  if (t==NULL) return ;
  else {
    printTree(t->left);
    printf("%s---%s---%s\n",(t->key).name,(t->key).tel,(t->key).email);
    printTree(t->right);
  }
}

int main(int argc,char * argv[]) {
  if (argc!=3) {
    printf("Wrong number of input\n");
    return 0;
  }
  FILE *fp;
  phoneaddress *phonearr;
  treetype t;
  makeNullTree(&t);
  int i,n,irc;
  n=10;
  phonearr=(phoneaddress*)malloc(n*sizeof(phoneaddress));
  if ((fp=fopen(argv[1],"rb"))==NULL) {
    printf("Cannot open %s file\n",argv[1]);
    return 0;
  }
  irc=fread(phonearr,sizeof(phoneaddress),n,fp);
  printf("fread return code %d\n",irc);
  fclose(fp);
  for (i=0;i<n;i++) {
    //printf("%s",phonearr[i].name);
    insertNode(phonearr[i],&t);
  }
  print2D(t,0);
  printf("\n");
  char email[25];
  printf("Search for email: ");
  gets(email);__fpurge(stdin);
  treetype tmp=search(email,t);
  if (tmp!=NULL) {
    FILE *fp1;
    if ((fp1=fopen(argv[2],"w"))==NULL) {
      printf("Cannot open %s file\n",argv[2]);
      return 0;
    }
    printf("%s---%s---%s\n",(tmp->key).name,(tmp->key).tel,(tmp->key).email);
    fprintf(fp1,"%s---%s---%s\n",(tmp->key).name,(tmp->key).tel,(tmp->key).email);
  }
  else printf("Not found\n");
  printf("\n");
  printf("Data stored in tree: \n");
  printTree(t);
  free(phonearr);
  return 0;
}
