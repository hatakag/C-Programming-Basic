#include <stdio.h>
#include <stdlib.h>
#include "os.h"

int main(int argc,char * argv[]) {
  if (argc!=3) {
    printf("Wrong number of input___\"./os #process run_memory\"\n");
    return 0;
  }
  int Max=atoi(argv[1]);
  Queue q1,q2;
  makeNullQueue(&q1);makeNullQueue(&q2);
  int choice;
  do {
    choice=0;
    printf("\n_____MENU_____\n");
    printf("1.Create new program\n");
    printf("2.Kill a program\n");
    printf("3.Running and Waiting processes\n");
    printf("4.Quit\n");
    printf("Select: ");
    scanf("%d",&choice);__fpurge(stdin);
    switch (choice) {
    case 1:
      {
	if (fullQueue(q1,Max)) printf("Full of running program. Cannot run new program -> waiting program\n");
	if (fullQueue(q2,Max)) {printf("Full of waiting program. Cannot wait new program -> kill programs for run\n");break;}
	float m;
	printf("Amount of necessary memory(MB): ");
	scanf("%f",&m);__fpurge(stdin);
	if (m<0) printf("Invalid memory amount\n");
	else if (m>atof(argv[2])) printf("Need too much memory\n");
	else {
	  int id;
	  printf("Program id: ");scanf("%d",&id);__fpurge(stdin);
	  Eltype x;
	  x.id=id;
	  x.m=m;
	  if (m+summem(q1)<=atof(argv[2]) && emptyQueue(q2)) enQueue(x,&q1,Max);
	  else enQueue(x,&q2,Max);
	}
	break;
      } 
    case 2:
      {
	if (emptyQueue(q1)) printf("There is no running program\n");
	else {
	  printf("Kill a running program\n");
	  deQueue(&q1);
	  while (!emptyQueue(q2)) {
	    if (topQueue(q2).m+summem(q1)<=atof(argv[2]))  
	      enQueue(deQueue(&q2),&q1,Max);
	    else break; 
	  }
	}
	break;
      }
    case 3:
      {
	if (emptyQueue(q1)) printf("There is no running program\n");
	else {
	  printf("Running program: \n");
	  printQueue(q1);
	}
	if (emptyQueue(q2)) printf("There is no waiting program\n");
	else {
	  printf("Waiting program: \n");
	  printQueue(q2);
	}
	break;
      }
    case 4:
      break;
    default: printf("Invalid choice\n");
      break;
    }
  } while(choice!=4);
  printf("\n____GOODBYE____\n");
  return 0;
}
