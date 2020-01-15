#include<stdio.h>
#include<conio.h>

void main()
{
int d,n,i,j,a[50];
clrscr();

printf("Enter a number:");
scanf("%d",&n);

if(n==0)
 printf("\nThe binary conversion of 0 is 0"):
else
{
printf("\nThe binary conversion of %d is 1",n);

for(i=1;n!=1;++i)
{
d=n%2;
a[i]=d;
n=n/2;
}

for(j=i-1;j>0;--j)
printf("%d",a[j]);
} getch();
}