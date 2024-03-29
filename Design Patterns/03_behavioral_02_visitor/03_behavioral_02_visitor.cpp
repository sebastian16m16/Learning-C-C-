#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class Employee;
class Manager;
class Programmer;


class Employee
{
protected:
	string m_name;
	double m_salary;
public:
	Employee(string name, double salary) : m_name(name), m_salary(salary) {}

	string getName() const { return m_name; }
	double getSalary() const { return m_salary; }
};


class Manager : public Employee
{
public:
	Manager(string name, double salary) : Employee(name, salary) {}

};

class Programmer : public Employee
{
public:
	Programmer(string name, double salary) : Employee(name, salary) {}

};


int main()
{
	Manager alex{"Alex", 100};
	Programmer george{"George", 100 };

	getchar();
	return 0;
}
