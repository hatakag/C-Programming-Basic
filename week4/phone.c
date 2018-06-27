#include <stdio.h>
#include <stdlib.h>

enum {SUCCESS,FAIL,MAX = 20};
typedef struct phoneaddress {
  char name[40];
  char tel[12];
  char email[25];
}phone;
int main() {
  FILE *fp;
  phone *phonearr;
  int i,n,irc;
  int reval=SUCCESS;
  printf("Howm many contacts you want to enter(<100)?\n");
  scanf("%d",&n);__fpurge(stdin);
  phonearr=(phone*)malloc(n*sizeof(phone));
  for (i=0;i<n;i++){
    printf("Name:");gets(phonearr[i].name);__fpurge(stdin);
    printf("Tel:");scanf("%s",phonearr[i].tel);__fpurge(stdin);
    printf("Email:");scanf("%s",phonearr[i].email);__fpurge(stdin);
  }
  if ((fp=fopen("phonebook.dat","w+b"))==NULL) {
    printf("Cannot open %s file\n","phonebook.dat");
    reval=FAIL;
  }
  irc = fwrite(phonearr,sizeof(phone),n,fp);
  printf("fwrite return code = %d\n",irc);
  fclose(fp);
  if ((fp=fopen("phonebook.dat","rb"))==NULL){
    printf("Cannot open %s file\n","phonebook.dat");
    reval=FAIL;
  }
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
