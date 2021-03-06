#include <stdio.h>
int main(int argc,char * argv[]) {
  if (argc != 4) {
    printf("WRONG INPUT\n");
    return 0;
  }
  enum {SUCCESS,FAIL};
  FILE *fptr1,*fptr2,*fptr3;
  int reval=SUCCESS,i;
  if ((fptr1 = fopen(argv[1],"r"))==NULL) {
    printf("Cannot open %s file.\n",argv[1]);
    reval=FAIL;
  } else if ((fptr2 = fopen(argv[2],"r"))==NULL) {
    printf("Cannot open %s file.\n",argv[2]);
    reval=FAIL;
  } else if ((fptr3 = fopen(argv[3],"w"))==NULL) {
    printf("Cannot open %s file.\n",argv[3]);
    reval=FAIL;
  } else {
    char str1[81],str2[81];
    while (((fgets(str1,81,fptr1)!=NULL) && (fgets(str2,81,fptr2))!=NULL)) {
      fputs(str1,fptr3);
      fputs(str2,fptr3);
    }
    
    while ((fgets(str1,81,fptr1)!=NULL)) {
      fputs(str1,fptr3);
    }
    while ((fgets(str2,81,fptr2)!=NULL)) {
      fputs(str2,fptr3);
    }
  }
  fclose(fptr1);
  fclose(fptr2);
  fclose(fptr3);
}
