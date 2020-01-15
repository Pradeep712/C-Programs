#include<stdio.h>
#include<conio.h>

void main()
{
int i,n,x,large=0;
clrscr(); //to clear the screen

printf("How many numbers?");
scanf("%d",&n);
for(i=0;i<n;++i)
{
printf("\nEnter number %d:",i+1);
scanf("%d",&x);
if(x>large)
large=x;
}

printf("\n\nThe largest number is %d",large);
getch(); //to stop the screen
}