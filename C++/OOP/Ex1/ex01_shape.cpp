#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

class A {};

class B : public A
{
public:
    B() {}
};

class Shape  // abstract
{
public:
    Shape(int x, int y, string name):
        x{x}, y{y}, name{name}
    {}

    Shape(const Shape &o):  // copy ctor
        x{o.x}, y{o.y}, name{o.name}
    {
        cout << "shape::copy()" << endl;
    }

    virtual ~Shape() {}
    virtual double area() const = 0;
    virtual double perimeter() const = 0;

    virtual int get_x() const { return x; }
    virtual int get_y() const { return y; }
    virtual void set_x(int x) { this->x = x; }
    virtual void set_y(int y) { this->y = y; }
    virtual string get_name() const { return name; }

    virtual string str() const
    {
        
        stringstream ss;
        ss << name << "(" << x << "," << y << ")";
        ss << ". area = " << area();
        ss << ". perimeter = " << perimeter();
        return ss.str();
    }

    friend ostream &operator<<(ostream &out, const Shape &s);

protected:
    int x{};
    int y{};
    string name{};
};

class Rectangle : public Shape
{
    public:
        Rectangle(int x, int y, int w, int h) :
            Shape(x, y, "rectangle"),
            w{w}, h{h}
            {}
            virtual ~Rectangle() = default;
            Rectangle(const Rectangle &o) = default;
            virtual double area() const override {return w * h;}
            virtual double perimeter() const override {return 2 * (w + h);}

            virtual string str() const override{
                stringstream ss;
                ss << Shape::str() << ". W = " << w << ", h = " << h;
                return ss.str();
            }
    protected:
        int w{};
        int h{};
};

class Square : public Rectangle
{
    public:
        Square(int x, int y, int l) : Rectangle(x, y, l, l){
            name = "square";
        }

        virtual ~Square(){}
        virtual string str() const override{
            stringstream ss;
            ss << Shape::str() << ". l = " << w;
            return ss.str();
        }
};

ostream &operator<<(ostream &out, const Shape &s)
{
    out << s.str();
    return out;
}

class Circle : public Shape
{
public:
    Circle(int x, int y, int radius) :
        Shape(x, y, "circle"),
        radius{radius}
    {}
    virtual ~Circle() {}
    virtual double area() const override
    {
        return acos(-1) * radius * radius;
    }
    virtual double perimeter() const override
    {
        return acos(-1) * radius * 2;
    }

    virtual string str() const override
    {
        stringstream ss;
        ss << Shape::str() << ". radius: " << radius;
        return ss.str();
    }

protected:
    int radius;
};

// cannot derive final class
// class SquareReinvented : public Square{};

int main()
{
    Circle c{10, 20, 10};
    cout << c << endl;

    Shape &s{c};
    cout << s << endl;

    vector<Shape*> shapes{
        new Circle{10, 20, 20}, new Circle{10, 10, 10},
        new Circle{10, 20, 30}, new Rectangle{10, 10, 20, 30},
        new Rectangle{20, 30, 20, 20}, new Square(10, 10, 20),
        new Square(10, 30, 50)
     };

    for (auto shape : shapes)
        cout << *shape << endl;

    for (auto s : shapes)
        delete s;

    return 0;
}
