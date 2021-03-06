#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define n 20

enum{SUCCESS,FAIL};
typedef struct PhoneDB {
  char model[30];
  int rom;
  float size;
  long price;
}phone;

typedef struct PhoneDB elementtype;

typedef struct node node;

struct node {
  elementtype element;
  node* prev;
  node* next;
};

//typedef node* doublelist;
//doublelist head,tail,cur;

node* makeNewNodeD(elementtype element) {
  node *new=(node*)malloc(sizeof(node));
  new->element=element;
  new->next=NULL;
  new->prev=NULL;
  return new;
}

void makeNullD(node** r) {
  (*r)=NULL;
}

int isEmptyD(node* r) {
  return (r==NULL);
}

void displayNodeD(node* p) {
  if (p==NULL) {
    printf("Error pointer NULL\n");
    return ;
  }
  elementtype tmp=p->element;
  printf("%p----%s----%dGB----%.1f\"----%ld VND----%p\n",p->prev,tmp.model,tmp.rom,tmp.size,tmp.price,p->next);
}

void traversingListForD(node* h) {
  node* p;
  for (p=h;p!=NULL;p=p->next) 
    displayNodeD(p);
}

void traversingListBackD(node* t) {
  node* p;
  for (p=t;p!=NULL;p=p->prev) 
    displayNodeD(p);
}

void insertAtHeadD(elementtype element,node** h,node** t,node** c) {
  node* new=makeNewNodeD(element);
  if (*h==NULL) {
    *h=new;*t=new;
  } else {
    (*h)->prev=new;
    new->next=*h;
    new->prev=NULL;
    *h=new;
  }
  *c=*h;
}

void insertAtTailD(elementtype element,node** h,node** t,node** c) {
  node* new=makeNewNodeD(element);
  if (*h==NULL) {
    *h=new;*t=new;
  } else {
    (*t)->next=new;
    new->prev=*t;
    new->next=NULL;
    *t=new;
  }
  *c=*t;
}

void insertAfterCurD(elementtype e,node** h,node** t,node** c) {
  node* new=makeNewNodeD(e);
  if (*h==NULL) {
    *h=new;*t=new;*c=*h;
  } else {
    new->next=(*c)->next;
    if ((*c)->next!=NULL) (*c)->next->prev=new;
    new->prev=*c;
    (*c)->next=new;
    *c=new;
    if (new->next==NULL) *t=new;
  }
}

void insertBeforeCurD(elementtype e,node** h,node** t,node** c) {
  node* new=makeNewNodeD(e);
  if (*h==NULL) {
    *h=new;*t=new;*c=*h;
  } else {
    new->next=*c;
    if (*c==*h) {
      (*h)->prev=new;
      new->prev=NULL;
      *h=new;
    } else {
      (*c)->prev->next=new;
      new->prev=(*c)->prev;
      (*c)->prev=new;
    }
    *c=new;
  }
}

void deleteListD(node* p,node** h,node** t,node**c) {
  if (*h==NULL) printf("Empty List\n");
  else {
    if (p!=*t) *c=p->next;
    else *c=p->prev;
    if (p==*h) (*h)=(*h)->next;
    else p->prev->next=p->next;
    if (p!=*t) p->next->prev=p->prev;
    free(p);
  }
}

void insertListD(elementtype x,node* p,node** h,node** t,node**c) {
  if (*h==NULL) {
    (*h)=(node*)malloc(sizeof(node));
    (*h)->element=x;
    (*h)->next=NULL;
    (*h)->prev=NULL;
    *t=*h;
    *c=*h;
  } else {
    node* temp=(node*)malloc(sizeof(node));
    temp->element=x;
    temp->next=p;
    temp->prev=p->prev;
    if (p->prev!=NULL) {
      p->prev->next=temp;
      p->prev=temp;
    }
    *c=temp;
  }
}

int curAt (node* r,node* c) {
  node *p=r;
  int i=-1;
  while (p!=NULL) {
    if (p==c) return (i+1);
    else {
      p=p->next;i++;
    }
  }
  return i;
}

int length(node *q) {
  node *p=q;
  int i=0;
  while (p!=NULL) {
    i++;p=p->next;
  }
  return i;
}

