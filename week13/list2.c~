#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define COUNT 5
typedef struct name_t{
  char full[100];
}name;
typedef struct node {
  name key;
  struct node *left,*right;
}node;
typedef node * treetype;

int compareName2(char* s1, char* s2)
{
  char buff1[30];
  char buff2[30];
  int i = strlen(s1);
  int j = strlen(s2);
  int check = 0;
  while(i >= 0 && j >= 0 && check == 0)
    {
      while(s1[i] != ' ' && i >= 0)
	i -= 1;
      while(s2[j] != ' ' && j >= 0)
	j -= 1;
      strncpy(buff1, s1 + i + 1, strlen(s1)-i+1);
      strncpy(buff2, s2 + j + 1, strlen(s2)-j+1);
      check = strcmp(buff1, buff2);
      if(check > 0) return 1;
      else if(check < 0) return -1;
      i--;
      j--;
    }
  if(i >= 0) return 1;
  if(j >= 0) return -1;
  return 0;   
}


treetype search(name x,treetype root) {
  if (root==NULL) return NULL;
  else if (compareName2((root->key).full,x.full)==0)
    return root;
  else if (compareName2((root->key).full,x.full)==-1) 
    return search(x,root->right);
  else 
    return search(x,root->left);
}

void makeNullTree(treetype *t) {
  (*t)=NULL;
}

void insertNode(name x,treetype *root) {
  if (*root==NULL) {
    *root=(node*)malloc(sizeof(node));
    (*root)->key=x;
    (*root)->left=NULL;
    (*root)->right=NULL;
  }
  else if (compareName2(((*root)->key).full,x.full)==1) 
    insertNode(x,&(*root)->left);
  else if (compareName2(((*root)->key).full,x.full)==-1) 
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
  printf("%s \n", (root->key).full);
  print2D(root->left, space);
}

void inorderPrint(treetype T) {
  if (T!=NULL) {
    inorderPrint(T->left);
    printf("%s \n",(T->key).full);
    inorderPrint(T->right);
  }
}


int main(int argc,char *argv[]) {
  if (argc!=2) {
    printf("Wrong numbe of input\n");
    return 0;
  }
  FILE *fp;
  int i,n;
  if ((fp=fopen(argv[1],"r"))==NULL) {
    printf("Cannot open %s file\n",argv[1]);
    return 0;
  }
  treetype t;
  makeNullTree(&t);
  n=28;
  name x[n];
  for (i=0;i<n;i++) {
    fscanf(fp,"%[^\n]s",x[i].full);
    fscanf(fp,"%*c");
    insertNode(x[i],&t);
  }
  fclose(fp);
  printf("\n___Student_List___\n\n");
  inorderPrint(t);
  name s;
  printf("\nStudent you want to search: \n");
  printf("Full name: ");scanf("%[^\n]s",s.full);
  if (search(s,t)!=NULL) printf("Found\n");
  else printf("Not found\n");
  print2D(t,0);
  return 0; 
}
