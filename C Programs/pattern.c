/* Print the pattern
A B C D E D C B A
  A B C D C B A
    A B C B A
      A B A
        A

And here is the code.
*/

//Printing pattern
#include<stdio.h>
#include<conio.h>
int main(){
 int n,i,j;
 printf("Enter no of lines: ");
 scanf("%d",&n);
 for(i=0;i<n;i++){
 for(j=0;j<i;j++){ //for printing spaces
 printf(" ");
 }
 for(j=0;j<n-i;j++){ //for printing the left side
  printf("%c ",'A'+j); //the value of j is added to 'A'(ascii value=65)
  }
  for(j=n-i-2;j>=0;j--){ //for printing the right side
    printf("%c ",'A'+j);
  }
 printf("\n");
 }
 getch();
}

