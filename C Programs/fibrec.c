//fibonnacci recursion
#include<stdio.h>
#include<conio.h>
int y;
fibonacci(int x){
 if(x==1 || x==0) //terminating step
 return x;
 y=fibonacci(x-1)+fibonacci(x-2); //recursive definition
 return y;
}
int main(){
 int a,r;
 printf("Enter the position : ");
 scanf("%d",&a);
 r=fibonacci(a);
 printf("The number at position %d is %d",a,r);
 getch();
 return 0;
}
