#include <stdio.h>
#include <stdlib.h>
#include "StackLinkedList.h"

int main() 
{
  int n;
  printf("Input a integer number: ");
  scanf("%d",&n);__fpurge(stdin);
  StackType s;
  initialize(&s);
  int d;
  while(n){
    d=n%2;
    push(d,&s);
    n=n/2;
  }
  int x;
  while (!empty(s)) {
    x=pop(&s);
    printf("%d",x);
  }
  printf("\n\n");
  return 0;
}
