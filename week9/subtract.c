#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"StackLinkedList.h"

int main()
{
  char a[100],b[100];
  StackType s1,s2,result;
  
  initialize(&s1);
  initialize(&s2);
  initialize(&result);
  
  printf("Input the first number:\n");
  scanf("%[^\n]s",a);__fpurge(stdin);
  do {
    printf("Input the second number(<= first number):\n");
    scanf("%[^\n]s",b);__fpurge(stdin);
    if (atoi(a)<atoi(b)) printf("Error---Second number must be less than or equal to first number\n");
  } while(atoi(a)<atoi(b));
  int i,t1,t2,r,x;
  //push(0,&s1);
  for (i=0;i<strlen(a);i++)
    {
      push(a[i]-'0',&s1);
    }
  //push(0,&s2);
  for (i=0;i<strlen(b);i++)
    {
      push(b[i]-'0',&s2);
    }
  
  int carry=0;
  while ((!empty(s1))||(!empty(s2))) {
    if (!empty(s1)) t1=pop(&s1);
    else t1=0;
    if (!empty(s2)) t2=pop(&s2);
    else t2=0;
    if (t1>=t2) {
      r=t1-t2-carry;
      carry=0;
    }
    else  {
      r=t1+10-t2-carry;
      carry=1;
    }
    push(r,&result);
  }
  printf("Subtract: ");
  while (!empty(result)) {
    x=pop(&result);
    printf("%d",x);
  }
  printf("\n");
  return 0;
}
  
