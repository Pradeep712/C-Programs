#include<stdio.h>
#include<conio.h>


void main()
{
    double temp,ctemp;
    int ch;
    clrscr();    //to clear the screen
    printf("Temprature Converrsion Menu");
    printf("\n\t1.Fahrenheit to Celsius");
    printf("\n\t2.Celsius to Fahrenheit");
    printf("\nEnter your choice(1/2):");
    scanf("%d",&ch);


    if(ch==1)
    {
        printf("Enter Temperature in Fahrenheit:");
        scanf("%lf",&temp);
        ctemp=(temp-32)/1.8;
        printf("\nTemprature in celcius is %lf",ctemp);
    }
    else
        if(ch==2)
        {
            printf("Enter Temperature in Celsius:");
            scanf("%lf",&temp);
            ctemp=(1.8*temp)+32;
            printf("\nTemperature in Fahrenheit is %lf",ctemp);
        }
    else
        printf("\nWrong choice.....!!");
    getch();    //to stop the screen
}
