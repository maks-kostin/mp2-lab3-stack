#pragma once

#include <iostream>
using namespace std;

template <class T>
class Stack
{
	int Size, MaxSize;
	T* arr;
public:
	Stack(int _MaxSize = 10); //конструктор по умолчанию
	Stack(const Stack<T>& m); //конструктор копирования
	~Stack(); //деструктор
	Stack& operator=(const Stack& m); //присваивание

	bool Empty();
	bool Full();
	void Push(T a);
	T Pop();
	T Top();
};

template <class T>
Stack<T>::Stack(int _MaxSize)
{
	MaxSize = _MaxSize;
	arr = new T[MaxSize];
	Size = 0;
}

template <class T>
Stack<T>::Stack(const Stack<T>& m)
{
	MaxSize = m.MaxSize;
	arr = new T[MaxSize];
	Size = m.Size;
	for (int i = 0; i < Size; i++)
	{
		arr[i] = m.arr[i];
	}
}

template <class T>
Stack<T>::~Stack()
{
	delete[] arr;
}

template <class T>
Stack<T>& Stack<T>::operator=(const Stack& m)
{
	if (MaxSize != m.MaxSize)
	{
		delete[] arr;
		MaxSize = m.MaxSize;
		arr = new T[MaxSize];
	}
	Size = m.Size;
	for (int i = 0; i < Size; i++)
	{
		arr[i] = m.arr[i];
	}
	return *this;
}

template <class T>
bool Stack<T>::Empty()
{
	if (Size == 0)
		return true;
	return false;
}

template <class T>
bool Stack<T>::Full()
{
	if (Size == MaxSize)
		return true;
	return false;
}

template <class T>
void Stack<T>::Push(T a)
{
	if (Full())
		throw MaxSize;
	arr[Size] = a;
	Size++;
}

template <class T>
T Stack<T>::Pop()
{
	if (Empty())
		throw 0;
	Size--;
	return arr[Size + 1];
}

template <class T>
T Stack<T>::Top()
{
	if (Empty())
		throw 0;
	return arr[Size - 1];
}