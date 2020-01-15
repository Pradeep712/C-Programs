/*
C – Passing struct to function

    A structure can be passed to any function from main function or from any sub function.
    Structure definition will be available within the function only.
    It won’t be available to other functions unless it is passed to those functions by value or by address(reference).
    Else, we have to declare structure variable as global variable. That means, structure variable should be declared outside the main function. So, this structure will be visible to all the functions in a C program.

Passing structure to function in C:

It can be done in below 3 ways.

        Passing structure to a function by value
        Passing structure to a function by address(reference)
        No need to pass a structure – Declare structure variable as global

Example program – passing structure to function in C by value:

           In this program, the whole structure is passed to another function by value. It means the whole structure is passed to another function with all members and their values. So, this structure can be accessed from called function. This concept is very useful while writing very big programs in C. */

#include <stdio.h>
#include <string.h>
 
struct student
{
            int id;
            char name[20];
            float percentage;
};
 
void func(struct student record);
 
int main()
{
            struct student record;
 
            record.id=1;
            strcpy(record.name, "Raju");
            record.percentage = 86.5;
 
            func(record);
            return 0;
}
 
void func(struct student record)
{
            printf(" Id is: %d \n", record.id);
            printf(" Name is: %s \n", record.name);
            printf(" Percentage is: %f \n", record.percentage);
}
