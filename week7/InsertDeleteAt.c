#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define n 20

typedef struct address_t {
  char name[40];
  char tel[12];
  char email[25];
}address;

typedef struct address_t elementtype;

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

void displayNode(node* p) {
  if (p==NULL) {
    printf("Error pointer NULL\n");
    return ;
  }
  elementtype tmp=p->element;
  printf("%s----%s----%s----%p\n",tmp.name,tmp.tel,tmp.email,p->next);
}

void insertAtHead(elementtype element,node** r,node** c) {
  node* new=makeNewNode(element);
  new->next=*r;
  *r=new; 
  *c=*r;
}

int length(node *q) {
  node *p=q;
  int i=0;
  while (p!=NULL) {
    i++;p=p->next;
  }
  return i;
}

node* insertAtPosition(elementtype ad,int k,node* r) {
  node* new;
  node* p=r;
  int i=0;
  if (r==NULL) {
    printf("No element in linked list\n");
    return NULL;
  }
  if (k<0||k>length(r)) printf("Invalid position of k\n"); 
  else {
    new=makeNewNode(ad);
    if (k==0) {
      new->next=r;
      r=new; 
    }
    else {
      while (p!=NULL && i!=k-1) { // duyet den k-1
	i++;
	p=p->next;
      }
      new->next=p->next;
      p->next=new;
    }
  }
  return new;
}

void traversingList(node *q){ //printData
  node *p;
  for (p=q;p!=NULL;p=p->next) 
    displayNode(p);
}

node* deleteAtPosition(int k,node* r) {
  node* p=r;
  int i=0;
  if (r==NULL) {
    printf("No element in linked list\n");
    return NULL;
  }
  if (k<0||k>length(r)-1) printf("Invalid position of k\n");
  else {
    if (k==0) r=r->next;
    else {
      while (p!=NULL && i!=k-1) {
	p=p->next;
	i++;
      }
      p->next=p->next->next;
    }
  }
  return r;
}

int main() {
  node *root=NULL,*cur=NULL;
  elementtype addr;
  strcpy(addr.name,"Nguyen Van Ty");
  strcpy(addr.tel,"0123456789");
  strcpy(addr.email,"ty@mail.com");
  elementtype addr1;
  strcpy(addr1.name,"Nguyen Van Thanh");
  strcpy(addr1.tel,"0123456789");
  strcpy(addr1.email,"thanh@mail.com");
  elementtype addr2;
  strcpy(addr2.name,"Bui Cong Thanh");
  strcpy(addr2.tel,"0123456789");
  strcpy(addr2.email,"thanh2412@mail.com");
  elementtype addr3;
  strcpy(addr3.name,"Pham Thi Lan");
  strcpy(addr3.tel,"0123456789");
  strcpy(addr3.email,"lan@mail.com");
  //
  insertAtHead(addr,&root,&cur);
  //
  insertAtHead(addr1,&root,&cur);
  //
  insertAtHead(addr2,&root,&cur);
  traversingList(root);printf("\n");
  //
  node* new=insertAtPosition(addr3,1,root);
  displayNode(new);printf("\n");
  traversingList(root);
  //
  node* root2=deleteAtPosition(2,root);
  printf("\n");traversingList(root);printf("\n");
  printf("\n");traversingList(root2);printf("\n");
}
