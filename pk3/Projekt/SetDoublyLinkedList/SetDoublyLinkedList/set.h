#pragma once
#include "list.h"

template <class T>
class Set : public DoublyLinkedList<T>
{
public:
	Set() :DoublyLinkedList<T>() {};
	Set(const Set<T>& set) :DoublyLinkedList<T>(set) {};
	~Set() { DoublyLinkedList<T>::~DoublyLinkedList(); };

	inline Node<T>* get_head() { return DoublyLinkedList<T>::get_head(); }
	inline Node<T>* get_tail() { return DoublyLinkedList<T>::get_tail(); }

	void add_element(T x);
	Node<T>* remove_element(T x);
	inline Node<T>* get(int index) { return DoublyLinkedList<T>::get(index); };
	inline int get_size() { return DoublyLinkedList<T>::size(); };
	const bool check_existence(const T& x);
	void clear();

	Set<T>& operator= (Set<T>& set);

	Set<T>& operator* (Set<T>& set);
	Set<T>& operator+ (Set<T>& set);
	Set<T>& operator- (Set<T>& set);

	Set<T>& operator+= (Set<T>& set);
	Set<T>& operator-= (Set<T>& set);
	Set<T>& operator*= (Set<T>& set);
	template <class N>
	friend std::ostream& operator<< (std::ostream& s, Set <N>& set);
};

template<class T>
inline void Set<T>::add_element(T x)
{
	if (this->search(x) == -1)
	{
		DoublyLinkedList<T>::insert_head(x);
	}
}

template<class T>
inline Node<T>* Set<T>::remove_element(T x)
{
	const int pos = this->search(x);
	Node<T>* element = nullptr;
	if (pos != -1)
	{
		element = this->get(pos);
		this->remove(pos);
	}
	return element;
}

template<class T>
inline const bool Set<T>::check_existence(const T& x)
{
	if (this->search(x) != -1)
		return true;
	return false;
}

template<class T>
inline void Set<T>::clear()
{
	while (this->get_size() > 0) {
		this->remove_head();
	}
}

template<class T>
inline Set<T>& Set<T>::operator=(Set<T>& set)
{
	if (this != &set)
	{
		if (this->get_size() > 0)
			this->clear();
		Node<T>* it = set.get_head();
		while (it)
		{
			T obj = it->value;
			this->add_element(obj);
			it = it->next;
		}
	}
	return *this;
}

template <class N>
std::ostream& operator<< (std::ostream& s, Set <N>& set)
{
	Node<N>* temp_node = set.get_head();
	s << "[";
	while (temp_node) {
		s << temp_node->value;
		if (temp_node != set.get_tail())
			s << ", ";
		temp_node = temp_node->next;
	}
	s << "]\n";
	return s;
}

template<class T>
inline Set<T>& Set<T>::operator*(Set<T>& set)
{
	Set<T> intersection{};

	if (this->get_size() > 0 && set.get_size() > 0)
	{
		Node<T>* temp_node = this->get_head();
		while (temp_node)
		{
			if (set.check_existence(temp_node->value))
			{
				intersection.add_element(temp_node->value);
			}
			temp_node = temp_node->next;
		}
	}

	return intersection;
}

template<class T>
inline Set<T>& Set<T>::operator+(Set<T>& set)
{
	Set<T> sum(*this);
	Node<T>* temp_node = set.get_head();

	while (temp_node)
	{
		sum.add_element(temp_node->value);
		temp_node = temp_node->next;
	}

	return sum;
}

template<class T>
inline Set<T>& Set<T>::operator- (Set<T>& set)
{
	Set<T> difference{};

	if (this->get_size() > 0 && set.get_size() > 0)
	{
		Node<T>* temp_node = this->get_head();
		while (temp_node)
		{
			if (!set.check_existence(temp_node->value))
			{
				difference.add_element(temp_node->value);
			}
			temp_node = temp_node->next;
		}
	}

	return difference;
}

template<class T>
inline Set<T>& Set<T>::operator+=(Set<T>& set)
{
	Set<T> temp(*this + set);
	*this = temp;
	return *this;
}

template<class T>
inline Set<T>& Set<T>::operator-=(Set<T>& set)
{
	Set<T> temp(*this - set);
	*this = temp;
	return *this;
}

template<class T>
inline Set<T>& Set<T>::operator*=(Set<T>& set)
{
	Set<T> temp(*this * set);
	*this = temp;
	return *this;
}
