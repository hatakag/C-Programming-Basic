#include <stdio.h>

int main(int argc,char* argv[]) {
  if (argc!=2) {
    printf("Wrong number of input\n");
    return 0;
  }
  enum {SUCCESS,FAIL};
  FILE *fptr1;
  int reval=SUCCESS;
  if ((fptr1 = fopen(argv[1],"a+"))==NULL) {
    printf("Cannot open %s file.\n",argv[1]);
    reval=FAIL;
  } else {
    int i=0,j;
    char buff[81],buff0[81];
    while ((fgets(buff,81,fptr1))!=NULL) {
      buff0[i]=buff[0];i++;
    }
    for (j=0;j<i;j++) 
      fprintf(fptr1,"%c",buff0[j]);
    fprintf(fptr1,"\n");
    fclose(fptr1);
  }
  return reval;
}
