#ifndef DEQUEUE_H
#define DEQUEUE_H

#include <exception>
#include <iostream>
#include <string>

namespace dequeue {

/**
 *  @brief  Dequeue implementation using doubly circular linked list.
 *  @var  dequeue  LinkedList object used as a dequeue.
 *
 *  @tparam  T  Data type for dequeue.
 *
 *  This is a wrapper class that encapsulates an internal double circular
 *  linked list class. This class is meant to make the linked list class
 *  behave as a dequeue. Internally, methods from this class call methods
 *  from the internal double circular linked list object.
 */
template <class T>
class Dequeue {

#ifndef TESTING
    protected:
#endif
#ifdef TESTING
    public:
#endif
        /**
          *  @brief  Doubly circular linked list used to represent dequeue.
          *  @var  head  Pointer to first node in list.
          *  @var  tail  Pointer to last node in list.
          *
          *  This circular linked list class is meant to be used internally
          *  to represent a dequeue. The dequeue class is a wrapper class
          *  for this linked list container class to make it behave as a
          *  dequeue.
          */
        class LinkedList {
            public:
                /**
                   *  @brief  Doubly node used for circular linked list.
                   *  @var  data  Data held by node.
                   *  @var  next  Pointer to next node in list.
                   *  @var  prev  Pointer to previous node in list.
                   *
                   *  This is the node object for the double circular linked
                   *  list class. This is the most fundamental representation
                   *  of data in the dequeue.
                   */
                class Node {
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
                ~LinkedList() { deleteList(); }
                
                /**
                   *  @brief  Delete all nodes in the list. 
                   */
                void deleteList();

                /**
                   *  @brief  Add node to the beginning of a list.
                   *  @param  data  Data that new node will hold.
                   *
                   *  If list is empty, new node will become the head
                   *  and tail of the list. Otherwise, it will only
                   *  become the head of the list.
                   */
                void push(const T data);

                /**
                   *  @brief  Add node to the end of a list.
                   *  @param  data  Data that new node will hold.
                   *
                   *  If list is empty, new node will become the head
                   *  and tail of the list. Otherwisem it will only
                   *  become the tail of the list.
                   */
                void append(const T data);

                /**
                   *  @brief  Remove and return data instance variable of first node.
                   *  @return Data instance variable of head.
                   */
                T leftPop();

                /**
                   *  @brief  Remove and return data instance variable of last node.
                   *  @return Data instance variable of tail.
                   */
                T rightPop();

                /**
                   *  @brief  Return data instance variable of first node.
                   *  @return Data instance variable of head.
                   */
                T leftPeek() const;

                /**
                   *  @brief  Return data instance variable of last node.
                   *  @return Data instance variable of tail.
                   */
                T rightPeek() const;

                /**
                   *  @return True if linked list is empty, false otherwise.
                   */
                bool empty() const { return this->head == nullptr; }

                /**
                   *  @brief  Print data instance variable of every node.
                   */
                void print() const;
        };  /// Dequeue::LinkedList

        LinkedList dequeue;

    public:
        Dequeue() : dequeue(LinkedList()) { }
        ~Dequeue() { deleteDequeue(); }
        void deleteDequeue() { dequeue.deleteList(); }

        typename Dequeue<T>::LinkedList::Node* getHead() const { return dequeue.head; }
        typename Dequeue<T>::LinkedList::Node* getTail() const { return dequeue.tail; }

        Dequeue(const Dequeue& q);
        Dequeue& operator =(const Dequeue& q);
        Dequeue(Dequeue&& q);
        Dequeue& operator =(Dequeue&& q);

        /**
          *  @brief  Add a node to the font of the dequeue.
          *  @param  data  Data to add to the front of the dequeue.
          */
        void insertFront(const T data) { dequeue.push(data); }

        /**
          *  @brief  Add a node to the end of the dequeue.
          *  @param  data  Data to add to the end of the dequeue.
          */
        void insertRear(const T data) { dequeue.append(data); }

        /**
          *  @brief  Remove and return data instance variable of first node.
          *  @return Data instance variable of the first node.
          */
        T deleteFront() { return dequeue.leftPop(); }

        /**
          *  @brief  Remove and return data instance variable of last node.
          *  @return Data instance variable of the last node.
          */
        T deleteRear() { return dequeue.rightPop(); }

