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
  //while(getchar() != '\n');
 
  printf("Input the second number:\n");
  scanf("%[^\n]s",b);__fpurge(stdin);
  //while(getchar() != '\n');
  
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
  
  int carry = 0;
  
  while ((empty(s1)!=1)||(empty(s2)!=1))
    {
      if (empty(s1)!=1) t1=pop(&s1);
          else t1=0;
      if (empty(s2)!=1) t2=pop(&s2);
          else t2=0;
      r = t1 + t2 + carry;
      if (r>=10)
	{
	  push(r-10,&result);
	  carry = 1;
	}
      else
	{
	  push(r,&result);
	  carry = 0;
	}
    }
  printf("Sum: ");
  while (!empty(result))
    {   
      x = pop(&result);
      printf("%d",x);
    }
  
  printf("\n\n");
  return 0;
}

