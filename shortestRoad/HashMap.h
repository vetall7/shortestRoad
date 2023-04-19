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
	void AddCity(String &name);
	int hash(String &key);
    void Print();
    ~HashMap();
};