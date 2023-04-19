#include "HashMap.h"


HashMap::HashMap(int size) : size (size)
{
	cities = new HashNode*[size]();
}

void HashMap::AddCity(String &name)
{
    int index = hash(name);
    if (cities[index] == nullptr) {
        cities[index] = new HashNode(City(name));
    }
    else {
        HashNode* node = cities[index];
        while (node->next != nullptr) {
            node = node->next;
        }
        node->next = new HashNode(City(name));
    }
}

int HashMap::hash(String &key)
{
    int hashValue = 0;
    for (int i = 0; i < key.size(); i++) {
        hashValue = (hashValue * 31 + key[i]) % size;
    }
    return hashValue;
}

void HashMap::Print()
{
    for (int i = 0; i < size; i++) {
        if (cities[i] != nullptr) {
            cout << cities[i]->key.GetName() << endl;
        }
    }
}

HashMap::~HashMap()
{
    for (int i = 0; i < size; i++) {
        HashNode* node = cities[i];
        while (node != nullptr) {
            HashNode* prev = node;
            node = node->next;
            delete prev;
        }
    }
    delete[] cities;
}

