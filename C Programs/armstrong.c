#include<stdio.h>
#include<conio.h>
#include<math.h>

void main()
{
int n,m=0,x,y;
clrscr();
printf("Enter any three digit numnber:");
scanf("%d",&n);
y=n;

while(n!=0)
{
x=n%10;
m+=pow(x,3);
n=n/10;
}

if(y==m)
printf("The given number is an Armstrong number");
else
printf("The given number is not an Armstrong number");
getch();
}