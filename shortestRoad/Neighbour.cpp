#include "Neighbour.h"

Neighbour::Neighbour(String name, int distance) : name (name), distance(distance)
{
}

String Neighbour::GetName()
{
	return name;
}

int Neighbour::GetDistance()
{
	return distance;
}

void Neighbour::SetDistance(int distance)
{
	this->distance = distance;
}
