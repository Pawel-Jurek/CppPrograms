#include "Queue.h"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
    Queue q(5);

    for (int i = 2; i < 2 + q.get_capacity(); i++)
    {
        q.enqueue(i);
    }
    //q.enqueue(3); //overflow test
    cout << q;
    cout << "\nThe first element is " << q.get_first() << endl;
    q.dequeue();
    cout << q;
    q.enqueue(4);
    cout << q;
    cout << "The queue size is " << q.get_size() << endl;

    //Queue a = q;

    for (int i = 2; i < 2 + q.get_capacity(); i++)
    {
        q.dequeue();
    }
    cout << q;

    //cout << "a: " << a;
    //q.dequeue(); //underflow test

    return 0;
}