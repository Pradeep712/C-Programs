//only3charfromastring
#include<stdio.h>
int main()
{

int i=0,j;
char a[] = "elephants";
i= (sizeof(a)-1);
if( (i % 3) != 0)
{
printf("%s \n",a);
return 0;
}
for(j=2;j<i;j=j+3)
printf("%c ",a[j]);

printf("\n");

return 0;
}
