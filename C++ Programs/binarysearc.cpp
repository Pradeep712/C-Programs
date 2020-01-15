#include<conio.h>
#include<iostream.h>

void main()
{
int search(int [],int,int);
clrscr();
int n,i,a[100],e=-3,res;
cout<<"How Many Elements:";
cin>>n;
cout<<"\nEnter Elements of Array in Accending order\n";

for(i=0;i<n;++i)
{
cin>>a[i];
}

cout<<"\nEnter element to search:";
cin>>e;
res=search(a,n,e);
if(res!=0)
cout<<"\nElement is Founded at "<<res+1<<"st position";
else
cout<<"\nElement is not found....!!!";
getch();
}

int search(int a[],int n,int e)
{
int f,l,m;
f=0;
l=n-1;
while(f<=l)
{
m=(f+l)/2;
if(e==a[m])
return(m);
else
if(e>a[m])
f=m+1;
else
l=m-1;
}
return 0;
}