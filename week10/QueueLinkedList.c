#include <stdio.h>
#include <stdlib.h>
#define Max 50

typedef int Eltype;
typedef struct node node;
typedef struct node {
  Eltype el;
  node *next;
  node *prev;
};
typedef struct {
  node *front,*rear;
}Queue;

void makeNullQueue(Queue *q) {
  /*node * header;
  header=(node*)malloc(sizeof(node));
  header->next=NULL;
  header->prev=NULL;*/
  q->front=NULL;
  q->rear=NULL;
}

int emptyQueue(Queue q) {
  return (q.front==NULL && q.rear==NULL);
}

int fullQueue(Queue q) {
  node *c=q.front;
  int i=0;
  while (c!=NULL) {
    c=c->next;
    ++i;
  }
  return i==Max;
}

void enQueue(Eltype x,Queue *q) {
  if (fullQueue(*q)) printf("Queue is full!\n");
  else {
    node *new=(node*)malloc(sizeof(node));
    new->el=x;
    if (emptyQueue(*q)) {
      new->next=NULL;new->prev=NULL;
      q->front=new;q->rear=new;
    } else {
      q->rear->next=new;
      new->prev=q->rear;
      new->next=NULL;
      q->rear=new;
    }
  }
}

Eltype deQueue(Queue *q) {
  if (!emptyQueue(*q)) {
    node* t;
    Eltype x;
    t=q->front;x=t->el;
    if (q->front==q->rear) {
      q->front=NULL;q->rear=NULL;
    } else {
      q->front=q->front->next;
      q->front->prev=NULL;
    }
    free(t);
    return x;
  }
  else printf("Queue is empty!\n");
}

void printQueue(Queue q) {
  node *c=q.front;
  while (c!=NULL) {
    printf("%d",c->el);
    c=c->next;
  }
}

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
  printf("Dequeue: ");
  while (!emptyQueue(q)) 
    printf("%d",deQueue(&q));
  printf("\n");
  return 0;
}
