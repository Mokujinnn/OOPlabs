#pragma once

#include "LinkedList.hpp"

class Queue : public LinkedList
{
private:
    static int countqueue;
    
public:
    Queue();

    Queue(int data);

    ~Queue();

    static void cnt();

    void pop();
};