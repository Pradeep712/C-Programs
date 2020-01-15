#include<stdio.h>
#include<conio.h>
#include<string.h>

void main()
{
int i,j,flag=1,len;
char str[50];
clrscr();
printf("Enter any string:");
gets(str);
len=strlen(str);

for(i=0,j=len-1;i<len/2;++i,--j)
if(str[i]!=str[j])
{
flag=0;
break;
}
if(flag)
printf("String is palindrome");
else
printf("String is not palindrome");
getch();
}