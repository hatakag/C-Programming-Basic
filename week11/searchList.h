#include "LinkedList.h"

int movetofront(char *model,node** r) {
  node *p=r,*c;
  int i=0;
  while (p!=NULL && strcmp((p->element).model,model)!=0) {
    p=p->next;
    i++;
  }
  if (p!=NULL) {
    elementtype tmp=p->element;
    deleteAtk(i,r,*c);
    insertAtHead(tmp,r,*c);
    return i;
  }
  else return -1;
}

int transpose(char *model,node** r) {
  node *p=r,*c;
  int i=0;
  while (p!=NULL && strcmp(((p->next)->element).model,model)!=0) {
    p=p->next;
    i++;
  }
  if (p!=NULL) {
    swapNode(p,p->next);
    return i+1;
  }
  else return -1;
}
