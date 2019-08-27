#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Derived1;
class Derived2;

class Base
{

    protected:
        int x{};

    public:

        Base(int x) : x{x} {}
        virtual ~Base(){}
        virtual bool operator>(const Base &o) const { return x > o.x; }
        virtual bool operator>(const Derived1 &o) const { return x > o.gety(); }
        virtual bool operator>(const Derived2 &o) const { return x > o.getz(); }
        virtual int getx() const { return x; }


};


class Derived1 : public Base
{
    protected:
        int y{};

    public:

        Derived1(int x, int y) : Base(x), y{y}{}\
        virtual ~Derived1(){}
        virtual bool operator>(const Base &o) const override { return y > o.getx(); }
        virtual bool operator>(const Derived1 &o) const override { return y > o.y; }
        virtual bool operator>(const Derived2 &o) const override { return y > o.getz(); }
        virtual int gety() const { return y; }
};

class Derived2 : public Base
{
    protected:
        int z{};

    public:

        Derived2(int x, int z) : Base(x), z{z}{}

        virtual ~Derived2(){}
        virtual bool operator>(const Base &o) const override { return z > o.getx(); }
        virtual bool operator>(const Derived1 &o) const override { return z > o.gety(); }
        virtual bool operator>(const Derived2 &o) const override { return z > o.z; }

        virtual int getz() const { return z; }


};



int main(){


    return 0;
}