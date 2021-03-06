#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char * my_strcat(char * str1,char * str2) {
  int l1,l2;
  char * result;
  l1=strlen(str1);
  l2=strlen(str2);
  result=(char*)malloc((l1+l2+1)*sizeof(char));
  if (result==NULL) {
    printf("Allocation failed! Check memory\n");
    return NULL;
  }
  strcpy(result,str1);
  strcpy(result+l1,str2);
  return result;
}
int main(void) {
  char str1[100],str2[100];
  char * cat_str;
  printf("Enter 2 string:\n");
  scanf("%100s",str1);
  getchar();
  scanf("%100s",str2);
  cat_str=my_strcat(str1,str2);
  if (cat_str==NULL) {
    printf("Memory allocation failed!\n");
    return 1;
  }
  printf("The concatenation of %s and %s is %s\n",str1,str2,cat_str);
  free(cat_str);
  return 0;
}
