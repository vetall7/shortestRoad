#pragma once
#include "City.h"

class HashNode {
public:
    City key;
    HashNode* next;

    HashNode(City key) {
        this->key = key;
        this->next = nullptr;
    }
};


class HashMap {
private: 
	int size;
    HashNode** cities;
public:
	HashMap(int size);
	void AddCity(const String &name);
    void AddNeighbour(const String& main_city, const String& neighbour, int distance);
    City* GetCity(const String& key);
	int hash(const String &key);
    void Print();
    ~HashMap();
};