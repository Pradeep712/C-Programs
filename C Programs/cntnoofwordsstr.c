#include<stdio.h>
#include<conio.h>

void main()
{
int i,words=1;
char str[100];
clrscr();
printf("Enter a string:");
gets(str);
for(i=0;str[i]!='\0';++i)
if(str[i]==' ')
words++;

printf("No. of words are %d",words);
getch();
}
