#include <stdio.h>
int main(int argc,char * argv[]){
  if (argc!=2) {
    printf("WRONG INPUT\n");
    return 0;
  }
  enum {SUCCESS,FAIL};
  FILE *fptr;
  int reval=SUCCESS;
  if ((fptr = fopen(argv[1],"r+"))==NULL) {
    printf("Cannot open %s file\n",argv[1]);
    reval=FAIL;
  } else {
    char buff[3];
    while ((fgets(buff,3,fptr))!=NULL) {
      printf("%s",buff);
    }
  }
  fclose(fptr);
  return reval;
}
