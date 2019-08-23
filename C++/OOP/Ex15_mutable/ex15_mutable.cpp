#include <iostream>
#include <string>

using namespace std;

void unmutable(){
    cout << "Unmutable begin\n";
    auto a{10};

    auto l{ [=](){ cout << "Internal scope: " << a << endl; } };

    a += 10;
    cout << "External scope: " << a << endl;
    l();

    a += 10;
    cout << "External scope: " << a << endl;
    l();

    cout << "Unmutable end\n";
}

void test_mutable(){
    cout << "Mutable begin\n";
    auto a{10};

    auto l{ [=]() mutable{ 
        
        a+=3; 
        static int b{20};
        b+=10;
        cout << "Internal scope: " << a << endl;
        cout << "b mic = " << b << endl;
    } };

    a += 10;
    cout << "External scope: " << a << endl;
    l();

    a += 10;
    cout << "External scope: " << a << endl;
    l();

    cout << "Mutable end\n";
}

int main(){

    unmutable();
    test_mutable();

    return 0;
}