#include<stdio.h>
#include<conio.h>

void main()
{
int fac,n;
int factorial(int);
clrscr();

printf("Enter any number:");
scanf("%d",&n);

fac=factorial(n);
printf("Factorial=%d",fac);
getch();
}

int factorial(int x)
{
int f;
if(x==1)
return 1;
else
f=x*factorial(x-1);

return f;
}
