#include <iostream>
#include <map>
#include <vector>
#include <initializer_list>
#include <sstream>

using namespace std;

double add(vector<double> &v){
        
        double sum{} ;

        for(auto e : v)
            sum += e;
        return sum;

        //return accumulate(v.begin(), v.end(), 0);   //include <algorithm>
}

double sub(vector<double> &v){
    
    if(v.size() == 0) return 0;
    double dif = 2 * v.at(0);

    for(auto e : v)
        dif -= e;
    
    return dif;
}

double div(vector<double> &v){
    double res = v[0] * v[0];

    if(res == 0)
        return 0;
    else{
        for(auto e : v){
            if(e == 0)
                return 0;
            res /= e;
        }
        return res;
    }
    return 0;
}

double mul(vector<double> &v){
    double res = 1;

    for(auto e : v)
        res *=e;
    return res;
}

int main(){

    vector<double> operands{};
    map<string, double(*)(vector<double>&)> operations{};
    operations["add"] = add;
    operations["sub"] = sub;
    operations["div"] = div;
    operations["mul"] = mul;

    while(true){
        cout << "Expression: ";

        operands.clear();
        string line;
        getline(cin, line);
        if(line == "end")
            break;
        istringstream is{line};
        string cmd;
        is >> cmd;
        double op;
        while(is >> op)
            operands.push_back(op);
        cout << "Cmd = " << cmd << endl;

        auto f {operations.find(cmd)};
        if(f != operations.end())
            cout << "Result: " << f->second(operands) << endl;
        else 
            cout << "Unknown operation\n";

    }


    return 0;
}