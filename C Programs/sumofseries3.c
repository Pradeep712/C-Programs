#include<stdio.h>
#include<conio.h>


void main()
{
int i,n,sum=0;
clrscr(); //to clear the screen

printf("1^2+3^2+5^2+.....+n^2");
printf("\n\nEnter value of n:");
scanf("%d",&n);


for(i=1;i<=n;i+=2)
sum+=i*i;
printf("Sum=%d",sum);
getch(); //to stop the screen
}