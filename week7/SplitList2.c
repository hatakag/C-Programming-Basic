
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

void traversingList(node *q){ //printData
  node *p;
  for (p=q;p!=NULL;p=p->next) 
    displayNode(p);
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
    //printf("%s----%s----%s\n",nodearr[i].name,nodearr[i].tel,nodearr[i].email);
    insertAfterCur(nodearr[i],r,c);
  }
  free(nodearr);
}

void exportToText(FILE *fp,node* r) {
  node *p=NULL;
  for (p=r;p!=NULL;p=p->next) {
    fprintf(fp,"%s----%s----%s\n",(p->element).name,(p->element).tel,(p->element).email);
  }  
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

node* copyList(node* r) {
  if (r==NULL) return NULL;
  node* new=(node*)malloc(sizeof(node));
  new->element=r->element;
  new->next=copyList(r->next);
  return new;
}

void splitList(int a,int b,node* r,node** r1,node** r2) {
  if (a<0 || a>length(r)-1) {
    printf("Invalid start position\n");
    return ;
  }
  if (b<=0 || b+a>length(r)) {
    printf("Invalid number of element of sublist 1\n");
    return ;
  }
  *r1=copyList(r);*r2=copyList(r);
  node *c1=*r1,*c2=*r2;
  //*r1=r;*r2=r;
  int i=a,j=b,k=b+a;
  //list2
  while (j!=0) {
    deleteAtk(a,r2,&c2);
    j--;
  }
  //list1
  while (i!=0) {
    deleteFirstEl(r1,&c1);
    i--;
  } 
  while (k!=length(r)) {
    deleteLastEl(r1,&c1);
    k++;
  }
}

void freeAllNode(node** r) { 
  node* to_free=*r;
  while (to_free!=NULL) {
    (*r)=(*r)->next;
    free(to_free);
    to_free=(*r);
  }
}

int main(int argc,char* argv[]) {
  if (argc!=4) {
    printf("Wrong number of input\n");
    return 0;
  }
  enum{SUCCESS,FAIL};
  int reval=SUCCESS;
  node* root=NULL,* cur=NULL;
  FILE *fp1,*fp2,*fp3;
  if ((fp1=fopen(argv[1],"rb"))==NULL) {
    printf("Cannot open %s file\n",argv[1]);
    reval=FAIL;
  } else if ((fp2=fopen(argv[2],"w"))==NULL) {
    printf("Cannot open %s file\n",argv[2]);
    reval=FAIL;
  } else if ((fp3=fopen(argv[3],"w"))==NULL) {
    printf("Cannot open %s file\n",argv[3]);
    reval=FAIL;
  } else {
    importFromDat(fp1,&root,&cur);
    //traversingList(root);
    node* root1=NULL,* root2=NULL;
    //traversingList(root);printf("\n");
    splitList(17,3,root,&root1,&root2);
    traversingList(root);printf("\n");
    traversingList(root1);printf("\n");
    traversingList(root2);printf("\n");
    exportToText(fp2,root1);
    exportToText(fp3,root2);
    freeAllNode(&root);freeAllNode(&root1);freeAllNode(&root2);
  }
  fclose(fp1);fclose(fp2);fclose(fp3);
  return reval;
}
