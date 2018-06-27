#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "LinkedList.h"
#define n 20

enum{SUCCESS,FAIL};

int main(int argc,char* argv[]) {
  if (argc!=3) {
    printf("Wrong number of input\n");
    return 0;
  }
  FILE *fp1,*fp2;
  int reval=SUCCESS;
  int choice,i,irc,flag=0;
  node *root=NULL,*cur=NULL;
  do {
    choice=0;
    printf("\n_____MENU_____\n");
    printf("1.Import from Dat\n");
    printf("2.Display List\n");
    printf("3.Add new phone\n");
    printf("4.Insert at Position\n");
    printf("5.Delete at Position\n");
    printf("6.Delete current element\n");
    printf("7.Delete first\n");
    printf("8.Search and Update\n");
    printf("9.Divide and Extract\n");
    printf("10.Reverse List\n");
    printf("11.Save to File\n");
    printf("12.Quit\n");
    printf("Select: ");
    scanf("%d",&choice);__fpurge(stdin);
    switch (choice) {
    case 1:
      {
	if (flag==0) flag=1;
	else {
	  printf("Already import to linked list\n");
	  break;
	}
	if ((fp1=fopen(argv[1],"rb"))==NULL) {
	  printf("Cannot open %s file\n",argv[1]);
	  return FAIL;
	}
	importFromDat(fp1,&root,&cur);fclose(fp1);
	break;
      }
    case 2:
      {
	if (flag==0) {
	  printf("Import database from dat file to linked list first\n");
	  break;
	}
	traversingList(root);
	break;
      }
    case 3:
      {
	if (flag==0) {
	  printf("Import database from dat file to linked list first\n");
	  break;
	}
	char s[6];
	printf("\nCurrent element at position %d\n",curAt(root,cur));
	do {
	  printf("Add before or after current: ");
	  gets(s);__fpurge(stdin);
	  if (strcmp(s,"before")!=0 && strcmp(s,"after")!=0)
	    printf("Please re-enter only \"before\" or \"after\"\n");
	} while(strcmp(s,"before")!=0 && strcmp(s,"after")!=0);
	printf("Phone's information: \n");
	if (strcmp(s,"before")==0) insertBeforeCur(readData(),&root,&cur);
	if (strcmp(s,"after")==0) insertAfterCur(readData(),&root,&cur);
	printf("\n");displayNode(cur);
	break;
      }
    case 4:
      {
	if (flag==0) {
	  printf("Import database from dat file to linked list first\n");
	  break;
	}
	int k;
	printf("Position you want to insert: ");scanf("%d",&k);__fpurge(stdin);
	if (k<0||k>length(root)) {
	  printf("Invalid position of k\n");
	  break;
	}
	insertAtk(readData(),k,&root,&cur);
	printf("After insert at position %d: \n",k);
	printf("\nCurrent element at position %d\n",curAt(root,cur));
	displayNode(cur);
	break;
      }
    case 5:
      {
	if (flag==0) {
	  printf("Import database from dat file to linked list first\n");
	  break;
	}
	int k;
	printf("Position you want to delete: ");scanf("%d",&k);__fpurge(stdin);
	deleteAtk(k,&root,&cur);
	//printf("\nCurrent element at position %d\n",curAt(root,cur));
	//displayNode(cur);
	printf("After delete element at position %d: \n\n",k);
	traversingList(root);
	break;
      }
    case 6:
      {
	if (flag==0) {
	  printf("Import database from dat file to linked list first\n");
	  break;
	}
	printf("\nCurrent element at position %d\n",curAt(root,cur));
	displayNode(cur);
	printf("After delete current element\n");
	deleteCurEl(&root,&cur);
	printf("\nCurrent element at position %d\n",curAt(root,cur));
	displayNode(cur);
	break;
      }
    case 7:
      {
	if (flag==0) {
	  printf("Import database from dat file to linked list first\n");
	  break;
	}
	deleteFirstEl(&root,&cur);
	printf("\nAfter delete first element\n");
	traversingList(root);
	break;
      }
    case 8:
      {
	if (flag==0) {
	  printf("Import database from dat file to linked list first\n");
	  break;
	}
	char s[30];
	printf("Model you want to search: ");gets(s);__fpurge(stdin);
	//searchAndUpdate(s,&root,&cur);
	printf("Move to front: %d\n",movetofrontUpdate(s,&root,&cur));
	//printf("Transpose: %d\n",transposeUpdate(s,&root));
	break;
      }
    case 9:
      {
	if (flag==0) {
	  printf("Import database from dat file to linked list first\n");
	  break;
	}
	int a,b;
	node *r1=NULL,*r2=NULL;
	printf("Extract from: ");scanf("%d",&a);__fpurge(stdin);
	printf("Number of element in sublist 1: ");scanf("%d",&b);__fpurge(stdin);
	printf("The rest is sublist 2\n");
	splitList(a,b,&root,&r1,&r2);
	printf("\nSublist 1:\n"); 
	printf("\n");traversingList(r1);printf("\n");
	printf("\nSublist 2:\n");
	printf("\n");traversingList(r2);printf("\n");
	freeAllNode(&r1);freeAllNode(&r2);
	//traversingList(root);
	break;
      }
    case 10:
      {
	if (flag==0) {
	  printf("Import database from dat file to linked list first\n");
	  break;
	}
	reverse(&root);
	printf("\nAfter reverse list: \n");
	traversingList(root);
	break;
      }
    case 11:
      {
	if (flag==0) {
	  printf("Import database from dat file to linked list first\n");
	  break;
	}
	char s[4];
	do {
	  printf("New text file or intial dat file?\n");
	  gets(s);__fpurge(stdin);
	  if (strcmp(s,"text")!=0 && strcmp(s,"dat")!=0) 
	    printf("Pleas re-enter only \"text\" or \"dat\"\n");
	} while (strcmp(s,"text")!=0 && strcmp(s,"dat")!=0);
	if (strcmp(s,"text")==0) {
	  if ((fp2=fopen(argv[2],"w"))==NULL) {
	    printf("Cannot open %s file\n",argv[2]);
	    return FAIL;
	  }
	  exportToText(fp2,root);fclose(fp2);
	}
	if (strcmp(s,"dat")==0) {
	  if ((fp1=fopen(argv[1],"wb"))==NULL) {
	    printf("Cannot open %s file\n",argv[1]);
	    return FAIL;
	  }
	  exportToDat(fp1,root);fclose(fp1);
	}
	printf("Saved to file. You can it check now!\n");
	break;
      }
    case 12:
      break;
    default: printf("Invalid choice\n");
      break;
    }
  } while(choice!=12);
  printf("\n____GOODBYE____\n");
  freeAllNode(&root);
  return reval;
}