void insertAtkD(elementtype element,int k,node** h,node** t,node** c) {
  if (*h==NULL) {
    printf("No element in double linked list\n");
    return ;
  }
  if (k<0||k>length(*h)) printf("Invalid position of k\n");
  else {
    if (k==0) insertAtHeadD(element,h,t,c);
    else if (k==length(*h)) insertAtTailD(element,h,t,c);
    else {
      int i=0;
      node* p=*h;
      node* new=makeNewNodeD(element);
      while (p!=NULL && i!=k-1) {
	i++;
	p=p->next;
      }
      new->next=p->next;
      new->prev=p;
      p->next->prev=new;
      p->next=new;
      *c=new;
    }
  }
}

int search(elementtype element,node* r) { //search only first one (name)
  node* p=r;
  int i=0;
  while (p!=NULL && strcmp((p->element).model,element.model)!=0) { //duyet den khi ket thuc hoac tim thay
    p=p->next;
    i++;
  }
  if (p!=NULL) return i; //tra ve vi tri tim thay
  else return -1; // tra ve 0 neu ko tim thay
}

void searchAll(elementtype element,node* r) { //search all position (name)
  node *p=r;
  int i=0,flag=0;
  while (p!=NULL) {
    if (strcmp((p->element).model,element.model)==0) { 
      printf("%d ",i);
      flag=1;
    }
    p=p->next;
    i++;
  }
  if (flag==0) printf("Not found");
  printf("\n");
}

void deleteFirstElD(node** h,node** t,node** c) {
  if (*h==NULL) printf("No element in linked list\n");
  else {
    (*h)=(*h)->next;
    (*h)->prev=NULL;
    *c=*h;
  }
}

void deleteLastElD(node** h,node** t,node** c) {
  if (*h==NULL) printf("No element in linked list\n");
  else {
    (*t)=(*t)->prev;
    (*t)->next=NULL;
    *c=*t;
  }
}

void deleteAtkD(int k,node** h,node** t,node** c) {
  if (*h==NULL) {
    printf("No element in linked list\n");
    return ;
  }
  if (k<0||k>length(*h)-1) printf("Invalid postion of k\n");
  else {
    if (k==0) deleteFirstElD(h,t,c);
    else if (k==length(*h)-1) deleteLastElD(h,t,c);
    else {
      node* p=*h;
      int i=0;
      while (p!=NULL && i!=k-1) {
	p=p->next;
	i++;
      }
      p->next=p->next->next;
      p->next->prev=p;
      *c=p;
    }
  }
}

void deleteCurElD(node** h,node** t,node** c){
  deleteAtkD(curAt(*h,*c),h,t,c);
}

void deleteElD(elementtype element,node** h,node** t,node** c) { //element.name
  int flag=0;
  while (search(element,*h)!=-1) {
    deleteAtkD(search(element,*h),h,t,c);flag=1;
  }
  if (flag==0) printf("Cannot find element\n");
}

void freeAllNodeD(node** h,node** t) { 
  node* to_free=*h;
  while (to_free!=NULL) {
    //(*h)->prev=NULL;
    (*h)=(*h)->next;
    free(to_free);
    to_free=(*h);
  }
  (*t)=NULL;
}

void reverseD(node** h) { //reverse void
  node* temp=NULL;
  node* cur=*h;
  while (cur!=NULL) {
    temp=cur->prev;
    cur->prev=cur->next;
    cur->next=temp;
    cur=cur->prev;
  }
  if (temp!=NULL) *h=temp->prev;
}
/*
node* reverseList(node* r) { //reverse node return node
  node* cur,* prev;
  cur=prev=NULL;
  while (r!=NULL) {
    cur =r;
    r=r->next;
    cur->next=prev;
    prev=cur;
  }
  return prev;
}
*/
void swapNode (node* a,node* b) {
  elementtype tmp=a->element;
  a->element=b->element;
  b->element=tmp;
}

void softNode(node** r) {
  int flag;
  node* p;
  node* q=NULL;
  if (*r==NULL) return;
  do {
    flag=0;
    p=*r;
    while (p->next!=q) {
      //if (p->element > p->next->element) { // can change condition for each addr_el
      if (strcmp((p->element).model,(p->next->element).model)>0) {	
	swapNode(p,p->next);
	flag=1;
      }
      p=p->next;
    }
    q=p;
  } while(flag);
}

