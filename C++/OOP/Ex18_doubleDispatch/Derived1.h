#pragma once
#include "base.h"

class Derived1 : public Base
{
    protected:
        int y{};

    public:

        Derived1(int x, int y) : Base(x), y{y}{}
        virtual ~Derived1(){}
        virtual bool operator>(const Base &o) const override ;
        virtual bool operator>(const Derived1 &o) const override ;
        virtual bool operator>(const Derived2 &o) const override ;
        virtual int gety() const ;
};
