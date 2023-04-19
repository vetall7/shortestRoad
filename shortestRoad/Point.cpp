#include "Point.h"

Point::Point(int x, int y) : x(x), y(y)
{
}

int Point::GetX()
{
	return x;
}

int Point::GetY()
{
	return y;
}

void Point::SetX(int x)
{
	this->x = x;
}

void Point::SetY(int y)
{
	this->y = y;
}
