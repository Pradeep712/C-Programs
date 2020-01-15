#include<stdio.h>
#include<conio.h>

void main()
{
int i;
char str[50];
clrscr();
printf("Enter a string:");
gets(str);

for(i=0;str[i]!='\0';++i);
printf("Lenth of string is %d",i);
getch();
}
