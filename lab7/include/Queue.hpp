#pragma once

#include "LinkedList.hpp"

class Queue : public LinkedList
{
private:
    static int countqueue
    
public:
    Queue() : LinkedList() {this->countqueue++;}

    Queue(int data) : LinkedList(data) {this->countqueue++;}

    ~Queue();
};