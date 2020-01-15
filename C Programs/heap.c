/*
This is a simple program for heap sort. Its performance is O(n log(n)). 
Heap sort :
The heapsort algorithm can be divided into two parts.
In the first step, a heap is built out of the data.
In the second step, a sorted array is created by repeatedly removing the largest element from the heap, and inserting it into the array. The heap is reconstructed after each removal. Once all objects have been removed from the heap, we have a sorted array. The direction of the sorted elements can be varied by choosing a min-heap or max-heap in step one.
Heapsort can be performed in place. The array can be split into two parts, the sorted array and the heap. The heap's invariant is preserved after each extraction, so the only cost is that of extraction.


Major functions : 
                         heapify : This function establishes the heap property by building a heap from the bottom up,                                        successively shifting downward.
                         heapsort : This function sorts the heap by calling heapify to maintain heap property.
*/
#include<stdio.h>
 
void heapify(int a[],int i,int n)
{
int largest;
int left=(2*i)+1;
int right=(2*i)+2;
if(left<n && a[left]>a[i])
{
largest=left;
}
else
{
largest=i;
}
if(right<n && a[right]>a[largest])
{
largest=right;
}
if(largest!=i)
{
int temp=a[i];
a[i]=a[largest];
a[largest]=temp;
heapify(a,largest,n);
}
}
 
void hsort(int a[],int n)
{
int i;
for(i=n-1;i>=1;i--)
{
int temp=a[i];
a[i]=a[0];
a[0]=temp;
n=n-1;
heapify(a,0,n);
}
}
 
void main()
{
int i;
printf("Enter n ");
int n;
scanf("%d",&n);
int a[n];
printf("Enter elements\n");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
printf("Before heapification\n");
for(i=0;i<n;i++)
{
printf("%d ",a[i]);
}
printf(" ");
for(i=(n-1)/2;i>=0;i--)
{
heapify(a,i,n);
}
printf("\nAfter heapification\n");
for(i=0;i<n;i++)
{
printf("%d ",a[i]);
}
hsort(a,n);
printf("\nAfter heap sort\n");
for(i=0;i<n;i++)
{
printf("%d ",a[i]);
}
printf(" ");
}
