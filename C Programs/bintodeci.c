#include<stdio.h>
#include<conio.h>
#include<math.h>

void main()
{
long int i,n,x=0,a;
clrscr();
printf("Enter any Binary number: ");
scanf("%ld",&n);
printf("\nThe Decimal conversion of %ld is ",n);

for(i=0;n!=0;++i)
{
a=n%10;
x=(a)*(pow(2,i))+x;
n=n/10;
}

printf("%ld",x);
getch();
}