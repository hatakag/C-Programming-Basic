#include <stdio.h>
#include <stdlib.h>

typedef struct sinhvien {
  int stt;
  int mssv;
  char name[40];
  char sdt[11];
  float diem;
} sv;

int main(int argc,char * argv[]){
  if (argc != 2) {
    printf("Wrong number of input\n");
    return 0;
  }
  enum {SUCCESS,FAIL};
  int reval=SUCCESS;
  FILE *fptr1,*fptr2;
  if ((fptr1 = fopen(argv[1],"r"))==NULL) {
    printf("Cannot open %s file.\n",argv[1]);
    reval=FAIL;
  } else {
    sv *data;
    int i,n=3,irc;
    char buff[100];
    data=(sv*)malloc(50*sizeof(sv));
    fgets(buff,100,fptr1);__fpurge(stdin);
    for (i=0;i<n;i++) {
      fscanf(fptr1,"%d %d %[^\t]%*c %s %f",&data[i].stt,&data[i].mssv,data[i].name,data[i].sdt,&data[i].diem);__fpurge(stdin);
    }
    if ((fptr2 = fopen("grade.dat","w+b"))==NULL) {
      printf("Cannot open %s file\n","grade.dat");
      reval=FAIL;
    }
    irc=fwrite(data,sizeof(sv),n,fptr2);
    printf("fwrite return code: %d\n",irc);
    fclose(fptr2);
    if ((fptr2=fopen("grade.dat","rb"))==NULL) {
      printf("Cannot open %s file\n","grade.dat");
      reval=FAIL;
    }
    irc=fread(data,sizeof(sv),n,fptr2);
    printf("fread return code: %d\n",irc);
    printf("%-5s %-10s %-30s %-14s %-4s\n","STT","MA SO SV","HO VA TEN","SO DT","DIEM SO");
    for (i=0;i<n;i++) {
      printf("%-5d %-10d %-30s %-14s %-4.2f\n",data[i].stt,data[i].mssv,data[i].name,data[i].sdt,data[i].diem);
    }
    fclose(fptr1);
    fclose(fptr2);
    free(data);
  }
  return reval;
}
