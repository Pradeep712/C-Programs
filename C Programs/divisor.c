#include<stdio.h>
#include<conio.h>

void main()
{
int i,n;
clrscr();  //to clear the screen

printf("Enter any number:");
scanf("%d",&n);
printf("\nDivisors of %d are",n);

for(i=1;i<n/2;++i)
if(n%i==0)
printf(" %d",i);
getch();  //to stop the screen
}