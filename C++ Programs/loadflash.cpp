#?include<iostream>
#include<unistd.h>

using namespace std;

main()
{
int i;
for(i=0;i<=100;i++)
{
cout<<"Loading......."<<i<<"%\r";
usleep(100000);
}

return 0;
}
