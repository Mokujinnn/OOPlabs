#include <iostream>

#include "LinkedList.hpp"
#include "Stack.hpp"
#include "Queue.hpp"

int main()
{
    LinkedList list;

    for (int i = 0; i < 10; i++)
    {
        list.push(i);
    }


    list.print();

    list.pop();
    list.print();
}