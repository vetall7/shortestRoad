#include "Stack.h"

template <typename T>
Stack<T>::Stack(int size) {
    data = new T[size];
    top_index = -1; // empty stack
}

template <typename T>
Stack<T>::~Stack() {
    delete[] data;
}

template <typename T>
void Stack<T>::push(T value) {
    top_index++;
    data[top_index] = value;
}


template <typename T>
void Stack<T>::pop() {
    if (top_index != -1) {
        top_index--;
    }
}


template <typename T>
T Stack<T>::top() {
   // if (top_index != -1) {
        return data[top_index];
   // }
}


template <typename T>
bool Stack<T>::empty() {
    return (top_index == -1);
}