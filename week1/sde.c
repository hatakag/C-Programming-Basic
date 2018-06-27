#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(int argc,char* argv[])
{
  double a,b,c,d;
  if (argc!=4) {
    printf("Wrong input numbers\n");
    return 1;
  }
  a=atof(argv[1]);
  b=atof(argv[2]);
  c=atof(argv[3]);
  if (a==0) {
    if (b==0) {
      if (c==0) {
	printf("The equation has infinite numbers of solution\n");
	return 0;
      }
      else {
	printf("The equation has no solution\n");
	return 0;
      }
    }
    else {
      printf("x=%f\n",-c/b);
      return 0;
    }
  }
  else {
    d=b*b-4*a*c;
    if (d>0) {
      printf("x1=%f , x2=%f\n",(-b+sqrt(d))/2/a,(-b-sqrt(d))/2/a);
      return 0;
    }
    else if (d==0) {
      printf("x1=x2=%f\n",-b/2/a);
      return 0;
    }
    else {
      printf("The equation has no solution\n");
      return 0;
    }
  }
}
