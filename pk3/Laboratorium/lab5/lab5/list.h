#pragma once
#include <iostream>

class Node
{
public:
	int value;
	Node* prev;
	Node* next;
	Node(int value = 0) : value{ value }, prev{ nullptr }, next{ nullptr } {};
};

class DoublyLinkedList {
private:
	int counter;
	Node* head;
	Node* tail;
public:
	DoublyLinkedList() = default;
	DoublyLinkedList(const DoublyLinkedList& copied);
	~DoublyLinkedList();
	Node* get(int index) const;

	inline Node* get_head() { return head; }
	void insert_head(const int& element);
	void insert_tail(const int& element);
	void insert(int index, const int& element);

	int search(const int& value) const;

	void remove_head();
	void remove_tail();
	void remove(int index);

	int size() const;
	friend std::ostream& operator<< (std::ostream& s, const DoublyLinkedList& list);
	DoublyLinkedList& operator= (const DoublyLinkedList& list);
};

class Queue :public DoublyLinkedList
{
public:
	Queue() :DoublyLinkedList() {};
	~Queue() { DoublyLinkedList::~DoublyLinkedList(); };

	inline Node* get_head() { return DoublyLinkedList::get_head(); }
	Node* dequeue();
	void enqueue(int x) { DoublyLinkedList::insert_tail(x); };
	inline Node* get(int index) { return DoublyLinkedList::get(index); };
	inline int get_size() {return DoublyLinkedList::size();};
	friend std::ostream& operator<< (std::ostream& s, Queue& q);
	
};
