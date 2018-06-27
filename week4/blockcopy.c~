#include <stdio.h>
#include <stdlib.h>
enum {SUCCESS,FAIL};
void blockreadwrite(FILE *fin,FILE *fout){
  int num;
  char buff[81];
  while (!feof(fin)){
    num = fread(buff,sizeof(char),80,fin);
    buff[num*sizeof(char)]='\0';
    printf("%s",buff);
    fwrite(buff,sizeof(char),num,fout);
  }
}
int main(){
  FILE *fptr1,*fptr2;
  int reval=SUCCESS;
  if ((fptr1=fopen("lab1.txt","r"))==NULL){
    printf("Cannot open %s file\n","lab1.txt");
    reval=FAIL;
  }
  if ((fptr2=fopen("lab1a.txt","w"))==NULL){
    printf("Cannot open %s file\n","lab1a.txt");
    reval=FAIL;
  }
  else {
    blockreadwrite(fptr1,fptr2);
  }
  fclose(fptr1);
  fclose(fptr2);
  return reval;
}
