#include <iostream>
#include <map>
#include <string>

using namespace std;


class Person{
    private:
        string first_name;
        string last_name;
        int height;
    
    public:
        Person(string fn, string ln, int height):
        first_name{fn},
        last_name{ln},
        height{height}
        {  }

        Person(){}

        friend ostream &operator<<(ostream &out, const Person &p){
            out << p.first_name << " " << p.last_name << ": " << p.height;
            return out;
        }

        bool operator<(const Person &o)noexcept{
            return last_name > o.last_name;
        }

        friend bool operator<(const Person &p1, const Person &p2)noexcept{
            return p1.last_name > p2.last_name;
        }

        bool operator==(const Person &o)const{
            return last_name == o.last_name;
        }

        bool operator>(const Person &o)const{
            return last_name > o.last_name;
        }

        


};


int main(){

    map<int, Person> people {
        {10, Person{"Ion", "Ionescu", 185}},
        {20, Person{"Maria", "Marinescu", 168}},
        {30, Person{"Mirela", "Memorandum", 180}}
    };

    cout << people[20] << endl;

    map<Person, int> weights {
        {Person{"Ion", "Ionescu", 185}, 10},
        {Person{"Maria", "Marinescu", 168}, 20},
        {Person{"Mirela", "Memorandum", 180}, 30}  
    };

    return 0;
}