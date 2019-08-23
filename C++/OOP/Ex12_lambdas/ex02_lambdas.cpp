#include <iostream>
#include <string>

using namespace std;

string process(const string &text, string(*op)(const string &s)){
    cout << "Processing " << text << "...." << endl;
    return op(text);
}


int main(){
    cout << [](){return "Hello from lambda!\n"; }();
    cout << [](const string &name){return "Hello " + name;}("Ion\n");

    cout << process("text", [](const string &s) { return "_prefix " + s; }) << endl;

    
}