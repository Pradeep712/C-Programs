#include<stdio.h>
#include<conio.h>

void main()
{
int *a,*b,*temp;
clrscr();
printf("Enter two mumbers:");
scanf("%d%d",a,b);
printf("Before Swaping:\na=%d b=%d",*a,*b);

temp=a;
a=b;
b=temp;

printf("\nAfter Swaping:\na=%d b=%d",*a,*b);
getch();
}
