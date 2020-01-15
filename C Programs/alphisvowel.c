#include<stdio.h>
#include<conio.h>

void main()
{
char ch;
clrscr();
printf("Enter an alphabate:");
scanf("%c",&ch);

switch(ch)
{
case 'a':
case 'A':
case 'e':
case 'E':
case 'i':
case 'I':
case 'o':
case 'O':
case 'u':
case 'U':
printf("The alphabate is vowel");
break;
default: printf("The alphabate is not vowel");
}

getch();
}