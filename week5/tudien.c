#include <stdio.h>
#include <stdlib.h>

enum{SUCCESS,FAIL};
typedef struct tudien{
  char word[100];
  char mean[100];
}td;
int main(int argc,char* argv[]){
  if (argc!=3) {
    printf("Wrong number of input\n");
    return 0;
  }
  FILE *fp1,*fp2;
  int i,irc,n=0,l1,l2;
  int reval=SUCCESS;
  td *data;
  if ((fp1=fopen(argv[1],"r"))==NULL) {
    printf("Cannot open %s file\n",argv[1]);
    return FAIL;
  } else if ((fp2=fopen(argv[2],"w+b"))==NULL) {
    printf("Cannot open %s file\n",argv[2]);
    return FAIL;
  } else {
    int c;
    while ((c=fgetc(fp1))!=EOF) {
      if (c=='\n') n++;
    }
    n=n-2;//xuong dong o dong dau va cuoi
    fclose(fp1);
    fp1=fopen(argv[1],"r");
    char buff[100];
    data=(td*)malloc(n*sizeof(td));
    fgets(buff,100,fp1);
    for (i=0;i<n;i++) {
      fscanf(fp1,"%[^:]%*c %[^\n]s",data[i].word,data[i].mean);__fpurge(stdin);
      //printf("%s: %s",data[i].word,data[i].mean);
    }
    printf("\n");
    irc=fwrite(data,sizeof(td),n,fp2);
    printf("fwrite return code = %d\n",irc);
    free(data);fclose(fp1);fclose(fp2);
    printf("Read from which line to which line: ");
    scanf("%d %d",&l1,&l2);__fpurge(stdin);
    if (l1<1 || l1>n || l2<1 || l2>n ) {
      printf("Line must be between 1 and %d\n",n);
      return 0;
    }
    fp2=fopen(argv[2],"rb");
    data=(td*)malloc(n*sizeof(td));
    fseek(fp2,(l1-1)*sizeof(td),SEEK_SET);
    irc=fread(data,sizeof(td),l2-l1+1,fp2);
    printf("fread return code = %d\n",irc);
    for (i=0;i<l2-l1+1;i++) {
      printf("%s: %s",data[i].word,data[i].mean);
    }
    printf("\n");
    fclose(fp2);free(data);
  }
  return reval;
}
