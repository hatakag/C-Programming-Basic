#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "expression.h"

int main() {
  int choice,i;
  do {
    choice=0;
    printf("\n_____MENU_____\n");
    printf("1.Input expression\n");
    printf("2.Evaluate expression\n");
    printf("3.Quit\n");
    printf("Select: ");scanf("%d",&choice);__fpurge(stdin);
    switch (choice) {
    case 1:
      {
	char a[100],x;
	treetype t;
	makeNullTree(&t);
	StackType s1,s2;
	initialize(&s1);initialize(&s2);
	printf("Input expression: ");gets(a);__fpurge(stdin);
	for (i=0;i<strlen(a);i++) {
	  if (a[i]>='0' && a[i]<='9') push(a[i],&s1);
	  else if (a[i]=='(') push(a[i],&s2);
	  else if (a[i]==')') {
	    x=pop(&s2);
	    while (x!='(') {
	      push(a[i],&s1);
	      x=pop(&s2);
	    }
	  }
	  else if (isop(a[i])) {
	    while (!empty(s2) && priority(a[i])<priority(top(s2))) {
	      x=pop(&s2);
	      push(x,&s1);
	    }
	    push(a[i],&s2);
	  }
	}
	while (!empty(s2)) {
	  x=pop(&s2);
	  if (x!='(') push(x,&s1);
	}
	printf("\n");
	buildTree(&s1,&t);
	print2D(t,0);
	break;
      }
    case 2:
      {
	break;
      }
    case 3:
      break;
    default: printf("Invalid choice\n");
      break;
    }
  } while (choice!=3);
  printf("\n____GOODBYE____\n");
  return 0;
}
