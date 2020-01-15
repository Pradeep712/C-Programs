#include<stdio.h>
#include<conio.h>

void main()
{
	int y,w,d,a;
	clrscr();    //to clear the screen
	printf("Enter total number of days:");
	scanf("%d",&d);

	y=d/365;
	a=d%365;
	w=a/7;
	d=a%7;
	printf("\nYears=%d\nWeeks=%d\nDays=%d",y,w,d);
	getch();    //to stop the screen
}