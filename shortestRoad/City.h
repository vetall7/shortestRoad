#pragma once
#include "String.h"
#include "List.cpp"

class City {
private:
	String name;
	list<String> neighbours;
public:
	City(String name);
	City() = default;
	void SetName(String& name);
	String GetName();
};