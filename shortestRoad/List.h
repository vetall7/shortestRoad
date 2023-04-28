template<typename T>
class list {
public:
	list();
	~list();
	int GetSize() {
		return Size;
	}
	void push_back(T data);
	void push_front(T data);
	void pop_front();
	void pop_back();
	void clear();
	void insert(T data, int index);

	T& operator[](const int index);
	template<typename T>
	class Node
	{
	public:
		Node* pNext;
		T data;
		Node(T data = T(), Node* pNext = nullptr) {
			this->data = data;
			this->pNext = pNext;
		}
	};
	int Size;
	Node<T>* head;

	class Iterator {
	private:
		Node<T>* size_node;
	public:
		Iterator(Node<T>* node) : size_node(node) {}
		bool operator==(const Iterator& other) const {
			return size_node == other.size_node;
		}
		bool operator!=(const Iterator& other) const {
			return !(*this == other);
		}
		T& operator*() const {
			return size_node->data;
		}
		Iterator& operator++() {
			size_node = size_node->pNext;
			return *this;
		}
		Iterator operator++(int) {
			Iterator iterator = *this;
			++(*this);
			return iterator;
		}
	};

	Iterator begin() {
		return Iterator(head);
	}

	Iterator end() {
		return Iterator(nullptr);
	}
private:

};