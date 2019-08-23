#include <iostream>
#include <string>
#include <typeinfo>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
auto power(T t, unsigned p){
    T result = 1;

    while(p-- > 0) result *= t;

    return result;
}

struct{
        template<typename T>
        auto operator()(T a, T b) { return a + b; };
    } add_generic;

void how_lambda_works(){
    struct{
        int operator()(int a, int b) { return a + b; };
    }add;

    cout << add(10, 20) << endl;

    
}

int main(){

    how_lambda_works();

    auto pwr{[](auto a, unsigned p){ 
        auto result = 1;

        while( p-- > 0 )
            result *= a;

        return result;
     }};

    //trailing return syntax
    cout << [](auto a, auto b) -> decltype(a/b){ 
        if(b==0)
            return -1.0;
        return a/b;
     }(10, 20) << endl;

     [](int a){return a == 0 ? 1 : 1.0;}(0);

    cout << power(10,2) << endl;
    cout << power(20.3, 5) << endl;

    cout << pwr(10.23, 2) << endl;
    cout << pwr(10.23f, 3) << endl;

    cout << typeid(pwr).name() << endl;

    vector<int> v{2, 3, 4, 1, 3, 0, 7};
    sort(v.begin(), v.end(), [&](auto a, auto b){ return a > b; });

    for(auto e : v)
        cout << e << " ";
    cout << endl;

    return 0;
}