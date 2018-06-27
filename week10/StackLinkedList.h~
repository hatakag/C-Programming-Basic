#define Max 50
typedef int Eltype;
struct node {
  Eltype data;
  struct node *link;
};

typedef struct node node;
typedef struct Stack {
  node *top;
}StackType;

void initialize(StackType *stack) {
  (*stack).top=NULL;
}

int empty(StackType stack) {
  return (stack.top==NULL);
}

int full (StackType stack) {
  node *c=stack.top;
  int i=0;
  while (c!=NULL) {
    i++;
    c=c->link;
  }
  return i==Max;
}

void push(int value,StackType *stack) {
  node *temp;
  temp=(node*)malloc(sizeof(node));
  if (temp==NULL) {
    printf("No mememory available Error\n");
    return ;
  }
  temp->data=value;
  temp->link=(*stack).top;
  (*stack).top=temp;
}

Eltype pop(StackType *stack) {
  node *temp;
  if ((*stack).top==NULL) {
    printf("The stack is empty cannot pop Error\n");
    return 0;
  }
  Eltype x;
  x=(*stack).top->data;
  temp=(*stack).top;
  (*stack).top=(*stack).top->link;
  //free(temp);
  return x;
}

Eltype top(StackType stack) {
  if (!empty(stack))
    return (stack.top)->data;
}


