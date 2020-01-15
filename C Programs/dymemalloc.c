//dynamic mem alloc eg.
#include<stdio.h>
#include<conio.h>
typedef struct{ //structure of emp
 char name[30];
 int age;
 float salary;
}emp;
int main(){
 int n,i;
 emp *employee;
 printf("Enter no of employees: ");
 scanf("%d",&n);
 employee=(emp*)malloc(n*sizeof(emp)); //dynamic memory allocation using malloc()
 for(i=0;i<n;i++){
 printf("\n\nEnter details of employee %d\n",i+1);
 printf("Enter name: ");
 scanf("%s",employee[i].name);
 printf("Enter age: ");
 scanf("%d",&employee[i].age);
 printf("Enter salary: ");
 scanf("%f",&employee[i].salary);
 }
 printf("\nPrinting details of all the employees:\n");
 for(i=0;i<n;i++){
 printf("\n\nDetails of employee %d\n",i+1);
 printf("\nName: %s",employee[i].name);
 printf("\nAge: %d",employee[i].age);
 printf("\nSalary: %.2f",employee[i].salary);
 }
 getch();
 return 0;
}