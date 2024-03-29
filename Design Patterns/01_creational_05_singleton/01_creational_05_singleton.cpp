#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <mutex>

using namespace std;

class Widget
{
public:
	friend ostream &operator<<(ostream &out, const Widget &w);

private:
	string m_name{};
	int m_x, m_y;

};


ostream &operator<<(ostream &out, const Widget &w)
{
	out << w.m_name << ", x=" << w.m_x << ", y=" << w.m_y;
	return out;
}


class WidgetDoubleChecked
{
public:
	friend ostream &operator<<(ostream &out, const WidgetDoubleChecked &w);

private:
	string m_name{};
	int m_x, m_y;

};

ostream &operator<<(ostream &out, const WidgetDoubleChecked &w)
{
	out << w.m_name << ", x=" << w.m_x << ", y=" << w.m_y;
	return out;
}


int main()
{
	vector<thread> workers{};
	for (auto& w : workers)
		if (w.joinable())
			w.join();

	getchar();
	return 0;
}
