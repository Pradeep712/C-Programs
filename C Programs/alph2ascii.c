#include<stdio.h>
#include<conio.h>

void main()
{
int i;
char name[50];
clrscr();
printf("Enter your name: ");
gets(name);
printf("\nCharacter\tASCII Code");

for(i=0;name[i]!='\0';i++)
printf("\n%c\t\t%d",name[i],name[i]);

getch();
}