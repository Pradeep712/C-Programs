/*What is Object Slicing in C++?

In C++, a derived class object can be assigned to a base class object, but reverse is not possible. Object slicing happens when a derived class object is assigned to a base class object, additional attributes of a derived class object are sliced off to form the base class object.

Take below example:*/

class Base
{
int a, b;
};

class Derived : public Base
{
int x,y;
};

int main()
{
Derived d;
Base b = d; //x and y of d are sliced off
}

/*Object slicing can be prevented by making the base class function pure virtual, this does not allow object creation.*/