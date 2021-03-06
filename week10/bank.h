#define Max 1000

typedef int Eltype;
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

int numQueue(Queue q) {
  node *c=q.front;
  int i=0;
  while (c!=NULL) {
    c=c->next;
    ++i;
  }
  return i;
}

int time1Queue(Queue q) {
  if (!emptyQueue(q)) 
    return (q.front)->el+15;
}

int timeQueue(Queue q) {
  if (!emptyQueue(q)) 
    return (q.front)->el+15*(numQueue(q)-1);
  return 0;
}

int waittime(Queue q) { // wait time of last person
  if (!emptyQueue(q)) {
    if (numQueue(q)==1) return 0;
    else return 15-((q.rear)->el-(q.front)->el)+15*(numQueue(q)-2);
  }
  return 0;
}

int sumwaittime(Queue q) { //all wait time of everybody
  if (!emptyQueue(q)) {
    int sum=0,i;
    if (numQueue(q)==1) return 0;
    else {
      for (i=2;i<=numQueue(q);i++){
	sum = sum + 15-((q.rear)->el-(q.front)->el) + 15*(i-2);
      }
      return sum;
    }
  }
  return 0;
}

void printQueue(Queue q) {
  node *c=q.front;
  while (c!=NULL) {
    printf("%d ",c->el);
    c=c->next;
  }
  printf("\n");
}

int waittimeat(Queue q,int i) { // wait time of last person
  if (!emptyQueue(q)) {
    if (i==1) return 0;
    else return 15-((q.rear)->el-(q.front)->el)+15*(i-2);
  }
  return 0;
}

void addwaittime(Queue *q) {
  if (!emptyQueue(*q)) {
    int i=0;
    int j[numQueue(*q)];
    node *c=q->front;
    while (c!=NULL) {
      j[i]=waittimeat(*q,i+1);
      i++;
      c=c->next;
    }
    c=q->front;
    int k=0;
    while (c!=NULL) {
      c->el=c->el+j[k];
      k++;
      c=c->next;
    }
  }
}
