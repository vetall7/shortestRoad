#include "HashMap.h"
#include "Neighbour.h"

HashMap::HashMap(int size) : size (size)
{
	cities = new HashNode*[size]();
}

void HashMap::AddCity(const String &name, int index)
{
    int i = hash(name);
    if (cities[i] == nullptr) {
        cities[i] = new HashNode(City(name, index));
    }
    else {
        HashNode* node = cities[i];
        while (node->next != nullptr) {
            node = node->next;
        }
        node->next = new HashNode(City(name, index));
    }
}


void HashMap::AddNeighbour(const String& main_city, const String& neighbour, int distance)
{
    GetCity(main_city)->AddNeigbour(Neighbour(neighbour, distance));
}


City* HashMap::GetCity(const String key) {
    int index = hash(key);
    HashNode* node = cities[index];
    while (node != nullptr) {
        if (node->key.GetName() == key) {
            return &(node->key);
        }
        node = node->next;
    }

    return nullptr;
}


int HashMap::hash(const String &key)
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
            cout << cities[i]->key.GetName() << " --- ";
            cities[i]->key.PrintN();
            cout << endl;
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

