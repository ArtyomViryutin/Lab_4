#pragma once
#include <iostream>
#include <vector>
using namespace std;

template <typename T, int N, class U>
class Iterator
{

public:
	Iterator(U *s) : stk(s)
	{
		index = this->begin();
	}

	T* begin() const
	{
		return &stk->StackPtr[stk->top];
	}
	T* end() const
	{
		return &stk->StackPtr[0];
	}
	T* current() const
	{
		return index;
	}

	bool isDone() const
	{
		return index == end() - 1;
	}

	const Iterator& operator++()
	{
		index = index + 1;
		return *this;
	}
	const Iterator operator++(int)
	{
		Iterator temp(*this);
		index = index + 1;
		return temp;
	}

	const Iterator& operator--()
	{
		index = index - 1;
		return *this;
	}
	const Iterator operator--(int)
	{
		Iterator temp(*this);
		index = index - 1;
		return temp;
	}

	T operator*() const
	{
		return *index;
	}

	bool operator== (Iterator &it) const
	{
		return (index == it.index);
	}

	void reset() {
		index = this->begin();
	}

private:
	U *stk;
	T *index;
};

template <typename T, int N>
class Stack
{
private:
	T *StackPtr; // Указатель на массив элементов
	int MaxSize = N; // Переменная, которая содержит максимальный размер стека
	int top; // Индекс верхнего элемента стека
public:
	Stack(); // Конструктор по умолчанию
	~Stack(); // Деструктор
	bool Push(const T value); // Операция добавления элемента в стек
	bool Pop(); // Операция удаления элемента из стека
	T Top() const; // Определение верхнего элемента без его удаления
	int Size() const; // Определение размера очереди
	bool Empty() const; // Проверка на пустоту
	bool Full() const; // Проверка на полноту
	Stack& operator=(Stack &a); // Перегрузка оператора присваивания
	friend class Iterator<T, N, Stack>;
	T* begin() const
	{
		return &StackPtr[top];
	}

	T* end() const
	{
		return &StackPtr[0];
	}

	Iterator<T, N, Stack> CreateIterator()
	{
		return *(new Iterator<T, N, Stack>(this));
	}


	
	// Перегрузка оператора вывода
	friend ostream& operator<< (ostream &out, const Stack &a)// Перегрузка оператора вывода
	{
		for (int i = a.top; i >= 0; i--) // Начиная с конца массива StackPtr выводим все элементы
			cout << a.StackPtr[i] << endl;
		return out;
	}

	// Перегрузка оператора ввода
	friend istream& operator>> (istream &in, Stack &a)// Перегрузка оператор ввода
	{
		int n = 0; // Счетчик
		T temp; // Временная переменная для ввода
		while (n++ != a.MaxSize) // Пока не максимальный размер очереди
		{
			cin >> temp; // Вводим элемент
			a.Push(temp); // Добавляем элемент в очередь
		}
		return in;
	}
};

// Выделяем память и присваиваем переменной top занчение -1, что говорит о пустоте очереди
template <typename T, int N>
Stack<T, N>::Stack() { StackPtr = new T[1]; top = -1; }

// Проверка на пустоту
template <typename T, int N>
bool Stack<T, N>::Empty() const	
{
	if (top == -1) // Если индекс верхнего элемента top = -1, стек пуст
		return true; // Возвращаем true
	return false; // Иначе - false - стек не пуст
}

// Проверка на полноту
template <typename T, int N>
bool Stack<T, N>::Full() const
{
	if (top + 1 == MaxSize) // Если индекс верхнего элемента (top + 1), то есть размер очереди, равен максимальному размеру очереди
		return true; // Значит очередь заполнена, возвращаем true
	return false; // Иначе - false - очередь не заполнена
}

// Деструктор
template <typename T, int N>
Stack<T, N>::~Stack() { delete[] StackPtr; } // Очищаем указатель на массив элементов

// Перегрузка оператора присванивания
template <typename T, int N>
Stack<T, N>& Stack<T, N>::operator=(Stack<T, N> &a)
{
	top = a.top; // Присваиваем индекс верхнего элемента очереди
	StackPtr = (T*)realloc(StackPtr, (a.top + 1) * sizeof(T)); // Выделяем память
	for (int i = 0; i < top + 1; i++)
		StackPtr[i] = a.StackPtr[i]; // Присваиваем значения элементов
	return *this; // Возвращаем указатель на объект, который вызвал метод
}


// Операция добавления элемента в стек
template <typename T, int N>
bool Stack<T, N>::Push(const T value)
{
	if (Full()) // Проверка очереди на полноту, если она заполнена, то выводим соответствующее сообщение и возвращаем false
	{
		cout << "Невозможно добавить элемент, так как стек полностью заполнен." << endl;
		return false; // стек полон
	}

	top++; // Увеличиваем индекс верхнего элемента на 1
	StackPtr = (T*)realloc(StackPtr, (top + 1) * sizeof(T)); // Выделяем память для нового элемента
	StackPtr[top] = value; // помещаем элемент в стек // Присваием значение
	return true; // При успехе возвращаем true
}

// Операция удаления элемента из очереди
template <typename T, int N>
bool Stack<T, N>::Pop()
{
	if (Empty()) // Провеврка очереди на пустоту, если она пуста, то удалять нечего
	{
		cout << "Невозможно удалить элемент, так как стек пуст." << endl; // Выводим соответсвующее сообщения
		return false; // И возвращаем false
	}
	StackPtr = (T*)realloc(StackPtr, top * sizeof(T)); // Уменьшаем размер очереди(массива StackPtr) на 1
	top--; // Уменьшаем индекс верхнего элемента 1

	return true; // В случае успеха возвращаем true
}

// Определение верхнего элемента без его удаления
template <typename T, int N>
T Stack<T, N>::Top() const { return StackPtr[top]; } // Возвращаем значение верхнего элемента по индексу top

// Определение размера очереди
template <typename T, int N>
int Stack<T, N>::Size() const { return top + 1; } // Возвращаем размер очереди, как индекс верхнего элемента + 1


void Sep() {
	cout << "-------------------------" << endl;
}

