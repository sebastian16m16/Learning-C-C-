#include "stdafx.h"
#include <iostream>

using namespace std;

class Node2D
{
public:
	virtual void draw() = 0;
};

class TextField : public Node2D
{
public:
	TextField(int w, int h) : m_width(w), m_height(h) { }

	virtual void draw()
	{
		cout << "TextField: " << m_width << ", " << m_height << '\n';
	}

private:
	int m_width{}, m_height{};
};

int main()
{

	getchar();
	return 0;
}
