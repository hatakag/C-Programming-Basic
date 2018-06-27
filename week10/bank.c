#include <stdio.h>
#include <stdlib.h>
#include "bank.h"

int main(int argc,char * argv[]) {
  if (argc!=2) {
    printf("Wrong number of input___\"./bank N(number of bank counter\"\n");
    return 0;
  }
  int N=atoi(argv[1]);
  Queue *q;
  q=(Queue*)malloc(N*sizeof(Queue));
  int choice,i,j;
  do {
    choice=0;
    printf("\n_____MENU_____\n");
    printf("1.Add customer\n");
    printf("2.All customer and waiting time\n");
    printf("3.Quit\n");
    printf("Select: ");scanf("%d",&choice);__fpurge(stdin);
    switch (choice) {
    case 1:
      {
	Eltype x;
	int h,min,n;
	printf("Time coming: ");scanf("%d%*c%d",&h,&min);__fpurge(stdin);
	if (min<0 || min>60) {printf("Invalid minutes\n");break;}
	x=h*60+min;
	if (x<540||x>660) {printf("Bank open from 9h->11h\n");break;}
	printf("Number of customer: ");
	scanf("%d",&n);__fpurge(stdin);
	for (j=1;j<=n;j++){
	  int flag=0;
	  for (i=0;i<N;i++){
	    while (x>=time1Queue(q[i]) && !emptyQueue(q[i])) {
	      if ((q[i].front->next)!=NULL) 
		(q[i].front->next)->el=(q[i].front)->el+15;
	      deQueue(&q[i]);}
	  }
	  int mintime=timeQueue(q[1]);
	  for (i=0;i<N;i++){
	    if (mintime>timeQueue(q[i])) mintime=timeQueue(q[i]);
	  }
	  for (i=0;i<N;i++){
	    if (emptyQueue(q[i])) {enQueue(x,&q[i]);flag=i;break;}
	  }
	  for (i=0;i<N;i++) {
	    if (!emptyQueue(q[i]) && mintime==timeQueue(q[i])) 
	      {enQueue(x,&q[i]);flag=i;break;}
	  }
	  printf("Customer number %d go to counter %d: wait %d min\n",j,flag+1,waittime(q[flag]));
	}
	break;
      }
    case 2:
      {
	int num=0;
	for (i=0;i<N;i++) {
	  num=num+numQueue(q[i]);
	  //printf("%d\n",numQueue(q[i]));
	}
	printf("Number of all customer(s): %d\n",num);
	float sum=0;
	for (i=0;i<N;i++) {
	  sum=sum+sumwaittime(q[i]);
	  //printf("%d\n",sumwaittime(q[i]));
	}
	printf("Sum of waiting time: %.0f\n",sum);
	float av;
	printf("Average waiting time: %.2f\n",av=sum/num);
	break;
      }
    case 3:
      break;
    default : printf("Invalid choice\n");
      break;
    }
  } while (choice!=3);
  free(q);
  printf("\n____GOODBYE____\n");
  return 0;
}
