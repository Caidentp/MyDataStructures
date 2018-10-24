#ifndef LINKED_LIST_STACK_H
#define LINKED_LIST_STACK_H
#include <iostream>


template <class T = int>
class Node
{
    private:
        T data;
        Node<T>* next = nullptr;

    public:
        Node(const T data) { this->data = data; }
        ~Node() { delete next; }

        T get_data() const { return this->data; }
        void set_data(const T data) { this->data = data; }
        Node<T>* get_next() const { return this->next; }
        void set_next(Node<T>* next) { this->next = next; }
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
        ~Stack() { delete head; }

        void push(const T data);
        T pop();
        T peek();
        bool isEmpty();
        int length() { return this->len; }

};

#include "linked_list_stack.tpp"
#endif // LINKED_LIST_STACK_H
