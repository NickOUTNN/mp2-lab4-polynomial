#pragma once
template <class Data>
struct Node
{
	Data data;
	Node* next;
};

template <class Data>
class List
{
protected:
	Node <Data> *head;
	Node <Data> *tail;

	Node <Data> *cursor;
	Node <Data> *preCursor;
public:
	int length;
	List() : head(0), tail(0), length(0) {};
	List(List &l) 
	{
		Node<Data> *p = l.head;
		while (p!=0)
		{
			push_back(p->data);
			p = p->next;
		}
	}

	bool isEmpty() const { return (head == 0); }

	Data quick_pop_front()
	{
		Node<Data> tmp = *head;
		Node<Data> *p = head;
		if (head->next)
		{
			head = head->next;
			delete p;
		}
		else
		{
			delete head;
			head = 0;
			tail = 0;
		}
		length--;
		return tmp.data;
	}
	Node<Data>* GetpTop() const
	{
		return head;
	}
	Node<Data>* GetCursor() const
	{
		return cursor;
	}
	bool MoveCursor()
	{
		preCursor = cursor;
		if (cursor != 0)
			cursor = cursor->next;
		return (cursor != 0);
	}

	void push_front(Data obj)
	{
		Node<Data> *newNode = new Node<Data>;
		newNode->data = obj;
		newNode->next = head;
		if (tail == 0)
			tail = head;
		head = newNode;
		length++;
	}
	void push_back(Data obj)
	{
		Node<Data> *newNode = new Node<Data>;
		newNode->data = obj;
		newNode->next = 0;
		if (tail == 0)
		{
			tail = newNode;
			head = newNode;
		}
		else 
		{
			tail->next = newNode;
			tail = newNode;
		}
		length++;
	}
	void setCursor()
	{
		cursor = head;
		preCursor = 0;
	}
	void push_after_cursor(Data *p)
	{
		Node<Data> *newNode = new Node<Data>;
		newNode->data = *p;		
		if (cursor != 0)
		{
			newNode->next = cursor->next;
			cursor->next = newNode;
		}
		else 
			cursor = newNode;
		length++;
	}
	void push_before_cursor(Data *p)
	{
		Node<Data> *newNode = new Node<Data>;
		newNode->data = *p;
		newNode->next = cursor;

		if (preCursor != 0)
			preCursor->next = newNode;
		else //вставка в начало списка
			head = newNode;

		preCursor = newNode;
		length++;
	}

	int reverce()
	{
		int count = 0;
		Node<Data> *tmp = 0;
		Node<Data> *next = 0;
		if (head)
		{
			next = head->next;
			tail = head;
		}
		while (next != 0)
		{
			head->next = tmp;
			tmp = head;
			head = next;
			next = head->next;
			count++;
		}
		count = count + 1;
		head->next = tmp;
		return count;
	}
	List<Data>& operator = (const List<Data> &l)
	{
		if (this == &l)
			return *this;
		//clear
		Node <Data> *tmp;
		while (!isEmpty())
		{
			tmp = head;
			head = head->next;
			delete tmp;
		}
		tail = 0;
		//fill
		tmp = l.head;
		while (tmp != 0)
		{
			push_back(tmp->data);
			tmp = tmp->next;
		}
		//head = l.head;
		return *this;
	}
	friend bool operator ==(const List<Data> &l1, const List<Data> &l2)
	{
		Node<Data>* p1 = l1.head, *p2 = l2.head;
		while (p1 && p2)
		{
			if (p1->data != p2->data)
				return false;
			p1 = p1->next;
			p2 = p2->next;
		}
		return (p1 == 0 && p2 == 0);
	}

	friend class test;
	~List()
	{
		Node <Data> *tmp;
		while (!isEmpty())
		{
			tmp = head;
			head = head->next;
			delete tmp;
		}
	}
};