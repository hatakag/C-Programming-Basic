#include <stdio.h>
#include <stdlib.h>
#include "planeticket2.h"

int main(int argc,char * argv[]) {
  if (argc!=2) {
    printf("Wrong number of input___\"./planeticket num of flight(N)\"\n");
    return 0;
  }
  int choice,num,n,i;
  int N=atoi(argv[1]);
  Queue *A,*B,*C,*D,*E,*F;
  A=(Queue*)malloc(N*sizeof(Queue));
  B=(Queue*)malloc(N*sizeof(Queue));
  C=(Queue*)malloc(N*sizeof(Queue));
  D=(Queue*)malloc(N*sizeof(Queue));
  E=(Queue*)malloc(N*sizeof(Queue));
  F=(Queue*)malloc(N*sizeof(Queue));
  for (i=1;i<=N;i++) {
    makeNullQueue(&A[i]);
    makeNullQueue(&B[i]);
    makeNullQueue(&C[i]);
    makeNullQueue(&D[i]);
    makeNullQueue(&E[i]);
    makeNullQueue(&F[i]);
  }
  do {
    choice=0;
    printf("\n_____MENU_____\n");
    printf("1.Adding\n");
    printf("2.Cancelling\n");
    printf("3.Modifying\n");
    printf("4.Quit\n");
    printf("Select: ");
    scanf("%d",&choice);__fpurge(stdin);
    switch (choice) {
    case 1:
      {
	printf("Flight number (1/2/.../N): ");scanf("%d",&num);__fpurge(stdin);
	if (num<1||num>N) {
	  printf("Invalid flight number\n");
	  break;
	}
	int sum=numQueue(A[num])+numQueue(B[num])+numQueue(C[num])+numQueue(D[num])+numQueue(E[num])+numQueue(F[num]);
	printf("Number of remained seat in this plane: %d\n",12-sum);
	printf("Quantity: ");scanf("%d",&n);__fpurge(stdin);
	if (n>12-sum) {printf("Invalid quantity.Too many not enough\n");break;}
	if (n<=0) {printf("Invalid quantity\n");break;}
	printf("Booking time: \n");
	for (i=1;i<=n;i++) {
	  Eltype x;
	  printf("Name of client %d: ",i);gets(x.name);__fpurge(stdin);
	  do {
	    printf("Seat type (W/C/N): ");scanf("%c",&x.t);__fpurge(stdin);
	    switch (x.t) {
	    case 'W'://C,F
	      {
		if (!fullQueue(C[num])) {
		  enQueue(x,&C[num]);
		  printf("Accept.Your seat is C_%d in the flight number %d\n",C[num].rear,num);
		} else if (fullQueue(C[num]) && !fullQueue(F[num])) {
		  enQueue(x,&F[num]);
		  printf("Accept.Your seat is F_%d in the flight number %d\n",F[num].rear,num);
		} else printf("Refuse/Wait.This seat type in this plane is full!\n");
		break;
	      }
	    case 'C'://A,D
	      {
		if (!fullQueue(A[num])) {
		  enQueue(x,&A[num]);
		  printf("Accept.Your seat is A_%d in the flight number %d\n",A[num].rear,num);
		} else if (fullQueue(A[num]) && !fullQueue(D[num])) {
		  enQueue(x,&D[num]);
		  printf("Accept.Your seat is D_%d in the flight number %d\n",D[num].rear,num);
		} else printf("Refuse/Wait.This seat type in this plane is full!\n");
		break;
	      }
	    case 'N'://B,E
	      {
		if (!fullQueue(B[num])) {
		  enQueue(x,&B[num]);
		  printf("Accept.Your seat is B_%d in the flight number %d\n",B[num].rear,num);
		} else if (fullQueue(B[num]) && !fullQueue(E[num])) {
		  enQueue(x,&E[num]);
		  printf("Accept.Your seat is E_%d in the flight number %d\n",E[num].rear,num);
		} else printf("Refuse/Wait.This seat type in this plane is full!\n");
		break;
	      }
	    default : printf("Invalid seat type\n");
	      break;
	    }
	  } while (x.t!='W'&&x.t!='C'&&x.t!='N');
	}
	break;
      }
    case 2:
      {
	printf("Your flight number: ");scanf("%d",&num);__fpurge(stdin);
	if (num<1||num>N) {
	  printf("Invalid flight number\n");
	  break;
	}
	char c;
	int d;
	printf("Your seat (*_*): ");scanf("%c%*c%d",&c,&d);__fpurge(stdin);/*
	if (c=='A') delQueueAt(d,&A[num]);
	else if (c=='B') delQueueAt(d,&B[num]);
	else if (c=='C') delQueueAt(d,&C[num]);
	else if (c=='D') delQueueAt(d,&D[num]);
	else if (c=='E') delQueueAt(d,&E[num]);
	else if (c=='F') delQueueAt(d,&F[num]);
	else {printf("Invalid seat column (A/B/C/D/E/F)\n");break;}
	printf("Cancelled successfully\n");*/
	break;
      }
    case 3:
      {
	printf("Your flight number: ");scanf("%d",&num);__fpurge(stdin);
	if (num<1||num>N) {
	  printf("Invalid flight number\n");
	  break;
	}
	char c;
	int d;
	printf("Your seat (*_*): ");scanf("%c%*c%d",&c,&d);__fpurge(stdin);/*
	if (c=='A') delQueueAt(d,&A[num]);
	else if (c=='B') delQueueAt(d,&B[num]);
	else if (c=='C') delQueueAt(d,&C[num]);
	else if (c=='D') delQueueAt(d,&D[num]);
	else if (c=='E') delQueueAt(d,&E[num]);
	else if (c=='F') delQueueAt(d,&F[num]);
	else {printf("Invalid seat column (A/B/C/D/E/F)\n");break;}
	printf("Modified successfully\n");*/
	break;
      }
    case 4:
      break;
    default : printf("Invalid choice\n");
      break;
    }
  } while (choice!=4);
  return 0;
}
