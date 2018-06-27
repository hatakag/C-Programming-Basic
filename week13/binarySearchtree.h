#define COUNT 5

typedef int keyType;
typedef struct nodeType {
  keyType key;
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

nodeT *createNode(keyType new) {
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

treetype search(keyType x,treetype t) {
  if (t==NULL) return NULL;
  else if (t->key==x)
    return t;
  else if (t->key<x)
    return search(x,t->right);
  else 
    return search(x,t->left);
}

void insertNode(keyType x,treetype *t) {
  if (*t==NULL) {
    *t=(nodeT*)malloc(sizeof(nodeT));
    (*t)->key=x;
    (*t)->left=NULL;
    (*t)->right=NULL;
  }
  else if (x<(*t)->key) insertNode(x,&(*t)->left);
  else if (x>(*t)->key) insertNode(x,&(*t)->right);
}

treetype insertNodeR(keyType x,treetype t) {
  if (t==NULL) {
    t=(nodeT*)malloc(sizeof(nodeT));
    t->key=x;
    t->left=NULL;
    t->right=NULL;
    return t;
  }
  else if (x<t->key) return insertNodeR(x,t->left);
  else if (x>t->key) return insertNodeR(x,t->right);
}

treetype findMin(treetype t) {
  if (t->left==NULL) return t;
  else return findMin(t->left);
}

treetype findMax(treetype t) {
  if (t->right==NULL) return t;
  else return findMax(t->right);
}

keyType deleteMin(treetype *r) {
  keyType k;
  if ((*r)->left==NULL) {
    k=(*r)->key;
    (*r)=(*r)->right;
    return k;
  }
  else return deleteMin(&(*r)->left);
}

void deleteNode(keyType x,treetype *r) {
  if (*r!=NULL) {
    if (x<(*r)->key) deleteNode(x,&(*r)->left);
    else if (x>(*r)->key) deleteNode(x,&(*r)->right);
    else if ((*r)->left==NULL && (*r)->right==NULL) *r=NULL;
    else if ((*r)->left==NULL) *r=(*r)->right;
    else if ((*r)->right==NULL) *r=(*r)->left;
    else (*r)->key=deleteMin(&(*r)->right);
  }
}


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

