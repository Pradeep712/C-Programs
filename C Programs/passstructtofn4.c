#include <iostream.h>

/*****************************************************
 File: struct5.C
 This program demonstrates how to pass a structure
 to functions    
*****************************************************/

struct date {
     int day;
     int month;
     int year;
};
typedef date Date; 
typedef Date *ptrdate;

void print_date(ptrdate ); // Declare prototype with Date pointer argument
void init_date(Date& ); //Declare prototype with Date reference argument

int main()
{
     Date today;

     init_date(today);// call init_date and pass reference to today
     print_date(&today); // call print and pass structure today

     exit(0);
}

void init_date(Date& ref_date)
{
     ref_date.day      = 31;
     ref_date.month    = 3;
     ref_date.year     = 1997;
}	

void print_date(ptrdate Pdate)
{
     cout << "Today\'s date is " << Pdate->day << ' '; 
     cout << Pdate->month << ' ' << Pdate->year << endl;
}



