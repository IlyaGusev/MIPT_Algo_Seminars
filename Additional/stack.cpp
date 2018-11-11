#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

class Stack {
public:
	Stack() :
		collection(new int[1]),
		size(0),
		capacity(1)
	{
		cout << "Constructor call" << endl;
	}

	Stack(const Stack& other) :
		capacity(other.capacity),
		size(other.size)
	{	
		collection = new int[other.capacity];
		for (size_t i = 0; i < size; i++) {
			collection[i] = other.collection[i];
		}
	}

	void operator=(const Stack& other) {
		size = other.size;
		capacity = other.capacity;
		delete[] collection;
		collection = new int[other.capacity];
		for (size_t i = 0; i < size; i++) {
			collection[i] = other.collection[i];
		}
	}
	
	~Stack() {
		delete[] collection;
	}

	size_t Size() const;
	int Back() const;
	void PushBack(int value);
	int PopBack();

private:
	int* collection;
	size_t size;
	size_t capacity;

	void Reserve(size_t newCapacity);	
};

int Stack::Size() const {
	return this->size;
}

void Stack::PushBack(int value) {
	if (size == capacity) {
		Reserve(capacity * 2);
	}
	size += 1;
	collection[size] = value;
} 

int Stack::PopBack() {
	if (size == 0) {
		throw runtime_error("Stack is empty");
	}
	int value = collection[size];
	size -= 1;
	return value;
}
	
int Stack::Back() const {
	return collection[size];
}

void Stack::Reserve(size_t newCapacity) {
	capacity = newCapacity;
	int* newCollection = new int[capacity];
	for (size_t i = 0; i < size; i++) {
		newCollection[i] = collection[i];
	}
	delete[] collection;
	collection = newCollection;
}

int main() {
	Stack s;
	while (true) {
		int command;
		int element;
		cin >> command;
		if (command == 0) {
			cin >> element;
			s.PushBack(element); 
		} else if (command == 1) {
			int backElem = s.PopBack();
			cout << backElem << endl;
		} else if (command == 2) {
			size_t size = s.Size();
			cout << size << endl;
		}
	}
	Stack s2(s);
}
