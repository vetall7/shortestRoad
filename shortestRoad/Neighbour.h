#pragma once
#include "String.h"

class Neighbour {
	String name;
	int distance;
public:
	Neighbour(String name, int distance);
	Neighbour() = default;
	String GetName();
	int GetDistance();

	void SetDistance(int distance);
};