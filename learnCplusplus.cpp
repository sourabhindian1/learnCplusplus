/*
 * PROBLEM: Deleting a Derived class object using a pointer of
 * Base class type that has a non-virtual destructor results in
 * undefined behavior (Derived class destructor is not called)
 * 
 * SOLUTION: Base class should be defined with a virtual destructor
 * Making base class destructor virtual guarantees that the object
 * of derived class is destructed properly, i.e., both base class 
 * and derived class destructors are called. 
 * 
 * NOTE: Any time you have a virtual function in a class, you should
 * immediately add a virtual destructor (even if it does nothing)
*/

#include <iostream>

using namespace std;

class Base {
public:
    Base() { cout << "Base class Constructor\n"; }
    virtual ~Base() { cout << "Base class Destructor\n"; }
};

class Derived: public Base {
public:
    Derived() { cout << "Derived class Constructor\n"; }
    ~Derived() { cout << "Derived class Destructor\n"; }
};

int main()
{
    // Dervied class object is assigned to Base class pointer
    Base* b = new Derived;
    delete b;
    return 0;
}
