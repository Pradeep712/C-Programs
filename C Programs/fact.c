#include<stdio.h>
#include<conio.h>

void main()
{
long i,n,fac=1;
clrscr(); //to clear the screen

printf("Enter value of n:");
scanf("%ld",&n);
for(i=n;i>=1;--i)
fac*=i;

printf("\nFactorial of %ld is %ld",n,fac);
getch(); //to stop the screen
}