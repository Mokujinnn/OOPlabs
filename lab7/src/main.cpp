#include <iostream>

#include "LinkedList.hpp"

int main()
{

    LinkedList<int> list;

    for (int i = 0; i < 10; i++)
    {
        list.pushBack(i);
    }


    list.print();

    list.popFront();
    list.print();
}