#include <stdio.h>
#include <string.h>
int main(int argc,char* argv[]) {
  enum {SUCCESS,FAIL,MAX_LEN=81};
  int reval=SUCCESS;
  FILE *fptr1,*fptr2;
  if ( argc != 3) {
    printf("Wrong input\n");
    return 0;
  }
  if ((fptr1 = fopen(argv[1],"r"))==NULL) {
    printf("Cannot open %s file.\n",argv[1]);
    reval=FAIL;
  } else if ((fptr2 = fopen(argv[2],"w"))==NULL) {
    printf("Cannot open %s file.\n",argv[2]);
    reval=FAIL;
  } else {
    char buff[MAX_LEN];
    int len;
    while ((fgets(buff, MAX_LEN, fptr1)) != NULL) {
      len=strlen(buff)-1;
      fprintf(fptr2,"%d %s",len,buff);
      printf("%s",buff);
    }
    
  }
  fclose(fptr1);
  fclose(fptr2);
  return reval;
}
