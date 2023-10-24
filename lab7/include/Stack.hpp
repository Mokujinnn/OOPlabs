#pragma once

#include "LinkedList.hpp"

class Stack : public LinkedList
{
private:

public:
    Stack() : LinkedList() {}

    Stack(int data) : LinkedList(data) {}

    ~Stack();
};
