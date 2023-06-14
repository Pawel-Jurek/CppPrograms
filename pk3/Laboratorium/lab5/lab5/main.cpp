#include "list.h"

int main()
{
	Queue q1;
	Queue q2;
	
	q1.enqueue(1);
	q1.enqueue(2);
	q1.enqueue(3);
	q1.enqueue(10);
	std::cout << q1;
	auto a = q1.dequeue();
	std::cout << q1;
	q2 = q1;
	Queue q3(q2);
	std::cout << q2;
	q3.enqueue(15);
	std::cout << q3;
	std::cout << q3.get_size();
}