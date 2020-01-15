//Removing the duplicates from an array
#include<stdio.h>
#include<conio.h>
int main()
{
	int a[100],i,j,k,b,t=0;
	printf("\nEnter the size of 1 dimensional array");
	scanf("%d",&b);
	printf("\nEnter the array");
	for(i=0;i scanf("%d",&a[i]);
	for(i=0;i {
	for(j=i+1;j {
		if(a[i]==a[j])
		{
			t++;
			for(k=j;k a[k]=a[k+1];
		}
	}
}
for(i=0;i<=b-t;i++)
printf("\n%d",a[i]);
system("pause");
return 0;
}