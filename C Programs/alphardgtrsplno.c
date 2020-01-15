#include<stdio.h>
#include<conio.h>


void main()
{
    char ch;
    clrscr();    //to clear the screen
    printf("Enter any character:");
    scanf("%c",&ch);
    if((ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z'))
        printf("\nYou have entered an alphabet");
    else
        if(ch>='0'&&ch<='9')
            printf("\nYou have entered a digit");
        else
            printf("\nYou have entered a special character");


    getch();    //to stop the screen
}
