//se citesc din students.txt
//E -> Elev
//S -> Student
//P -> Profesor

// ex: E Ion Anton M 80 15 7 8 9 10 7
//   status--Nume -- sex -- greutate -- varsta -- note...


//operatii posibile:
    //-aflarea notei maxime pentru un student oarecare show S
    //-afisarea celor mai buni studenti (media): best
    //-afisarea mediei generale (toti studentii)
    //-end => iesire din program


#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <fstream>
#include <functional>

using namespace std;

enum class SEX {F, M};

// istream &operator>>(istream &in, SEX &s){
//     string v;
//     in >> v;

//     if(v == "M") 
//         s = SEX::M;
//     else 
//         s = SEX::F;
    
//     return in;
// }

SEX to_sex(const string &s){
    if(s == "M")
        return SEX::M;
    else 
        return SEX::F;
}

class Person{
    protected:
        string first_name{};
        string last_name{};
        unsigned age{};
        unsigned weight{};
        SEX sex {SEX::F};
    
    public:
        Person(string fn, string ln, unsigned age, unsigned weight, SEX sex):
            first_name{fn},
            last_name{ln},
            age{age},
            weight{weight},
            sex{sex}
            {  }
        Person(){}

        friend istream &operator>>(istream &in, Person &p){
            in >> p.first_name >> p.last_name >> p.age >> p.weight;
            string v;
            in >> v;
            p.sex = to_sex(v);
            
            return in;
        }

        friend ostream &operator<<(ostream &out, Person &p){

            out << p.str();

            return out;
        }

        string full_name() const { return first_name + " " + last_name; }

        virtual ~Person(){}

        virtual string str() const{
            stringstream ss;
            ss << first_name << " " << last_name << ". age: " << age << ". sex: "
            << [this](){return sex == SEX::M ? 'M' : 'F';}() << ". weight: " << weight;

            return ss.str();
        }
};

class Student : public Person{
    protected:
        vector<unsigned> marks;

    public:
        Student(string fn, string ln, unsigned age, unsigned weight, SEX sex, vector<unsigned> &marks):
            Person(fn, ln, age, weight, sex),
            marks{marks}
            {  }

        Student(){}
        virtual ~Student(){}

        virtual string str() const override{
            stringstream ss;
            ss << Person::str() << ". Marks: ";
            for(auto mark : marks){
                ss << mark << " ";
            }

            return ss.str();
        }

        friend istream &operator>>(istream &in, Student &p){
            in >> p.first_name >> p.last_name >> p.age >> p.weight;
            string v;
            in >> v;
            p.sex = to_sex(v);
            if(in){
                unsigned mark;

                while(in >> mark) {
                    p.marks.push_back(mark);
                }
            }
            return in;
        }
};

class Retired : public Person{
    protected:
        unsigned pension;
    
    public:
        Retired(string fn, string ln, unsigned age, unsigned weight, SEX sex, unsigned pension) :
            Person(fn, ln, age, weight, sex),
            pension{pension}
            {  }
        Retired(){}

        friend istream &operator>>(istream &in, Retired &p){
            in >> p.first_name >> p.last_name >> p.age >> p.weight;
            string v;
            in >> v;
            p.sex = to_sex(v);
            return in >> p.pension;
        }

        virtual ~Retired() {}
        virtual string str() const override{
            return Person::str() + ". pension: " + to_string(pension);
        }
};

class Worker : public Person{
    protected:
        unsigned salary{};

    public:
        Worker(string fn, string ln, unsigned age, unsigned weight, SEX sex, unsigned salary) :
            Person(fn, ln, age, weight, sex),
            salary{salary}{  }
        Worker(){}

        virtual string str() const override{
            return Person::str() + ". salary:" + to_string(salary);
        }

        friend istream &operator>>(istream &in, Worker &p){
            in >> p.first_name >> p.last_name >> p.age >> p.weight;
            string v;
            in >> v;
            p.sex = to_sex(v);

            

            return in >> p.salary;
        }

        virtual ~Worker(){}
    
};

void process_commands(map<string, vector<Person*>> &people){
    
    string line;

    map<string, function<void(void)>> commands {
        {"show", [&](){ for(auto p : people["S"]) cout << *p << endl; }},
        {"best", [&](){ for(auto p : people["S"]) cout << *p << endl; }}
    };
    
    while(true){
        cout << "Command: ";
        getline(cin, line);
        istringstream ss{line};
        string cmd;
        ss >> cmd;

        if(cmd == "end") break;
        
        auto it = commands.find(cmd);
        
        if(it != commands.end())
            it->second();
        else
            cout << "Unknown command!\n";
    }
}

int main(){

    const string fname{"people.txt"};
    ifstream f{fname};
    if(!f.is_open()) {
        cerr << "Cannot open file" << endl;
        return -1;
    }

    // map<string, void (*)(Person&, const istream&)> factories{
    //     {"S", [](Student &s, const istream &is ){ is >> s; }},
    //     {"P", [](Retired &r, const istream &is){ is >> r; }},
    //     {"M", [](Worker &w, const istream &is){ is >> w; }},
    //     {"O", [](Person &p, const istream &is){ is >> p; }}
    // };


    map<string, vector<Person*>> people;
    

    string line;

    while( getline(f, line) ){
        istringstream ss{line};
        string type;
        ss >> type;
    

        if(type == "S"){
            Student *s = new Student{};
            ss >> *s;
            people["S"].push_back(s);
        }else if(type == "P"){
            Retired *r = new Retired{};
            ss >> *r;
            people["P"].push_back(r);
        }else if(type == "M"){
            Worker *w = new Worker{};
            ss >> *w;
            people["M"].push_back(w);
        }else if(type == "O"){
            Person *p = new Person{};
            ss >> *p;
            people["O"].push_back(p);
        }
        // cout << type << ": " << line << endl;

       // process_commands(people);
    }
        for(auto it = people.begin(); it != people.end(); it++){
            for(auto p : it->second){
                cout << *p << endl;
            }
        }

        //free resources
        for(auto it = people.begin(); it != people.end(); it++){
            for(auto p : it->second){
                delete p;
            }
        }
    

    return 0;
}