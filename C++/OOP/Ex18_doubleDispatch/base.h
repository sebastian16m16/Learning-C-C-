#pragma once //include only once

#ifndef __BASE_H
#define __BASE_H
    class Base;
#endif

#include "Derived1.h"
#include "Derived2.h"

class Derived1;
class Derived2;

class Base
{

    protected:
        int x{};

    public:

        Base(int x) : x{x} {}
        virtual ~Base(){}
        virtual bool operator>(const Base &o);
        virtual bool operator>(const Derived1 &o);
        virtual bool operator>(const Derived2 &o);
        virtual int getx() const;


};

