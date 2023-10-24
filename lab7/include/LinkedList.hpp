#pragma once

#include <iostream>

#include "Node.hpp"

class LinkedList
{
protected:
    Node * first;
    static int count;
    
public:
    LinkedList();

    LinkedList(int data);

    virtual ~LinkedList();

    virtual int cnt();

    void print();

    virtual void push(int data);

    virtual void pop();
};
