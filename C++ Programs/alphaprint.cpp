#include<iostream.h>
#include<conio.h>
void main()
{
clrscr();
int i,j,k=1;
char ch;
cout<<"Input an Alphabate in capital letters that you want to print:";
cin>>ch;
cout<<"\n\n\n\n";
switch(ch)
{
case 'A':
cout<<"\t\t\t    ";
for(i=1;i<=40;++i)
{
for(j=0;j<=22;++j)
{
if(i==1||i==2||i==21||i==20)
cout<<"*";
else
{
if(j==0||j==20)
cout<<"**";
else
cout<<" ";
}
}
cout<<"\n\t\t\t    ";

}
break;



case 'B':
cout<<"\t\t\t\t";

while(k<=2)
{
for(i=1;i<=9;++i)
{
for(j=0;j<=i;++j)
{
if(j==0||j==i)
cout<<"**";
else
cout<<" ";
}

cout<<"\n\t\t\t\t";

}
for(i=1;i<=10;++i)
{
if(i==1||i==10)
cout<<"**";
else
cout<<" ";
}
cout<<"\n\t\t\t\t";

for(i=1;i<=10;++i)
{
if(i==1||i==10)
cout<<"**";
else
cout<<" ";
}
cout<<"\n\t\t\t\t";

for(i=9;i>=1;--i)
{
for(j=0;j<=i;++j)
{
if(j==0||j==i)
cout<<"**";
else
cout<<" ";
}
cout<<"\n\t\t\t\t";
}
++k;
}
 break;

 case'C':
cout<<"\t\t\t    ";

for(i=1;i<=40;++i)
{
for(j=0;j<=22;++j)
{
if(i==1||i==2||i==39||i==40)
cout<<"*";
else
{
if(j==0)
cout<<"**";
else
cout<<" ";
}
}
cout<<"\n\t\t\t    ";

}
break;

 case'D':
 cout<<"\t\t\t\t";
 for(i=1;i<=18;++i)
 {
for(j=0;j<=i;++j)
{
if(j==0||j==i)
cout<<"**";
else
cout<<" ";
}
cout<<"\n\t\t\t\t";
 }
 while(k<=4)
 {
for(i=1;i<=19;++i)
{
if(i==1||i==19)
cout<<"**";
else
cout<<" ";
}
cout<<"\n\t\t\t\t";
 ++k;
 }
 for(i=18;i>=1;--i)
 {
for(j=0;j<=i;++j)
{
if(j==0||j==i)
cout<<"**";
else
cout<<" ";
}
 cout<<"\n\t\t\t\t";
 }
 break;

 case'E':

 cout<<"\t\t\t\t";
 for(i=1;i<=39;++i)
 {
for(j=1;j<=20;++j)
{
if(i==1||i==2||i==20||i==21||i==38||i==39)
cout<<"*";
else
{
if(j==1)
cout<<"**";
else
cout<<" ";
}
}
 cout<<"\n\t\t\t\t";
 }
 break;

 case'F':

 cout<<"\t\t\t\t";

for(i=1;i<=40;++i)
{
for(j=1;j<=20;++j)
{
if(i==1||i==2||i==18||i==19)
cout<<"*";
else
{
if(j==1)
cout<<"**";
else
cout<<" ";
}
}
cout<<"\n\t\t\t\t";
}
break;

 case'G':

cout<<"\t\t\t";
for(i=1;i<=25;++i)
{
for(j=1;j<=20;++j)
{
if(i==1||i==2)
cout<<"*";
else
{
if(j==1)
cout<<"**";
else
cout<<" ";
}
}
cout<<"\n\t\t\t";
}
for(i=1;i<=10;++i)
{
for(j=1;j<=20;++j)
{
if(i==1||i==2)
{ if(j==1||j==14||j==15||j==16)
cout<<"**";
  else
  cout<<" ";
}
else
{
if(i==9||i==10)
cout<<"*";
else
{  if(j==1||j==18)
  cout<<"**";
  else
  cout<<" ";
}
}
}
cout<<"\n\t\t\t";
}
break;


 case'H':

cout<<"\t\t\t";
for(i=1;i<=40;++i)
{
for(j=1;j<=21;++j)
{
if(i==20||i==21)
cout<<"*";
else
{
if(j==1||j==19)
cout<<"**";
else
cout<<" ";
}
}
cout<<"\n\t\t\t";
}
break;

 case'I':

cout<<"\t\t\t";
for(i=1;i<=40;++i)
{
for(j=1;j<=30;++j)
{
if(i==1||i==2||i==39||i==40)
cout<<"*";
else
{
if(j==15)
cout<<"**";
else
cout<<" ";
}
}
cout<<"\n\t\t\t";
}
break;


 case'J':
cout<<"\t\t\t";

for(i=1;i<=30;++i)
{
for(j=1;j<=28;++j)
{
if(i==1||i==2)
cout<<"*";
else
{
if(j==14)
cout<<"**";
else
cout<<" ";
}
}
cout<<"\n\t\t\t";
}
for(i=1;i<=10;++i)
{
for(j=1;j<=15;++j)
{
if(i==10||i==9)
cout<<"*";
else
{
if(j==1||j==13)
cout<<"**";
else
cout<<" ";
}
}
cout<<"\n\t\t\t";
}
break;

 case'K':

cout<<"\t\t\t";
for(i=20;i>=1;--i)
{
for(j=0;j<=i;++j)
{
if(j==0||j==i)
cout<<"**";
else
cout<<" ";
}
cout<<"\n\t\t\t";
}

for(i=1;i<=20;++i)
{
for(j=0;j<=i;++j)
{
if(j==0||j==i)
cout<<"**";
else
cout<<" ";
}
cout<<"\n\t\t\t";
}
break;

 case'L':

cout<<"\t\t\t";
for(i=1;i<=40;++i)
{
for(j=1;j<=25;++j)
{
if(i==39||i==40)
cout<<"*";
else
{
if(j==1)
cout<<"**";
else
cout<<" ";
}
}
cout<<"\n\t\t\t";
}
break;


 case'S':

cout<<"\t\t\t";

for(i=1;i<=20;++i)
{
for(j=1;j<=20;++j)
{
if(i==1||i==2||i==19||i==20)
cout<<"*";
else
{
if(j==1)
cout<<"**";
else
cout<<" ";
}
}
cout<<"\n\t\t\t";
}
for(i=1;i<=18;++i)
{
for(j=1;j<=20;++j)
{
if(i==17||i==18)
cout<<"*";
else
{
if(j==19)
cout<<"**";
else
cout<<" ";
}
}
cout<<"\n\t\t\t";
}
break;



}
getch();
}
