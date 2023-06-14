#include "Queue.h"


using std::cout; 
using std::endl;


Queue::Queue(int size)
{
    arr = new int[size];
    capacity = size;
    first_elem_pos = 0;
    last_elem_pos = -1;
    current_size = 0;
}

Queue::~Queue()
{
    delete[] arr;
}

int Queue::dequeue()
{
    if (isEmpty())
    {
        cout << "Underflow\n";
        exit(EXIT_FAILURE);
    }

    int x = arr[first_elem_pos];
    cout << "Removing: " << x << endl;

    first_elem_pos = (first_elem_pos + 1) % capacity;
    current_size--;

    return x;
}

void Queue::enqueue(int item)
{
    if (isFull())
    {
        cout << "Overflow\n";
        exit(EXIT_FAILURE);
    }

    cout << "Inserting [" << item << "]" << endl;

    last_elem_pos = (last_elem_pos + 1) % capacity;
    arr[last_elem_pos] = item;
    current_size++;
}

int Queue::get_first()
{
    if (isEmpty())
    {
        cout << "Underflow\n";
        exit(EXIT_FAILURE);
    }
    return arr[first_elem_pos];
}

int Queue::get_size() {
    return current_size;
}

bool Queue::isEmpty() {
    return (get_size() == 0);
}

bool Queue::isFull() {
    return (get_size() == capacity);
}


std::ostream& operator<< (std::ostream &s, const Queue &q)
{
    s << "[";  
    int first = q.first_elem_pos;
    int last = q.current_size;

    for (int i = first; i < first + last; i++)
    {
        s << q.arr[i % q.capacity];
        if (i + 1 < first + last)
        {
            s << ", ";
        }
    }
    s << "]\n";
    return s;
}

Queue &Queue::operator= (const Queue& q)
{
    if (&q != this)
    {
        arr = q.arr;
        capacity = q.capacity;
        first_elem_pos = q.first_elem_pos;
        last_elem_pos = q.last_elem_pos;
        current_size = q.last_elem_pos;
    }
    return *this;
}

int Queue::get_capacity()
{
    return capacity;
}