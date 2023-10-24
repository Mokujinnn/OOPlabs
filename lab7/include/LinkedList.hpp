#pragma once

#include <iostream>

#include "Node.hpp"

class LinkedList
{
private:
    Node * first;
    static int count;
    
public:
    LinkedList();

    LinkedList(int data);

    virtual ~LinkedList();

    void print();

    virtual void push(int data);

    virtual void pop();
};
