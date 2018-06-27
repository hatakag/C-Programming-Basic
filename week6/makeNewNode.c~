#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct address_t {
  char name[40];
  char tel[12];
  char email[30];
}address;
typedef struct AddressList {
  struct AddressList *next;
  address addr;
}node_addr;

node_addr* makeNewNode(address addr) {
  node_addr* new=(node_addr*)malloc(sizeof(node_addr));
  new->addr=addr;
  new->next=NULL;
  return new;
}
int main() {
  node_addr *root;
  node_addr *cur;
  address addr;
  strcpy(addr.name,"Nguyen Van Ty");
  strcpy(addr.tel,"0123456789");
  strcpy(addr.email,"thanh@mail.com");
  root = makeNewNode(addr);
  cur = root;
  printf("%s----%s----%s\n",(cur->addr).name,(cur->addr).tel,(cur->addr).email);
}
//new->next=cur->next;
//cur->next=new;
//cur=cur->next;
