#include <iostream>
#include <list>

using namespace std;

template<typename T>
class AList : list
{
private:
    T value;
    AList next;
public:
    AList(T value):
    value{value}{}

    AList(){}
    ~AList(){}

    virtual void remove(T value){
        AList temp = this;
        AList prev = NULL;

        while(temp != NULL){
            if(temp.value == this->value)
                break;
            prev = temp;
            temp = temp.next;
        }
        prev.next = temp.next;
        free(temp);
    }
};

class B{
    public:
        int x;
        B(){}
        ~B(){}
};



int main(){

    AList<B> lista;

    return 0;
}