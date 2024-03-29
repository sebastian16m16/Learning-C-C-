#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <chrono>

using namespace std;

class Sound {};

class Texture {};

class Node2D
{
public:
	Node2D(int x, int y, string name) :
		m_x(x),
		m_y(y),
		m_name(name)
	{}
	
	Node2D() = default;

	virtual void setX(const int x) { m_x = x; }
	virtual void setY(const int y) { m_y = y; }
	virtual void setName(const string name) { m_name = name; }

	friend ostream &operator<<(ostream& out, const Node2D& e);

protected:
	int m_x{};
	int m_y{};
	string m_name{};
};



ostream &operator<<(ostream& out, const Node2D& e)
{
	out << e.m_name << ": " << e.m_x << ", " << e.m_y;
	return out;
}


int main()
{

	getchar();
	return 0;
}
