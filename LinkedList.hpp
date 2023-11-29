#pragma once

class Node
{
	public:
		Node(void* value);
		Node();
		~Node();
		Node( Node const & src );
		Node &		operator=( Node const & rhs );
		void* data;
		Node* next;
};

class LinkedList
{
	public:
		LinkedList();
		~LinkedList();
		LinkedList( LinkedList const & src );
		LinkedList &		operator=( LinkedList const & rhs );
		void insertAtEnd(void* value);
		void clear();
	private:
		Node* head;
};