#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "StackLinkedList.h"


int main() {
  int choice,a,b,c;
  StackType i,s;
  initialize(&i);
  initialize(&s);
  do {
    choice=0;
    printf("\n_____MENU_____\n");
    printf("1.Add 1 element\n");
    printf("2.Top element\n");
    printf("3.Pop 1 element\n");
    printf("4.Undo\n");
    printf("5.Quit\n");
    printf("select: ");
    scanf("%d",&choice);__fpurge(stdin);
    switch (choice) {
    case 1:
      {
	printf("Push element (interger): ");
	scanf("%d",&a);__fpurge(stdin);
	push(a,&i);push(-99999*a,&s);
	break;
      }
    case 2:
      {
	if (empty(i)) printf("No element\n");
	else printf("Top element: %d\n",top(i));
	break;
      }
    case 3:
      {
	b=pop(&i);
	printf("Pop element: %d\n",b);
	push(b,&s);
	break;
      }
    case 4:
      {
	c=pop(&s);
	//while (c) {
	  if (c<=-99999||c>=99999) {
	    printf("Undo push %d -> pop %d\n",c/-99999,c/-99999);pop(&i);
	  }
	  else {
	    printf("Undo pop %d -> push %d\n",c,c);push(c,&i);
	  }
	  //}
	break;
      }
    case 5: 
      break;
    default: printf("Invalid choice\n");
      break;
    }
  } while(choice!=5);
  printf("\n____GOODBYE____\n");
  return 0;
}
