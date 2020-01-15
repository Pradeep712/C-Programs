#include<stdio.h>
#include<conio.h>

void main()
{
int first=0,second=1,third,i,n;
clrscr();  //to clear the screen

printf("Enter how many elements?");
scanf("%d",&n);
printf("\n%d %d",first,second);

for(i=2;i<n;++i)
{
third=first+second;
printf(" %d",third);
first=second;
second=third;
}
getch();  //to stop the screen
}