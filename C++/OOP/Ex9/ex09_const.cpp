#include <iostream>
#include <string>

using namespace std;


class A{
    private:
        int x{};
    public:
        A(int x):x{x}{}

        void show() const {cout << x << endl;}
        void set_x(int x) {/* this->x = x;*/ }
};

void f(const A &a, int x){
    //won't compile
   // a.set_x(x); //atata timp cat argumentul e declarat cu const, nu e voie sa se apeleze functii declarate fara "const"
}


//nu va compila pentru nu se poate pune const decat pe functii ale clasei:D
//      |
//      |
//     \|/
// void g() const{

// }


int main()
{
    
    A a{10};
    a.show();

    f(a, 20);
    a.show();

    return 0;
}