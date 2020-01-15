#include<stdio.h>
#include<conio.h>

void main()
{
char s1[30],s2[30],s3[60];
int i,j;
clrscr();

printf("Enter first string:");
gets(s1);
printf("Enter second string:");
gets(s2);

for(i=0;s1[i]!='\0';++i)
s3[i]=s1[i];

for(j=0;s2[j]!='\0';++j)
s3[i+j]=s2[j];

s3[i+j]='\0';

printf("\nThe concatenated string is: %s",s3);
getch();
}
- See more at: http://www.thecrazyprogrammer.com/2013/07/c-program-to-concatenate-two-strings.html#sthash.dfvySW1F.dpuf