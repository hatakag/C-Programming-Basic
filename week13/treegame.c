#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "treegame.h"

int main() {
  FILE *fp1,*fp2;
  int i,n,irc;
  n=16;
  if ((fp1=fopen("USopen.txt","r"))==NULL) {
    printf("Cannot open %s file\n","USopen.txt");
    return 0;
  }
  char name[40][n];
  for (i=0;i<n;i++) {
    fscanf(fp1,"%[^,]s",name[i]);
    fscanf(fp1,"%*c");
  }
  fclose(fp1);
  treetype t[n];
  for (i=0;i<n;i++) {
    makeNullTree(&t[i]);
    t[i]=createNode(name[i]);
  }
  if ((fp2=fopen("treegame.txt","w"))==NULL) {
    printf("Cannot open %s file\n","treegame.txt");
    return 0;
  }
  //
  fprintf(fp2,"\n_____Eight-finals_____\n\n");
  treetype t1[n/2];
  srand(time(NULL));
  for (i=0;i<n/2;i++) {
    if (0+rand()%2==1) {
      t1[i]=createFrom2(t[i]->element,t[i],t[n-1-i]);
      fprintf(fp2,"%s win %s\n",t[i]->element,t[n-1-i]->element);
    }
    else {
      t1[i]=createFrom2(t[n-1-i]->element,t[i],t[n-1-i]);
      fprintf(fp2,"%s win %s\n",t[n-1-i]->element,t[i]->element);
    }
  }
  //
  fprintf(fp2,"\n_____Quarterfinals_____\n\n");
  treetype t2[n/4];
  srand(time(NULL));
  for (i=0;i<n/4;i++) {
    if (0+rand()%2==1) {
      t2[i]=createFrom2(t1[i]->element,t1[i],t1[n/2-1-i]);
      fprintf(fp2,"%s win %s\n",t1[i]->element,t1[n/2-1-i]->element);
    }
    else {
      t2[i]=createFrom2(t1[n/2-1-i]->element,t1[i],t1[n/2-1-i]);
      fprintf(fp2,"%s win %s\n",t1[n/2-1-i]->element,t1[i]->element);
    }
  }
  //
  fprintf(fp2,"\n_____Semifinals_____\n\n");
  treetype t3[n/8];
  srand(time(NULL));
  for (i=0;i<n/8;i++) {
    if (0+rand()%2==1) {
      t3[i]=createFrom2(t2[i]->element,t2[i],t2[n/4-1-i]);
      fprintf(fp2,"%s win %s\n",t2[i]->element,t2[n/4-1-i]->element);
    }
    else {
      t3[i]=createFrom2(t2[n/4-1-i]->element,t2[i],t2[n/4-1-i]);
      fprintf(fp2,"%s win %s\n",t2[n/4-1-i]->element,t2[i]->element);
    }
  }
  //
  fprintf(fp2,"\n_____Final_____\n\n");
  treetype t4[n/16];
  srand(time(NULL));
  for (i=0;i<n/16;i++) {
    if (0+rand()%2==1) {
      t4[i]=createFrom2(t3[i]->element,t3[i],t3[n/8-1-i]);
      fprintf(fp2,"%s win %s\n",t3[i]->element,t3[n/8-1-i]->element);
    }
    else {
      t4[i]=createFrom2(t3[n/8-1-i]->element,t3[i],t3[n/8-1-i]);
      fprintf(fp2,"%s win %s\n",t3[n/8-1-i]->element,t3[i]->element);
    }
  }
  //
  fprint2D(t4[0],0,fp2);
  fclose(fp2);
  print2D(t4[0],0);
  return 0;
}
