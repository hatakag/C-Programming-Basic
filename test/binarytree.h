#define COUNT 5

typedef int elmType;
typedef struct nodeType {
  elmType key;
  struct nodeType *left,*right;
}nodeT;
typedef struct nodeType *treetype;

#include "QueueLinkedListTree.h"
#include "StackLinkedListTree.h"

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

nodeT *createNode(elmType new) {
  nodeT *n;
  n=(nodeT*)malloc(sizeof(nodeT));
  if (n!=NULL) {
    n->left=NULL;
    n->right=NULL;
    n->key=new;
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

treetype createFrom2(elmType v,treetype l,treetype r) {
  treetype N;
  N=(nodeT*)malloc(sizeof(nodeT));
  N->key=v;
  N->left=l;
  N->right=r;
  return N;
}

treetype addLeft(treetype *T,elmType e) {
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

treetype addRight(treetype *T,elmType e) {
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
    printf("%d ",T->key);
    inorderPrint(T->right);
  }
}

void postorderPrint(treetype T) {
  if (T!=NULL) {
    postorderPrint(T->left);
    postorderPrint(T->right);
    printf("%d ",T->key);
  }
}

void preorderPrint(treetype T) {
  if (T!=NULL) {
    printf("%d ",T->key);
    preorderPrint(T->left);
    preorderPrint(T->right);
  }
}

void iter_inorder(treetype node) { //using stack
  StackTypeT top;
  initializeT(&top);
  for (;;) {
    for (;node;node=node->left)
      pushT(node,&top);
    if (!emptyT(top)) node=popT(&top);
    if (node==NULL) break;
    printf("%d ",node->key);
    node=node->right;
  }
}

void breath_first(treetype node) {
  QueueT queue;
  treetype c;
  makeNullQueueT(&queue);
  if (node!=NULL) {
    enQueueT(node,&queue);
    while (!emptyQueueT(queue)) {
      node=deQueueT(&queue);
      printf("%d ",node->key);
      if (node->left!=NULL) {
	enQueueT(node->left,&queue);
      }
      if (node->right!=NULL) {
	enQueueT(node->right,&queue);
      }
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


void freetree(treetype t) {
  if (t!=NULL) {
    freetree(t->left);
    freetree(t->right);
    free((void*)t);
  }
}

void print2D(treetype root, int space)
{
  // Base case
  if (root == NULL)
    return;
  
  // Increase distance between levels
  space += COUNT;
  
  // Process right child first
  print2D(root->right, space);
  
  // Print current node after space
  // count
  printf("\n");
  int i;
  for (i = COUNT; i < space; i++)
    printf(" ");
  printf("%d\n", root->key);
  
  // Process left child
  print2D(root->left, space);
}

treetype buildTree(Eltype a[],int l,int r) { //t=buildTree(a,0,n-1);
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
