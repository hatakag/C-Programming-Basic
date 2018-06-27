#include <stdio.h>
#include <string.h>
#define n 10
int main(int argc,char* argv[]){
  if (argc!=2 && argc!=3) {
    printf("Wrong input\n");
    return 1;
  }
  enum {SUCCESS,FAIL};
  int reval=SUCCESS;
  int line=0,c;
  FILE * fptr;
  if ((fptr = fopen(argv[1],"r"))==NULL) {
    printf("Cannot open %s file.\n",argv[1]);
    reval=FAIL;
  } else {
    if (argc==2) {
      while ((c=fgetc(fptr))!=EOF) {	
	putchar(c);
      }
    }
    else if (argc==3 && strcmp(argv[2],"-p")==0) {
      while ((c=fgetc(fptr))!=EOF) {
	putchar(c);
	if (c=='\n') {
	  line++;
	  if (line==n) {
	    line=0;
	    printf("\nPress \"enter\" for the next page\n");
	    getchar(); //press enter for next page
	    printf("_______________________\n\n");
	  }
	}
      }
    }
    else printf("Error-- cat filename -p\n");
  }
  fclose(fptr);
  return reval;
}
