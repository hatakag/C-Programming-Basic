#define Max 50

typedef int Eltype;
typedef struct {
  Eltype el[Max];
  int front,rear;
}Queue;

void makeNullQueue(Queue *q) {
  q->front=-1;
  q->rear=-1;
}

int emptyQueue(Queue q) {
  return q.front==-1;
}

int fullQueue(Queue q) {
  return (q.rear-q.front+1)%Max==0;
}

void enQueue(Eltype x,Queue *q) {
  if (!fullQueue(*q)) {
    if (emptyQueue(*q)) q->front=0;
    q->rear=(q->rear+1)%Max;
    q->el[q->rear]=x;
  } else printf("Queue is full!\n");
}

Eltype deQueue(Queue *q) {
  if (!emptyQueue(*q)) {
    Eltype x=(q->el)[q->front];
    if (q->front==q->rear) makeNullQueue(q);
    else {
      q->front=(q->front+1)%Max;
    }
    return x;
  }
  else printf("Queue is empty");
} 
/*
void printQueue(Queue q) {
  int i;
  for (i=q.front;i<=q.rear;i++) {
    printf("%d",q.el[i]);
  }
  printf("\n");
}
*/
