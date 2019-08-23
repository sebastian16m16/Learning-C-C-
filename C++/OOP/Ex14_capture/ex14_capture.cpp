#include <iostream>
#include <string>

using namespace std;

class Test{
    public:
        void run(){
            int c{3}, d{4};
            auto print{[this, c, d](){
                cout << a << b << c << d << endl;
            }};
            print();
        }
    private:
        int a{1};
        int b{2};
};

int main(){

    int a{10};

    auto l {[a](){cout << a << endl;}};
    l();

    [&a](){a +=10; cout << a << endl;}();

    int b{20}, c{30};

    [=](){ cout << a << b << c << endl; }(); //[=] -> ia toate variabilele declarate in mediu ca valoare (Nu pot fi modificate)
    [&](){ cout << ++a << ++b + ++c << endl; }(); //[&] --> ia toate variabilele declarate in mediu cu ampersant (pot fi modificate)
    [=, &c](){ cout << a << b << ++c << endl; }(); //[=, &c] --> ia toate variabilele ca si valoare, mai putin variabila c
    [&, c](){ cout << ++a << ++b << c << endl; }();//[&, c] --> ia toate variabilele cu ampersant, mai putin c

    return 0;
}