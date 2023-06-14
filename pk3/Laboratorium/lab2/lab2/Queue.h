#pragma once
#include <iostream>

class Queue
{
    int* arr;
    int capacity;
    int first_elem_pos;
    int last_elem_pos;
    int current_size;

public:
    Queue(int size = 10);     
    ~Queue();                   

    int dequeue();
    void enqueue(int x);
    int get_first();
    int get_size();
    bool isEmpty();
    bool isFull();
    int get_capacity();
    friend std::ostream& operator<< (std::ostream &s, const Queue &q);
    Queue& operator= (const Queue& q);
};