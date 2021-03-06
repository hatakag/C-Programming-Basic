typedef int elmType;
typedef struct nodeType {
  elmType element;
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

nodeT *createNode(elmType new) {
  nodeT *n;
  n=(nodeT*)malloc(sizeof(nodeT));
  if (n!=NULL) {
    n->left=NULL;
    n->right=NULL;
    n->element=new;
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
  N->element=v;
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
