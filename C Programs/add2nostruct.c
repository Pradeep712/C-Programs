#include<stdio.h>
#include<conio.h>

struct sum
{
int a;
int b;
};

void main()
{
int sum1;
struct sum s;
clrscr();

printf("Enter two numbers:");
scanf("%d%d",&s.a,&s.b);

sum1=s.a+s.b;
printf("\nSum=%d",sum1);
getch();
}