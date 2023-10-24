#pragma once

#include <iostream>

#include "Node.hpp"

template<typename T>
class LinkedList
{
private:
    Node<T> * first;
    Node<T> * last;

public:
    LinkedList() : first(nullptr), last(nullptr) {}

    LinkedList(T data);

    ~LinkedList();

    void print();

    void pushFront(T data);

    void pushBack(T data);

    void popFront();

    void popBack();
};

template<typename T>
LinkedList<T>::LinkedList(T data) : first(new Node<T>)
{
    this->first->data = data;
    this->last = this->first;
}

template<typename T>
LinkedList<T>::~LinkedList()
{
    for (Node<T>* node = this->first; node != nullptr; node = node->next)
    {
        delete node;
    }
}

template<typename T>
void LinkedList<T>::print()
{
    for (Node<T>* node = this->first; node != nullptr; node = node->next)
    {
        std::cout << node->data << ' ';
    }
    std::cout << '\n';
}

template<typename T>
void LinkedList<T>::pushFront(T data)
{
    Node<T> *node;

    if (this->first == nullptr)
    {
        node = new Node<T>;
        node->data = data;
        this->first = node;
        this->last = node;
    }
    else
    {
        node = new Node<T>(data, this->first, nullptr);
        this->first->prev = node;
        this->first = node;
    }
}

template<typename T>
void LinkedList<T>::pushBack(T data)
{
    Node<T> *node;

    if (this->first == nullptr)
    {
        node = new Node<T>;
        node->data = data;
        this->first = node;
        this->last = node;
    }
    else
    {
        node = new Node<T>(data, nullptr, this->last);
        this->last->next = node;
        this->last = node;
    }
}

template<typename T>
void LinkedList<T>::popFront()
{
    if (this->first == nullptr)
    {
        return;
    }
    
    Node<T> * next = this->first->next;

    delete this->first;

    if (next != nullptr)
        next->prev = nullptr;
    else
        this->last = nullptr;

    this->first = next;

}

template<typename T>
void LinkedList<T>::popBack()
{
    if (this->last == nullptr)
    {
        return;
    }
    
    Node<T> * prev = this->last->prev;

    delete this->last;

    if (prev != nullptr)
        prev->next = nullptr;
    else
        this->first = nullptr;

    this->last = prev;

}