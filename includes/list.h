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
	Node <Data> *end;
public:
	List() : head(0), end(0) {};
	List(List &l)
	{
		Node<Data> *p = l.head;
		while (p!=0)
		{
			push_back(p->data);
			p = p->next;
		}
	}

	bool isEmpty() { return (head == 0); }

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
			end = 0;
		}
		return tmp.data;
	}
	Node<Data>* GetpTop() const
	{
		return head;
	}

	void push_front(Data obj)
	{
		Node<Data> *newNode = new Node<Data>;
		newNode->data = obj;
		newNode->next = head;
		if (end == 0)
			end = head;
		head = newNode;
	}
	void push_back(Data obj)
	{
		Node<Data> *newNode = new Node<Data>;
		newNode->data = obj;
		newNode->next = 0;
		if (end == 0)
		{
			end = newNode;
			head = newNode;
		}
		else 
		{
			end->next = newNode;
			end = newNode;
		}
	}
	void push_after(Node<Data> *p, Data d)
	{
		Node<Data> *newNode = new Node<Data>;
		newNode->data = d;
		if (p != 0)
		{			
			if (p->next = 0)
				end = newNode;
			newNode->next = p->next;
			p->next = newNode;
		}
		else
		{
			end = newNode;
			head = newNode;
		}
	}

	int reverce()
	{
		int count = 0;
		Node<Data> *tmp = 0;
		Node<Data> *next = 0;
		if (head)
		{
			next = head->next;
			end = head;
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
		//fill
		Node<Data> *p = l.head;
		while (p != 0)
		{
			push_back(p->data);
			p = p->next;
		}
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