#define n 20
typedef struct {
  int coef;
  int exp;
} elementtype;

typedef struct node node;
struct node{
  elementtype element;
  node *next;
};

node* makeNewNode(elementtype element) { 
  node* new=(node*)malloc(sizeof(node));
  new->element=element;
  new->next=NULL;
  return new;  
}

void insertAtHead(elementtype element,node** r,node** c) {
  node* new=makeNewNode(element);
  new->next=*r;
  *r=new; 
  *c=*r;
}

void displayNode(node* p) {
  if (p==NULL) {
    printf("Error pointer NULL\n");
    return ;
  }
  elementtype tmp=p->element;
  if (tmp.coef>=0  && tmp.exp!=0)
    printf("+%d^%d",tmp.coef,tmp.exp);
  else if (tmp.coef>=0 &&tmp.exp==0) 
    printf("+%d",tmp.coef);
  else if (tmp.coef<0  && tmp.exp!=0)
    printf("%d^%d",tmp.coef,tmp.exp);
  else if (tmp.coef<0 &&tmp.exp==0) 
    printf("%d",tmp.coef);
}

void displayNodeP(node* p) {
  if (p==NULL) {
    printf("Error pointer NULL\n");
    return ;
  }
  elementtype tmp=p->element;
  if (tmp.coef>=0 && tmp.exp!=0)
    printf("+%d^%d(%p)",tmp.coef,tmp.exp,p->next);
  else if (tmp.coef>=0 && tmp.exp==0) 
    printf("+%d(%p)",tmp.coef,p->next);
  else if (tmp.coef<0 && tmp.exp!=0)
    printf("%d^%d(%p)",tmp.coef,tmp.exp,p->next);
  else if (tmp.coef<0 && tmp.exp==0) 
    printf("%d(%p)",tmp.coef,p->next);
}

void traversingList(node *q){ //printData
  node *p;
  for (p=q;p!=NULL;p=p->next) 
    displayNode(p);
}

void traversingListP(node *q){ //printData
  node *p;
  for (p=q;p!=NULL;p=p->next) 
    displayNodeP(p);
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

void importFromText(FILE *fp,node **r1,node**c1,node **r2,node **c2){
  elementtype *nodearr1;
  int i=0;
  nodearr1=(elementtype*)malloc(n*sizeof(elementtype));
  if (nodearr1==NULL) {
    printf("Memory allocation failed\n");
    return ;
  }	  
  printf("P=");
  while (1){
    fscanf(fp,"%d",&nodearr1[i].coef);__fpurge(stdin);
    fscanf(fp,"%*c");
    if (nodearr1[i].coef==-1) break;
    fscanf(fp,"%d",&nodearr1[i].exp);__fpurge(stdin);
    fscanf(fp,"%*c");
    insertAtTail(nodearr1[i],r1,c1);
    if (nodearr1[i].coef>=0 && i!=0 && nodearr1[i].exp!=0)
      printf("+%d^%d",nodearr1[i].coef,nodearr1[i].exp);
    else if (nodearr1[i].coef>=0 && i!=0 &&nodearr1[i].exp==0) 
      printf("+%d",nodearr1[i].coef);
    else if (nodearr1[i].coef<0 && nodearr1[i].exp!=0)
      printf("%d^%d",nodearr1[i].coef,nodearr1[i].exp);
    else if (nodearr1[i].coef<0 && nodearr1[i].exp==0) 
      printf("%d",nodearr1[i].coef);
    else printf("%d^%d",nodearr1[i].coef,nodearr1[i].exp);
    i++;
  }
  elementtype *nodearr2;
  i=0;
  nodearr2=(elementtype*)malloc(n*sizeof(elementtype));
  if (nodearr2==NULL) {
    printf("Memory allocation failed\n");
    return ;
  }
  printf("\n");
  printf("Q=");
  while (1){
    fscanf(fp,"%d",&nodearr2[i].coef);__fpurge(stdin);
    fscanf(fp,"%*c");
    if (nodearr2[i].coef==-1) break;
    fscanf(fp,"%d",&nodearr2[i].exp);__fpurge(stdin);
    fscanf(fp,"%*c");
    insertAtTail(nodearr2[i],r2,c2);
    if (nodearr2[i].coef>=0 && i!=0 && nodearr2[i].exp!=0)
      printf("+%d^%d",nodearr2[i].coef,nodearr2[i].exp);
    else if (nodearr2[i].coef>=0 && i!=0 &&nodearr2[i].exp==0) 
      printf("+%d",nodearr2[i].coef);
    else if (nodearr2[i].coef<0 && nodearr2[i].exp!=0)
      printf("%d^%d",nodearr2[i].coef,nodearr2[i].exp);
    else if (nodearr2[i].coef<0 && nodearr2[i].exp==0) 
      printf("%d",nodearr2[i].coef);
    else printf("%d^%d",nodearr2[i].coef,nodearr2[i].exp);
    i++;
  }
  
}
/*
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
      if ((p->element).exp<(p->next->element).exp) {	
	swapNode(p,p->next);
	flag=1;
      } else if ((p->element).exp==(p->next->element).exp) {
	(p->element).coef+=(p->next->element).coef;
	p->next=p->next->next;
      }
      p=p->next;
    }
    q=p;
  } while(flag);
}
