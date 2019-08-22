#include <iostream>
#include <string>

using namespace std;

class Person{
    private:
        int age;
        string name;
        static const int MAX_AGE;
    public:

        static int get_max_age(){ return MAX_AGE; } //functiile si atributele statice apartin clasei si nu e specific obiectului
                                                    // nu se pot accesa membrii non-statici in interiorul unei functii statice:D (eroare de compilare)
        Person(string name, int age) :
            name{name},
            age{age}
            {  }
        ~Person(){}

        int get_age() const {return age;}
};

const int Person::MAX_AGE = 255;

int main()
{
    cout << Person::get_max_age() << endl;

    Person p{"Ion", 20};
    cout << p.get_max_age() << endl;

    return 0;
}