void importFromDatDAfter(FILE *fp,node **h,node **t,node **c) {
  elementtype * nodearr;
  int irc,i;
  nodearr=(elementtype*)malloc(n*sizeof(elementtype));
  if (nodearr==NULL) {
    printf("Memory allocation failed\n");
    return ;
  }
  irc=fread(nodearr,sizeof(elementtype),n,fp);
  printf("fread return code = %d\n",irc);
  for (i=0;i<n;i++) {
    //printf("%s----%dGB----%.1f\"----%ld VND\n",nodearr[i].model,nodearr[i].rom,nodearr[i].size,nodearr[i].price);
    insertAfterCurD(nodearr[i],h,t,c);
  }
  free(nodearr);
}


void importFromDatDBefore(FILE *fp,node **h,node **t,node **c) {
  elementtype * nodearr;
  int irc,i;
  nodearr=(elementtype*)malloc(n*sizeof(elementtype));
  if (nodearr==NULL) {
    printf("Memory allocation failed\n");
    return ;
  }
  irc=fread(nodearr,sizeof(elementtype),n,fp);
  printf("fread return code = %d\n",irc);
  for (i=0;i<n;i++) {
    //printf("%s----%dGB----%.1f\"----%ld VND\n",nodearr[i].model,nodearr[i].rom,nodearr[i].size,nodearr[i].price);
    insertBeforeCurD(nodearr[i],h,t,c);
  }
  free(nodearr);
}

void exportToArrayD(elementtype *nodearr,node* h) {
  node *p;
  int i=0;
  for (p=h;p!=NULL;p=p->next) {
    nodearr[i]=p->element;
    printf("%s----%dGB----%.1f\"----%ld VND\n",nodearr[i].model,nodearr[i].rom,nodearr[i].size,nodearr[i].price);
    i++;
  }
}

void exportToDatD(FILE *fp,node* h) {
  node *p=NULL;
  elementtype * nodearr;
  int irc,i;
  nodearr=(elementtype*)malloc(n*sizeof(elementtype));
  if (nodearr==NULL) {
    printf("Memory allocation failed\n");
    return ;
  }
  exportToArrayD(nodearr,h);
  irc=fwrite(nodearr,sizeof(elementtype),n,fp);
  printf("fwrite return code = %d\n",irc);
  
}

void importFromTextD(FILE *fp,node** h,node** t,node** c) {
  elementtype *nodearr;
  int i;
  nodearr=(elementtype*)malloc(n*sizeof(elementtype));
  if (nodearr==NULL) {
    printf("Memory allocation failed\n");
    return ;
  }	  
  for (i=0;i<n;i++) {
    fscanf(fp,"%*c%[^\t]%*c %d%*s %f%*c %ld%*s",nodearr[i].model,&nodearr[i].rom,&nodearr[i].size,&nodearr[i].price);__fpurge(stdin);
    printf("%s----%dGB----%.1f\"----%ld VND\n",nodearr[i].model,nodearr[i].rom,nodearr[i].size,nodearr[i].price);
    insertAfterCurD(nodearr[i],h,t,c);	    
  }
  free(nodearr);
}

void exportToTextD(FILE *fp,node* h) {
  node *p=NULL;
  for (p=h;p!=NULL;p=p->next) {
    fprintf(fp,"%s----%dGB----%.1f\"----%ld VND\n",(p->element).model,(p->element).rom,(p->element).size,(p->element).price);
  }  
}
/*
node* copyList(node* r) {
  if (r==NULL) return NULL;
  node* new=(node*)malloc(sizeof(node));
  new->element=r->element;
  new->next=copyList(r->next);
  return new;
}
*/

elementtype readData() {
  elementtype res;
  printf("Model: ");gets(res.model);__fpurge(stdin);
  printf("ROM(GB): ");scanf("%d",&res.rom);__fpurge(stdin);
  printf("Size(\"): ");scanf("%f",&res.size);__fpurge(stdin);
  printf("Price(VND): ");scanf("%ld",&res.price);__fpurge(stdin);
  return res;
}

