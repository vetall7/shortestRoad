#pragma once
#include <iostream>
using namespace std;

template<class T>
class VectorIterator {
private:
    T* ptr;
public:
    VectorIterator(T* p = nullptr) : ptr(p) {}
    VectorIterator(const VectorIterator<T>& other) : ptr(other.ptr) {}

    VectorIterator<T>& operator=(const VectorIterator<T>& other) {
        ptr = other.ptr;
        return *this;
    }

    VectorIterator<T>& operator++() {
        ++ptr;
        return *this;
    }

    VectorIterator<T> operator++(int) {
        VectorIterator<T> temp(*this);
        ++(*this);
        return temp;
    }

    bool operator==(const VectorIterator<T>& other) const {
        return ptr == other.ptr;
    }

    bool operator!=(const VectorIterator<T>& other) const {
        return !(*this == other);
    }

    T& operator*() {
        return *ptr;
    }
};

template <class T>
class Vector {
private:
    T* arr;
    int capacity;
    int length;

public:
    Vector() {
        arr = new T[1];
        capacity = 1;
        length = 0;
    }

    void push_back(T data) {
        if (length == capacity) {
            T* temp = new T[2 * capacity];

            for (int i = 0; i < capacity; i++) {
                temp[i] = arr[i];
            }

            delete[] arr;
            capacity *= 2;
            arr = temp;
        }

        arr[length] = data;
        length++;
    }

    int size() {
        return length;
    }
    T& back() {
        return arr[length - 1];
    }
    void pop_back() {
        length--;
    }
    T& operator[](int index) {
        return arr[index];
    }
    VectorIterator<T> begin() {
        return VectorIterator<T>(arr);
    }

    VectorIterator<T> end() {
        return VectorIterator<T>(arr + length);
    }
};