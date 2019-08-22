#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main()
{
    set<int> s{1, 2, 3, 4};

    for(auto e : s)
        cout << e << " ";
    cout << endl;

    vector<int> v {1 ,2 ,2 ,2 ,3 , 4, 5, 5, 5, 5};

    set<int> s2 {v.begin(), v.end()};

    for(auto e : s2)
        cout << e << " ";
    cout << endl;

    s2.insert(10);
    s2.insert(20);

    cout << s2.size() << endl;

    auto key {5};
    if(s2.find(key) != s2.end()){
        cout << "Found\n";
    }else
    {
        cout << "NOT Found\n";
    }

    

    

    return 0;
}