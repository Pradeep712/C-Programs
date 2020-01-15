#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>

void main()
{
clrscr();
char a[3][50];
int i,j,k,len;
cout<<"Enter 3 strings:\n";

for(i=0;i<3;i++)
{
gets(a[i]);
}
cout<<"\nThe list of orignal strings:\n" ;

for(i=0;i<3;i++)
{
cout<<a[i]<<"\n";
}
cout<<"\nThe list of changed string:\n";

for(i=0;i<3;i++)
{
len=strlen(a[i]);
for(j=0,k=len-1;k>=0;j++,k--)
{
cout<<a[i][k];
}
cout<<"\n";
}
getch();
}