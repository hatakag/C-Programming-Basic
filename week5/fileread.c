#include <stdio.h>
#include <stdlib.h>

enum {SUCCESS,FAIL};
typedef struct phoneaddress {
  char name[40];
  char tel[12];
  char email[25];
}phone;
int main(int argc,char* argv[]) {
  if (argc!=2) {
    printf("Wrong number of input\n");
    return 0;
  }
  FILE *fp;
  phone *phonearr;
  int i,n=0,irc;
  int reval=SUCCESS;
  if ((fp=fopen(argv[1],"rb"))==NULL){
    printf("Cannot open %s file\n",argv[1]);
    reval=FAIL;
  }
  //number of data in file
  phonearr=(phone*)malloc(1*sizeof(phone));
  if (phonearr==NULL) {
    printf("Memory allocation failed\n");
    return FAIL;
  }
  while (!feof(fp)) {
    fread(phonearr,sizeof(phone),1,fp);
    if (!feof(fp)) n++;
  }
  free(phonearr);
  fclose(fp);
  //
  phonearr=(phone*)malloc(n*sizeof(phone));
  if (phonearr==NULL) {
    printf("Memory allocation failed\n");
    return FAIL;
  }
  fp=fopen(argv[1],"rb");
  irc = fread(phonearr,sizeof(phone),n,fp);
  printf("fread return code = %d\n",irc);
  for (i=0;i<n;i++) {
    printf("%s-",phonearr[i].name);
    printf("%s-",phonearr[i].tel);
    printf("%s\n",phonearr[i].email);
  }
  free(phonearr);
  fclose(fp);
  return reval;
}
