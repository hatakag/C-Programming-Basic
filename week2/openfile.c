#include <stdio.h>

enum {SUCCESS,FAIL};

main(void)
{
  FILE *fptr;
  char filename[]="haiku.txt";
  int reval=SUCCESS;
  if ((fptr = fopen(filename,"r"))==NULL) {
    printf("Cannot open %s file.\n,filename");
    reval = FAIL;
  } else {
    printf("The value of fptr: 0x%p\n",fptr);
    printf("Ready to close file.\n");	
    fclose(fptr);
  }
}
