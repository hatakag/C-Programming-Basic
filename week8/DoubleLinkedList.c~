#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum{SUCCESS,FAIL};
typedef struct address_t {
  char name[40];
  char tel[12];
  char email[25];
}address;

typedef struct address_t elementtype;

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
  printf("%p----%s----%s----%s----%p\n",p->prev,(p->element).name,(p->element).tel,(p->element).email,p->next);
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
  while (p!=NULL && strcmp((p->element).name,element.name)!=0) { //duyet den khi ket thuc hoac tim thay
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

void importFromTextD(FILE *fp,node** h,,node** t,node** c) {
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
    insertAfterCurD(nodearr[i],h,r,c);	    
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
int main() {
  node *head=NULL,*tail=NULL,*cur=NULL;
  elementtype addr,addr1,addr2,addr3,addr4;
  strcpy(addr.name,"bui cong thanh");
  strcpy(addr.tel,"0123456789");
  strcpy(addr.email,"thanh@mail.com");
  //
  strcpy(addr1.name,"bui cong duy");
  strcpy(addr1.tel,"0123456789");
  strcpy(addr1.email,"duy@mail.com");
  //
  strcpy(addr2.name,"nguyen hoang hai");
  strcpy(addr2.tel,"0123456789");
  strcpy(addr2.email,"hai@mail.com");
  //
  strcpy(addr3.name,"pham thi lan");
  strcpy(addr3.tel,"0123456789");
  strcpy(addr3.email,"lan@mail.com");
  //
  strcpy(addr4.name,"nguyen thi hoa");
  strcpy(addr4.tel,"0123456789");
  strcpy(addr4.email,"hoa@mail.com");
  //
  insertAtHeadD(addr,&head,&tail,&cur);
  insertAtTailD(addr1,&head,&tail,&cur);
  insertAtTailD(addr2,&head,&tail,&cur);
  insertBeforeCurD(addr3,&head,&tail,&cur);
  //deleteListD(cur,&head,&tail,&cur);
  //insertListD(cur);
  //insertAtkD(addr4,1,&head,&tail,&cur);
  //deleteFirstElD(&head,&tail,&cur);
  //deleteLastElD(&head,&tail,&cur);
  //deleteAtkD(1,&head,&tail,&cur);
  //deleteCurElD(&head,&tail,&cur);
  //freeAllNodeD(&head,&tail);
  printf("\n");printf("cur at %d, length: %d\n",curAt(head,cur),length(head));
  displayNodeD(cur);
  reverseD(&head);//reverseD(&tail);
  displayNodeD(cur);
  //
  printf("\n");traversingListForD(head);
  printf("\n");traversingListBackD(tail);
}
