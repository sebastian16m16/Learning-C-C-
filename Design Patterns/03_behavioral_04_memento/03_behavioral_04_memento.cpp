#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Notepad
{
private:
	vector<string> m_lines{};
public:
	Notepad& addLine(string line)
	{
		m_lines.push_back(line);
		return *this;
	}

	friend ostream& operator<<(ostream& out, const Notepad& n);
};


ostream& operator<<(ostream& out, const Notepad& n)
{
	stringstream ss;
	for (auto line : n.m_lines)
		ss << line << "\n";
	out << ss.str();
	return out;
}



int main()
{

	getchar();
	return 0;
}
