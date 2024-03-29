#include "stdafx.h"
#include <iostream>

using namespace std;

class AmericanPlug;
class AmericanSocket;
class AmericanSocket;

class AmericanPlug
{
public:
	void plug(AmericanSocket& socket);
};

class AmericanSocket
{
public:
	void accept(AmericanPlug& plug);
};

void AmericanPlug::plug(AmericanSocket& socket)
{
	socket.accept(*this);
}

void AmericanSocket::accept(AmericanPlug& plug)
{
	cout << "American plug inserted" << endl;
}

class AmericanSmartPhone
{
public:
	AmericanSmartPhone(string name) : m_name(name) {}

	void charge(AmericanSocket &socket)
	{
		socket.accept(m_plug);
	}

	friend ostream &operator<<(ostream& out, const AmericanSmartPhone &s);
private:
	string m_name{};
	AmericanPlug m_plug{};
};

ostream &operator<<(ostream &out, const AmericanSmartPhone &s)
{
	out << s.m_name;
	return out;
}



int main()
{

	getchar();
	return 0;
}
