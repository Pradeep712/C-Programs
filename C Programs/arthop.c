#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void main()
{
int ch;
float a,b,res;
clrscr();
printf("Enter two numbers:");
scanf("%f%f",&a,&b);
printf("\nMenu\n1.Addition\n2.Subtraction\n3.Multiplication\n4.Division");
printf("\nEnter your choice:");
scanf("%d",&ch);

switch(ch)
{
case 1: res=a+b;
break;
case 2: res=a-b;
break;
case 3: res=a*b;
break;
case 4: res=a/b;
break;
default: printf("Wrong choice!!\nPress any key...");
getch();
exit(0);
}

