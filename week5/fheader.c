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
void LineReadWrite(FILE *fin,FILE *fout) {
  int MAX_LEN=100;
  char buff[MAX_LEN];
  while(fgets(buff,MAX_LEN, fin) != NULL) {
    fputs(buff, fout);
    //printf("%s",buff);
  }
}
int main(int argc,char* argv[]) {
  if (argc!=2) {
    printf("Wrong number of input\n");
    return 0;
  }
  FILE *fp;
  fhead head[1];
  int i,irc;
  int reval=SUCCESS;
  if ((fp=fopen(argv[1],"r+b"))==NULL){
    printf("Cannot open %s file\n",argv[1]);
    return FAIL;
  }
  //fclose(fp);
  // text file
  /* if ((fp=fopen(argv[1],"w+"))!=NULL) {
     fp1=fopen("temp.txt","w");
     LineReadWrite(fp,fp1);
     fseek(fp,0,SEEK_END);
     head[0].size=ftell(fp);
     printf("Size of file: %ld\n",head[0].size);
     printf("Author's name: ");gets(head[0].name);__fpurge(stdin);
     printf("Day/month/year created: ");scanf("%d %d %d",&head[0].day,&head[0].month,&head[0].year);__fpurge(stdin);  
     rewind(fp);
     irc=fwrite(head,sizeof(fhead),1,fp);
     printf("fwrite return code = %d\n",irc);
     fseek(fp,1*sizeof(fhead),SEEK_SET);
     LineReadWrite(fp1,fp);
     fclose(fp);fclose(fp1);
     }*/
  // binary file
  //if ((fp=fopen(argv[1],"w+b"))!=NULL) {
  //fp1=fopen("temp.dat","r+b");
  //LineReadWrite(fp,fp1);
  irc=fread(head,sizeof(fhead),1,fp);
  printf("fread return code = %d\n",irc);
  if (head[0].flag==1) {
    printf("File already has header\n");
    return 0;
  }
  fclose(fp);
  fp=fopen(argv[1],"r+b");
  fseek(fp,0,SEEK_END);
  head[0].size=ftell(fp);
  printf("Size of file: %ld bytes\n",head[0].size);
  printf("Author's name: ");gets(head[0].name);__fpurge(stdin);
  do {
    printf("Day/month/year created: ");scanf("%d %d %d",&head[0].day,&head[0].month,&head[0].year);__fpurge(stdin);  
    if (head[0].day<=0 || head[0].month<=0 || head[0].year<=0) {
      printf("Invalid input - redo\n");
    }
  } while (head[0].day<=0 || head[0].month<=0 || head[0].year<=0);
  head[0].flag=1;
  rewind(fp);
  irc=fwrite(head,sizeof(fhead),1,fp);
  printf("fwrite return code = %d\n",irc);
  //fseek(fp,1*sizeof(fhead),SEEK_SET);
  //LineReadWrite(fp1,fp);
  fclose(fp);//fclose(fp1);
  //}
  return reval;
}
