#include <iostream>
#include <string>


using namespace std;

class TextOperation{
    public:
        virtual string operator()(string &input) = 0;
        virtual ~TextOperation(){}
};

class Append : public TextOperation{
    public:
        Append(const string &suffix) : suffix{suffix}{}
        virtual string operator()(string &input) override{
            return input + suffix;
        }

    private:
        string suffix{};
};

class Prepend : public TextOperation{
    public:
        Prepend(const string &prefix) : prefix{prefix}{}
        virtual string operator()(string &input) override{
            return prefix + input;
        }

    private:
        string prefix{};
};

string process(string &text, TextOperation &operation){
    return operation(text);
}

class A{
    public:
        A(){}
        A(const A &o){}
};
A getA() {return A();}

void lrvalues(){
    int i = 10;

    int &j = i;

    A a = getA();
    const A &ra = getA();

}


int main(){

    Append append{"_SUFFIX_"};
    Prepend prepend {"_PREFIX_"};
    cout << "Enter text: ";
    string text;
    cin >> text;
    cout << process(text, append) << endl;
    cout << process(text, prepend) << endl;


    return 0;
}