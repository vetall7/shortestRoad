#include "List.h"


template <typename T>
list<T>::list() {
	Size = 0;
	head = nullptr;
}

template<typename T>
list<T>::~list()
{
	clear();
}

template<typename T>
void list<T>::push_back(T data)
{
	if (head == nullptr) {
		head = new Node<T>(data); // creating the node and returns address
	}
	else {
		Node<T>* size = this->head;

		while (size->pNext != nullptr) {
			size = size->pNext;
		}
		size->pNext = new Node<T>(data);
	}
	Size++;
}


template<typename T>
void list<T>::clear() {
	while (Size) {
		pop_front();
	}
}

template<typename T>
void list<T>::insert(T data, int index) {
	if (index == 0) {
		head->data = data;
	}
	else {
		Node<T>* element = new Node<T>(data);
		Node<T>* temp1 = this->head;
		Node<T>* temp2 = this->head;
		for (int i = 0; i < index; i++) {
			temp1 = temp1->pNext;
			if (i == index - 2) temp2 = temp1;
		}
		temp2->pNext = element;
		element->pNext = temp1;
	}
}

template<typename T>
void list<T>::pop_front() {
	Node<T>* temp = head;
	head = head->pNext;
	delete temp;
	Size--;
}

template<typename T>
void list<T>::pop_back() {
	Node<T>* temp1 = head;
	Node<T>* temp2 = head;
	for (int i = 0; i < Size - 1; i++) {
		temp1 = temp1->pNext;
		if (i == Size - 2) temp2 = temp1;
	}
	delete temp1;
	temp2->pNext = nullptr;
	Size--;
}


template<typename T>
void list<T>::push_front(T data) {
	if (head == nullptr) {
		head = new Node<T>(data);
	}
	else {
		Node<T>* first_element = new Node<T>(data);
		first_element->pNext = head;
		head = first_element;
	}
	Size++;
}


template<typename T>
T& list<T>::operator[](const int index)
{
	Node<T>* curr = this->head;
	int counter = 0;

	while (counter - 1 != index - 1) {
		curr = curr->pNext;
		counter++;
	}
	return curr->data;
}
