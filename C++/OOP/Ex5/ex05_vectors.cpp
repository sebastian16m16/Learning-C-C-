#include <iostream>
#include <string>
#include <vector>
#include <thread>

using namespace std;

template<typename T>
void show_info(vector<T> &v){

    cout<< "Capacity: " << v.capacity() << endl;
    cout<< "Size: " << v.size() << endl;

    for(auto i : v)
        cout << i << " ";
    cout << endl;
}

void f(){
    cout << "CUCU BAU" << endl;
}

int main(){

    vector<int> v { 3 ,4 ,1 ,2 };
    v.push_back(4);

    vector<int> v2{1, 2, 3, 4, 5};
    v.insert(v.end(), v2.begin(), v2.end());


    show_info(v);

    vector<int> v3{10, 2};
    vector<string> v4{10, "2"};

    vector<thread> workers;
    workers.emplace_back(thread{f});

    for(auto &w : workers)
        if(w.joinable())
            w.join();

    v4.resize(20);
    show_info(v4);

    // auto i = v4.find("2");

    // if(i!=v4.end())
    //     cout << *i << endl;
    v3.resize(100);
    show_info(v3);

    v3.swap(v);
    show_info(v3);
    

    return 0;
}