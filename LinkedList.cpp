#include "LinkedList.hpp"
#include <cstdlib>

Node::Node(void* value) : data(value), next(NULL)
{

}

Node::Node() : data(NULL), next(NULL)
{

}

Node::~Node()
{

}

Node::Node( Node const & src )
{
	*this = src;
}

Node &		Node::operator=( Node const & rhs )
{
	if (this != &rhs)
	{
		this->data = rhs.data;
		this->next = rhs.next;
	}
	return (*this);
}

LinkedList::LinkedList() : head(NULL)
{

}

LinkedList::~LinkedList()
{
	clear();
}

LinkedList::LinkedList( LinkedList const & src )
{
	*this = src;
}

LinkedList &		LinkedList::operator=( LinkedList const & rhs )
{
	if (this != &rhs)
	{
		clear();
		Node* current = rhs.head;
		while (current)
		{
			insertAtEnd(current->data);
			current = current->next;
		}
	}
	return (*this);
}

void LinkedList::insertAtEnd(void* value)
{
	Node* newNode = new Node(value);

	if (!this->head)
	{
		this->head = newNode;
		return;
	}

	Node* current = this->head;
	while (current->next)
	{
		current = current->next;
	}

	current->next = newNode;
}

void LinkedList::clear()
{
	Node* current = head;
	Node* nextNode;

	while (current)
	{
		nextNode = current->next;
		delete current->data;
		delete current;
		current = nextNode;
	}

	head = NULL;
}