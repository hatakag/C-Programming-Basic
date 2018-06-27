#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"StackStruct.h"

int priority(char c) {
  if (c=='*'||c=='/') return 2;
  else if (c=='+'||c=='-') return 1;
  else return 0;
}

int isop(char c) {
  if (c=='+'||c=='-'||c=='*'||c=='/') return 1;
  else return 0;
}

int main() {
  char a[100];
  StackType s,result;
  initialize(&s);
  printf("Input an expression:\n");
  gets(a);__fpurge(stdin);
  printf("Output expression:\n");
  int i;
  char x;
  for (i=0;i<strlen(a);i++) {
    if (a[i]>='0' && a[i]<='9' || a[i]==' ') printf("%c",a[i]);
    else if (a[i]=='(') push(a[i],&s);
    else if (a[i]==')') {
      x=pop(&s);
      while (x!='(') {
	printf("%c",x);
	x=pop(&s);
      }
    }
    else if (isop(a[i])) {
      while (!empty(s) && priority(a[i])<priority(top(s))) {
	x=pop(&s);
	printf("%c",x);
      }
      push(a[i],&s);
    }
  }
  while (!empty(s)) {
    x=pop(&s);
    if (x!='(') printf("%c",x);
  }
  printf("\n");
}
