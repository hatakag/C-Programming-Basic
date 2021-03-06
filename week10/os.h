
typedef struct {
  int id;
  float m;
}Eltype;

typedef struct node node;
struct node {
  Eltype el;
  node *next;
  node *prev;
};
typedef struct {
  node *front,*rear;
}Queue;

void makeNullQueue(Queue *q) {
  q->front=NULL;
  q->rear=NULL;
}

int emptyQueue(Queue q) {
  return (q.front==NULL && q.rear==NULL);
}

int fullQueue(Queue q,int Max) {
  node *c=q.front;
  int i=0;
  while (c!=NULL) {
    c=c->next;
    ++i;
  }
  return i==Max;
}

float summem(Queue q) {
  node *c;
  float sum=0;
  for (c=q.front;c!=NULL;c=c->next) {
    sum=sum+(c->el).m;
  }
  return sum;
}

void enQueue(Eltype x,Queue *q,int Max) {
  if (fullQueue(*q,Max)) printf("Queue is full!\n");
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

Eltype topQueue(Queue q) {
  if (!emptyQueue(q)) 
    return (q.front->el);
}

void printQueue(Queue q) {
  node *c=q.front;
  while (c!=NULL) {
    printf("ID: %d - Memory: %.2fMB\n",(c->el).id,(c->el).m);
    c=c->next;
  }
}
