#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc,char * argv[]) {
  if (argc!=2) {
    printf("Wrong number of input\n");
    return 0;
  }
  int N=atoi(argv[1]);
  typedef struct elementtype{
    int el;
    int count;
  }Eltype;
  Eltype *a;
  a=(Eltype*)malloc(N*sizeof(Eltype));
  int i,x,j;
  for (i=0;i<N;i++) {
    a[i].el=i;
    a[i].count=0;
  }
  char c;
  do {
    printf("Search: ");scanf("%d",&x);__fpurge(stdin);
    printf("Before search: ");
    for (i=0;i<N;i++) 
      printf("%d(%d) ",a[i].el,a[i].count);
    printf("\n");
    clock_t start1=clock();
    for (i=0;i<N;i++) {
      if (a[i].el==x)  break;
    }
    clock_t finish1=clock();
    double duration1=(double)(finish1-start1)/CLOCKS_PER_SEC;
    printf("%d in %f\n",i,duration1);
    //
    for (i=0;i<N;i++) {
      if (a[i].el==x) a[i].count++;
    } 
    for (i=0;i<N;i++) {
      for (j=i;j<N;j++) {
	if (a[j].count>a[i].count) {
	  Eltype tmp;
	  tmp.el=a[i].el;tmp.count=a[i].count;
	  a[i].el=a[j].el;a[i].count=a[j].count;
	  a[j].el=tmp.el;a[j].count=tmp.count;
	}
      }
    }
    //
    printf("After search: ");
    for (i=0;i<N;i++) 
      printf("%d(%d) ",a[i].el,a[i].count);
    printf("\n");
    clock_t start2=clock();
    for (i=0;i<N;i++) {
      if (a[i].el==x)  break;
    }
    clock_t finish2=clock();
    double duration2=(double)(finish2-start2)/CLOCKS_PER_SEC;
    printf("%d in %f\n",i,duration2);
    
    do {
      printf("Do you want to continue (y/n): ");scanf("%c",&c);__fpurge(stdin);
      if (c!='y' && c!='n') printf("Invalid y/n\n");
    } while (c!='y'&&c!='n');
  } while(c!='n');
  free(a);
}
