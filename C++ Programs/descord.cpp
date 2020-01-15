#include<iostream.h>
#include<conio.h>
void main()
{
clrscr();
int n,i,z;
cout<<"Enter number to print series of odd numbers in decending 
order from it: ";
cin>>n;
cout<<endl<<"The series is:"<<endl;
if(n%2==0)
{
z=n-1;

for(i=z;i>0;i-=2)
cout<<i<<endl;
}
else
{
for(i=n;i>0;i-=2)
cout<<i<<endl;
}
getch();
}