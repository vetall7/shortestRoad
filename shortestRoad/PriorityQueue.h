#pragma once
#include <vector>
#include <iostream>

template<typename T>
class PriorityQueue {
public:
    PriorityQueue() {}

   
    void push(T value) {
        
        heap.push_back(value);

        int index = heap.size() - 1;
        while (index > 0 && heap[index] < heap[parent(index)]) {
            std::swap(heap[index], heap[parent(index)]);
            index = parent(index);
        }
    }

    T top() {
        return heap[0];
    }

    void pop() {
        heap[0] = heap.back();
        heap.pop_back();

        int index = 0;
        while (left_child(index) < heap.size()) {
            int child = left_child(index);
            if (right_child(index) < heap.size() && heap[right_child(index)] < heap[child]) {
                child = right_child(index);
            }
            if (heap[index] < heap[child]) {
                break;
            }
            std::swap(heap[index], heap[child]);
            index = child;
        }
    }

    int size() {
        return heap.size();
    }

    bool empty() {
        return heap.empty();
    }

private:
    int parent(int index) {
        return (index - 1) / 2;
    }

    int left_child(int index) {
        return 2 * index + 1;
    }

    int right_child(int index) {
        return 2 * index + 2;
    }

    std::vector<T> heap;
};