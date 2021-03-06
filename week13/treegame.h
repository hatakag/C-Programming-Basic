#include "StackLinkedList.h"
#include "QueueLinkedList.h"
#define COUNT 10

typedef char elmType;
typedef struct nodeType {
  elmType element[40];
  struct nodeType *left,*right;
}nodeT;
typedef struct nodeType *treetype;

void makeNullTree(treetype *T) {
  (*T)=NULL;
}

int emptyTree(treetype T) {
  return T==NULL;
}

treetype leftChild(treetype T) {
  if (T!=NULL) return T->left;
  else return NULL;
}

treetype rightChild(treetype T) {
  if (T!=NULL) return T->right;
  else return NULL;
}

nodeT *createNode(elmType new[]) {
  nodeT *n;
  n=(nodeT*)malloc(sizeof(nodeT));
  if (n!=NULL) {
    n->left=NULL;
    n->right=NULL;
    strcpy(n->element,new);
  }
  return n;
}

int isLeaf(treetype T) {
  if (T!=NULL) 
    return (leftChild(T)==NULL)&&(rightChild(T)==NULL);
  else return 0;
}

int nbNode(treetype T) {
  if (emptyTree(T)) return 0;
  else return 1+nbNode(leftChild(T))+nbNode(rightChild(T));
}

treetype createFrom2(elmType v[],treetype l,treetype r) {
  treetype N;
  N=(nodeT*)malloc(sizeof(nodeT));
  strcpy(N->element,v);
  N->left=l;
  N->right=r;
  return N;
}

treetype addLeft(treetype *T,elmType e[]) {
  nodeT *new=createNode(e);
  if (new==NULL) return new;
  if (*T==NULL) *T=new;
  else {
    nodeT *Lnode=*T;
    while (Lnode->left!=NULL) Lnode=Lnode->left;
    Lnode->left=new;
  }
  return new;
}

treetype addRight(treetype *T,elmType e[]) {
  nodeT *new=createNode(e);
  if (new==NULL) return new;
  if (*T==NULL) *T=new;
  else {
    nodeT *Rnode=*T;
    while (Rnode->right!=NULL) Rnode=Rnode->right;
    Rnode->right=new;
  }
  return new;
}
//traversing
void inorderPrint(treetype T) {
  if (T!=NULL) {
    inorderPrint(T->left);
    printf("%s\n",T->element);
    inorderPrint(T->right);
  }
}

void postorderPrint(treetype T) {
  if (T!=NULL) {
    postorderPrint(T->left);
    postorderPrint(T->right);
    printf("%s\n",T->element);
  }
}

void preorderPrint(treetype T) {
  if (T!=NULL) {
    printf("%s\n",T->element);
    preorderPrint(T->left);
    preorderPrint(T->right);
  }
}
/*
void iter_inorder(treetype node) { //using stack
  StackType top;
  initialize(&top);
  //treetype stack[MaxS];
  for (;;) {
    for (;node;node=node->left)
      push(node->key,&top);
    node->key=pop(&top);
    if (node==NULL) break;
    printf("%d",node->key);
    node=node->right;
  }
}

void breath_first(treetype node) {
  Queue queue;
  if (node!=NULL) {
    enQueue(node->key,&queue);
    while (!emptyQueue(queue)) {
      node->key=deQueue(&queue);
      printf("%d",node->key);
      if (node->left!=NULL)
	enQueue(node->left->key,&queue);
      if (node->right!=NULL) 
	enQueue(node->right->key,&queue);
    }
  }
}
//

void prettyPrint(treetype t,char* prefix) {
  char *prefixend=prefix+strlen(prefix);
  if (t!=NULL) {
    printf("%4d",t->key);
    if (t->left!=NULL) 
      if (t->right==NULL) {
	wprintf("\304");strcat(prefix,"     ");
      }
      else {
	wprintf("\302");strcat(prefix,"\263     ");
      }
    prettyPrint(t->left,prefix);
    *prefixend='\0';
    if (t->right!=NULL)
      if (t->left!=NULL) {
	printf("\n%s",prefix);wprintf("\300");
      } else wprintf("\304");
    strcat(prefix,"     ");
    prettyPrint(t->right,prefix);
  }
}
*/

void freetree(treetype t) {
  if (t!=NULL) {
    freetree(t->left);
    freetree(t->right);
    free((void*)t);
  }
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
  printf("%s\n", root->element);
  print2D(root->left, space);
}

void fprint2D(treetype root, int space,FILE *fp)
{
  if (root == NULL)
    return;
  space += COUNT;
  fprint2D(root->right, space,fp);
  fprintf(fp,"\n");
  int i;
  for (i = COUNT; i < space; i++)
    fprintf(fp," ");
  fprintf(fp,"%s\n", root->element);
  fprint2D(root->left, space,fp);
}

void makeTreeFrom(treetype *t,int n) {
  while (nbNode(*t)<=n/2) {
    if (*t==NULL) *t=createNode("0");
    addLeft(t,"0");
    addRight(t,"0");
    makeTreeFrom(&(*t)->left,n/2);
    makeTreeFrom(&(*t)->right,n/2);
  }
}
