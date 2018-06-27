#include <stdio.h>
#include <stdlib.h>
#include <string.h>
enum {SUCCESS,FAIL};
typedef struct phoneaddress {
  char name[40];
  char tel[12];
  char email[25];
} phone;

int main() {
  FILE * fp;
  phone * phonearr;
  int i,irc,begin,end;
  int reval=SUCCESS;
  printf("Read from ");scanf("%d",&begin);__fpurge(stdin);
  printf("Read to ");scanf("%d",&end);__fpurge(stdin);
  printf("Read from data %d to data %d\n",begin,end);
  if ((fp=fopen("phonebook.dat","r+b"))==NULL) {
    printf("Cannot open %s file\n","phonebook.dat");
    reval=FAIL;
  }
  int j=end-begin+1,k=begin-1;
  phonearr=(phone*)malloc(j*sizeof(phone));
  if (phonearr==NULL) {
    printf("Memory allocation failed\n");
    return FAIL;
  }
  if (fseek(fp,k*sizeof(phone),SEEK_SET)!=0) {
    printf("Fseek failed\n");
    return FAIL;
  }
  irc = fread(phonearr,sizeof(phone),j,fp);
  for (i=0;i<j;i++) {
    printf("%s-",phonearr[i].name);
    printf("%s-",phonearr[i].tel);
    printf("%s\n",phonearr[i].email);
  }
  //modify 
  int l;
  printf("What data you want to change (%d-%d): ",begin,end);scanf("%d",&l);
  if (l<begin || l>end) {
    printf("Data you want to change must be >=%d and <=%d\n",begin,end);
    return 0;
  }
  strcpy(phonearr[l-begin].name,"LAN HOA");
  strcpy(phonearr[l-begin].tel,"023456789");
  strcpy(phonearr[l-begin].email,"lan@mail.com");
  fseek(fp,k*sizeof(phone),SEEK_SET);
  irc=fwrite(phonearr,sizeof(phone),j,fp);
  printf("fwrite return code = %d\n",irc);
  fclose(fp);free(phonearr);
  return reval;
}
