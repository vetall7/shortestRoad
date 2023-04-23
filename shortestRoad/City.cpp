#include "City.h"

City::City(String name, int index) : name(name), index(index), total_distance(0)
{
}

void City::SetName(String& name)
{
	this->name = name;
}

void City::AddNeigbour(Neighbour n)
{

	for (int i = 0; i < neighbours.GetSize(); i++) {
		if (neighbours[i].GetName() == n.GetName()) {
			if (n.GetDistance() < neighbours[i].GetDistance()) {
				neighbours[i].SetDistance(n.GetDistance());
				//cout << neighbours[i].GetDistance() << endl;
			}
			return;
		}
	}
	neighbours.push_back(n);
}

void City::PrintN()
{
	for (Neighbour i : neighbours) {
		cout << i.GetName() << " " << i.GetDistance() << " ";
	}
}

String City::GetName()
{
	return name;
}

Neighbour* City::isNeighbour(String city)
{
	for (Neighbour i : neighbours) {
		if (i.GetName() == city) {
			return &i;
		}
	}
	return nullptr;
}

list<Neighbour>* City::GetNeighbours()
{
	return &neighbours;
}

int City::GetIndex()
{
	 return index;
}

int City::GetTotalDistance()
{
	return total_distance;
}

void City::IncreaseDistance(int i)
{
	total_distance += i;
}

void City::DistanceToZero()
{
	total_distance = 0;
}

void City::SetDistance(int distance)
{
	total_distance = distance;
}
