#include <stdio.h>
#include <string.h>

int main (int argc, char * argv[]){
  if ( argc != 3) {
    printf("Wrong number of input\n");
    return 0;
  }
  enum {SUCCESS,FAIL};
  int reval=SUCCESS;
  FILE *fptr1,*fptr2;
  if ((fptr1 = fopen(argv[1],"r"))==NULL) {
    printf("Cannot open %s file.\n",argv[1]);
    reval=FAIL;
  } else if ((fptr2 = fopen(argv[2],"r"))==NULL) {
    printf("Cannot open %s file.\n",argv[2]);
    reval=FAIL;
  } else {
    char str1[81],str2[81];
    int line=0,i=0,alllines;
    int dline[100];
    dline[0]=0;
    while (((fgets(str1,81,fptr1)!=NULL) && (fgets(str2,81,fptr2))!=NULL)) {
      line++;
      if (strcmp(str1,str2)!=0) {
	dline[i]=line;i++;alllines=i;
      }
    }
    while ((fgets(str1,81,fptr1)!=NULL)) {
      line++;dline[i]=line;i++;alllines=i+1;dline[alllines-1]=line+1;      
    }    
    while ((fgets(str2,81,fptr2)!=NULL)) {
      line++;dline[i]=line;i++;alllines=i;
    }

    if (dline[0]==0) {
      printf("They are the same\n");
    } else {
      printf("The first line where they differ: line number %d\n",dline[0]);
      printf("All lines where they differ: line number ");
      for (i=0;i<alllines;i++) 
	printf("%d ",dline[i]);
      printf("\n");
    }
  }
  fclose(fptr1);
  fclose(fptr2);
  return reval;
}
