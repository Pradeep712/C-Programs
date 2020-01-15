/* C Program and Algorithm for Conversion of an Expression from Infix to Postfix
In infix notation or expression operators are written in between the operands while in postfix notation every operator follows all of its operands.

Example:
Infix Expression: 5+3*2
Postfix Expression: 5 3 2*+.

Algorithm for Conversion of an Expression from Infix to Postfix
Let Q be any infix expression and we have to convert it to postfix expression P. For this the following procedure will be followed.

1. Push left parenthesis onto STACK and add right parenthesis at the end of Q.

2. Scan Q from left to right and repeat step 3 to 6 for each element of Q until the STACK is empty.

3. If an operand is encountered add it to P.

4. If a left parenthesis is encountered push it onto the STACK.

5. If an operator is encountered, then

    Repeatedly pop from STACK and add to P each operator which has same precedence as or higher precedence than the operator encountered.
    Push the encountered operator onto the STACK.


6. If a right parenthesis is encountered, then

    Repeatedly pop from the STACK and add to P each operator until a left parenthesis is encountered.
    Remove the left parenthesis; do not add it to P.


7. Exit
*/
 // Operator supported: +,-,*,/,%,^,(,)
// Operands supported: all single character operands

#include<stdio.h>
#include<conio.h>
#include<ctype.h>

#define MAX 50

typedef struct stack
{
    int data[MAX];
    int top;
}stack;

int precedence(char);
void init(stack *);
int empty(stack *);
int full(stack *);
int pop(stack *);
void push(stack *,int);
int top(stack *);   //value of the top element
void infix_to_postfix(char infix[],char postfix[]);

void main()
{
    char infix[30],postfix[30];
    printf("Enter an infix expression(eg: 5+2*4): ");
    gets(infix);
    infix_to_postfix(infix,postfix);
    printf("\nPostfix expression: %s",postfix);
}

void infix_to_postfix(char infix[],char postfix[])
{
    stack s;
    char x,token;
    int i,j;    //i-index of infix,j-index of postfix
    init(&s);
    j=0;

    for(i=0;infix[i]!='\0';i++)
    {
        token=infix[i];
        if(isalnum(token))
            postfix[j++]=token;
        else
            if(token=='(')
               push(&s,'(');
        else
            if(token==')')
                while((x=pop(&s))!='(')
                      postfix[j++]=x;
                else
                {
                    while(precedence(token)<=precedence(top(&s))&&!empty(&s))
                    {
                        x=pop(&s);
                        postfix[j++]=x;
                    }
                    push(&s,token);
                }
    }

    while(!empty(&s))
    {
        x=pop(&s);
        postfix[j++]=x;
    }

    postfix[j]='\0';
}

int precedence(char x)
{
    if(x=='(')
        return(0);
    if(x=='+'||x=='-')
        return(1);
    if(x=='*'||x=='/'||x=='%')
        return(2);

    return(3);
}

void init(stack *s)
{
    s->top=-1;
}

int empty(stack *s)
{
    if(s->top==-1)
        return(1);

    return(0);
}

int full(stack *s)
{
    if(s->top==MAX-1)
        return(1);

    return(0);
}

void push(stack *s,int x)
{
    s->top=s->top+1;
    s->data[s->top]=x;
}

int pop(stack *s)
{
    int x;
    x=s->data[s->top];
    s->top=s->top-1;
    return(x);
}

int top(stack *p)
{
    return (p->data[p->top]);
}


