// operator new example
#include<iostream>
#include <new>
using namespace std;
struct myclass {myclass() {cout <<"myclass constructed\n";}};
int main () {
int * p1 = new int; // same as: int * p1 = (int*) operator new (sizeof(int));
int * p2 = new (nothrow) int; // same as: int * p2 = (int*) operator new (sizeof(int),nothrow);
myclass * p3 = (myclass*) operator new (sizeof(myclass));
// (!) not the same as: myclass * p3 = new myclass;
// (constructor not called by function call, even for non-POD types)
new (p3) myclass; // calls constructor
// same as: operator new (sizeof(myclass),p3)
return 0;
}