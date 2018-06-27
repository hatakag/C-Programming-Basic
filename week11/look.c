#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define n 1000000

enum{SUCCESS,FAIL};
int main(int argc,char * argv[]){
  if (argc!=2) {
    printf("Wrong number of input\n");
    return 0;
  }
  int reval=SUCCESS;
  FILE *fp;
  const char *filePath="/usr/share/dict/words";
  if ((fp=fopen(filePath,"r"))==NULL) {
    printf("Cannot open file\n");
    return FAIL;
  } else {
    int k;
    char arr[100];
    while (fgets(arr,100,fp)!=NULL) {
      k=0;
      while (k<strlen(argv[1]) && arr[k]==argv[1][k])
	k++;
      if (k>=strlen(argv[1])) printf("%s\n",arr);
    }
  }
  fclose(fp);
  return reval;
}
