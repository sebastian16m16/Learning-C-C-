#include "Derived1.h"
#include "Derived2.h"
#include "base.h"


Derived2::Derived2(int x, int z) : Base(x), z{z}{}

Derived2::~Derived2(){}
bool Derived2::operator>(const Base &o) const  { return z > o.getx(); }
bool Derived2::operator>(const Derived1 &o) const  { return z > o.gety(); }
bool Derived2::operator>(const Derived2 &o) const  { return z > o.z; }
int Derived2::getz() const { return z; }


