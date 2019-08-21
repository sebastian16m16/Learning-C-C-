#include <iostream>

using namespace std;

class A{
    public:
        A(){cout << "A()\n";}
        ~A(){cout << "~A()\n";}
        A(const A &a) {cout << "Copy()\n";}
        A &operator = (const A &a){ cout << "Op = \n"; return *this; }

};

class NonCopyable{
    public:
        NonCopyable(){cout << "NonCopyable()\n";}
        ~NonCopyable(){cout << "~NonCopyable()\n";}
        NonCopyable(const NonCopyable &a) = delete;
        NonCopyable &operator = (const NonCopyable &a)= delete;

};

int main(){
    
    A a1{}; // e apelat destructorul pentru ca e alocat pe stack

    A *a2 = new A{}; // nu e apelat destructorul pentru ca nu e sters (e pe heap)
    delete a2;

    A a3{a1}; // e apelat copy constructor

    A a4{};
    a3 = a4; // assignment opperator

    NonCopyable n1;
    
    //doesn't compile
    //NonCopyable n2{n1};

    //NonCopyable n2;
    //doesn't compile
    //n2 = n1;

    return 0;
}