#pragma once

#include <iostream>
using namespace std;

template <class T>
class Node
{
	public:
		T value;
		T local_min;
		Node* next;

		Node(T value) : value{ value }, next{ nullptr }, local_min{ value } {}
	
};

template <class T>
class Single_LL
{
	public:
		Node<T>* head;

		Single_LL() : head{ nullptr } {}

		~Single_LL()
		{
			Node<T>* tmp{ head };
			Node<T>* tmp2{ nullptr };
			while (tmp != nullptr)
			{
				tmp2 = tmp;
				tmp = tmp->next;
				delete(tmp2);
			}
		}

		void append(T value)
		{
			//bracket initializers are safer than assignment initialization
			Node<T>* cur { head };
			while (cur != nullptr)
			{
				cur = cur->next;
			}
			cur->next = new Node<T>(value);
		}

		void prepend(T value)
		{
			Node<T>* new_node{ new Node<T>(value) };
			new_node->next = head;
			head = new_node;
		}

		void remove(int index)
		{
			Node<T>* pre_node{ head };
			Node<T>* i_node{ nullptr };
			if (index == 0)
			{
				i_node = head->next;
				delete head;
				head = i_node;
				return;
			}
			for (int i = 0; i < index - 1; i++)
			{
				if (pre_node == nullptr)
				{
					return;
				}
				pre_node = pre_node->next;
			}
			if (pre_node == nullptr)
			{
				return;
			}

			if ((i_node = pre_node->next) != nullptr)
			{
				pre_node->next = i_node->next;
				delete i_node;
			}
		}

		void print()
		{
			Node<T>* ptr{ head };

			while (ptr != nullptr)
			{
				cout << ptr->value;
				ptr = ptr->next;
			}
		}
};