#pragma once
#include "base.h"
#include "Derived1.h"



class Derived2 : public Base
{
    protected:
        int z{};

    public:

        Derived2(int x, int z);

        virtual ~Derived2(){}
        virtual bool operator>(const Base &o) const override;
        virtual bool operator>(const Derived1 &o) const override;
        virtual bool operator>(const Derived2 &o) const override;

        virtual int getz() const;


};
