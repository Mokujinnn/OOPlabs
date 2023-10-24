#pragma once

#include "LinkedList.hpp"

class Stack : public LinkedList
{
private:
    static int countstack;

public:
    Stack() : LinkedList() { this->countstack++; }

    Stack(int data) : LinkedList(data) {this->countstack++;}

    ~Stack();
};
