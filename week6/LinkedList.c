#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct address_t {
  char name[40];
  char tel[12];
  char email[30];
}address;

struct list_el {
  address addr;
  struct list_el *next;
};
typedef struct list_el node_addr;

node_addr *root,*cur,*prev;

node_addr* makeNewNode(address addr) { 
  node_addr* new=(node_addr*)malloc(sizeof(node_addr));
  new->addr=addr;
  new->next=NULL;
  return new;
}

void displayNode(node_addr* p) {
  if (p==NULL) {
    printf("Error pointer NULL\n");
    return ;
  }
  address tmp=p->addr;
  printf("%s----%s----%s----%p\n",tmp.name,tmp.tel,tmp.email,p->next);
}

address readNode(node_addr* p) {
  if (p==NULL) {
    printf("Error pointer NULL\n");
    return ;
  }
  return p->addr;
}

void insertAtHead(address addr) {
  node_addr* new=makeNewNode(addr);
  new->next=root;
  root=new;
  cur=root;
}

void insertAtTail(address addr) {
  node_addr *new=makeNewNode(addr);
  node_addr *p=root;
  while (p->next!=NULL) {
    p=p->next;
  }
  p->next=new;
  new->next=NULL;
}

void insertAfterCur(address addr) {
  node_addr* new=makeNewNode(addr);
  new->next=cur->next;
  cur->next=new;
  cur=cur->next;
}

void insertBeforeCur(address addr) {
  node_addr* new=makeNewNode(addr);
  for (prev=root;prev!=NULL;prev=prev->next) {
    if (prev->next=cur) break;
  }
  if (root==NULL) { //no element in root
    root=new;
    cur=root;
    prev=NULL;
  }else{ 
    new->next=cur;
    if (cur==root) //if cur pointed to first element 
      root=new;    //new is the first element
    else 
      prev->next=new;
    cur=new;
  }
} 

int length(node_addr *q) {
  node_addr *p=q;
  int i=0;
  while (p!=NULL) {
    i++;p=p->next;
  }
  return i;
}

void insertAtk(node_addr* q,address addr,int k) {
  node_addr* new;
  node_addr* p=q;
  int i=1;
  if (q==NULL) {
    printf("No element in linked list\n");
    return;
  }
  if (k<1||k>length(q)+1) printf("Invalid position of k\n"); 
  else {
    new=makeNewNode(addr);
    if (k==1) insertAtHead(addr);
    else {
      while (p!=NULL && i!=k-1) { // duyet den k-1
	i++;
	p=p->next;
      }
      new->next=p->next;
      p->next=new;
    }
    cur=new;
  }
}

void traversingList(){
  node_addr *p;
  for (p=root;p!=NULL;p=p->next) 
    displayNode(p);
}

int search(address addr) { //search only first one (name)
  node_addr* p=root;
  int i=1;
  while (p!=NULL && strcmp((p->addr).name,addr.name)!=0) { //duyet den khi ket thuc hoac tim thay
    p=p->next;
    i++;
  }
  if (p!=NULL) return i; //tra ve vi tri tim thay
  else return 0; // tra ve 0 neu ko tim thay
}

void searchAll(address addr) { //search all position (name)
  node_addr *p=root;
  int i=1,flag=0;
  while (p!=NULL) {
    if (strcmp((p->addr).name,addr.name)==0) { 
      printf("%d ",i);
      flag=1;
    }
    p=p->next;
    i++;
  }
  if (flag==0) printf("Not found");
  printf("\n");
}

void deleteFirstEl() {
  if (root==NULL) printf("root has no element\n");
  else root=root->next;
}

void deleteLastEl() {
  node_addr* p=root;
  while (p->next->next!=NULL) p=p->next;
  p->next=NULL;
  cur=p;
}

void deleteCurEl() {
  if (cur==root) deleteFirstEl();
  else {
    for (prev=root;prev!=NULL;prev=prev->next) {
      if (prev->next=cur) break;
    }
    prev->next=cur->next;
    free(cur);
    cur=prev->next;
  }
}

void deleteAtk(node_addr* q,int k) {
  node_addr* p=q;
  int i=1;
  if (q==NULL) {
    printf("No element in linked list\n");
    return ;
  }
  if (k<1||k>length(q)) printf("Invalid position of k\n");
  else {
    if (k==1) deleteFirstEl();
    else {
      while (p!=NULL && i!=k-1) {
	p=p->next;
	i++;
      }
      p->next=p->next->next;
    }
    cur=p->next;
  }
}

void deleteAddr(address addr) { //addr.name
  while (search(addr)) deleteAtk(root,search(addr));
}

int curAt () {
  node_addr *p=root;
  int i=1;
  while (p!=NULL) {
    if (p==cur) return i;
    p=p->next;
    i++;
  }
}

