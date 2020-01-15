//armstrong no - eg. 371

#include <stdio.h>
 
int main()
{
   int number, sum = 0, temp, remainder;
 
   printf("Enter an integer\n");
   scanf("%d",&number);
 
   temp = number;
 
   while( temp != 0 )
   {
      remainder = temp%10;
      sum = sum + remainder*remainder*remainder;
      temp = temp/10;
   }
 
   if ( number == sum )
      printf("Entered number is an armstrong number.\n");
   else
      printf("Entered number is not an armstrong number.\n");
 
   return 0;
}