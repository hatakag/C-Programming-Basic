#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main() {
  treetype t;
  makeNullTree(&t);
  t=createNode(1);
  if (emptyTree(t)) printf("tree is empty\n");
  else printf("tree is not empty\n");
  printf("number of node in tree: %d\n",nbNode(t));
  if (isLeaf(t)) printf("this node is leaf\n");
  else printf("this node is not leaf\n");
  printf("addleft %d\n",addLeft(&t,2)->element);
  printf("addright %d\n",addRight(&t,3)->element);
  printf("number of node in tree: %d\n",nbNode(t));
  if (isLeaf(t)) printf("this node is leaf\n");
  else printf("this node is not leaf\n");
  printf("leftChild %d\n",leftChild(t)->element);
  printf("rightChild %d\n",rightChild(t)->element);
  makeNullTree(&t);
  if (emptyTree(t)) printf("tree is empty\n");
  else printf("tree is not empty\n");
  return 0;
}
