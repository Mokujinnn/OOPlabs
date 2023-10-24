#pragma once

#include "LinkedList.hpp"

class Queue : public LinkedList
{
private:
    
public:
    Queue() : LinkedList() {}

    Queue(int data) : LinkedList(data) {}

    ~Queue();
};