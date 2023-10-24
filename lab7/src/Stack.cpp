#include "Stack.hpp"

int Stack::countstack = 0;

Stack::~Stack()
{
    this->countstack--
}

int Stack::cnt()
{
    return Stack::countstack;
}
