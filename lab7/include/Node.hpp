#pragma once

template<typename T>
struct Node
{
    T data;
    Node<T> * next;
    Node<T> * prev;

    Node() : data(0), next(nullptr), prev(nullptr) {}

    Node(T data, Node<T> * next, Node<T> * prev) : data(data), next(next), prev(prev) {}

    ~Node() {};
};