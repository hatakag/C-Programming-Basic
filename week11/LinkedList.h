#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define n 20

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
  node *next;
};

//node *root,*cur,*prev;

node* makeNewNode(elementtype element) { 
  node* new=(node*)malloc(sizeof(node));
  new->element=element;
  new->next=NULL;
  return new;  
}

elementtype readData() {
  elementtype res;
  printf("Model: ");gets(res.model);__fpurge(stdin);
  printf("ROM(GB): ");scanf("%d",&res.rom);__fpurge(stdin);
  printf("Size(\"): ");scanf("%f",&res.size);__fpurge(stdin);
  printf("Price(VND): ");scanf("%ld",&res.price);__fpurge(stdin);
  return res;
}

void printData(elementtype res) {
  printf("%s----%dGB----%.1f\"----%ld VND\n",res.model,res.rom,res.size,res.price);
}

void displayNode(node* p) {
  if (p==NULL) {
    printf("Error pointer NULL\n");
    return ;
  }
  elementtype tmp=p->element;
  printf("%s----%dGB----%.1f\"----%ld VND----%p\n",tmp.model,tmp.rom,tmp.size,tmp.price,p->next);
}

elementtype readNode(node* p) {
  if (p==NULL) {
    printf("Error pointer NULL\n");
    return ;
  }
  return p->element;
}

void insertAtHead(elementtype element,node** r,node** c) {
  node* new=makeNewNode(element);
  new->next=*r;
  *r=new; 
  *c=*r;
}

