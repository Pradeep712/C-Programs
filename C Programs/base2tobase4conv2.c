//base2tobase4conv
#include<stdio.h>
#include<conio.h>
#include<string.h>
#define MAX 20
typedef struct stack
{
	int data[MAX];
	int top;
}stack;



void push(stack*, int );
int pop(stack*);
int empty(stack*);
void initialise(stack*);
int atoi(char);


void main()
{
char arr[MAX];
stack S;
int first, second, i, num, l;
printf("Enter the string:");
scanf("%s", arr);


initialise(&S);
l=strlen(arr);
while(l>0)
{
second=atoi(arr[l-1]);
if(l!=1)
first=atoi(arr[l-2]);
else
first=0;
num=(2*first)+second;
printf("%d\n",num);
push(&S, num);
l=l-2;
}
while(!empty(&S))
{
i=pop(&S);
printf("%d",i);
}
}


void initialise(stack *S)
{S->top=-1;
}
void push(stack *S, int num)
{
S->top=S->top+1;
S->data[S->top]=num;
}


int pop(stack *S)
{
int k=S->data[S->top];
S->top=S->top-1;
return k;
}


int empty(stack *S)
{
if(S->top==-1)
return 1;
return 0;
}
int atoi(char c)
{
if(c=='0')
return 0;
return 1;
}


