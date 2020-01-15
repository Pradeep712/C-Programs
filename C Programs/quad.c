#include<stdio.h>
#include<conio.h>
#include<math.h>


void main()
{
float root1,root2,a,b,c,d;
clrscr();
printf("Quadratic Equation is ax^2=bx+c=0");
printf("\nEnter values of a,b and c:");
 	scanf("%f%f%f",&a,&b,&c);


d=(b*b)-(4*a*c);
if(d>0)
{
printf("\nTwo real and distinct roots");
root1=(-b+sqrt(d))/(2*a);
root2=(-b-sqrt(d))/(2*a);
printf("\nRoots are %f and %f",root1,root2);
}


else
if(d==0)
{
printf("\nTwo real and equal roots");
root1=root2=-b/(2*a);
printf("\nRoots are %f and %f",root1,root2);
}
else
printf("\nRoots are COMPLEX and IMAGINARY....!!!");
getch();
}