        /**
          *  @brief  Return data instance variable of first node.
          *  @return Data instance variable of first node.
          */
        T getFront() const { return dequeue.leftPeek(); }

        /**
          *  @brief  Return data instance variable of last node.
          *  @return Data instance variable of last node.
          */
        T getRear() const { return dequeue.rightPeek(); }

        /**
          *  @return True if dequeue is empty, false otherwise.
          */
        bool empty() const { return dequeue.empty(); }

        /**
          *  @brief  Print every node in the dequeue.
          */
        void print() const { dequeue.print(); }
};  /// Dequeue


struct EmptyDequeue : public std::exception {
    const char* what() const throw() {
        return "Dequeue is empty.";
	}
};


// ========================== Dequeue=========================

/// copy ctor
template <class T>
Dequeue<T>::Dequeue(const Dequeue& q) {
    if (q.getHead() == nullptr) {
        return;
    }
    typename Dequeue<T>::LinkedList::Node* temp = q.getHead();
    do {
        this->insertRear(temp->data);
        temp = temp->next;
    }
    while (temp != q.getHead());
}


/// copy assignment
template <class T>
Dequeue<T>& Dequeue<T>::operator =(const Dequeue& q) {
    if (q.getHead() != nullptr) {
        typename Dequeue<T>::LinkedList::Node* temp = q.getHead();
        do {
            this->insertRear(temp->data);
            temp = temp->next;
        }
        while (temp != q.getHead());
    }
    return *this;
}


/// move ctor
template <class T>
Dequeue<T>::Dequeue(Dequeue&& q) {
    if (q.getHead() == nullptr) {
        return;
    }
    typename Dequeue<T>::LinkedList::Node* temp = q.getHead();
    do {
        this->insertRear(temp->data);
        temp = temp->next;
    }
    while (temp != q.getHead());
    q.deleteDequeue();
}


/// move assignment
template <class T>
Dequeue<T>& Dequeue<T>::operator =(Dequeue&& q) {
    if (q.getHead() != nullptr) {
        typename Dequeue<T>::LinkedList::Node* temp = q.getHead();
        do {
            this->insertRear(temp->data);
            temp = temp->next;
        }
        while (temp != q.getHead());
    }
    q.deleteDequeue();
    return *this;
}
// ========================== Dequeue=========================


// =================== Dequeue::LinkedList ===================

/// delete list
template <class T>
void Dequeue<T>::LinkedList::deleteList() {
    if (head == nullptr) {
        return;
    }
    Node *curr = head;
    do {
        Node *temp = curr;
        curr = curr->next;
        delete temp;
    }
    while (curr != head);
    head = nullptr;
    tail = nullptr;
}


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
T Dequeue<T>::LinkedList::rightPop() {
    if (head == nullptr)
        throw EmptyDequeue();

    Node* temp = tail;
    T data = tail->data;
    if (tail == head) {
        Node* head_temp = head;
        delete head_temp;
        tail = nullptr;
        head = nullptr;
    }
    else {
        tail->prev->next = tail->next;
        tail->next->prev = tail->prev;
        tail = tail->prev;
    }
    delete temp;
    return data;
}


/// Delete and return the first node in a list
template <class T>
T Dequeue<T>::LinkedList::leftPop() {
    if (head == nullptr)
        throw EmptyDequeue();

    Node* temp = head;
    T data = head->data;
    if (tail == head) {
        Node* tail_temp = tail;
        delete tail_temp;
        tail = nullptr;
        head = nullptr;
    }
    else {
        head->next->prev = head->prev;
        head->prev->next = head->next;
        head = head->next;
    }
    delete temp;
    return data;
}


/// View head of dequeue without removing it
template <class T>
T Dequeue<T>::LinkedList::leftPeek() const {
    if (!head)
        throw EmptyDequeue();
    return head->data;
}


/// View tail of dequeue without removing it
template <class T>
T Dequeue<T>::LinkedList::rightPeek() const {
    if (!tail)
        throw EmptyDequeue();
    return tail->data;
}


/// Print the contents of a list in order
template <class T>
void Dequeue<T>::LinkedList::print() const {
    Node* probe = head;
    if (probe == nullptr) {
        return;
    }
    do {
        std::cout << probe->data << " ";
        probe = probe->next;
    }
    while (probe != head);
}

// =================== Dequeue::LinkedList ===================

}  /// namespace dequeue

typedef dequeue::Dequeue<int> deq;

#endif /// DEQUEUE_H
