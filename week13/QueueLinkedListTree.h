#define MaxQT 50

typedef treetype EltypeQT;
typedef struct nodeQT nodeQT;
struct nodeQT {
  EltypeQT elQT;
  nodeQT *nextQT;
  nodeQT *prevQT;
};
typedef struct {
  nodeQT *frontT,*rearT;
}QueueT;

void makeNullQueueT(QueueT *q) {
  q->frontT=NULL;
  q->rearT=NULL;
}

int emptyQueueT(QueueT q) {
  return (q.frontT==NULL && q.rearT==NULL);
}

int fullQueueT(QueueT q) {
  nodeQT *c=q.frontT;
  int i=0;
  while (c!=NULL) {
    c=c->nextQT;
    ++i;
  }
  return i==MaxQT;
}

void enQueueT(EltypeQT x,QueueT *q) {
  if (fullQueueT(*q)) printf("Queue is full!\n");
  else {
    nodeQT *new=(nodeQT*)malloc(sizeof(nodeQT));
    new->elQT=x;
    if (emptyQueueT(*q)) {
      new->nextQT=NULL;new->prevQT=NULL;
      q->frontT=new;q->rearT=new;
    } else {
      q->rearT->nextQT=new;
      new->prevQT=q->rearT;
      new->nextQT=NULL;
      q->rearT=new;
    }
  }
}

EltypeQT deQueueT(QueueT *q) {
  if (!emptyQueueT(*q)) {
    nodeQT* t;
    EltypeQT x;
    t=q->frontT;x=t->elQT;
    if (q->frontT==q->rearT) {
      q->frontT=NULL;q->rearT=NULL;
    } else {
      q->frontT=q->frontT->nextQT;
      q->frontT->prevQT=NULL;
    }
    free(t);
    return x;
  }
  else printf("Queue is empty!\n");
}

void printQueueT(QueueT q) {
  nodeQT *c=q.frontT;
  while (c!=NULL) {
    printf("%d",c->elQT->key);
    c=c->nextQT;
  }
}

