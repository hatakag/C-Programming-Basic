#include <stdio.h>
#include <stdlib.h>
#include "StackLinkedList.h"
#include <string.h>

int main(int argc,char * argv[]) {
  if (argc!=2) {
    printf("Wrong number of input\n");
    return 0;
  }
  StackType s;
  initialize(&s);
  int i,a,b,c;
  for (i=0;i<strlen(argv[1]);i++){
    if (argv[1][i]>='0'&&argv[1][i]<='9') push(argv[1][i]-'0',&s);
    else if (argv[1][i]=='+'||argv[1][i]=='-'||argv[1][i]=='*'||argv[1][i]=='/') {
      b=pop(&s);a=pop(&s);
      if (argv[1][i]=='+') c=a+b;
      if (argv[1][i]=='-') c=a-b;
      if (argv[1][i]=='*') c=a*b;
      if (argv[1][i]=='/') c=a/b;
      push(c,&s);
    }
  }
  printf("Calculate polish notation expression %s -> result: ",argv[1]);
  c=pop(&s);printf("%d\n",c);
  return 0;
}
