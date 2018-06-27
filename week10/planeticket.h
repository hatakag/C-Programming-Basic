#define Max 50

typedef struct {
  char name[40];
  char t;
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

int fullQueue(Queue q) {
  node *c=q.front;
  int i=0;
  while (c!=NULL) {
    c=c->next;
    ++i;
  }
  return i==Max;
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

void enQueue(Eltype x,Queue *q) {
  if (fullQueue(*q)) printf("Seat type in this flight is full!\n");
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
  else printf("Seat is empty!\n");
}

void delQueueAt(int d,Queue *q) {
  if (emptyQueue(*q)) printf("There is no seat booked\n");
  else {
    if (d<1||d>numQueue(*q)) printf("Invalid position\n");
    else {
      if (numQueue(*q)==1) {
	makeNullQueue(q);
      } else if (d==1) {
	q->front=q->front->next;
	q->front->prev=NULL;
      } else if (d==numQueue(*q)) {
	q->rear=q->rear->prev;
	q->rear->next=NULL;
      } else {
	node *p=q->front;
	int i=0;
	while (p!=NULL && i!=d-1) {
	  p=p->next;
	  i++;
	}
	p->next=p->next->next;
	if (p->next!=NULL) 
	  p->next->prev=p;
      } 
    }
  }
}

void modQueueAt(int d,int num,Queue *q,Queue *A,Queue *B,Queue *C,Queue *D,Queue *E,Queue *F) {
  if (emptyQueue(*q)) printf("There is no seat booked\n");
  else {
    if (d<1||d>numQueue(*q)) printf("Invalid position\n");
    else {
      node *c=q->front;
      int i=1;
      while (c!=NULL && i!=d) {
	c=c->next;
	i++;
      }
      printf("Name : %s\n",(c->el).name);
      printf("Your seat type: %c\n",(c->el).t);
      Eltype x;
      printf("Change name to: ");gets(x.name);__fpurge(stdin);
      int flag=0;
      do {
	printf("Seat type (W/C/N): ");scanf("%c",&x.t);__fpurge(stdin);
	if (x.t==(c->el).t) {
	  strcpy((c->el).name,x.name);
	  printf("Accept.Your seat is not change\n");
	  break;
	}
	switch (x.t) {
	case 'W'://C,F
	  {
	    if (!fullQueue(*C)) {
	      enQueue(x,C);flag=1;
	      printf("Accept.Your seat is C_%d in the flight number %d\n",numQueue(*C),num);
	    } else if (fullQueue(*C) && !fullQueue(*F)) {
	      enQueue(x,F);flag=1;
	      printf("Accept.Your seat is F_%d in the flight number %d\n",numQueue(*F),num);
	    } else printf("Refuse/Wait.This seat type in this plane is full!\n");
	    break;
	  }
	case 'C'://A,D
	  {
	    if (!fullQueue(*A)) {
	      enQueue(x,A);flag=1;
	      printf("Accept.Your seat is A_%d in the flight number %d\n",numQueue(*A),num);
	    } else if (fullQueue(*A) && !fullQueue(*D)) {
	      enQueue(x,D);flag=1;
	      printf("Accept.Your seat is D_%d in the flight number %d\n",numQueue(*D),num);
	    } else printf("Refuse/Wait.This seat type in this plane is full!\n");
	    break;
	  }
	case 'N'://B,E
	  {
	    if (!fullQueue(*B)) {
	      enQueue(x,B);flag=1;
	      printf("Accept.Your seat is B_%d in the flight number %d\n",numQueue(*B),num);
	    } else if (fullQueue(*B) && !fullQueue(*E)) {
	      enQueue(x,E);flag=1;
	      printf("Accept.Your seat is E_%d in the flight number %d\n",numQueue(*E),num);
	    } else printf("Refuse/Wait.This seat type in this plane is full!\n");
	    break;
	  }
	default : printf("Invalid seat type\n");
	  break;
	}
      } while (x.t!='W'&&x.t!='C'&&x.t!='N');
      if (flag==1) delQueueAt(d,q);
    }
  }
}

void printQueue(Queue q,char x) {
  if (!emptyQueue(q)) {
    node *c=q.front;
    int i=1;
    while (c!=NULL) {
      printf("%s\t%c_%d\n",(c->el).name,x,i);
      c=c->next;i++;
    }
  }
}
