#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <initializer_list>

using namespace std;

template<typename T>
class my_collection{
    private:
        vector<T> v;
    
    public:
        my_collection(initializer_list<T> l)
        { 
            for(auto t : l)
                v.push_back(t);
        }

        friend ostream &operator<<(ostream &out, const my_collection &c){
            for(auto e : c.v){
                out << e << " ";
            }
            return out;
        }

};


int main(){

    vector<string> names{"Anaa", "Maria", "Ioana"};

    for(auto n : names)
        cout << n << " ";
    cout << endl;

    my_collection<string> objects{"dulap", "masa", "clasa"};

    cout << objects << endl;

    map<string, int> m {
        {"Ioana", 4},
        {"Valer", 44},
        {"Zacusca", 32}
    };

    return 0;
}