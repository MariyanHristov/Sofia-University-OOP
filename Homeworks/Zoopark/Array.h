#pragma once

template <class T>
class Array {
private:
	unsigned int size;
	unsigned int capacity;
	T* data;
public:
	Array();
	Array(unsigned int);
	Array(unsigned int, const T&);
	Array(const Array<T>&);

	Array<T>& operator=(const Array<T>&);
	~Array();

	unsigned int getSize() const;
	unsigned int getCapacity() const;

	T& operator[](unsigned int i);
	T& operator[](unsigned int i) const;

	void resize(unsigned int);
	void resize(unsigned int, const T&);
	void pushBack(const T&);
	void pop();
	void clear();
	bool empty() const;
	void popAt(unsigned int);
private:
	void copy(const Array<T>&);
	void free();
};

template <class T>
Array<T>::Array() {
	size = 0;
	capacity = 0;
	data = nullptr;
}

template <class T>
Array <T>::Array(unsigned int n) {
	size = n;
	capacity = n;
	data = new T(n);
}

template <class T>
Array<T>::Array(unsigned int n, const T& other) {
	size = n;
	capacity = n;
	data = new T(n);
	for (int i = 0; i < n; i++)
		data[i] = other;
}

template <class T>
Array<T>::Array(const Array<T>& other) {
	copy(other);
}

template <class T>
void Array<T>::copy(const Array<T>& other) {
	size = other.size;
	capacity = other.capacity;
	data = new T(other.size);
	for (int i = 0; i < other.size; i++)
		data[i] = other[i];
}

template <class T>
void Array<T>::free() {
	for (unsigned int i = 0; i < size; i++)
		delete data[i];
	delete[] data;
}

template <class T>
Array<T>::~Array() {
	free();
}

template <class T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
	if (this != &other) {
		free();
		copy(other);
	}
	return *this;
}

template <class T>
unsigned int Array<T>::getSize() const {
	return size;
}

template <class T>
unsigned int Array<T>::getCapacity() const {
	return capacity;
}

template <class T>
T& Array<T>::operator[](unsigned int n) {
	if (n >= size)
		throw "Out of bounds!";
	return data[n];
}

template <class T>
T& Array<T>::operator[](unsigned int n) const {
	if (n >= size)
		throw "Out of bounds!";
	return data[n];
}

template <class T>
void Array<T>::resize(unsigned int n) {
	if (n == 0) {
		clear();
	}
	else {
		if (n > capacity) {
			capacity = n;
			T* newData = new T[n];
			for (int i = 0; i < n; i++)
				newData[i] = data[i];
			delete[] data;
			data = newData;
		}
		size = n;
	}
}

template <class T>
void Array<T>::resize(unsigned int n, const T& other) {
	if (n == 0) {
		clear();
	}
	else {
		if (n > capacity) {
			capacity = n;
			T* newData = new T[n];
			for (int i = 0; i < n; i++)
				newData[i] = data[i];
			delete[] data;
			data = newData;
		}
		if (n > size) {
			for (int i = size; i < n; i++)
				data[i] = other;
		}
		size = n;
	}
}

template <class T>
void Array<T>::pushBack(const T& other) {
	if (size == capacity) {
		capacity += capacity / 2 + 1;
		T* newData = new T[capacity];
		for (unsigned int i = 0; i < size; i++)
			newData[i] = data[i];
		delete[] data;
		data = newData;
	}

	data[size++] = other;
}

template <class T>
void Array<T>::pop() {
	if (!empty()) {
		size--;
		if (empty())
			clear();
	}
}

template <class T>
void Array<T>::clear() {
	free();
	size = 0;
	capacity = 0;
	data = nullptr;
}

template <class T>
bool Array<T>::empty() const {
	return size == 0;
}

template <class T>
void Array<T>::popAt(unsigned int n) {
	if (n >= size)
		throw "Out of bounds!";
	for (unsigned int i = n; i < size - 1; i++)
		data[i] = data[i + 1];
	size--;
	if (empty())
		clear();
}
