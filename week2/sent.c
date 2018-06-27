//chu hoa thanh chu thuong, thuong thanh hoa
#include <stdio.h>
#include <ctype.h>
int main() {
  enum {SUCCESS,FAIL};
  FILE *fptr1,*fptr2;
  char filename1[]="sent.txt";
  char filename2[]="sentw.txt";
  int reval=SUCCESS;
  if ((fptr1 = fopen(filename1,"r"))==NULL) {
    printf("Cannot open %s file.\n",filename1);
    reval=FAIL;
  } else if ((fptr2 = fopen(filename2,"w"))==NULL) {
    printf("Cannot open %s file.\n",filename2);
    reval=FAIL;
  } else {
    int c;
    while ((c=fgetc(fptr1))!=EOF) {
      if islower(c) c=toupper(c);
      else if isupper(c) c=tolower(c);
      fputc(c,fptr2);
      putchar(c);
    }
    fclose(fptr1);
    fclose(fptr2);   
  }
  return reval;
}

