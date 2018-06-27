#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void CharReadWrite(FILE* fin,FILE* fout) {
  int c;
  while ((c=fgetc(fin))!=EOF) {
    fputc(c,fout);
    //putchar(c);
  }
}
void LineReadWrite(FILE *fin,FILE *fout) {
  int MAX_LEN=100;
  char buff[MAX_LEN];
  while(fgets(buff,MAX_LEN, fin) != NULL) {
    fputs(buff, fout);
    //printf("%s",buff);
  }
}
void BlockReadWrite(FILE *fin,FILE *fout,int MAX_LEN) {
  int num;
  char buff[MAX_LEN+1];
  while (!feof(fin)){
    num = fread(buff,sizeof(char),MAX_LEN,fin);
    buff[num*sizeof(char)]='\0';
    //printf("%s",buff);
    fwrite(buff,sizeof(char),num,fout);
  }
}
int main(int argc,char * argv[]) {
  if (argc!=3) {
    printf("Wrong number of input\n");
    return 0;
  }
  enum {SUCCESS,FAIL};
  int reval=SUCCESS;
  FILE *fptr1,*fptr2;
  if ((fptr1=fopen(argv[1],"r"))==NULL) {
    printf("Cannot open %s file\n",argv[1]);
    reval=FAIL;
  } else if ((fptr2=fopen(argv[2],"w"))==NULL) {
    printf("Cannot open %s file\n",argv[2]);
    reval=FAIL;
  } else {
    fclose(fptr1);
    fclose(fptr2);
    int choice;
    do {
      printf("\n_____MENU_____\n\n");
      printf("1.SAO CHEP THEO KI TU\n");
      printf("2.SAO CHEP THEO DONG\n");
      printf("3.SAO CHEP THEO BLOCK\n");
      printf("4.THOAT\n");
      printf("Chon: ");
      scanf("%d",&choice);__fpurge(stdin);
      switch (choice) {
      case 1:
	{
	  fptr1=fopen(argv[1],"r");
	  fptr2=fopen(argv[2],"w");
	  clock_t begin = clock();
	  CharReadWrite(fptr1,fptr2);
	  clock_t end = clock();
	  double time = (double)(end-begin)/CLOCKS_PER_SEC;
	  printf("Process time: %lf\n",time);
	  fclose(fptr1);fclose(fptr2);
	  break;
	}
      case 2:
	{
	  fptr1=fopen(argv[1],"r");
	  fptr2=fopen(argv[2],"w");
	  clock_t begin = clock();
	  LineReadWrite(fptr1,fptr2);
	  clock_t end = clock();
	  double time = (double)(end-begin)/CLOCKS_PER_SEC;
	  printf("Process time: %lf\n",time);
	  fclose(fptr1);fclose(fptr2);
	  break;
	}
      case 3:
	{
	  fptr1=fopen(argv[1],"r");
	  fptr2=fopen(argv[2],"w");
	  int size;
	  printf("Kich thuoc cua block: ");
	  scanf("%d",&size);
	  clock_t begin = clock();
	  BlockReadWrite(fptr1,fptr2,size);
	  clock_t end = clock();
	  double time = (double)(end-begin)/CLOCKS_PER_SEC;
	  printf("Process time: %lf\n",time);
      	  fclose(fptr1);fclose(fptr2);
	  break;
	}
      case 4:
	break;
      default: printf("CHON KHONG HOP LE\n");
	break;
      }
    } while (choice!=4);
    printf("\n___GOODBYE___\n");
  }
  return reval;
}
