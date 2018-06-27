#include <stdio.h>
enum {SUCCESS,FAIL,MAX_LEN=81};
void LineReadWrite(FILE* fin, FILE *fout) {
  char buff[MAX_LEN];
  while(fgets(buff, MAX_LEN, fin) != NULL) {
    fputs(buff, fout);
    printf("%s",buff);
  }
  
