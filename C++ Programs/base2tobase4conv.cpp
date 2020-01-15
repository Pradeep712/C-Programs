//base2tobase4conv
#include<iostream>
#include<malloc.h>
#include<string.h>



using namespace std;


main()
{
char *a= new char[20];
cout<<"Enter string \n";
cin >>a;
cout<<"\n\n";
int len =strlen(a);
int i;
if(len%2 ==0) {
for(i=0;i< len ;i+=2){
cout<<((a[i]-'0')*2+(a[i+1]-'0'));
}
}
else{
cout<<a[0];
for(i=1;i< len ;i+=2){
cout<<((a[i]-'0')*2+(a[i+1]-'0'));
}
}
cout<<"\n";
}

