//Selection sort
#include<stdio.h>
#include<conio.h>
int main()
{
 int arr[20], n, i, j, pos, temp;
 printf("Enter number of elements (max 20): ");
 scanf("%d", &n);
 for(i=0;i<n;i++){
 printf("Enter no %d: ", i+1);
 scanf("%d",(arr+i)); //(arr+i) is the pointer to the individual elements of the array
 }
 for (i=0;i<(n-1);i++){ //selection sorting is done
 pos=i;
 for (j=i+1;j<n;j++ ){  if (*(arr+pos)> *(arr+j)) //checks if arr[pos] is greater than arr[j]
 pos=j;
 }
 if ( pos!=i ){ //if value of pos changes the swapping is done
 temp= *(arr+i);
 *(arr+i)= *(arr+pos);
 *(arr+pos)= temp;
 }
 }
 printf("Sorted list in ascending order:\n");
 for(i=0;i<n;i++)
 printf("%d ", *(arr+i));
 getch();
 return 0;
}