void insertAtTail(elementtype element,node** r,node** c) {
  node *new=makeNewNode(element);
  node *p=*r;
  if (p==NULL) insertAtHead(element,r,c);
  else {
    while (p->next!=NULL) {
      p=p->next;
    }
    p->next=new;
    new->next=NULL;
    *c=new;
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

void insertAfterCur(elementtype element,node** r,node** c) {
  node* new=makeNewNode(element);
  if (*r==NULL) {
    *r=new;
    *c=*r;
  } else {
    new->next=(*c)->next;
    (*c)->next=new;
    (*c)=(*c)->next;
  }
}

int length(node *q) {
  node *p=q;
  int i=0;
  while (p!=NULL) {
    i++;p=p->next;
  }
  return i;
}

void insertAtk(elementtype element,int k,node** r,node** c) {
  node* new;
  node* p=*r;
  int i=0;
  if (*r==NULL) {
    printf("No element in linked list\n");
    return;
  }
  if (k<0||k>length(*r)) printf("Invalid position of k\n"); 
  else {
    new=makeNewNode(element);
    if (k==0) insertAtHead(element,r,c);
    else {
      while (p!=NULL && i!=k-1) { // duyet den k-1
	i++;
	p=p->next;
      }
      new->next=p->next;
      p->next=new;
    }
    *c=new;
  }
}

void insertBeforeCur(elementtype element,node** r,node** c) {
  if (*r==NULL)  //no element in root ->insertAtHead
    insertAtHead(element,r,c);
  else
    insertAtk(element,curAt(*r,*c),r,c); //insert at position cur
}

void traversingList(node *q){ //printData
  node *p;
  for (p=q;p!=NULL;p=p->next) 
    displayNode(p);
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

void deleteFirstEl(node** r,node** c) {
  if (*r==NULL) printf("root has no element\n");
  else {
    (*r)=(*r)->next;
    *c=*r;
  }
}

void deleteLastEl(node** r,node** c) {
  node* p=*r;
  if (*r==NULL) printf("root has no element\n");
  else {
    while (p->next->next!=NULL) p=p->next;
    p->next=NULL;
    *c=p;
  }
}

void deleteAtk(int k,node** r,node** c) { //cur after point to before deleted
  node* p=*r;
  int i=0;
  if (*r==NULL) {
    printf("No element in linked list\n");
    return ;
  }
  if (k<0||k>length(*r)-1) printf("Invalid position of k\n");
  else {
    if (k==0) deleteFirstEl(r,c);
    else {
      while (p!=NULL && i!=k-1) {
	p=p->next;
	i++;
      }
      p->next=p->next->next;
      *c=p;
    }
  }
}

void deleteCurEl(node** r,node** c) {
  deleteAtk(curAt(*r,*c),r,c);
}

void deleteEl(elementtype element,node** r,node** c) { //element.name
  int flag=0;
  while (search(element,*r)!=-1) {
    deleteAtk(search(element,*r),r,c);flag=1;
  }
  if (flag==0) printf("Cannot find element\n");
}

int isEmpty(node* r) {
  return (r==NULL);
}

void freeAllNode(node** r) { 
  node* to_free=*r;
  while (to_free!=NULL) {
    (*r)=(*r)->next;
    free(to_free);
    to_free=(*r);
  }
}

void reverse(node** r) { //reverse void
  node* prev=NULL;
  node* cur=*r;
  node* next;
  while (cur!=NULL) {
    next=cur->next;
    cur->next=prev;
    prev=cur;
    cur=next;
  }
  *r=prev;
}

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

void importFromDat(FILE *fp,node **r,node **c) {
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
    insertAfterCur(nodearr[i],r,c);
  }
  free(nodearr);
}

void exportToArray(elementtype *nodearr,node* r) {
  node *p;
  int i=0;
  for (p=r;p!=NULL;p=p->next) {
    nodearr[i]=p->element;
    printf("%s----%dGB----%.1f\"----%ld VND\n",nodearr[i].model,nodearr[i].rom,nodearr[i].size,nodearr[i].price);
    i++;
  }
}

void exportToDat(FILE *fp,node* r) {
  node *p=NULL;
  elementtype * nodearr;
  int irc,i;
  nodearr=(elementtype*)malloc(n*sizeof(elementtype));
  if (nodearr==NULL) {
    printf("Memory allocation failed\n");
    return ;
  }
  exportToArray(nodearr,r);
  irc=fwrite(nodearr,sizeof(elementtype),n,fp);
  printf("fwrite return code = %d\n",irc);
  
}

void importFromText(FILE *fp,node** r,node** c) {
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
    insertAfterCur(nodearr[i],r,c);	    
  }
  free(nodearr);
}

void exportToText(FILE *fp,node* r) {
  node *p=NULL;
  for (p=r;p!=NULL;p=p->next) {
    fprintf(fp,"%s----%dGB----%.1f\"----%ld VND\n",(p->element).model,(p->element).rom,(p->element).size,(p->element).price);
  }  
}

node* copyList(node* r) {
  if (r==NULL) return NULL;
  node* new=(node*)malloc(sizeof(node));
  new->element=r->element;
  new->next=copyList(r->next);
  return new;
}

void splitList(int a,int b,node** r,node** r1,node** r2) {
  if (a<0 || a>length(*r)-1) {
    printf("Invalid start position\n");
    return ;
  }
  if (b<0 || b+a>length(*r)) {
    printf("Invalid number of element of sublist1\n");
    return ;
  }
  *r1=copyList(*r);*r2=copyList(*r);
  int i=0,j=0;
  while(*r1!=NULL && *r2!=NULL) {
    if (i==a) break;
    (*r1)=(*r1)->next;
    (*r2)=(*r2)->next;
    i++;
  }
  node *c1=*r1;
  while(c1!=NULL) {
    j++;
    if (j==b) {
      c1->next=NULL;
      (*r2)=(*r2)->next;
      break;
    }
    c1=c1->next;
    (*r2)=(*r2)->next;    
  }
}

void searchAndUpdate(char* model,node** r,node** c) {
  node *p=*r;
  int flag=0;
  if (strcmp(((*r)->element).model,model)==0) {
    flag=1;
    node *new=makeNewNode(readData());
    new->next=(*r)->next;
    free(*r);
    *r=new;
    *c=new;
    displayNode(*c);
  }
  while (p->next!=NULL) {
    if (strcmp(((p->next)->element).model,model)==0) {
      flag=1;
      node *new=makeNewNode(readData());
      new->next=p->next->next;
      free(p->next);
      p->next=new;
      *c=new;
      displayNode(*c);
    }
    p=p->next;
  }
  if (flag==0) printf("Not found\n");
}

int movetofront(char *model,node** r,node** c) {
  node *p=*r;
  int i=0;
  while (p!=NULL && strcmp((p->element).model,model)!=0) {
    p=p->next;
    i++;
  }
  if (p!=NULL) {
    elementtype tmp=p->element;
    deleteAtk(i,r,c);
    insertAtHead(tmp,r,c);
    return i;
  }
  else return -1;
}

int transpose(char *model,node** r) {
  node *p=*r;
  int i=0;
  if (strcmp((p->element).model,model)==0) return 0;
  while (p->next!=NULL && strcmp(((p->next)->element).model,model)!=0) {
    p=p->next;
    i++;
  }
  if (p->next!=NULL) {
    swapNode(p,p->next);
    return i+1;
  }
  else return -1;
}

int movetofrontUpdate(char *model,node** r,node** c) {
  node *p=*r;
  int i=0;
  while (p!=NULL && strcmp((p->element).model,model)!=0) {
    p=p->next;
    i++;
  }
  if (p!=NULL) {
    deleteAtk(i,r,c);
    insertAtHead(readData(),r,c);
    return i;
  }
  else return -1;
}

int transposeUpdate(char *model,node** r) {
  node *p=*r;
  int i=0;
  if (strcmp((p->element).model,model)==0) {
    p->element=readData();
    return 0;
  }
  while (p->next!=NULL && strcmp(((p->next)->element).model,model)!=0) {
    p=p->next;
    i++;
  }
  if (p->next!=NULL) {
    (p->next)->element=readData();
    swapNode(p,p->next);
    return i+1;
  }
  else return -1;
}
