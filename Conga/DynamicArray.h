#ifndef _DYNAMIC_ARRAY_
#define _DYNAMIC_ARRAY_

#include <stdexcept>
#include "Student.h"

template<class T>
class DynArray
{
public:

	DynArray();
	DynArray(bool isSorted);

	DynArray(const DynArray &other);

	void Pushback(const T& newElement);
	void Remove(int index);

	DynArray& operator=(const DynArray &other);

	T& operator[](size_t index);
	const T& operator[](size_t index) const;

	size_t GetSize() const;


	~DynArray();


private:

	void ResizeUp();
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
DynArray<T>::DynArray(bool isSorted)
	:isSorted(isSorted)
{
	this->elements = new T*[2];
	this->size = 0;
	this->capacity = 2;
}

template<class T>
DynArray<T>::DynArray(const DynArray& other)
{
	Copy(other);
}

template<class T>
DynArray<T>::~DynArray()
{
	Clear();
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
	T** temp = new T*[capacity *= 2];

	for (size_t i = 0; i < size; i++)
	{
		temp[i] = elements[i];
	}
	delete[] elements;

	elements = temp;
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
void DynArray<T>::Pushback(const T& newElement)
{
	if (size == capacity)
		ResizeUp();

		elements[size] = new T(newElement);
		size++;
}

template<class T>
void DynArray<T>::Remove(int index)
{
	if (index < 0 || index >= size)
	{
		throw std::out_of_range("Out of range.");
	}

	delete elements[index];

	if (!isSorted)
	{
		elements[index] = elements[size];
		--size;
	}
	else
	{
		for (size_t i = index; i < size - 1; ++i)
		{
			elements[i] = elements[i + 1];
		}
		--size;
	}
}

template<class T>
size_t DynArray<T>::GetSize() const
{
	return size;
}

#endif // !_DYNAMIC_ARRAY_