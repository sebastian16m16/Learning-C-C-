#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

class Student{
    public:
    Student(string studentName, double studentGrade) :
        name{studentName},
        grade{studentGrade}
        {cout << "Student " << name << " was created!" << endl;}
    Student(){}

    double getGrade(){
        return this->grade;
    }

    string getName(){
        return this->name;
    }

    private:
        string name{};
        double grade{};
};

void displayStudents(vector<Student> students){
    for(Student s : students)
    {
        cout<< "Name: " << s.getName() << " ----> Grade: " << s.getGrade() << endl;
    }
}


vector<Student> best2(vector<Student> students){
    
    vector<Student> best2S;
    
    Student s1 {};

    for(Student s : students){
        for(Student sn : students){
            if(s.getGrade() > sn.getGrade()){
                s1 = s;
            }else
            {
                s1 = sn;
            }
            
        }
        students.erase(remove(students.begin(), students.end(), s1), students.end());
        best2S.push_back(s1);
        if(best2S.size() == 2)
            break;
    }

    return best2S;
}

vector<Student> insertedStudents(string fileName){
    ifstream fp;
    fp.open(fileName);

    if (!fp) {
    cerr << "Unable to open file ";
    exit(1);   
    }
    int nr_students;
    fp >> nr_students;

    vector<Student> students;
    for(int i=0; i<nr_students; i++){
         string name;
        double grade;
        fp >> name >> grade;
        Student s {name, grade};
        students.push_back(s);
    }

   
    return students;
}


int main(){

    vector<Student> students = insertedStudents("studenti.txt");
    // int n;
    // string name;
    // double grade;

    // cout << "How many student do you want to enter? :";
    // cin >> n;
    // cout << endl;
    // for(int i=0; i<n; i++){

    //     cout << "Enter the name of the student: ";
    //     cin >> name;
    //     cout << endl;
    //     cout << "Enter the grade of the student: ";
    //     cin >> grade;
    //     cout << endl;

    //     Student s {name, grade};

    //     students.push_back(s);
    // }

    displayStudents(students);

    cout << "The best 2 students are: " << endl;

    //displayStudents(best2(students));

    return 0;
}
