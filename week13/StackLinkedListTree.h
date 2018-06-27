#define MaxST 50
typedef treetype EltypeST;
struct nodeST {
  EltypeST dataST;
  struct nodeST *linkST;
};

typedef struct nodeST nodeST;
typedef struct StackT {
  nodeST *topT;
}StackTypeT;

void initializeT(StackTypeT *stack) {
  (*stack).topT=NULL;
}

int emptyT(StackTypeT stack) {
  return (stack.topT==NULL);
}

int fullT(StackTypeT stack) {
  nodeST *c=stack.topT;
  int i=0;
  while (c!=NULL) {
    i++;
    c=c->linkST;
  }
  return i==MaxST;
}

void pushT(EltypeST value,StackTypeT *stack) {
  nodeST *temp;
  temp=(nodeST*)malloc(sizeof(nodeST));
  if (temp==NULL) {
    printf("No mememory available Error\n");
    return ;
  }
  temp->dataST=value;
  temp->linkST=(*stack).topT;
  (*stack).topT=temp;
}

EltypeST popT(StackTypeT *stack) {
  nodeST *temp;
  if ((*stack).topT==NULL) {
    printf("The stack is empty cannot pop Error\n");
    return 0;
  }
  EltypeST x;
  x=(*stack).topT->dataST;
  temp=(*stack).topT;
  (*stack).topT=(*stack).topT->linkST;
  free(temp);
  return x;
}

EltypeST topT(StackTypeT stack) {
  if (!emptyT(stack))
    return (stack.topT)->dataST;
}


