//Newton-Raphson Method
#include <complex.h>
#include <stdio.h>
#include <stdlib.h>
 
typedef complex<double> dcomplex;
 
FILE *fn;
 
// Evaluate polynomial with coefficients a at a given value of x
dcomplex evalpoly(dcomplex *a,dcomplex x,int n)
{
int i;
dcomplex y;
y=*(a+n-1);
for(i=0;i<n-1;i++)
y+=*(a+i)*pow(x,1.0*(n-i-1));
return(y);
}
 
// Evaluate the first derivative of the polynomial with coefficients a at value x
dcomplex evalpder(dcomplex *a,dcomplex x,int n)
{
int i;
dcomplex y;
y=dcomplex(0.0,0.0);
for(i=0;i<n-1;i++)
y+=dcomplex(n-i-1,0.0)**(a+i)*pow(x,1.0*(n-i-2));
return(y);
}
 
// Perform synthetic division to reduce a polynomial to the next lower degree after finding a complex root
dcomplex *reduce_pol(dcomplex *a,dcomplex x,int n)
{
int i;
dcomplex *b;
b=(dcomplex*)calloc(n-1,sizeof(dcomplex));
*b=*a;
for(i=1;i<n-1;i++)
*(b+i)=*(a+i)+*(b+i-1)*x;
return(b);
}
 
// Newton-Raphson algorithm for finding the complex root of a polynomial
dcomplex *newton(double *ain,double tol,int maxiter,int m)
{
int iter,root_ktr,i,n;
dcomplex x,*roots,dx,*a;
double temp;
char dummy[2];
n=m;
a=(dcomplex*)calloc(n,sizeof(dcomplex));
temp=*ain;
printf("\nOriginal polynomial normalized:\n\n");
fprintf(fn,"\nOriginal polynomial normalized:\n\n");
for(i=0;i<n;i++) {
*(a+i)=dcomplex(*(ain+i),0.0)/temp;
printf("a%d = %10.6f + j%10.6f\n",i,real(*(a+i)),imag(*(a+i)));
fprintf(fn,"a%d = %10.6f + j%10.6f\n",i,real(*(a+i)),imag(*(a+i)));
}
roots=(dcomplex*)calloc(n,sizeof(dcomplex));
root_ktr=0;
while(n>1) {
root_ktr++;
printf("\nFinding Root#%d:\n",root_ktr);
fprintf(fn,"\nFinding Root#%d:\n",root_ktr);
iter=0;
// Initial value of x
x=dcomplex(1.9,-2.1);
dx=dcomplex(10.0,0.0);
while((abs(dx)>=tol)&&(iter<maxiter)) {
dx=-evalpoly(a,x,n)/evalpder(a,x,n);
printf("Iter=%d, X = %10.6f + j%10.6f, X-Mismatch = %10.6f + j%10.6f\n",iter,real(x),imag(x),real(dx),imag(dx));
fprintf(fn,"Iter=%d, X = %10.6f + j%10.6f, X-Mismatch = %10.6f + j%10.6f\n",iter,real(x),imag(x),real(dx),imag(dx));
x+=dx;
iter++;
}
// Stop if divergent
if(abs(dx)>=tol) {
printf("\nError: Divergent solution, program aborted.\n");
fprintf(fn,"\nError: Divergent solution, program aborted.\n");
fclose(fn);
exit(1);
}
// Root found
*(roots+root_ktr-1)=x;
printf("Found Root#%d = %10.6f + j%10.6f\n\n",root_ktr,real(*(roots+root_ktr-1)),imag(*(roots+root_ktr-1)));
fprintf(fn,"Found Root#%d = %10.6f + j%10.6f\n\n",root_ktr,real(*(roots+root_ktr-1)),imag(*(roots+root_ktr-1)));
// Reduce polynomial to a lower degree by dividing it by the newly found root
if(n>2) {
printf("Reducing polynomial by one degree via synthetic division\n");
fprintf(fn,"Reducing polynomial by one degree via synthetic division\n");
a=reduce_pol(a,*(roots+root_ktr-1),n);
for(i=0;i<n-1;i++) {
printf("a%d = %10.6f + j%10.6f\n",i,real(*(a+i)),imag(*(a+i)));
fprintf(fn,"a%d = %10.6f + j%10.6f\n",i,real(*(a+i)),imag(*(a+i)));
}
}
n--;
// Add the complex conjugate of a complex root to the solution list
if(abs(imag(*(roots+root_ktr-1)))>tol*10.0) {
root_ktr++;
*(roots+root_ktr-1)=conj(*(roots+root_ktr-2));
printf("Found Conjugate Root#%d = %10.6f + j%10.6f\n\n",root_ktr,real(*(roots+root_ktr-1)),imag(*(roots+root_ktr-1)));
fprintf(fn,"Found Conjugate Root#%d = %10.6f + j%10.6f\n\n",root_ktr,real(*(roots+root_ktr-1)),imag(*(roots+root_ktr-1)));
if(n>2) {
printf("Reducing polynomial by one degree via synthetic division\n");
fprintf(fn,"Reducing polynomial by one degree via synthetic division\n");
a=reduce_pol(a,*(roots+root_ktr-1),n);
for(i=0;i<n-1;i++) {
printf("a%d = %10.6f + j%10.6f\n",i,real(*(a+i)),imag(*(a+i)));
fprintf(fn,"a%d = %10.6f + j%10.6f\n",i,real(*(a+i)),imag(*(a+i)));
}
}
n--;
}
}
return(roots);
}
 
