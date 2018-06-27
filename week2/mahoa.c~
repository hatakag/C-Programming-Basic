#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main(int argc,char* argv[]){
  if (argc!=3) {
    printf("Wrong input\n");
    return 1;
  }
  if (atoi(argv[2])<0) {
    printf("Error--Difference must be >=0\n");
    return 0;
  }
  enum {SUCCESS,FAIL};
  int reval=SUCCESS;
  FILE * fptr;
  if ((fptr = fopen(argv[1],"r+"))==NULL) {
    printf("Cannot open %s file.\n",argv[1]);
    reval=FAIL;
  } else {
    int c;
    while ((c=fgetc(fptr))!=EOF) {
      if (c>=65&&c<=90) c=(c-65+atoi(argv[2]))%26+65;
      else if (c>=97&&c<=122) c=(c-97+atoi(argv[2]))%26+97;
      else c=c;
      fseek(fptr,-1,SEEK_CUR);
      fputc(c,fptr);
      putchar(c);
    }
    fclose(fptr);
  }
  return reval;
}
