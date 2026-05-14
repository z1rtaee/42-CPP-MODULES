#include "Array.hpp"

template <typename T>
Array<T>::Array() : _array(NULL), _size(0) {
}

template <typename T>
Array<T>::Array(unsigned int n) : _array(NULL), _size(n) {
	if (n == 0) {
		_array = NULL;
	} else {
		_array = new T[n]();
	}
}

template <typename T>
Array<T>::Array(const Array &src) : _array(NULL), _size(src._size) {
	if (_size == 0) {
		_array = NULL;
	} else {
		_array = new T[_size];
		for (unsigned int i = 0; i < _size; ++i)
			_array[i] = src._array[i];
	}
}

template <typename T>
Array<T>::~Array() {
	delete [] _array;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &obj) {
	if (this == &obj)
		return *this;
	delete [] _array;
	_size = obj._size;
	if (_size == 0) {
		_array = NULL;
	} else {
		_array = new T[_size];
		for (unsigned int i = 0; i < _size; ++i)
			_array[i] = obj._array[i];
	}
	return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int idx) {
	if (idx >= _size)
		throw std::out_of_range("Index out of bounds");
	return _array[idx];
}

template <typename T>
const T &Array<T>::operator[](unsigned int idx) const {
	if (idx >= _size)
		throw std::out_of_range("Index out of bounds");
	return _array[idx];
}

template <typename T>
unsigned int Array<T>::size() const {
	return _size;
}
