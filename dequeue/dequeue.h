#ifndef DEQUEUE_H
#define DEQUEUE_H

#include <iostream>
#include <string>


namespace dequeue {


/** Dequeue implementation using doubly circular linked list.
 *
 * template class T : Data type for dequeue.
 *
 * @param dequeue : LinkedList object used as a dequeue.
 */
template <class T>
class Dequeue
{
    private:

        /** Doubly circular linked list used to represent
         * dequeue.
         *
         * @param head : Pointer to first node in list.
         * @param tail : Pointer to last node in list.
         */
        class LinkedList
        {
            private:

                /** Doubly node used for circular linked list.
                 *
                 * @param data : Data held by node.
                 * @param next : Pointer to next node in list.
                 * @param prev : Pointer to previous node in list.
                 */
                class Node
                {
                    public:
                        T data;
                        Node* next;
                        Node* prev;
                        Node(T data, Node* next = nullptr, Node* prev = nullptr)
                            : data(data)
                            , next(next)
                            , prev(prev) { }
                };  /// Dequeue::LinkedList::Node

                Node* head;
                Node* tail;

            public:
                LinkedList()
                    : head(nullptr)
                    , tail(nullptr) { }
                ~LinkedList() { delete head; }

                Node* get_head() const { return head; }
                Node* get_tail() const { return tail; }

                void push(const T data);
                void append(const T data);
                T right_pop();
                T left_pop();
                T left_peek() const { return head->data; }
                T right_peek() const { return tail->data; }

                void print() const;
        };  /// Dequeue::LinkedList

        LinkedList dequeue;

    public:
        Dequeue() { dequeue = LinkedList(); }

        void insertFront(const T data) { dequeue.push(data); }
        void insertRear(const T data) { dequeue.append(data); }
        T deleteFront() { dequeue.left_pop(); }
        T deleteRear() { dequeue.right_pop(); }
        T getFront() const { dequeue.left_peek(); }
        T getRear() const { dequeue.right_peek(); }
        void print() const { dequeue.print(); }
};



/// Add a node to the beginning of a list
template <class T>
void Dequeue<T>::LinkedList::push(const T data) {
    if (head == nullptr) {
        Node* new_node = new Node(data);
        head = new_node;
        tail = new_node;
        head->next = head;
        head->prev = head;
    }
    else {
        Node* new_node = new Node(data, head, tail);
        head->prev = new_node;
        tail->next = new_node;
        head = new_node;
    }
}


/// Add a node to the end of a list
template <class T>
void Dequeue<T>::LinkedList::append(const T data) {
    if (head == nullptr)
        this->push(data);
    else {
        Node* new_node = new Node(data, head, tail);
        tail->next = new_node;
        head->prev = new_node;
        tail = new_node;

    }
}


/// Delete and return the first node in a list
template <class T>
T Dequeue<T>::LinkedList::right_pop() {
    if (head != nullptr) {
        T data = tail->data;
        if (tail == head) {
            tail = nullptr;
            head = nullptr;
        }
        else {
            tail->prev->next = tail->next;
            tail->next->prev = tail->prev;
            tail = tail->prev;
        }
        return data;
    }
}


/// Delete and return the first node in a list
template <class T>
T Dequeue<T>::LinkedList::left_pop() {
    if (head != nullptr) {
        T data = head->data;
        if (tail == head) {
            tail = nullptr;
            head = nullptr;
        }
        else {
            head->next->prev = head->prev;
            head->prev->next = head->next;
            head = head->next;
        }
        return data;
    }
}


/// Print the contents of a list in order
template <class T>
void Dequeue<T>::LinkedList::print() const {
    Node* probe = head;
    do {
        std::cout << probe->data << " ";
        probe = probe->next;
    }
    while (probe != head);
}



}  /// namespace dequeue


typedef dequeue::Dequeue<T> dequeue;


#endif /// DEQUEUE_H
