#pragma once

#include "LinkedList.hpp"

class Stack : public LinkedList
{
private:

public:
    Stack() : LinkedList() {}

    Stack(T data) : LinkedList(data) {}

    ~Stack();
};

Stack::~Stack()
{

}
