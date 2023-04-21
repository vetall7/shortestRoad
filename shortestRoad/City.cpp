#include "City.h"

City::City(String name) : name(name)
{
}

void City::SetName(String& name)
{
	this->name = name;
}

void City::AddNeigbour(Neighbour n)
{
	/*for (Neighbour i : neighbours) {
		if (i.GetName() == n.GetName()) {
			if (n.GetDistance() < i.GetDistance()) {
				i.SetDistance(n.GetDistance());
				cout << i.GetDistance() << endl;
			}
			return;
		}
	}*/

	for (int i = 0; i < neighbours.GetSize(); i++) {
		if (neighbours[i].GetName() == n.GetName()) {
			if (n.GetDistance() < neighbours[i].GetDistance()) {
				neighbours[i].SetDistance(n.GetDistance());
				cout << neighbours[i].GetDistance() << endl;
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
