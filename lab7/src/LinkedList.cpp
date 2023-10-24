#include "LinkedList.hpp"

int LinkedList::count = 0;

LinkedList::LinkedList() : first(nullptr)
{
    this->count++;
}

LinkedList::LinkedList(int data) : first(new Node)
{
    this->first->data = data;
    this->count++;
}

LinkedList::~LinkedList()
{
    for (Node* node = this->first; node != nullptr; node = node->next)
    {
        delete node;
    }
    this->count--;
}

int LinkedList::cnt()
{
    return LinkedList::count;
}

void LinkedList::print()
{
    for (Node* node = this->first; node != nullptr; node = node->next)
    {
        std::cout << node->data << ' ';
    }
    std::cout << '\n';
}

void LinkedList::push(int data)
{
    Node *node;

    if (this->first == nullptr)
    {
        node = new Node;
        node->data = data;
        this->first = node;
    }
    else
    {
        node = new Node(data, this->first, nullptr);
        this->first->prev = node;
        this->first = node;
    }
}

void LinkedList::pop()
{
    if (this->first == nullptr)
    {
        return;
    }
    
    Node * next = this->first->next;

    delete this->first;

    if (next != nullptr)
        next->prev = nullptr;

    this->first = next;

}