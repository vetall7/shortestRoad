#include "City.h"

City::City(String name) : name(name)
{
}

void City::SetName(String& name)
{
	this->name = name;
}

String City::GetName()
{
	return name;
}