void searchAndUpdateD(char* model,node** h,node** t,node** c) {
  node *p=*h;
  int flag=0;
  if (strcmp(((*h)->element).model,model)==0) {
    flag=1;
    node *new=makeNewNodeD(readData());
    new->next=(*h)->next;
    (*h)->next->prev=new;
    free(*h);
    new->prev=NULL;
    *h=new;
    *c=new;
    displayNodeD(*c);
  }
  while (p->next!=NULL) {
    if (strcmp(((p->next)->element).model,model)==0) {
      flag=1;
      node *new=makeNewNodeD(readData());
      new->next=p->next->next;
      if (p->next->next!=NULL) new->next->next->prev=new;
      free(p->next);
      new->prev=p;
      p->next=new;
      *c=new;
      displayNodeD(*c);
    }
    p=p->next;
  }
  if (flag==0) printf("Not found\n");
}

void copyListD(node* h,node *t,node **h1,node **t1) {
  if (h==NULL) {
    *h1=NULL;*t1=NULL;
  }
  node *c1=NULL;
  while (h!=NULL) {
    insertAtTailD(h->element,h1,t1,&c1);
    h=h->next;
  }
}

void splitListD(int a,int b,node* h,node* t,node** h1,node** h2) {
  if (a<0 || a>length(h)-1) {
    printf("Invalid start position\n");
    return ;
  }
  if (b<0 || b+a>length(h)) {
    printf("Invalid number of element of sublist1\n");
    return ;
  }
  node *t1=NULL,*t2=NULL;
  copyListD(h,t,h1,&t1);
  copyListD(h,t,h2,&t2);
  node *c1=*h1,*c2=*h2;
  int i=0;
  while(*h1!=NULL) {
    if (i==a) break;
    (*h1)=(*h1)->next;
    (*h1)->prev=NULL;
    i++;
  }
  while(c1!=NULL) {
    deleteAtkD(i,h2,&t2,&c2);
    if (i==b+a-1) {
      c1->next=NULL;
      break;
    }
    c1=c1->next;
    i++;
  }
}

void splitListD2(int a,int b,node* h,node* t,node** h1,node** h2) {
  if (a<0 || a>length(h)-1) {
    printf("Invalid start position\n");
    return ;
  }
  if (b<=0 || b+a>length(h)) {
    printf("Invalid number of element of sublist 1\n");
    return ;
  }
  node *t1=NULL,*t2=NULL;
  copyListD(h,t,h1,&t1);
  copyListD(h,t,h2,&t2);
  node *c1=*h1,*c2=*h2;
  int i=a,j=b,k=b+a;
  //list2
  while (j!=0) {
    deleteAtkD(a,h2,&t2,&c2);
    j--;
  }
  //list1
  while (i!=0) {
    deleteFirstElD(h1,&t1,&c1);
    i--;
  } 
  while (k!=length(h)) {
    deleteLastElD(h1,&t1,&c1);
    k++;
  }
}

