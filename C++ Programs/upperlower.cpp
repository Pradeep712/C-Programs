#include<conio.h>
#include<iostream.h>
#include<dos.h>
#include<process.h>


void main()
{
clrscr();
char ch,a[]={"Made By : Neeraj Mishra"};
int j=0;


cout<<"Uppercase Alphabates\n\n";
for(int i=65;i<91;++i)
{
j++;
ch=i;
cout<<ch<<":"<<i<<"\t";
if(j==10)
{
cout<<"\n";
j=0;
}
}
j=0;


cout<<"\n\n\nLowercase Alphabates\n\n";
for(i=97;i<123;++i)
{
j++;
ch=i;
cout<<ch<<":"<<i<<"\t";
if(j==10)
{
cout<<"\n";
j=0;
}
}


cout<<"\n\n\nDigits\n\n";
for(i=48;i<58;i++)
{
ch=i;
cout<<ch<<":"<<i<<"\t";
}


cout<<"\n\n\n\n\t\t";
for(i=0;a[i]!='\0';++i)
{
cout<<a[i];
sleep(1);
}
exit(0);
}