int isEmpty() {
  return (root==NULL);
}

void freeAllNode() { 
  node_addr* to_free=root;
  while (to_free!=NULL) {
    root=root->next;
    free(to_free);
    to_free=root;
  }
}

void reverse() {
  node_addr* prev=NULL;
  node_addr* cur= root;
  node_addr* next;
  while (cur!=NULL) {
    next=cur->next;
    cur->next=prev;
    prev=cur;
    cur=next;
  }
  root=prev;
}

void swapNode (node_addr* a,node_addr* b) {
  address tmp=a->addr;
  a->addr=b->addr;
  b->addr=tmp;
}

void softNode() {
  int flag;
  node_addr* p;
  node_addr* q=NULL;
  if (p==NULL) return;
  do {
    flag=0;
    p=root;
    while (p->next!=q) {
      //if (p->addr > p->next->addr) { // can change condition for each addr_el
      if (strcmp((p->addr).name,(p->next->addr).name)>0) {	
	swapNode(p,p->next);
	flag=1;
      }
      p=p->next;
    }
    q=p;
  } while(flag);
}

int main() { 
  /*for (prev=root;prev!=NULL;prev=prev->next) {
    if (prev->next=cur) break;
    }*/
  address addr;
  strcpy(addr.name,"Nguyen Van Ty");
  strcpy(addr.tel,"0123456789");
  strcpy(addr.email,"ty@mail.com");
  root = makeNewNode(addr);  //
  cur = root;
  printf("%s----%s----%s\n",(cur->addr).name,(cur->addr).tel,(cur->addr).email);
  displayNode(root);     //
  displayNode(cur);
  printf("Length: %d\n",length(root));
  address tmp=readNode(cur);   //
  printf("%s----%s----%s\n",tmp.name,tmp.tel,tmp.email);
  address addr1;
  strcpy(addr1.name,"Nguyen Van Thanh");
  strcpy(addr1.tel,"0987654321");
  strcpy(addr1.email,"thanh@mail.com");
  printf("\nInsert At Head\n");
  insertAtHead(addr1);  //
  displayNode(cur);
  displayNode(root);
  printf("\n");traversingList(root);printf("\n");
  address addr2;
  strcpy(addr2.name,"Nguyen Van Thang");
  strcpy(addr2.tel,"0464876341");
  strcpy(addr2.email,"thang@mail.com");
  printf("cur at %d\n",curAt());
  printf("\nInsert After Current\n");
  insertAfterCur(addr2); //
  displayNode(cur);
  displayNode(root);
  printf("\n");traversingList(root);printf("\n");
  printf("cur at %d\n",curAt());
  printf("\nInsert Before Current\n");
  insertBeforeCur(addr); //
  printf("\n");traversingList(root);printf("\n");
  printf("cur at %d\n",curAt());
  printf("\nInsert at k\n");
  insertAtk(root,addr1,3);     //
  printf("Length: %d\n",length(root));
  printf("\n");
  traversingList(root); 
  printf("\n");
  //traversingList(cur); //begin from root (declared) to null->no different from above
  //search only first one
  printf("cur at %d\n",curAt());
  address addr3;
  strcpy(addr3.name,"Bui Cong Thanh");
  strcpy(addr3.tel,"0184635488");
  strcpy(addr3.email,"thanh2412@mail.com");
  printf("Search for Nguyen Van Ty\n");
  if (search(addr)) printf("Position of addr: %d\n",search(addr));
  else printf("Not found\n");
  // search all position
  printf("Position of addr: ");
  searchAll(addr);
  //reverse
  printf("\nReverse linked list\n");
  reverse();
  printf("\n");traversingList(root);printf("\n");
  printf("cur at %d\n",curAt());
  // delete first element
  printf("Delete first element\n");
  deleteFirstEl();
  printf("\n");traversingList(root);printf("\n");
  printf("cur at %d\n",curAt());
  printf("Delete current element\n");
  deleteCurEl();
  printf("\n");traversingList(root);printf("\n");
  printf("cur at %d\n",curAt());
  printf("Delete At k\n");
  deleteAtk(root,0);
  printf("\n");traversingList(root);printf("\n");
  printf("cur at %d\n",curAt());
  printf("Delete address\n");
  deleteAddr(addr3);
  printf("\n");traversingList(root);printf("\n");
  printf("cur at %d\n",curAt());
  printf("Sorting by name\n");
  softNode();
  printf("\n");traversingList(root);printf("\n");
  printf("cur at %d\n",curAt());
  printf("Delete Last Element\n");
  deleteLastEl();
  printf("\n");traversingList(root);printf("\n");
  printf("cur at %d\n",curAt());
  printf("Free all node in root\n");
  freeAllNode();
  printf("\n");traversingList(root);printf("\n");
  printf("cur at %d\n",curAt());
}
