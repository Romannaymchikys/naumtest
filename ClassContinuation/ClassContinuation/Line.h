#pragma once
#include "Point.h"
class Line
{
public:
	explicit Line(const float x, const float y = 0) :k(x), b(y) {}
	Line(const Point, const Point);

	float getK() const;
	float getB() const;

	void setK(const float);
	void setB(const float);

	bool checkLiesPoint(const Point);
	bool chekLies(const int, const int);
	int chekHigherOrBelow(const Point);
	~Line() {};
private:
	float k;
	float b;
};
Point pointIntersect(Line l1, Line l2);

