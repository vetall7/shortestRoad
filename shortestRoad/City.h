#pragma once
#include "String.h"
#include "List.cpp"
#include "Neighbour.h"

class City {
private:
	String name;
	list<Neighbour> neighbours;
public:
	City(String name);
	City() = default;
	void SetName(String& name);
	void AddNeigbour(Neighbour n);
	void PrintN();
	String GetName();
};