#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <math.h>


#include "FINALTEST.h"

enum{SUCCESS,FAIL};

int main(int argc,char* argv[]) {
  if (argc!=2) {
    printf("Wrong number of input\n");
    return 0;
  }
  FILE *fp;
  int reval=SUCCESS;
  int choice,i,irc,flag=0;
  node *r1=NULL,*c1=NULL;
  node *r2=NULL,*c2=NULL;
  do {
    choice=0;
    printf("\n_____MENU_____\n");
    printf("1.Doc du lieu tu file\n");
    printf("2.Hien thi da thuc\n");
    printf("3.Chuan hoa da thuc\n");
    printf("4.Cong hai da thuc\n");
    printf("5.Thoat\n");
    printf("Chon: ");
    scanf("%d",&choice);__fpurge(stdin);
    switch (choice) {
    case 1:
      {
	if (flag==0) flag=1;
	else {
	  printf("Already import to linked list\n");
	  break;
	}
	if ((fp=fopen(argv[1],"r"))==NULL) {
	  printf("Cannot open %s file\n",argv[1]);
	  return FAIL;
	}
	importFromText(fp,&r1,&c1,&r2,&c2);
	fclose(fp);
	break;
      }
    case 2:
      {
	if (flag==0) {
	  printf("Import database from file to linked list first\n");
	  break;
	}
	printf("a\n");
	printf("List 1\n");
	traversingList(r1);
	printf("\n");
	printf("List 2\n");
	traversingList(r2);
	printf("\n");
	printf("b\n");
	printf("List 1\n");
	traversingListP(r1);
	printf("\n");
	printf("List 2\n");
	traversingListP(r2);
	printf("\n");
	break;
      }
    case 3:
      {
	if (flag==0) {
	  printf("Import database from file to linked list first\n");
	  break;
	}
	softNode(&r1);
	softNode(&r2);
	break;
      }
    case 4:
      {
	if (flag==0) {
	  printf("Import database from file to linked list first\n");
	  break;
	}
	break;
      }
    case 5:
      break;
    default : printf("Invalid choice\n");
      break;
    }
  } while (choice!=5);
  printf("\n____GOODBYE____\n");
  //free
  return reval;
}
