#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * subStr(char * s1,int offset,int number) {
  char *substr;
  substr=(char*)malloc((number)*sizeof(char));
  if (number>strlen(s1)-offset) {
    strcpy(substr,s1+offset);
    return substr;
  }
  else {
    strcpy(substr,s1+offset);
    substr[number]='\0';
    return substr;
  }
}
int main() {
  char s[100];
  int offset,number;
  printf("Input a string: ");gets(s);__fpurge(stdin);
  printf("Input offset index: ");scanf("%d",&offset);__fpurge(stdin);
  if (offset>strlen(s)) {
    printf("Error-offset index must be less than string length\n"); 
    return 0;
  }
  printf("Input number of character: ");scanf("%d",&number);__fpurge(stdin);
  printf("Substring from string \"%s\" begin at offset index %d with %d number of characters is \"%s\"\n",s,offset,number,subStr(s,offset,number));
  return 0;
}
