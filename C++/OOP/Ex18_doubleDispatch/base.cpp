#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "base.h"


Base::Base(int x) : x{x} {}
Base::~Base(){}
bool Base::operator>(const Base &o) const { return x > o.x; }
bool Base::operator>(const Derived1 &o) const { return x > o.gety(); }
bool Base::bool operator>(const Derived2 &o) const { return x > o.getz(); }
int Base::int getx() const { return x; }

