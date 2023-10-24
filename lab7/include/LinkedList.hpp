#pragma once

#include <iostream>

#include "Node.hpp"

class LinkedList
{
private:
    Node * first;
    
public:
    LinkedList() : first(nullptr) {}

    LinkedList(int data);

    virtual ~LinkedList();

    void print();

    virtual void push(int data);

    virtual void pop();
};
