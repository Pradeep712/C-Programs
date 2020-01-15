#include<stdio.h>
#include<conio.h>

void main()
{
int n,i,sum=0;
clrscr(); //to clear the screen
printf("Enter the value of n:");
scanf("%d",&n);

for(i=1;i<=n;++i)
{
printf("\n%d",i);
sum+=i;
}
printf("\n\nSum of first n natural numbers is:%d",sum);
getch(); //to stop the screen
}