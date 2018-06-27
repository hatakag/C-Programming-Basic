#include <stdio.h>
#include <stdlib.h>

enum {SUCCESS,FAIL};
typedef struct phoneaddress {
  char name[40];
  char tel[12];
  char email[25];
} phone;

int main(int argc,char * argv[]) {
  if (argc!=5) {
    printf("Wrong number of input\n");
    return 0;
  }
  FILE *fptr1,*fptr2,*fptr3;
  phone * phonearr;
  int i,irc,num=0;
  int reval=SUCCESS;
  if ((fptr1=fopen(argv[1],"rb"))==NULL) {
    printf("Cannot open %s file\n",argv[1]);
    return FAIL;
  } else if ((fptr2=fopen(argv[3],"wb"))==NULL) {
    printf("Cannot open %s file\n",argv[3]);
    return FAIL;
  } else if ((fptr3=fopen(argv[4],"wb"))==NULL) {
    printf("Cannot open %s file\n",argv[4]);
    return FAIL;
  }
  //number of data in file1
  phonearr=(phone*)malloc(1*sizeof(phone));
  if (phonearr==NULL) {
    printf("Memory allocation failed\n");
    return FAIL;
  }
  while (!feof(fptr1)) {
    fread(phonearr,sizeof(phone),1,fptr1);
    if (!feof(fptr1)) num++;
  }
  free(phonearr);
  fclose(fptr1);
  //
  fptr1=fopen(argv[1],"rb");
  phonearr=(phone*)malloc(num*sizeof(phone));
  if (phonearr==NULL) {
    printf("Memory allocation failed\n");
    return FAIL;
  }
  int j=atoi(argv[2]);
  irc=fread(phonearr,sizeof(phone),j,fptr1);
  irc=fwrite(phonearr,sizeof(phone),j,fptr2);
  printf("fwrite 1 return code = %d\n",irc);
  if (fseek(fptr1,j*sizeof(phone),SEEK_SET)!=0) {
    printf("Fseek failed\n");
    return FAIL;
  }
  irc=fread(phonearr,sizeof(phone),num-j,fptr1);
  irc=fwrite(phonearr,sizeof(phone),num-j,fptr3);
  printf("fwrite 2 return code = %d\n",irc);
  fclose(fptr1);fclose(fptr2);fclose(fptr3);
  free(phonearr);
  return reval;
}
