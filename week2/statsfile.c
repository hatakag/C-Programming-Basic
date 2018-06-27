#include <stdio.h>

void swap(int *a,int *b) {
  int temp;
  temp=*a;
  *a=*b;
  *b=temp;
}

int main(int argc,char* argv[]) {
  if (argc!=2) {
    printf("Wrong input\n");
    return 1;
  }
  enum {SUCCESS,FAIL};
  int reval=SUCCESS;
  FILE *fptr1,*fptr2;
  if ((fptr1 = fopen(argv[1],"r"))==NULL) {
    printf("Cannot open %s file.\n",argv[1]);
    reval=FAIL;
  } else if ((fptr2 = fopen("sourcestats.txt","w"))==NULL) {
    printf("Cannot open %s file.\n","sourcestats.txt");
    reval=FAIL;
  } else {
    int a[1000],i=0,j,dem,n;
    while ((a[i]=fgetc(fptr1))!=EOF) {
      if (a[i]>=65 && a[i]<=90) a[i]=a[i]+32;//ko phan biet chu hoa chu thuong
      i++;n++;//n la size cac phan tu trong file
    }
    for (i=0;i<n-1;i++) {
      for (j=i+1;j<n;j++) {
	if (a[j]<a[i]) swap(&a[i],&a[j]);//sx tu lon den be
      }
    }
    i=0;j=0;dem=0;
    while (i<n) {
      dem=0;
      j=i;
      while (a[j]==a[i]) {
	dem++;j++;
      }
      printf("%c appears for %d times\n",a[i],dem);
      fprintf(fptr2,"%c appears for %d times\n",a[i],dem);
      i=j;
    }
  }
  printf("\n");
  fclose(fptr1);
  fclose(fptr2);
  return reval;
}
