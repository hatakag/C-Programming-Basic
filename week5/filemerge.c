#include <stdio.h>
#include <stdlib.h>

enum{SUCCESS,FAIL};
typedef struct phoneaddress {
  char name[40];
  char tel[12];
  char email[25];
} phone;

int main(int argc,char* argv[]) {
  if (argc!=4) {
    printf("Wrong number of input\n");
    return 0;
  }
  FILE *fptr1,*fptr2,*fptr3;
  phone * phonearr;
  int i,irc,num1=0,num2=0;
  int reval=SUCCESS;
  if ((fptr1=fopen(argv[1],"rb"))==NULL) {
    printf("Cannot open %s file\n",argv[1]);
    return FAIL;
  } else if ((fptr2=fopen(argv[2],"rb"))==NULL) {
    printf("Cannot open %s file\n",argv[2]);
    return FAIL;
  } else if ((fptr3=fopen(argv[3],"wb"))==NULL) {
    printf("Cannot open %s file\n",argv[3]);
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
    if (!feof(fptr1)) num1++;
  }
  free(phonearr);
  fclose(fptr1);
  //number of data in file2
  phonearr=(phone*)malloc(1*sizeof(phone));
  if (phonearr==NULL) {
    printf("Memory allocation failed\n");
    return FAIL;
  }
  while (!feof(fptr2)) {
    fread(phonearr,sizeof(phone),1,fptr2);
    if (!feof(fptr2)) num2++;
  }
  free(phonearr);
  fclose(fptr2);
  //
  fptr1=fopen(argv[1],"rb");fptr2=fopen(argv[2],"rb");
  phonearr=(phone*)malloc((num1+num2)*sizeof(phone));
  if (phonearr==NULL) {
    printf("Memory allocation failed\n");
    return FAIL;
  }
  // chep file1 vao file3
  irc=fread(phonearr,sizeof(phone),num1,fptr1);
  irc=fwrite(phonearr,sizeof(phone),num1,fptr3);
  printf("fwrite return code = %d\n",irc);
  // chep file2 vao file3 (them tiep)
  if (fseek(fptr3,num1*sizeof(phone),SEEK_SET)!=0) {
    printf("Fseek failed\n");
    return FAIL;
  }
  irc=fread(phonearr,sizeof(phone),num2,fptr2);
  irc=fwrite(phonearr,sizeof(phone),num2,fptr3);
  printf("fwrite return code = %d\n",irc);
  fclose(fptr1);fclose(fptr2);fclose(fptr3);
  free(phonearr);
  return reval;
}
