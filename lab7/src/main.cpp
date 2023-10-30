#include <iostream>

#include "LinkedList.hpp"
#include "Stack.hpp"
#include "Queue.hpp"

int main()
{
    LinkedList::cnt();
    Stack stack;

    Stack::cnt();

    LinkedList::cnt();

    LinkedList list;

    Queue q;

    q.pop();
    list.pop();
    stack.pop();
    LinkedList::cnt();
    Queue::cnt();

    list.print();
}