#include<stdio.h>
#include<conio.h>

void main()
{
long n,rev=0,d;
clrscr(); //to clear the screen
printf("Enter any number:");
scanf("%ld",&n);

while(n!=0)
{
d=n%10;
rev=(rev*10)+d;
n=n/10;
}

printf("The reversed number is %ld",rev);
getch(); //to stop the screen
}