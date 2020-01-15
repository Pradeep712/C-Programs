#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node
{
int data;
struct node *link;
} NODE;
 
void push(int);
int pop();
void display();
struct node *top= NULL; // to point the top element of stack
 
void main()
{
int opn,elem;
printf("LINKED lIST IMPLEMENTATION OF STACK OPERATIONS");
printf("\n1.push\n2.pope\n3.Display\n4.exit\n");
do
{
printf("\nenter your option"); // option for pushing,popping,displaying or exit
scanf("%d",&opn);
switch(opn)
{
case 1:
printf("\nenter the element to be pushed");
scanf("%d",&elem);
push(elem);
break;
 
case 2:
elem=pop();
if(elem!=-1)	// if -1 then stack empty
printf("poped node node from front is %d",elem);
break;
 
case 3:
printf("\nelements in stack for ll implementation are ");
display();
break;
case 4: exit();
}
}while(opn!=4);
}
 
void push(int info)
{
struct node *temp;
temp=(struct node *)malloc(sizeof(struct node)); // assinging memory to the node
if(temp==NULL)
printf("out of memory");
else
{
temp->data=info;
temp->link=top;
top=temp;
printf("\nNode pushed at end");
}
}
 
int pop()
{
int info;
struct node *t;
if(top==NULL)
{
printf("underflow");
return -1;
}
 
else
{
t=top;
info=top->data; // to store the data in the node to be poped
top=top->link;
t->link=NULL;
free(t);
return(info);
}
}
 
void display()
{
struct node *t;
if(top==NULL)
printf("stack empty");
else
{
t=top;
printf(" TOP->");
while(t)
{
printf("%d : ",t->data);
t=t->link;
}
}
}