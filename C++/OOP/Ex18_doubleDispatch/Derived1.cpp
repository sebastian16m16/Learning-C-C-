
#include "base.h"
#include "Derived1.h"
#include "Derived2.h"


Derived1::Derived1(int x, int y) : Base(x), y{y}{}
Derived1::~Derived1(){}
bool Derived1::operator>(const Base &o) const  { return y > o.getx(); }
bool Derived1::operator>(const Derived1 &o) const  { return y > o.y; }
bool Derived1::operator>(const Derived2 &o) const  { return y > o.getz(); }
int Derived1::gety() const { return y; }
