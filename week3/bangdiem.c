#include <stdio.h>

typedef struct sinhvien {
  int stt;
  int mssv;
  char name[40];
  char sdt[11];
  int diem;
} sv;

int main(int argc,char * argv[]){
  if (argc != 3) {
    printf("Wrong number of input\n");
    return 0;
  }
  enum {SUCCESS,FAIL};
  int reval=SUCCESS;
  FILE *fptr1,*fptr2;
  if ((fptr1 = fopen(argv[1],"r"))==NULL) {
    printf("Cannot open %s file.\n",argv[1]);
    reval=FAIL;
  } else if ((fptr2 = fopen(argv[2],"w"))==NULL) {
    printf("Cannot open %s file.\n",argv[2]);
    reval=FAIL;
  } else {
    sv data[30];
    int i,line=3;
    char buff[100],str[100];
    fgets(buff,100,fptr1);
    for (i=0;i<line;i++) {
      fscanf(fptr1,"%d %d %[^\t]%*c %s",&data[i].stt,&data[i].mssv,data[i].name,data[i].sdt);__fpurge(stdin);
    }
    for (i=0;i<line;i++) {
      printf("Nhap diem cho sinh vien so %d: ",data[i].stt);
      scanf("%d",&data[i].diem);__fpurge(stdin);
    }
    fprintf(fptr2,"%-5s %-10s %-30s %-14s %-4s\n","STT","MA SO SV","HO VA TEN","SO DT","DIEM SO");
    for (i=0;i<line;i++) {
      fprintf(fptr2,"%-5d %-10d %-30s %-14s %-4d\n",data[i].stt,data[i].mssv,data[i].name,data[i].sdt,data[i].diem);__fpurge(stdin);
    }
  }
  fclose(fptr1);
  fclose(fptr2);
  return reval;
}
