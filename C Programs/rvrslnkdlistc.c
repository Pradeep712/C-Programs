//reversing linked list - c program
#include<stdio.h>
#include<conio.h>
struct list
{
int data;
struct list *link;
}*start;
void createlist(int);
void disp();
void main()
{
struct list *p1,*p2,*p3;
int i,n,m;
clrscr();
printf(“\nHow many nodes u Want to Created”);
scanf(“%d”,&n);
for(i=0;i<n;i++)
{
printf(“\n\nEnter the Data”);
scanf(“%d”,&m);
createlist(m);
}
printf(“\n\nCreated List Is\n\n”);
disp();
printf(“\n\nReverses List is\n\n”);
p1=start;
p2=p1->link;
p3=p2->link;
p1->link=NULL;
p2->link=p1;
while(p3!=NULL)
{
p1=p2;
p2=p3;
p3=p3->link;
p2->link=p1;
}
start=p2;
disp();
getch();
}
void createlist(int m)
{
struct list *tmp,*q;
tmp=(struct list *) malloc(sizeof(struct list));
tmp->data=m;
tmp->link=NULL;
if(start==NULL)
start=tmp;
else
{
q=start;
while(q->link!=NULL)
{
q=q->link;
}
q->link=tmp;
}
}
void disp()
{
struct list *q;
q=start;
while(q!=NULL)
{
printf(“%d->”,q->data);
q=q->link;
}
printf(“NULL”);
}