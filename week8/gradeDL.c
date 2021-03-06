#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define n 3

enum{SUCCESS,FAIL};
typedef struct grade_t {
  int stt;
  int mssv;
  char name[40];
  char sdt[11];
  float diem;
}grade;

typedef struct grade_t elementtype;

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
  printf("%p----%d----%d----%s----%s----%4.2f----%p\n",p->prev,(p->element).stt,(p->element).mssv,(p->element).name,(p->element).sdt,(p->element).diem,p->next);
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

int search(float diem,node* r) { //search only first one (name)
  node* p=r;
  int i=0;
  while (p!=NULL && (p->element).diem==diem) { //duyet den khi ket thuc hoac tim thay
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
    if (strcmp((p->element).name,element.name)==0) { 
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

void deleteElD(float diem,elementtype element,node** h,node** t,node** c) { //element.diem
  int flag=0;
  while (search(diem,*h)!=-1) {
    
    deleteAtkD(search(diem,*h),h,t,c);flag=1;
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
      if (strcmp((p->element).name,(p->next->element).name)>0) {	
	swapNode(p,p->next);
	flag=1;
      }
      p=p->next;
    }
    q=p;
  } while(flag);
}

void importFromDatD(FILE *fp,node **h,node** t,node **c) {
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

void exportToArrayD(elementtype *nodearr,node* h) {
  node *p;
  int i=0;
  for (p=h;p!=NULL;p=p->next) {
    nodearr[i]=p->element;
    printf("%d----%d----%s----%s----%4.2f\n",nodearr[i].stt,nodearr[i].mssv,nodearr[i].name,nodearr[i].sdt,nodearr[i].diem);
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
    fscanf(fp,"%d %d %[^\t]%*c %s %f",&nodearr[i].stt,&nodearr[i].mssv,nodearr[i].name,nodearr[i].sdt,&nodearr[i].diem);__fpurge(stdin);
    printf("%d----%d----%s----%s----%4.2f\n",nodearr[i].stt,nodearr[i].mssv,nodearr[i].name,nodearr[i].sdt,nodearr[i].diem);
    insertAfterCurD(nodearr[i],h,t,c);	    
  }
  free(nodearr);
}

void importFromTextD2(FILE *fp,node** h1,node** t1,node** c1,node** h2,node ** t2,node** c2) {
  elementtype *nodearr;
  int i;
  nodearr=(elementtype*)malloc(n*sizeof(elementtype));
  if (nodearr==NULL) {
    printf("Memory allocation failed\n");
    return ;
  }	  
  for (i=0;i<n;i++) {
    fscanf(fp,"%d %d %[^\t]%*c %s %f",&nodearr[i].stt,&nodearr[i].mssv,nodearr[i].name,nodearr[i].sdt,&nodearr[i].diem);__fpurge(stdin);
    printf("%d----%d----%s----%s----%4.2f\n",nodearr[i].stt,nodearr[i].mssv,nodearr[i].name,nodearr[i].sdt,nodearr[i].diem);
    if (nodearr[i].diem >=8) 
      insertAfterCurD(nodearr[i],h1,t1,c1);
    else insertAfterCurD(nodearr[i],h2,t2,c2);
  }
  free(nodearr);
}

void exportToTextD(FILE *fp,node* h) {
  node *p=NULL;
  for (p=h;p!=NULL;p=p->next) {
    fprintf(fp,"%d----%d----%s----%s----%4.2f\n",(p->element).stt,(p->element).mssv,(p->element).name,(p->element).sdt,(p->element).diem); 
  }  
}

elementtype readData() {
  elementtype res;
  printf("STT: ");scanf("%d",&res.stt);__fpurge(stdin);
  printf("MSSV: ");scanf("%d",&res.mssv);__fpurge(stdin);
  printf("Name: ");gets(res.name);__fpurge(stdin);
  printf("SDT: ");gets(res.sdt);__fpurge(stdin);
  printf("Diem: ");scanf("%f",&res.diem);__fpurge(stdin);
  return res;
}


int main(int argc,char* argv[]) {
  if (argc!=2) {
    printf("Wrong number of input\n");
    return 0;
  }
  FILE *fp;
  int reval=SUCCESS;
  int choice,i,irc,flag=0;
  node *head1=NULL,*tail1=NULL,*cur1=NULL;
  node *head2=NULL,*tail2=NULL,*cur2=NULL;
  do {
    choice=0;
    printf("\n_____MENU_____\n");
    printf("1.Initiate\n");
    printf("2.Display\n");
    printf("3.Add student\n");
    printf("4.Move student\n");
    printf("5.Concatenate\n");
    printf("6.Concatenate and soft\n");
    printf("7.Quit\n");
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
	if ((fp=fopen(argv[1],"r"))==NULL) {
	  printf("Cannot open %s file\n",argv[1]);
	  return FAIL;
	}
	importFromTextD2(fp,&head1,&tail1,&cur1,&head2,&tail2,&cur2);
	break;
      }
    case 2:
      {
	if (flag==0) {
	  printf("Import database from dat file to linked list first\n");
	  break;
	}
	printf("List1: \n");
	traversingListForD(head1);
	printf("List2: \n");
	traversingListForD(head2);
	break;
      }
    case 3:
      {
	if (flag==0) {
	  printf("Import database from dat file to linked list first\n");
	  break;
	}
	elementtype tmp=readData();
	if (tmp.diem >=8) insertAtTailD(tmp,&head1,&tail1,&cur1);
	else insertAtTailD(tmp,&head2,&tail2,&cur2);
	break;
      }
    case 4:
      {
	if (flag==0) {
	  printf("Import database from dat file to linked list first\n");
	  break;
	}
	break;
      }
    case 5:
      {
	if (flag==0) {
	  printf("Import database from dat file to linked list first\n");
	  break;
	}
	break;
      }
    case 6:
      {
	if (flag==0) {
	  printf("Import database from dat file to linked list first\n");
	  break;
	}
	break;
      }
    case 7:
      break;
    default: printf("Invalid choice\n");
      break;
    }
  } while(choice!=7);
  printf("\n____GOODBYE____\n");
  freeAllNodeD(&head1,&tail1);
  freeAllNodeD(&head2,&tail2);
  return reval;
}
