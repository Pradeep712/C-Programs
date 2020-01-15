#include<stdio.h>
#include<conio.h>

void main()
{
int n,a,b=0,num;
clrscr(); //to clear the screen
printf("Enter any number:");
scanf("%d",&n);
num=n;

while(n!=0)
{
a=n%10;
b=a+(b*10);
n=n/10;
}
if(num==b)
printf("\nThe given number is palindrome");
else
printf("\nThe given number is not palindrome");
getch(); //to clear the screen;
}