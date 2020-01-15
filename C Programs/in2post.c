//Program to covert any valid infix expression to postfix one
//Start of Program
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
int valchek(char ck)//Function to check valididy of expression
{
if((ck>=65 && ck<=90) || (ck>=97 && ck<=122))
return 1;
else if(ck=='+' || ck=='-' || ck=='/' || ck=='*' || ck=='^')
return -1;
else if(ck=='[' || ck==']' || ck=='{' || ck=='}' || ck=='(' || ck==')')
return 0;
else
return 2;
}
int prechek(char ck,int s)//Function to check precedence
{
if(ck=='+' || ck=='-')
return (s==1?1:2);
else if(ck=='*' || ck=='/')
return (s==1?3:4);
else if(ck=='^')
return (s==1?6:5);
else if((ck>=65 && ck<=90) || (ck>=97 && ck<=122))
return (s==1?7:8);
else if(ck=='(')
return (s==1?9:0);
else
return 0;
}
void main()
{
char in[15],stak[15],polis[15];//List of Variablles
int cek=0,ts=0,tp=0,i;
clrscr();
printf("\nEnter the infix expresssion: ");//Input
gets(in);
for(i=0;i<strlen(in);i++)//Loop to check Validity of Expression
if((cek+=valchek(in[i]))!=1 && cek!=0)
exit(printf("\nInvalid")||1);
polis[tp]=in[0];
stak[ts]='\0';
for(i=1;i<strlen(in) && ts>=0;i++)//Loop for conversion
{
while((cek=prechek(in[i],1))<(cek=prechek(stak[ts],2)))
polis[++tp]=stak[ts--];
stak[++ts]=in[i];
}
while(ts>=0)
polis[++tp]=stak[ts--];
printf("\nThe postfix expression is: %s",polis);//Output
getch();
}//End of Program