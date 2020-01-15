#include<stdio.h>
#include<conio.h>
#include<string.h>

void main()
{
int i,n;
char a[30];
clrscr();
printf("Enter any string:");
gets(a);

n=strlen(a);
printf("Reverse of string:");
for(i=(n-1);i>=0;--i)
printf("%c",a[i]);
getch();
}
