#pragma once


struct Node
{
    int data;
    Node * next;
    Node * prev;

    Node() : data(0), next(nullptr), prev(nullptr) {}

    Node(int data, Node * next, Node * prev) : data(data), next(next), prev(prev) {}

    ~Node() {};
};