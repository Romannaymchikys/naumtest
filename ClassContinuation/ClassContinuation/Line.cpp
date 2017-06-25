#include "Line.h"

float Line::getK() const { return k; }
float Line::getB() const { return b; }

void Line::setK(const float x) { k = x; }
void Line::setB(const float y) { b = y; }

Line::Line(const Point pt, const Point pt1) 
{
	k = ((pt1.getY() - pt.getY()) / (pt1.getX() - pt.getX()));
	b = pt1.getY() - k * pt1.getX();
}

bool Line::checkLiesPoint(const Point pt)
{
	return (pt.getX() == pt.getX()*getK() + getB());
}

int Line::chekHigherOrBelow(const Point pt)
{
	if (pt.getY() == pt.getX()*getK() + getB())
	{
		return 0;
	}
	else
	{
		if (pt.getY() > pt.getX()*getK() + getB())
		{
			return 1;
		}
		return -1;
	}
}

bool Line::chekLies(const int x, const int y)
{
	return  y == x*getK() + getB();
}
Point pointIntersect(Line l1, Line l2)
{
	float x = (l1.getB() - l2.getB()) / (l1.getK() - l2.getK());
	float y = l1.getK()*x + l1.getB();
	Point intersect(x, y);
	return intersect;
}
