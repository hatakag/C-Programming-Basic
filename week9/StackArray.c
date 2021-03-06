#include <stdio.h>
#include "StackArray.h"
#define Max 50
typedef int Eltype;
typedef Eltype StackType[Max];
int top;

void initialize(StackType stack) {
  top=0;
}

int empty(StackType stack) {
  return top==0;
}

int full(StackType stack) {
  return top==Max;
}

void push(Eltype el,StackType stack) {
  if (full(stack))
    printf("stack overflow\n");
  else stack[top++]=el;
}

Eltype pop(StackType stack) {
  if (empty(stack))
    printf("stack underflow\n");
  else return stack[--top];
}

Eltype top(StackType stack) {
  if (empty(stack)) {
    printf("stack overflow\n");
    return -999999;
  }
  else return stack[top-1];
}

