#include "stdafx.h"
#include <iostream>
#include <string>

#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

class CartesianPoint2D
{
private:
	double m_x, m_y;
public:
	CartesianPoint2D(double x, double y) : m_x(x), m_y(y) {}

	void move(int dx, int dy)
	{
		m_x += dx;
		m_y += dy;
	}
	double getX() const { return m_x; }
	double getY() const { return m_y;	}
	friend ostream& operator<<(ostream& out, const CartesianPoint2D& p);
};

ostream& operator<<(ostream& out, const CartesianPoint2D& p)
{
	out << "(" << to_string(p.m_x) << ", " << to_string(p.m_y) << ")";
	return out;
}

class PolarPoint2D
{
private:
	double m_radius, m_angle;
public:
	PolarPoint2D(double radius, double angle) : m_radius(radius), m_angle(angle) {}

	void rotate(int ang) {
		m_angle += ang % 360;
	}

	double getRadius() const { return m_radius; }
	double getAngle()  const { return m_angle; }

	friend ostream& operator<<(ostream& out, const PolarPoint2D& p);
};

ostream& operator<<(ostream& out, const PolarPoint2D& p)
{
	out << "(" << to_string(p.m_radius) << " @ " << to_string(p.m_angle) << ")";
	return out;
}


class CoordUtils
{
public:
	static CartesianPoint2D polarToCartesian(PolarPoint2D pp)
	{
		const double angleRad = pp.getAngle() * M_PI / 180.0;
		const double radius = pp.getRadius();
		double x = cos(angleRad) * radius;
		double y = sin(angleRad) * radius;
		return CartesianPoint2D(x, y);
	}

	static PolarPoint2D cartesianToPolar(CartesianPoint2D pc)
	{
		double x = pc.getX();
		double y = pc.getY();
		double radius = sqrt(x * x + y * y);
		double angleRad = atan2(y, x) * 180 / M_PI;
		return PolarPoint2D(radius, angleRad);
	}
};



int main()
{

	getchar();
	return 0;
}
