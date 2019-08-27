#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>

using namespace std;

class Sample
{
public:

	friend ostream &operator<<(ostream& out, const Sample& s);

private:
	int m_i1{};
	int m_i2{};
	int m_i3{};
	int m_i4{};

};

ostream &operator<<(ostream& out, const Sample& s)
{
	out << "i1=" << s.m_i1 << ", i2=" << s.m_i2 << ", i3=" << s.m_i3 << ", i4=" << s.m_i4;
	return out;
}


int main()
{

	getchar();
	return 0;
}
