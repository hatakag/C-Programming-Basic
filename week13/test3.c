#include <stdio.h>
#include <stdlib.h>
#include "QueueLinkedList.h"

int main() {
  Queue q;
  printf("Initialize Queue\n");
  makeNullQueue(&q);
  if (emptyQueue(q)) printf("Queue is empty\n");
  else printf("Queue is not empty\n");
  printf("Enqueue: ");
  int i;
  for (i=0;i<10;i++){
    printf("%d",i);
    enQueue(i,&q);
  }
  printf("\n");
  printf("Print Queue: ");
  printQueue(q);
  printf("\n");
  if (fullQueue(q)) printf("Queue is full\n");
  else  printf("Queue is not full\n");
  if (emptyQueue(q)) printf("Queue is empty\n");
  else printf("Queue is not empty\n");
  printf("Dequeue: ");
  while (!emptyQueue(q)) 
    printf("%d",deQueue(&q));
  printf("\n");
  if (emptyQueue(q)) printf("Queue is empty\n");
  else printf("Queue is not empty\n");
  return 0;
}
