#include <stdio.h>
#include <stdlib.h>
int main (int argc,char* argv[])
{
  int i=1;
  double temp,emx,x,e;
  if (argc!=2 && argc!=3) {
    printf("Wrong input numbers\n");
    return 1;
  }
  if (argc==2) {
    x=atof(argv[1]);
    e=0;
  }
  if (argc==3) {
    x=atof(argv[1]);
    e=atof(argv[2]);
  }
  emx=1+x,temp=x;
  while (temp>e) {
    i++;
    temp=temp*x/i;
    emx=emx+temp;
  }
  printf("e mu x bang %f\n",emx);
  return 0;
}
