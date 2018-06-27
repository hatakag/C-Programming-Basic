#include <stdio.h>
#include <stdlib.h>

enum{SUCCESS,FAIL};
typedef struct fileheader {
  long size;
  char name[40];
  int day;
  int month;
  int year;
  int flag;
} fhead;
int main(int argc,char* argv[]) {
  if (argc!=2) {
    printf("Wrong number of input\n");
    return 0;
  }
  FILE *fp;
  fhead head[1];
  int i,irc;
  int reval=SUCCESS;
  if ((fp=fopen(argv[1],"rb"))==NULL){
    printf("Cannot open %s file\n",argv[1]);
    return FAIL;
  }
  irc=fread(head,sizeof(fhead),1,fp);
  printf("fread return code = %d\n",irc);
  fseek(fp,0,SEEK_END);
  long size=ftell(fp);
  //printf("%ld %ld %u\n",size,head[0].size,1*sizeof(fhead));
  //if (size!=head[0].size || irc==0) {
  if (head[0].flag!=1) {
    printf("File has no header\n");
    return 0;
  } else {
    printf("____HEADER____\n");
    printf("Size of file: %ld bytes\n",head[0].size);
    printf("Author's name: %s\n",head[0].name);
    printf("Day/month/year created: %d/%d/%d\n",head[0].day,head[0].month,head[0].year);
  }
  fclose(fp);
  return reval;
}
