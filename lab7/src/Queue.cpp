#include "Queue.hpp"

int Queue::countqueue = 0;

Queue::~Queue()
{
    this->countqueue--;
}

Queue::cnt()
{
    return Queue::countstack;
}

Queue::pop()
{
    Node* node = nullptr;

    for(; node->next != nullptr; node = node->next){};

    
}