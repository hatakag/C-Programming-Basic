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

node *root,*cur,*prev;

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

elementtype readNode(node* p) {
  if (p==NULL) {
    printf("Error pointer NULL\n");
    return ;
  }
  return p->element;
}

void insertAtHead(elementtype element) {
  node* new=makeNewNode(element);
  new->next=root;
  root=new;
  cur=root;
}

void insertAtTail(elementtype element,node* root) {
  node *new=makeNewNode(element);
  node *p=root;
  if (p==NULL) insertAtHead(element);
  else {
    while (p->next!=NULL) {
      p=p->next;
    }
    p->next=new;
    new->next=NULL;
  }
}

void insertAfterCur(elementtype element) {
  node* new=makeNewNode(element);
  if (root==NULL) {
    root=new;
    cur=root;
  } else {
    new->next=cur->next;
    cur->next=new;
    cur=cur->next;
  }
}

void insertBeforeCur(elementtype element) {
  node* new=makeNewNode(element);
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

int length(node *q) {
  node *p=q;
  int i=0;
  while (p!=NULL) {
    i++;p=p->next;
  }
  return i;
}

void insertAtk(node* q,elementtype element,int k) {
  node* new;
  node* p=q;
  int i=1;
  if (q==NULL) {
    printf("No element in linked list\n");
    return;
  }
  if (k<1||k>length(q)+1) printf("Invalid position of k\n"); 
  else {
    new=makeNewNode(element);
    if (k==1) insertAtHead(element);
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

void traversingList(node *q){ //printData
  node *p;
  for (p=q;p!=NULL;p=p->next) 
    displayNode(p);
}

int search(elementtype element) { //search only first one (name)
  node* p=root;
  int i=1;
  while (p!=NULL && strcmp((p->element).name,element.name)!=0) { //duyet den khi ket thuc hoac tim thay
    p=p->next;
    i++;
  }
  if (p!=NULL) return i; //tra ve vi tri tim thay
  else return 0; // tra ve 0 neu ko tim thay
}

void searchAll(elementtype element) { //search all position (name)
  node *p=root;
  int i=1,flag=0;
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

void deleteFirstEl() {
  if (root==NULL) printf("root has no element\n");
  else root=root->next;
}

void deleteLastEl() {
  node* p=root;
  while (p->next->next!=NULL) p=p->next;
  p->next=NULL;
  cur=p;
}

void deleteCurEl() {
  if (cur==NULL) return;
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

void deleteAtk(node* q,int k) {
  node* p=q;
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

void deleteAddr(elementtype element) { //element.name
  while (search(element)) deleteAtk(root,search(element));
}

int curAt () {
  node *p=root;
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
  node* to_free=root;
  while (to_free!=NULL) {
    root=root->next;
    free(to_free);
    to_free=root;
  }
}

void reverse() { //reverse void
  node* prev=NULL;
  node* cur= root;
  node* next;
  while (cur!=NULL) {
    next=cur->next;
    cur->next=prev;
    prev=cur;
    cur=next;
  }
  root=prev;
}

node* reverseList(node* root) { //reverse node return node
  node* cur,* prev;
  cur=prev=NULL;
  while (root!=NULL) {
    cur =root;
    root=root->next;
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

void softNode() {
  int flag;
  node* p;
  node* q=NULL;
  if (p==NULL) return;
  do {
    flag=0;
    p=root;
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

void importFromDat(FILE *fp,node *root) {
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
    printf("%s----%s----%s\n",nodearr[i].name,nodearr[i].tel,nodearr[i].email);
    insertAtTail(nodearr[i],root);
  }
  free(nodearr);
}

int main(int argc,char * argv[]) {
  if (argc!=2) {
    printf("Wrong number of input\n");
    return 0;
  }
  /*for (prev=root;prev!=NULL;prev=prev->next) {
    if (prev->next=cur) break;
    }*/
  elementtype addr;
  strcpy(addr.name,"Nguyen Van Ty");
  strcpy(addr.tel,"0123456789");
  strcpy(addr.email,"ty@mail.com");
  root = makeNewNode(addr);  //
  cur = root;
  printf("%s----%s----%s\n",(cur->element).name,(cur->element).tel,(cur->element).email);
  displayNode(root);     //
  displayNode(cur);
  printf("Length: %d\n",length(root));
  elementtype tmp=readNode(cur);   //
  printf("%s----%s----%s\n",tmp.name,tmp.tel,tmp.email);
  elementtype addr1;
  strcpy(addr1.name,"Nguyen Van Thanh");
  strcpy(addr1.tel,"0987654321");
  strcpy(addr1.email,"thanh@mail.com");
  printf("\nInsert At Head\n");
  insertAtHead(addr1);  //
  displayNode(cur);
  displayNode(root);
  printf("\n");traversingList(root);printf("\n");
  elementtype addr2;
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
  elementtype addr3;
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
  //reverse by node return node
  printf("\nReverse linked list again\n");
  root=reverseList(root);
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
  printf("Is empty root\n");
  if (!isEmpty) printf("root is empty\n");
  else printf("root is not empty\n");
  printf("\n");traversingList(root);printf("\n");
  printf("cur at %d\n",curAt());
  printf("\n________________________________________\n");
  printf("\nRead Data from DAT file to root\n");
  FILE *fp;
  if ((fp=fopen(argv[1],"r+b"))==NULL) {
    printf("Cannot open %s file\n",argv[1]);
    return 0;
  }
  //importFromDat(fp,root);
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
    printf("%s----%s----%s\n",nodearr[i].name,nodearr[i].tel,nodearr[i].email);
    insertAtTail(nodearr[i],root);
  }
  free(nodearr);
  //
  printf("Is empty root\n");
  if (!isEmpty) printf("root is empty\n");
  else printf("root is not empty\n");
  printf("\n");traversingList(root);printf("\n");
  printf("cur at %d\n",curAt());
  fclose(fp);
}
