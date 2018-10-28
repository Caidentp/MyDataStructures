#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "node.h"



/** Abstract Base Class for Singly, Doubly, and Circular linked lists.
 *
 * template class T1: The data type that the linked list nodes will hold.
 *      - Defaults to int.
 * template class T2: The type of linked list node that the list will consist of.
 *      - This type will default to the appropriate node based on the linked list type.
 */
template <class T1, class T2>
class LinkedListABC
{
    private:
        /// The head node of a linked list
        T2* head = nullptr;

        /// The tail node of a linked list
        T2* tail = nullptr;

        /// The total number of nodes currently in a linked list
        int len = 0;

    protected:
        T2* get_head() const    { return this->head; }
        void set_head(T2* head) { this->head = head; }
        T2* get_tail() const    { return this->tail; }
        void set_tail(T2* tail) { this->tail = tail; }
        void set_len(int len)   { this->len = len; }

    public:
        LinkedListABC();
        LinkedListABC(const T1 data);
        virtual ~LinkedListABC() { delete head; }

        /**
            @return len instance variable.
        */
        int length() const { return this->len; }

        /**
            Check to see if a node exists in a list by its data instance variable.

            @param data : The data instance variable to search the list for.
            @return True : if a node in the list contains the data, false otherwise.
        */
        bool contains(const T1 data);

        /**
            Find the index of a node by its data instance variable.

            @param data : Data to search the list for.
            @return Index of node that contains data.
        */
        int find_index_of(const T1 data);

        /**
            Print the list in order starting at the head and ending at the tail.
        */
        void print() const;

        /**
            Add a node to the beginning of a list.

            @param data : Data instance variable of new node.
        */
        virtual void push(const T1 data) = 0;

        /**
            Add a node to the end of a list.

            @param data : Data instance variable of new node.
        */
        virtual void append(const T1 data) = 0;

        /**
            Remove a node from a list by index; index counting starts at 0.

            @param index : Position of node to remove from list.
        */
        virtual void delete_node(const int index) = 0;

        /**
            Insert a node into a list by index; index counting starts at 0.

            @param data : Data instance variable of new node.
            @param index : Position in list to insert new node at.
        */
        virtual void insert_node(const T1 data, const int index) = 0;
};



/** Singly linked list class. Inherits from LinkedListABC
 * template class T1: The data type that the linked list nodes will hold.
 *      - Defaults to int.
 * template class T2: The type of linked list node that the list will consist of.
 *      - Defaults to SNode<>.
 */
template <class T1 = int, class T2 = SNode<>>
class SinglyLinkedList : public LinkedListABC<T1, T2>
{
    public:
        SinglyLinkedList();
        SinglyLinkedList(const T1 data);
        SinglyLinkedList<T1, T2>(const SinglyLinkedList<T1, T2>& other);
        virtual ~SinglyLinkedList() {}

        /// Adds capability to initialize linked list with initialization list.
        SinglyLinkedList(const std::initializer_list<T1> li);

        /// Overload index at operator [].
        T2* operator [] (const int index);

        /// Overload assignment operator.
        SinglyLinkedList<T1, T2>& operator = (const SinglyLinkedList& other);

        /// Overload binary left shift operator for printing string representation of linked list.
        friend std::ostream& operator << (std::ostream& os, SinglyLinkedList<>& linked_list);

        void push(const T1 data);
        void append(const T1 data);
        void insert_node(const T1 data, const int index);
        void delete_node(const int index);
};



/** Doubly linked list class. Inherits from LinkedListABC
 * template class T1: The data type that the linked list nodes will hold.
 *      - Defaults to int.
 * template class T2: The type of linked list node that the list will consist of.
 *      - Defaults to DNode<>.
 */
template <class T1 = int, class T2 = DNode<>>
class DoublyLinkedList : public LinkedListABC<T1, T2>
{
    public:
        DoublyLinkedList();
        DoublyLinkedList(const T1 data);
        virtual ~DoublyLinkedList() {}

        /// Adds capability to initialize linked list with initialization list.
        DoublyLinkedList(const std::initializer_list<T1> li);

        /// Overload index at operator [].
        T2* operator [] (const int index);

        /// Overload assignment operator.
        DoublyLinkedList<T1, T2>& operator = (const DoublyLinkedList& other);

        /// Overload binary left shift operator for printing string representation of linked list.
        friend std::ostream& operator << (std::ostream& os, DoublyLinkedList<>& linked_list);

        void push(const T1 data);
        void append(const T1 data);
        void insert_node(const T1 data, const int index);
        void delete_node(const int index);

        /// Print list in reverse.
        void print_reverse() const;
};



/** Circular linked list class. Inherits from LinkedListABC
 * template class T1: The data type that the linked list nodes will hold.
 *      - Defaults to int.
 * template class T2: The type of linked list node that the list will consist of.
 *      - Defaults to CNode<>.
 */
template <class T1 = int, class T2 = DNode<>>
class CircularLinkedList : public LinkedListABC<T1, T2>
{
    public:
        CircularLinkedList();
        CircularLinkedList(const T1 data);
        virtual ~CircularLinkedList() {}

        /// Adds capability to initialize linked list with initialization list.
        CircularLinkedList(const std::initializer_list<T1> li);

        /// Overload index at operator [].
        T2* operator [] (const int index);

        /// Overload assignment operator.
        CircularLinkedList<T1, T2>& operator = (const CircularLinkedList& other);

        /// Overload binary left shift operator for printing string representation of linked list.
        friend std::ostream& operator << (std::ostream& os, CircularLinkedList<>& linked_list);

        void push(const T1 data);
        void append(const T1 data);
        void insert_node(const T1 data, const int index);
        void delete_node(const int index);
};



/// Exception to throw when node index requested is longer than the list.
struct IndexError : public std::exception {
    const char* what() const throw() { return "List index out of range."; } };



// Include functions for linked lists
#include "linkedlistabc.tpp"
#include "singlylinkedlist.tpp"
#include "doublylinkedlist.tpp"
#include "circularlinkedlist.tpp"

#endif  // LINKEDLIST_H
