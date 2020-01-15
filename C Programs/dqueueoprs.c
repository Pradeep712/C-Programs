/*
 C Program for Various Operations on a Dequeue (Double Ended Queue) Represented Using a Circular Array
 What is Dequeue?
The word dequeue is short form of double ended queue. In a dequeue , insertion as well as deletion can be carried out either at the rear end or the front end.

Operations on a Dequeue
1. initialize(): Make the queue empty
2. empty(): Determine if queue is empty
3. full(): Determine if queue is full
4. enqueueF(): Insert an element at the front end of the queue
5. enqueueR(): Insert an element at the rear end of the queue
6. dequeueR(): Delete the rear element
7. dequeueF(): Delete the front element
8. print(): Print elements of the queue

*/
 #include<stdio.h>

#define MAX 30

typedef struct dequeue
{
    int data[MAX];
    int rear,front;
}dequeue;

void initialize(dequeue *p);
int empty(dequeue *p);
int full(dequeue *p);
void enqueueR(dequeue *p,int x);
void enqueueF(dequeue *p,int x);
int dequeueF(dequeue *p);
int dequeueR(dequeue *p);
void print(dequeue *p);

void main()
{
    int i,x,op,n;
    dequeue q;
    initialize(&q);

    do
    {
        printf("\n1.Create\n2.Insert(rear)\n3.Insert(front)\n4.Delete(rear)\n5.Delete(front)");
        printf("\n6.Print\n7.Exit\n\nEnter your choice:");
        scanf("%d",&op);

        switch(op)
        {
            case 1: printf("\nEnter number of elements:");
                    scanf("%d",&n);
                    initialize(&q);
                    printf("\nEnter the data:");

                    for(i=0;i<n;i++)
                    {
                        scanf("%d",&x);
                        if(full(&q))
                        {
                            printf("\nQueue is full!!");
                            exit(0);
                        }
                        enqueueR(&q,x);
                    }
                    break;

            case 2: printf("\nEnter element to be inserted:");
                    scanf("%d",&x);

                    if(full(&q))
                    {
                        printf("\nQueue is full!!");
                        exit(0);
                    }
                    enqueueR(&q,x);
                    break;

                case 3: printf("\nEnter the element to be inserted:");
                        scanf("%d",&x);

                        if(full(&q))
                        {
                            printf("\nQueue is full!!");
                            exit(0);
                        }
                        enqueueF(&q,x);
                        break;

                case 4: if(empty(&q))
                        {
                            printf("\nQueue is empty!!");
                            exit(0);
                        }
                        x=dequeueR(&q);
                        printf("\nElement deleted is %d\n",x);
                        break;

                case 5: if(empty(&q))
                        {
                            printf("\nQueue is empty!!");
                            exit(0);
                        }
                        x=dequeueF(&q);
                        printf("\nElement deleted is %d\n",x);
                        break;

                case 6: print(&q);
                        break;

                default: break;
        }
    }while(op!=7);
}

void initialize(dequeue *P)
{
    P->rear=-1;
    P->front=-1;
}

int empty(dequeue *P)
{
    if(P->rear==-1)
        return(1);
    return(0);
}

int full(dequeue *P)
{
    if((P->rear+1)%MAX==P->front)
        return(1);
    return(0);
}

void enqueueR(dequeue *P,int x)
{
    if(empty(P))
    {
        P->rear=0;
        P->front=0;
        P->data[0]=x;
    }
    else
    {
            P->rear=(P->rear+1)%MAX;
            P->data[P->rear]=x;
    }
}

void enqueueF(dequeue *P,int x)
{
    if(empty(P))
    {
        P->rear=0;
        P->front=0;
        P->data[0]=x;
    }
    else
    {
        P->front=(P->front-1+MAX)%MAX;
        P->data[P->front]=x;
    }
}

int dequeueF(dequeue *P)
{
    int x;
    x=P->data[P->front];
    if(P->rear==P->front)   //delete the last element
        initialize(P);
    else
        P->front=(P->front+1)%MAX;
    return(x);
}

int dequeueR(dequeue *P)
{
    int x;
    x=P->data[P->rear];
    if(P->rear==P->front)
        initialize(P);
    else
        P->rear=(P->rear-1+MAX)%MAX;
    return(x);
}

void print(dequeue *P)
{
    if(empty(P))
    {
        printf("\nQueue is empty!!");
        exit(0);
    }

    int i;
    i=P->front;
    while(i!=P->rear)
    {
        printf("\n%d",P->data[i]);
        i=(i+1)%MAX;
    }
    printf("\n%d\n",P->data[P->rear]);
}

