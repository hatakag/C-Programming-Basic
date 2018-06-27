#include <stdio.h>
#include <stdlib.h>
#include "StackStruct.h"

int checkMatch(char x, char y) {
  if (x=='('&&y==')') return 1;
  if (x=='['&&y==']') return 1;
  if (x=='{'&&y=='}') return 1;
  return 0;
}

enum{SUCCESS,FAIL};

int main(int argc,char *argv[]){
  FILE * fp;
  int reval=SUCCESS;
  StackType s;
  initialize(&s);
  if (argc!=2) {
    printf("Wrong number of input\n");
    return FAIL;
  }
  if ((fp=fopen(argv[1],"r"))==NULL) {
    printf("Cannot open %s file\n",argv[1]);
    return FAIL;
  } else {
    int c;
    //char buff[100];
    while ((c=fgetc(fp))!=EOF) {
      if (c=='('||c=='['||c=='{') push(c,&s);
      else if (c==')'||c==']'||c=='}') {
	if (empty(s)) {
	  printf("Not match with '%c'\n",c);
	  //printf("%s",buff);
	}
	else {
	  char x=pop(&s);
	  if (checkMatch(x,c)==0) {
	    printf("Not match with '%c' and '%c'\n",x,c);
	    //printf("%s",buff);
	  }
	}
      }
    }
  }
  while (!empty(s)) printf("Not match with '%c'\n",pop(&s));
  fclose(fp);
  return reval;
}
