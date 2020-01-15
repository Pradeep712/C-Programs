 #include<iostream.h>
#include<conio.h>

struct Node
{
int data;
Node *next;
}*top,*p;

Node* newnode(int x)
{
p=new Node;
p->data=x;
p->next=NULL;
return(p);
}

void push(Node *q)
{
if(top==NULL)
top=q;
else
{
q->next=top;
top=q;
}
}

void showstack(Node *q)
{
while(q!=NULL)
{
cout<<q->data<<" ";
q=q->next;
}
}

void main()
{
clrscr();
int x;
char ch='y';
Node *nptr;
while(ch=='y'||ch=='Y')
{
cout<<"\nEnter the data(int type):";
cin>>x;
nptr=newnode(x);
push(nptr);
cout<<"\nThe stack is:";
showstack(top);
cout<<"\n\nWnat push more(y/n):";
cin>>ch;
}

}