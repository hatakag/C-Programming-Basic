#include <stdio.h>
void CharReadWrite(FILE* fin,FILE* fout) {
  int c;
  while ((c=fgetc(fin))!=EOF) {
    fputc(c,fout);
    putchar(c);
  }
}
int main() {
  enum {SUCCESS,FAIL};
  FILE *fptr1,*fptr2;
  char filename1[]="lab1.txt";
  char filename2[]="lab1w.txt";
  int reval=SUCCESS;
  if ((fptr1 = fopen(filename1,"r"))==NULL) {
    printf("Cannot open %s file.\n",filename1);
    reval=FAIL;
  } else if ((fptr2 = fopen(filename2,"w"))==NULL) {
    printf("Cannot open %s file.\n",filename2);
    reval=FAIL;
  } else {
    CharReadWrite(fptr1,fptr2);
    fclose(fptr1);
    fclose(fptr2);   
  }
  return reval;
}
  
