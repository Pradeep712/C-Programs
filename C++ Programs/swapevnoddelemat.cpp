#include<iostream.h>
#include<conio.h>

void main()
{
clrscr();
int a[30],i,temp,n;
cout<<"How many elements?";
cin>>n;

cout<<"Enter elements of array:\n";
for(i=0;i<n;++i)
cin>>a[i];

cout<<"\nArray before swapping:\n";
for(i=0;i<n;++i)
cout<<a[i]<<" ";

for(i=1;i<n;i+=2)
{
temp=a[i];
a[i]=a[i-1];
a[i-1]=temp;
}

cout<<"\n\nArray after swapping:\n";
for(i=0;i<n;++i)
cout<<a[i]<<" ";

getch();
}
