#pragma once

#include "SingleLL.cpp"

template <class T>
class MinStack
{
	public:
		int size;
		Single_LL<T>* stack;
		Single_LL<Node<T>*>* min;

		MinStack() :  min{ new Single_LL<Node<T>*>() }, stack{ new Single_LL<T>() }, size{ 0 } {}
		
		~MinStack()
		{
			delete stack;
			delete min;
		}

		void push(T value)
		{
			stack->prepend(value);
			if ((size == 0) ||
				(value < ((Node<T>*)(min->head->value))->value))
			{
				min->prepend(stack->head);
			}
			size++;
		}

		T peek()
		{
			if (size > 0)
			{
				return stack->head->value;
			}
			return T();
		}

		T minimum()
		{
			if (size > 0)
			{
				return ((Node<T>*)(min->head->value))->value;
			}
			return T();
		}

		void pop()
		{
			if (size > 0)
			{
				if ((Node<T>*)(min->head->value) == (Node<T>*)(stack->head))
				{
					min->remove(0);
				}
				stack->remove(0);
			}
		}
};