template <class T>
class Single_Node
{
	public:
		T value;
		Single_Node* next;

		Single_Node(T value)
		{
			this->value = value;
			next = nullptr;
		}			
};

template <class T>
class Single_LL
{
	public:
		Single_Node<T>* head;

		Single_LL()
		{
			head = nullptr;
		}

		void append(T value)
		{
			Single_Node<T>* cur = head;
			while (cur != nullptr)
			{
				cur = cur->next;
			}
			cur->next = new Single_Node<T>(value);
		}
};