 #include<iostream>

using namespace std;

class Num
{
    public:
    static int i;
    Num()
    {
        cout<<i++<<" ";
    }
};

int Num::i=1;

int main()
{
    int n;
    cout<<"Enter value on n:";
    cin>>n;
    Num obj[n];
    return 0;
}

/*In this program we are using the concept of static data member and array of objects. Class Num contains a static variable i whose value will remain till the program terminates. We are creating an array of objects of class Num. In this program we are creating n objects, value of n depends on input we give. The default constructor is called for all objects one by one. In the constructor the value of i is printed and is incremented by one in each call. In this way numbers from 1 to n are printed.*/

