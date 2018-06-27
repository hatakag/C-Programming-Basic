#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct address {
  char name[40];
  char tel[12];
  char email[30];
}phone;
typedef struct AddressList {
  struct AddressList *next;
  phone addr;
}node_addr;

node_addr* makeNewNode() {
  node_addr* new=(node_addr*)malloc(sizeof(node_addr));
  strcpy((new->addr).name,"Tran Van Thanh");
  strcpy((new->addr).tel,"0123456789");
  strcpy((new->addr).email,"thanh@gmail.com");
  new->next=NULL;
  return new;
}
void InsertAtHead(node_addr *root,node_addr *cur) {
  node_addr *new;
  new = makeNewNode();
  if (root==NULL) {
    root=new;
    cur=root;
  }
  else {
    cur->next=new;
    cur=cur->next;
  }
}
void DisplayNode (node_addr *cur) {
  while (cur!=NULL) {
    printf("%s----%s----%s----%p\n",(cur->addr).name,(cur->addr).tel,(cur->addr).email,cur->next);
  }
}
void TravelingNode(node_addr *root) {
  node_addr *cur;
  for (cur=root;cur!=NULL;cur=cur->next) {
    DisplayNode(cur);
  }
}
enum{SUCCESS,FAIL};
int main(int argc,char* argv[]) {
  if (argc!=2) {
    printf("Wrong number of input\n");
    return FAIL;
  }
  FILE *fp;
  int reval=SUCCESS;
  int irc;
  node_addr *root;
  node_addr *cur;
  if ((fp=fopen(argv[1],"rb"))==NULL) {
    printf("Cannot open %s file\n",argv[1]);
    return FAIL;
  }
  int n=20;
  root=(node_addr*)malloc(n*sizeof(node_addr));
  irc = fread((root->addr),sizeof(phone),n,fp);
  
}
/*viet thu vien su dung link list */
