#include <stdio.h>

int main() {
  enum {SUCCESS,FAIL};
  int reval=SUCCESS;
  int line=0,c;
  FILE * fptr;
  if ((fptr = fopen("class1EF.txt","r+"))==NULL) {
    printf("Cannot open %s file.\n","class1EF.txt");
    reval=FAIL;
  } else {
    while ((c=fgetc(fptr))!=EOF) {
      if (c=='\n') {
	//fseek(fptr,-1,SEEK_CUR);
	fputc('\n',fptr);
      }
    }  
  }
  fclose(fptr);
  return reval;
}
