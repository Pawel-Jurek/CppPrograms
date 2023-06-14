#include "list.h"

Node* Queue::dequeue()
{
	auto temp = DoublyLinkedList::get(0);
	DoublyLinkedList::remove_head();
	return temp;
}

std::ostream& operator<< (std::ostream& s, const DoublyLinkedList& list)
{
	Node* temp_node = list.head;
	s << "[";
	while (temp_node) {
		s << temp_node->value;
		if (temp_node != list.tail)
			s << ", ";
		temp_node = temp_node->next;
	}
	s << "]\n";
	return s;
}

DoublyLinkedList::DoublyLinkedList (const DoublyLinkedList& copied)
{
	if (this != &copied)
	{
		Node* it = copied.head;
		while (it)
		{
			int obj = it->value;
			this->insert_tail(obj);
			it = it->next;
		}
	}
}

DoublyLinkedList& DoublyLinkedList:: operator= (const DoublyLinkedList& list)
{
	if (this != &list)
	{
		Node* it = list.head;
		while (it)
		{
			int obj = it->value;
			insert_tail(obj);
			it = it->next;
		}
	}
	return *this;
}


std::ostream& operator<< (std::ostream& s, Queue& q)
{
	Node* temp_node = q.get_head();
	s << "[";
	while (temp_node) {
		s << temp_node->value;
		s << " ";
		temp_node = temp_node->next;
	}
	s << "]\n";
	return s;
}


void DoublyLinkedList::remove_tail()
{
	if (counter == 0) {
		return;
	}

	if (counter == 1)
	{
		remove_head();
		return;
	}

	Node* node = tail;
	tail = tail->prev;

	tail->next = nullptr;

	delete node;
	counter--;
}

void DoublyLinkedList::remove_head()
{
	if (counter == 0) {
		return;
	}

	Node* node = head;

	head = head->next;

	delete node;

	if (head != nullptr) {
		head->prev = nullptr;
	}

	counter--;
}

void DoublyLinkedList::remove(int index)
{
	if (counter == 0) {
		return;
	}

	if (index < 0 || index >= counter) {
		return;
	}

	if (index == 0)
	{
		remove_head();
		return;
	}

	else if (index == counter - 1)
	{
		remove_tail();
		return;
	}

	Node* prev_node = head;

	for (int i = 0; i < index - 1; ++i)
	{
		prev_node = prev_node->next;
	}

	Node* node = prev_node->next;
	Node* next_node = node->next;

	prev_node->next = next_node;
	next_node->prev = prev_node;

	delete node;
	counter--;
}

void DoublyLinkedList::insert_head(const int& value)
{
	Node* node = new Node{ value };
	node->next = head;

	if (head != nullptr) {
		head->prev = node;
	}

	head = node;

	if (counter == 0) {
		tail = head;
	}

	counter++;
}

void DoublyLinkedList::insert_tail(const int& value)
{
	if (counter == 0)
	{
		insert_head(value);
		return;
	}

	Node* node = new Node{ value };
	tail->next = node;
	node->prev = tail;
	tail = node;

	counter++;
}

void DoublyLinkedList::insert(int index, const int& value)
{
	if (index < 0 || index > counter) {
		return;
	}

	if (index == 0)
	{
		insert_head(value);
		return;
	}

	else if (index == counter)
	{
		insert_tail(value);
		return;
	}

	Node* prev_node = head;

	for (int i = 0; i < index - 1; ++i)
	{
		prev_node = prev_node->next;
	}

	Node* next_node = prev_node->next;

	Node* node = new Node{ value };

	node->next = next_node;
	node->prev = prev_node;
	prev_node->next = node;
	next_node->prev = node;

	counter++;
}

int DoublyLinkedList::size() const {
	return counter;
}

int DoublyLinkedList::search(const int& value) const {

	if (counter == 0) {
		return -1;
	}

	int index = 0;

	Node* temp_node = head;

	while (temp_node->value != value)
	{
		index++;
		temp_node = temp_node->next;

		if (!temp_node)
		{
			return -1;
		}
	}

	return index;
}

DoublyLinkedList::~DoublyLinkedList()
{
	Node* temp;
	while (head) {
		temp = head->next;
		delete head;
		head = temp;
	}
}

Node* DoublyLinkedList::get(int index) const
{
	if (index < 0 || index > counter) {
		return nullptr;
	}

	if (index == 0) {
		return head;
	}

	if (index == counter - 1) {
		return tail;
	}

	Node* temp_node = head;

	for (int i = 0; i < index; ++i)
	{
		temp_node = temp_node->next;
	}

	return temp_node;
}