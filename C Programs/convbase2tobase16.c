//conv base 2 to base 16 
#include<conio.h>
 #include<stdio.h>
  void main()
  {
      int b,n,i,r,digit,p,count=0;
      char a[100];// clrscr();
      printf("\nEnter the decimal number:\n");
     scanf("%d",&n);
      printf("\nEnter the base to be converted:\n");
    scanf("%d",&b);
      p=n;
      do
    {
        r=p%b;
        digit='0'+r;
        if(digit>'9')
            digit=digit+7;
        a[count]=digit;
        count++;
        p=p/b;
         } while(p!=0);
      printf("\nbase %d equivalent of num %d is ",b,n);
      for(i=count-1;i>=0;--i)
        printf("%c",a[i]);
    printf(".\n");
//  getch();
  }

#include <stdio.h>

void main(void)
{
   char base_digits[16] =
	 {'0', '1', '2', '3', '4', '5', '6', '7',
	  '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

   int converted_number[64];
   long int number_to_convert;
   int next_digit, base, index=0;

   /* get the number and base */
   printf("Enter number and desired base: ");
   scanf("%ld %i", &number_to_convert, &base);

   /* convert to the indicated base */
   while (number_to_convert != 0)
   {
	 converted_number[index] = number_to_convert % base;
	 number_to_convert = number_to_convert / base;
	 ++index;
   }

   /* now print the result in reverse order */
   --index;  /* back up to last entry in the array */
   printf("\n\nConverted Number = ");
   for(  ; index>=0; index--) /* go backward through array */
   {
	 printf("%c", base_digits[converted_number[index]]);
   }
   printf("\n");
}
