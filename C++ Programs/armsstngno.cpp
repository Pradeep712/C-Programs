/*What is an Armstrong number?
A number is armstrong if the sum of cubes of individual digits of a number is equal to the number itself. For example 153 is an armstrong number as 1 + 125 + 27 = 153.
*/
#include<iostream>

using namespace std;

int main()
{
int n,m=0,x,y;
cout<<"Enter any three digit numnber:";
cin>>n;
y=n;

while(n!=0)
{
x=n%10;
m+=(x*x*x);
n=n/10;
}

if(y==m)
cout<<"The number is an Armstrong number";
else
cout<<"The number is not an Armstrong number";

return 0;
}
