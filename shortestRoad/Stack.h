#pragma once

template <typename T>
class Stack {
private:
    T* data;
    int top_index; // last element index 

public:
    Stack(int size);
    Stack() = default;
    ~Stack();
    void push(T value);
    void pop();
    T top();
    bool empty();
};