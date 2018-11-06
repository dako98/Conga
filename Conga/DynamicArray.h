#ifndef _DYNAMIC_ARRAY_
#define _DYNAMIC_ARRAY_

#include <stdexcept>
#include "Student.h"

template<class T>
class DynArray
{
public:

	DynArray();
	DynArray(const DynArray &other);

	void Insert(const T& newElement);

	DynArray& operator=(const DynArray &other);

	T& operator[](size_t index);
	const T& operator[](size_t index) const;

	size_t GetSize() const;

	void Sort();
	int Search(const T& target);


	~DynArray();


private:

	void ResizeUp();
	void ResizeDown();
	void Clear();
	void Copy(const DynArray& other);

	bool isSorted;

	T** elements;
	size_t size;
	size_t capacity;



};
template<class T>
DynArray<T>::DynArray()
{
	this->elements = new T*[2];
	this->size = 0;
	this->capacity = 2;
	isSorted = false;
}

template<class T>
DynArray<T>::DynArray(const DynArray& other)
{
	Copy(other);
}

//-----------------------------------------------

template<class T>
T& DynArray<T>::operator[](size_t index)
{
	if (index >= size)	throw std::out_of_range("Out of range.");

	return *elements[index];
}

template<class T>
const T& DynArray<T>::operator[](size_t index) const
{
	if (index >= size)	throw std::out_of_range("Out of range.");

	return *elements[index];
}

template<class T>
DynArray<T>::~DynArray()
{
	Clear();
}

template<class T>
DynArray<T>& DynArray<T>::operator=(const DynArray& other)
{
	if (this != &other)
	{
		Clear();
		Copy(other);
	}
	return *this;
}

template<class T>
void DynArray<T>::Copy(const DynArray &other)
{
	this->elements = new T*[other.capacity];
	this->capacity = other.capacity;

	for (size_t i = 0; i < other.size; i++)
		this->elements[i] = new T(*other.elements[i]);

	this->size = other.size;
	isSorted = other.isSorted;
}

template<class T>
void DynArray<T>::ResizeUp()
{
	T** temp = new T*[capacity * 2];

	for (size_t i = 0; i < capacity; i++)
	{
		temp[i] = elements[i];
	}
	delete[] elements;

	elements = temp;
	temp = nullptr;
}

template<class T>
void DynArray<T>::ResizeDown()
{
	if (size < capacity / 3)
	{
		T** temp = new T*[capacity / 3];

		for (size_t i = 0; i < size; i++)
		{
			temp[i] = elements[i];
		}
		delete[] elements;

		elements = temp;
		temp = nullptr;
	}
}

template<class T>
void DynArray<T>::Clear()
{
	for (size_t i = 0; i < size; i++)
	{
		delete elements[i];
	}
	delete[] elements;

	elements = nullptr;
	size = 0;
	capacity = 0;
	isSorted = false;
}

template<class T>
void DynArray<T>::Insert(const T& newElement)
{
	if (size == capacity)
		ResizeUp();

	elements[size] = new T(newElement);
	size++;
}

template<class T>
void swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

template<class T>
void SelectionSort(T** arr, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = i + 1; j < size; j++)
		{
			if (*arr[j] < *arr[j])
				swap(arr[i], arr[j]);
		}
	}
}

template<class T>
void DynArray<T>::Sort()
{
	if (isSorted)	return;

	SelectionSort(elements, size);
	isSorted = true;
}

template<class T>
int _BinSearch(int begin, int end, T** arr, T target)
{
	if (begin >= end && *arr[begin] != target) return -1;
	else if (*arr[(begin + end) / 2] == target)	return (begin + end) / 2;
	else if (*arr[(begin + end) / 2] < target) return _BinSearch(((begin + end) / 2) + 1, end, arr, target);
	else return _BinSearch(begin, ((begin + end) / 2) - 1, arr, target);
}

template<class T>
int BinSearch(T** arr, int size, T target)
{
	if (size == 0)
		return -1;
	return _BinSearch(0, size, arr, target);
}

template<class T>
int DynArray<T>::Search(const T& target)
{
	if (!isSorted)
	{
		for (size_t i = 0; i < size; i++)
			if (*elements[i] == target)
				return i;
	}
	return BinSearch(elements, size, target);
}

template<class T>
size_t DynArray<T>::GetSize() const
{
	return size;
}



#endif // !_DYNAMIC_ARRAY_