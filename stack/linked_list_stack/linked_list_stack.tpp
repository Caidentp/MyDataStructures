#include "linked_list_stack.h"


template <class T>
Stack<T>::Stack()
{
    this->head = nullptr;
    this->len = 0;
}


template <class T>
Stack<T>::Stack(const T data)
{
    Node<T>* new_node = new Node<T>(data);
    this->head = new_node;
    this->len++;
}


template <class T>
void Stack<T>::push(const T data)
{
    Node<T>* new_node = new Node<T>(data);
    if (this->head == nullptr)
        this->head = new_node;
    else
    {
        new_node->set_next(this->head);
        this->head = new_node;
    }
    this->len++;
}


template <class T>
T Stack<T>::pop()
{
    if (this->len > 0)
    {
        T data = this->head->get_data();
        this->head = this->head->get_next();
        this->len--;
        return data;
    }
}


template <class T>
T Stack<T>::peek()
{
    if (this->head != nullptr)
        return this->head->get_data();
}


template <class T>
bool Stack<T>::isEmpty()
{
    return this->len == 0;
}