int main(int argc,char* argv[]) {
  if (argc!=3) {
    printf("Wrong number of input\n");
    return 0;
  }
  FILE *fp1,*fp2;
  int reval=SUCCESS;
  int choice,i,irc,flag=0;
  node *head=NULL,*tail=NULL,*cur=NULL;
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
    printf("8.Delete last\n");
    printf("9.Search and Update\n");
    printf("10.Divide and Extract\n");
    printf("11.Reverse List\n");
    printf("12.Save to File\n");
    printf("13.Quit\n");
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
	char s[6];
	do {
	  printf("Insert before or Insert at tail: ");
	  gets(s);__fpurge(stdin);
	  if (strcmp(s,"before")!=0 && strcmp(s,"at tail")!=0)
	    printf("Please re-enter only \"before\" or \"at tail\"\n");
	} while(strcmp(s,"before")!=0 && strcmp(s,"at tail")!=0);
	if (strcmp(s,"at tail")==0) 
	  importFromDatDAfter(fp1,&head,&tail,&cur);
	else importFromDatDBefore(fp1,&head,&tail,&cur);
	fclose(fp1);
	break;
      }
    case 2:
      {
	if (flag==0) {
	  printf("Import database from dat file to linked list first\n");
	  break;
	}
	char s[8];
	do {
	  printf("Traversing forward or backward: ");
	  gets(s);__fpurge(stdin);
	  if (strcmp(s,"forward")!=0 && strcmp(s,"backward")!=0)
	    printf("Please re-enter only \"forward\" or \"backward\"\n");
	} while(strcmp(s,"forward")!=0 && strcmp(s,"backward")!=0);
	if (strcmp(s,"forward")==0) 
	  traversingListForD(head);
	else traversingListBackD(tail);
	break;
      }
    case 3:
      {
	if (flag==0) {
	  printf("Import database from dat file to linked list first\n");
	  break;
	}
	printf("\nCurrent element at position %d\n",curAt(head,cur));
	printf("Insert after current element\n");
        insertAfterCurD(readData(),&head,&tail,&cur);
	printf("\n");displayNodeD(cur);
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
	if (k<0||k>length(head)) {
	  printf("Invalid position of k\n");
	  break;
	}
	insertAtkD(readData(),k,&head,&tail,&cur);
	printf("After insert at position %d: \n",k);
	printf("\nCurrent element at position %d\n",curAt(head,cur));
	displayNodeD(cur);
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
	deleteAtkD(k,&head,&tail,&cur);
	//printf("\nCurrent element at position %d\n",curAt(root,cur));
	//displayNode(cur);
	printf("After delete element at position %d: \n\n",k);
	traversingListForD(head);
	break;
      }
    case 6:
      {
	if (flag==0) {
	  printf("Import database from dat file to linked list first\n");
	  break;
	}
	printf("\nCurrent element at position %d\n",curAt(head,cur));
	displayNodeD(cur);
	printf("After delete current element\n");
	deleteCurElD(&head,&tail,&cur);
	printf("\nCurrent element at position %d\n",curAt(head,cur));
	displayNodeD(cur);
	break;
      }
    case 7:
      {
	if (flag==0) {
	  printf("Import database from dat file to linked list first\n");
	  break;
	}
	deleteFirstElD(&head,&tail,&cur);
	printf("\nAfter delete first element\n");
	traversingListForD(head);
	break;
      }
    case 8:
      {
	if (flag==0) {
	  printf("Import database from dat file to linked list first\n");
	  break;
	}
	deleteLastElD(&head,&tail,&cur);
	printf("\nAfter delete last element\n");
	traversingListForD(head);
	break;
      }
    case 9:
      {
	if (flag==0) {
	  printf("Import database from dat file to linked list first\n");
	  break;
	}
	char s[30];
	printf("Model you want to search: ");gets(s);__fpurge(stdin);
	searchAndUpdateD(s,&head,&tail,&cur);
	//traversingList(root);printf("\n");
	//displayNode(cur);
	break;
      }
    case 10 :
      {
	if (flag==0) {
	  printf("Import database from dat file to linked list first\n");
	  break;
	}
	int a,b;
	node *h1=NULL,*h2=NULL;
	printf("Extract from: ");scanf("%d",&a);__fpurge(stdin);
	printf("Number of element in sublist 1: ");scanf("%d",&b);__fpurge(stdin);
	printf("The rest is sublist 2\n");
	splitListD2(a,b,head,tail,&h1,&h2);
	printf("\nSublist 1:\n"); 
	printf("\n");traversingListForD(h1);printf("\n");
	printf("\nSublist 2:\n");
	printf("\n");traversingListForD(h2);printf("\n");
	//freeAllNode(&r1);freeAllNode(&r2);
	//traversingList(root);
	break;
      }
    case 11:
      {
	if (flag==0) {
	  printf("Import database from dat file to linked list first\n");
	  break;
	}
	reverseD(&head);
	printf("\nAfter reverse list: \n");
	traversingListForD(head);
	break;
      }
    case 12:
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
	  exportToTextD(fp2,head);fclose(fp2);
	}
	if (strcmp(s,"dat")==0) {
	  if ((fp1=fopen(argv[1],"wb"))==NULL) {
	    printf("Cannot open %s file\n",argv[1]);
	    return FAIL;
	  }
	  exportToDatD(fp1,head);fclose(fp1);
	}
	printf("Saved to file. You can it check now!\n");
	break;
      }
    case 13:
      break;
    default: printf("Invalid choice\n");
      break;
    }
  } while(choice!=13);
  printf("\n____GOODBYE____\n");
  freeAllNodeD(&head,&tail);
  return reval;
}
