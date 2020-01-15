#include<stdio.h>
#include<conio.h>
void Convert(int,long);
void Printer(int);
void main()
{
	long Number=0,x=0,Multiplier=1000000000;
	textcolor(GREEN);
	clrscr();
	printf("\nCoverting The Numeric Number to Words");
	printf("\nEnter the Number (Max of 9 digits):");
	scanf("%ld",&Number);// Reading the Number
	Number=Number%Multiplier; //Converting the Number to 9 Digits if Possible
	printf("Considerd Number %ld",Number);
	printf("\n");
	while(Multiplier>=10000) //Here the Loop Starts (only up to Thousands place
	{
		x=Number%Multiplier; //Getting the starting 2 Digits of Given Number
		x=x/(Multiplier/100); //by removing all digits expect first 2
		// printf("%d",x);
		if(x>0)
		{
			// printf("\nx=%ld Mul= %ld",x,Multiplier/10);
			Convert(x,Multiplier/10); //Calling the Converter Function
		}
		Multiplier/=100; // decreasing the digits of Multiplier by 2,
	} // so that next 2 digits will obation from given number , in the next ittration

	x=Number%1000;
	x=x/100; // Caliculatin of hundreds place
	if(x>0)
	{
		Printer(x);
		printf(" Hundred ");
	}
	x=Number%100;
	Convert(x, 100); // Caliculation of tens place
	getch();
}
void Convert(int key,long fact) // 2 digits and Multiplication factor
{ 
	int First=0,Second=0;
	if(key>19)
	{
		Second=key%10; // to obtain 2nd digit of 2 digit Number
		First=key/10; // to obtain 1st digit of 2 digit Number
		switch(First)
		{
			case 2 : printf("Twenty "); break;
			case 3 : printf("Thirty "); break;
			case 4 : printf("Forty "); break;
			case 5 : printf("Fifty "); break;
			case 6 : printf("Sixty "); break;
			case 7 : printf("Seventy "); break;
			case 8 : printf("Eighty "); break;
			case 9 : printf("Ninty "); break;
		}
		Printer(Second); // for printing of single digit	 
	}
	else
	{
		if(key>9) // for printing number >9 and < 20
		{
			switch(key)
			{
				case 10 : printf("TEN "); break;
				case 11 : printf("Eleven "); break;
				case 12 : printf("Twelve "); break;
				case 13 : printf("Thirteen "); break;
				case 14 : printf("Fourteen "); break;
				case 15 : printf("Fifteen "); break;
				case 16 : printf("Sixteen "); break;
				case 17 : printf("Seventeen "); break;
				case 18 : printf("Eightteen "); break;
				case 19 : printf("Nineteen "); break;
			}
		}
		else
		{
			Printer(key);
		} 
	}
	switch(fact)
	{
		case 10000 : printf("Thousand "); break;
		case 1000000 : printf("Lakh(s) "); break;
		case 100000000 : printf("Crore(s) "); break;
	}
}
 
void Printer(int num) // function for single digit printing
{
	switch(num)
	{
		case 1 : printf("One "); break;
		case 2 : printf("Two "); break;
		case 3 : printf("Three "); break;
		case 4 : printf("Four "); break;
		case 5 : printf("Five "); break;
		case 6 : printf("Six "); break;
		case 7 : printf("Seven "); break;
		case 8 : printf("Eight "); break;
		case 9 : printf("Nine "); break; 
	}
}

