#define MaxS 50
typedef int EltypeS;
struct nodeS {
  EltypeS dataS;
  struct nodeS *linkS;
};

typedef struct nodeS nodeS;
typedef struct Stack {
  nodeS *top;
}StackType;

void initialize(StackType *stack) {
  (*stack).top=NULL;
}

int empty(StackType stack) {
  return (stack.top==NULL);
}

int full (StackType stack) {
  nodeS *c=stack.top;
  int i=0;
  while (c!=NULL) {
    i++;
    c=c->linkS;
  }
  return i==MaxS;
}

void push(EltypeS value,StackType *stack) {
  nodeS *temp;
  temp=(nodeS*)malloc(sizeof(nodeS));
  if (temp==NULL) {
    printf("No mememory available Error\n");
    return ;
  }
  temp->dataS=value;
  temp->linkS=(*stack).top;
  (*stack).top=temp;
}

EltypeS pop(StackType *stack) {
  nodeS *temp;
  if ((*stack).top==NULL) {
    printf("The stack is empty cannot pop Error\n");
    return 0;
  }
  EltypeS x;
  x=(*stack).top->dataS;
  temp=(*stack).top;
  (*stack).top=(*stack).top->linkS;
  //free(temp);
  return x;
}

EltypeS top(StackType stack) {
  if (!empty(stack))
    return (stack.top)->dataS;
}


