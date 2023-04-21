#include "Point.h"

Point::Point(int x, int y) : x(x), y(y), distance (0)
{
}

Point::Point(int x, int y, int distance) : x(x), y(y), distance(distance)
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

int Point::GetDistance()
{
	return distance;
}

void Point::SetX(int x)
{
	this->x = x;
}

void Point::SetY(int y)
{
	this->y = y;
}

void Point::DistanceIncrement()
{
	distance++;
}
