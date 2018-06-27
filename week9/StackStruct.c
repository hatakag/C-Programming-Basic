#define Max 50
typedef int Eltype;
typedef struct StackRec {
  Eltype storage[Max];
  int top;
};
typedef struct StackRec StackType;

void initialize(StackType *stack) {
  (*stack).top=0;
}

int empty(StackType stack) {
  return stack.top==0;
}

int full(StackType stack) {
  return stack.top==Max;
}

void push(Eltype el,StackType *stack) {
  if (full(*stack))
    printf("stack overflow\n");
  else (*stack).storage[(*stack).top++]=el;
}

Eltype pop(StackType *stack) {
  if (empty(*stack))
    printf("stack underflow\n");
  else 
    return (*stack).storage[--(*stack).top];
}
