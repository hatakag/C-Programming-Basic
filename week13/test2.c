#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "binarySearchtree.h"
int main() {
  treetype t;
  makeNullTree(&t);
  insertNode(50,&t);
  int i;
  srand(time(NULL));
  for (i=0;i<10;i++) {
    keyType x=0+rand()%100;
    printf("%d ",x);
    insertNode(x,&t); // tu 0-> 99 (99-0+1=100)
  }
  printf("\n");
  /*
  if (search(1,t)) printf("Found\n");
  else printf("Not Found\n");
  printf("\n\n");
  
  inorderPrint(t);printf("\n");
  postorderPrint(t);printf("\n");
  preorderPrint(t);printf("\n");
  printf("\n");
  printf("Min: %d\n",findMin(t)->key);
  printf("Max: %d\n",findMax(t)->key);
  */
  printf("______________________________________\n");
  print2D(t,0);
  /*
  insertNode(100,&t);
  printf("______________________________________\n");
  print2D(t,0);

  deleteNode(50,&t);
  printf("______________________________________\n");
  print2D(t,0);
  */
  inorderPrint(t);printf("\n");
  postorderPrint(t);printf("\n");
  preorderPrint(t);printf("\n");
  iter_inorder(t);printf("\n");
  breath_first(t);printf("\n");
  print2D(t,0);
  freetree(t);
  return 0;
}