void main(void)
{
double *a;
dcomplex *x;
char filename[20];
int n,m,i;
system("color 1E");
printf("\nNewton-Raphson Method For Polymomal Complex Root Solving\n");
printf("Gerardo V. Lozada, M.S., P.E.E., Borland C/C++, November 7, 1999 / 2013\n\n");
// Output data text-format filename
printf("Enter Output Filename: ");
scanf("%s",filename);
fn=fopen(filename,"wt");
printf("\n\nEnter Polynomial Degree (n): ");
scanf("%d",&m);
n=m+1;
a=(double*)calloc(n,sizeof(double));
printf("\nPolynomial form is: a0*x^n + a1*x^(n-1) + a2*x^(n-2) + ... + an-1*x + an\n\n");
printf("Enter Polynomial Coefficients (a0 to a%d):\n",m);
for(i=0;i<n;i++) {
printf("a%d (coefficient of x^%d): ",i,n-i-1);
scanf("%lf",(a+i));
}
fprintf(fn,"Newton-Raphson Method For Polymomal Complex Root Solving\n");
fprintf(fn,"Gerardo V. Lozada, M.S., P.E.E., Borland C/C++, November 7, 1999 / 2013\n\n");
fprintf(fn,"Polynomial form is: a0*x^n + a1*x^(n-1) + a2*x^(n-2) + ... + an-1*x + an\n");
fprintf(fn," where n = %d\n\n",m);
fprintf(fn,"Polynomial Coefficients are:\n",m);
for(i=0;i<n;i++)
fprintf(fn,"a%d (coefficient of x^%d) = %10.6f\n",i,n-i-1,*(a+i));
printf("\nSolving for Roots...\n\n");
fprintf(fn,"\nSolving for Roots...\n\n");
x=newton(a,0.0000001,200,n);
printf("\nSummary of Roots Found:\n");
fprintf(fn,"\nSummary of Roots Found:\n");
for(i=0;i<m;i++) {
printf("No. %d: %10.6f + j%10.6f\n",i+1,real(*(x+i)),imag(*(x+i)));
fprintf(fn,"No. %d: %10.6f + j%10.6f\n",i+1,real(*(x+i)),imag(*(x+i)));
}
fprintf(fn,"\nProgram execution terminated.\n");
fclose(fn);
printf("\nOutput data is in file %s\n",filename);
printf("\nProgram execution terminated.\n");
}