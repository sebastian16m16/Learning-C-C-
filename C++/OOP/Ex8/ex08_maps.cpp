#include <iostream>
#include <map>
#include <string>

using namespace std;




int main(){

    map<string, int> ages{
        {"Ion", 14},
        {"Vasile", 20},
        {"Maria", 25}
    };

    cout << ages["Maria"] << endl;
    ages.insert(make_pair("Ioana", 30));
    ages["Vasilica"] = 22;

    cout << ages.at("Vasile") << endl;

    for(auto it = ages.begin(); it != ages.end(); ++it){
        cout << "Key = " << it->first << ", Age = " << it->second << endl;
    }

    ages["Vasilica"] ++;
    cout << ages["Vasilica"] << endl;
    ages.insert(make_pair("Vasilica", 50));
    cout << ages["Vasilica"] << endl;



    return 0;
}