#ifndef LINKED_LIST_STACK_H
#define LINKED_LIST_STACK_H

#include <iostream>


template <class T = int>
class Node
{
    public:
        T data;
        Node<T>* next = nullptr;

        Node(const T data) { this->data = data; }
};


template <class T = int>
class Stack
{
    private:
        int len;
        Node<T>* head;

    public:
        Stack();
        Stack(const T data);
        virtual ~Stack() { delete head; }

        void push(const T data);
        T pop();
        T peek();
        bool empty() { return this->head == nullptr; }
        int size() { return this->len; }

};


#include "linked_list_stack.tpp"

#endif // LINKED_LIST_STACK_H
