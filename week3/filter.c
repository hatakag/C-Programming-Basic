#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void replace(char* str,char c,int l) {
  int i;
  for (i=0;i<l;i++) {
    if (str[i]!=' ') {
      str[i]=c;
    }
  }
}
int main(int argc,char * argv[]) {
  if (argc!=3) {
    printf("Wrong number of input\n");
    return 0;
  }
  char banword[5][30]={"fuck",
		       "di ve sinh",
		       "ngu",
		       "dai bay",
		       "dien"};
  enum {SUCCESS,FAIL};
  int reval;
  FILE * fptr;
  if ((fptr = fopen(argv[1],"r"))==NULL) {
    printf("Cannot open %s file.\n",argv[1]);
    reval=FAIL;
  } else {
    char buff[81];
    int i,j;
    char c=argv[2][0],strptr[81];
    while ((fgets(buff,81,fptr))!=NULL) {
      for (i=0;i<5;i++) {
	for(j=0;j<strlen(buff)-strlen(banword[i]);j++) {
	  memset(strptr,'\0',sizeof(strptr));
	  strncpy(strptr,buff+j,strlen(banword[i]));
	  if ((strcmp(strptr,banword[i]))==0) 
	    replace(buff+j,c,strlen(banword[i]));
	}
      }
      printf("%s",buff);
    }
    fclose(fptr);
  }
  return reval;
}
      
      
