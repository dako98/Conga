#ifndef _LIST_
#define _LIST_


template<class Type>
class List
{

public:

	List();
	List(const List &other);
	List& operator=(const List &other);
	~List();

	void PushBack(const Type &element);
	void PushFront(const Type &element);

	void PopBack();
	void PopFront();


private:


	struct Box
	{
		Box(Type data, Box* next = nullptr);

		Type data;
		Box* next;
	};

public:

	class Iterator
	{

		friend List;

	public:

		Iterator(Box* node)
			:node(node)
		{}

		Iterator& operator++()
		{
			node = node->next;

			return *this;
		}

		Iterator operator++(int)
		{
			Iterator tmp(*this);

			node = node->next;

			return tmp;
		}

		Type& operator*()
		{
			return node->data;
		}

		Type* operator->()
		{
			return &node->data;
		}

		bool operator==(const Iterator &other) const
		{
			return this->node == other.node;
		}

		bool operator!=(const Iterator &other) const
		{
			return !(*this == other);
		}

	private:

		Box* node;

	};


	Iterator InsertAfter(const Iterator &target, const Type &element);
	void RemoveAfter(const Iterator &target);

	Iterator begin() const;
	Iterator end() const;

	Iterator GetTail() const;

	List SplitAfter(Iterator &target);
	void Append(List &other);

private:

	void Clear();
	void Copy(const List &other);

	Box* head;
	Box* tail;
};

template<class Type>
typename List<Type>::Iterator List<Type>::GetTail() const
{
	return Iterator(tail);
}

template<class Type>
typename List<Type>::Iterator List<Type>::begin() const
{
	return Iterator(head);
}

template<class Type>
typename List<Type>::Iterator List<Type>::end() const
{
	return Iterator(nullptr);
}

template<class Type>
List<Type>::List()
{
	head = nullptr;
	tail = nullptr;
}

template<class Type>
List<Type>::List(const List &other)
	:head(nullptr)
	, tail(nullptr)
{
	Copy(other);
}

template<class Type>
List<Type>& List<Type>::operator=(const List<Type> &other)
{
	if (this != &other)
	{
		Clear();
		Copy(other);
	}
	return *this;
}

template<class Type>
List<Type>::~List()
{
	Clear();
}

template<class Type>
void List<Type>::Clear()
{
	if (head != nullptr)
	{

		Box* nextBox = head->next;
		Box* currentBox = head;

		while (nextBox != nullptr)
		{
			delete currentBox;
			currentBox = nextBox;
			nextBox = nextBox->next;
		}
		delete currentBox;
	}
	head = nullptr;
	tail = nullptr;
}

template<class Type>
void List<Type>::Copy(const List<Type> &other)
{
	for (const Type& i : other)
		PushBack(i);

}

template<class Type>
void List<Type>::PushBack(const Type &element)
{
	Box* temp = new Box(element);

	if (head == nullptr)
	{
		head = temp;
		tail = temp;

		return;
	}

	tail->next = temp;
	tail = tail->next;
}

template<class Type>
void List<Type>::PushFront(const Type &element)
{
	Box* temp = new Box(element, head);

	head = temp;

	if (tail == nullptr)
		tail = temp;

}

template<class Type>
void List<Type>::PopBack()
{
	if (head != nullptr)
	{
		Box* current = head;

		while (current->next != tail &&
			current->next != nullptr)

			current = current->next;

		tail = current;
		delete current->next;
		current->next = nullptr;
	}
}

template<class Type>
void List<Type>::PopFront()
{
	if (head != nullptr)
	{
		Box* target = head;
		head = target->next;
		delete target;
	}
}

template<class Type>
typename List<Type>::Iterator List<Type>::InsertAfter(const Iterator &target, const Type &element)
{

	Box* newElement = new Box(element, target.node->next);

	target.node->next = newElement;

	return Iterator(newElement);
}

template<class Type>
void List<Type>::RemoveAfter(const Iterator &target)
{
	if (target.node != nullptr && target.node->next != nullptr)
	{
		Box* tmp = target.node->next->next;
		delete target.node->next;
		target.node->next = tmp;
	}
}

template<class Type>
List<Type>::Box::Box(Type element, Box* next)
	:data(element)
	,next(next)
{ }


template<class Type>
List<Type> List<Type>::SplitAfter(Iterator &target)
{
	List<Type>::Iterator it(target);
	//List<Type>* tmp = new List<Type>;
	List<Type> tmp;

	//Setting the new list's head as the element after the given iterator.
	if (it.node->next != nullptr)
	{
		//tmp->head = (++it).node;
		tmp.head = (++it).node;

	}
	//If the next element is nullptr, we return an empty list.
	else
	{
		//tmp->head = nullptr;
		//tmp->tail = nullptr;
		tmp.head = nullptr;
		tmp.tail = nullptr;
		return tmp;
	}

	//Creating a second iterator.
	List<Type>::Iterator currentIt(it);

	//Setting the new list's tail by following the links.
	while (it.node->next != nullptr)
	{
		//Following the links up to before the last element.
			//tmp->tail = it.node;
		tmp.tail = it.node;

			++it;

	}
	//Setting the last element as the tail.
	//tmp->tail = it.node;
	tmp.tail = it.node;


	//Closing off the link from the first list.
	target.node->next=nullptr;

	//Setting the element as the last one.
	tail = target.node;

	return tmp;
}

template<class Type>
void List<Type>::Append(List<Type> &other)
{
	List<Type>::Iterator it(begin());

	while (it.node->next != nullptr)
	{
		++it;
	}

	it.node->next = other.head;


	while (it.node->next != nullptr)
	{
		++it;
	}

	tail = it.node;


	other.head = nullptr;
	other.tail = nullptr;
}




#endif // !_LIST_