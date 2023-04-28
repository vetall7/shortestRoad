#pragma once
#include "String.h"
#include "List.cpp"
#include "Neighbour.h"
#include <queue>

class City {
private:
	String name;
	vector<Neighbour> neighbours;
	int index;
	int total_distance;
public:
	City(String name, int index);
	City() = default;
	void SetName(String& name);
	void AddNeigbour(Neighbour n);
	void PrintN();
	String GetName();
	Neighbour* isNeighbour(String city);
	vector<Neighbour>* GetNeighbours();
	int GetIndex();
	int GetTotalDistance();
	void IncreaseDistance(int i);
	void DistanceToZero();
	void SetDistance(int distance);
	int GetNeighboursCounter();

	bool operator>(const City* other) const {
		return total_distance > other->total_distance;
	}
};