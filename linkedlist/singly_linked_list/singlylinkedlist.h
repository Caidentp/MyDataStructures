#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H
#include <iostream>
#include <exception>

// TODO: Define copy constructor for the Node class
// TODO: Define copy constructor for the SinglyLinkedList class
// TODO: Operator overload assignment operator for Node class
// TODO: Operator overload assignment operator for SinglyLinkedList class


struct IndexError : public std::exception
{
    const char* what() const throw() { return "List index out of range."; }
};


class Node
{
    private:
        int data;
        Node* next = nullptr;

    public:
        Node();
        Node(const int data);
        ~Node();

        int get_data() const { return this->data; }
        void set_data(const int data) { this->data = data; }
        Node* get_next() const { return this->next; }
        void set_next(Node* next) { this->next = next; }
};


class SinglyLinkedList
{
    private:
        Node* head;
        Node* tail;
        int list_length;

    public:
        SinglyLinkedList();
        SinglyLinkedList(const int data);
        ~SinglyLinkedList();

        Node* get_head() const { return this->head; }
        Node* get_tail() const { return this->tail; }
        int length() const { return this->list_length; }

        SinglyLinkedList& operator += (SinglyLinkedList& right);
        SinglyLinkedList& operator -= (SinglyLinkedList& right);
        friend SinglyLinkedList operator + (SinglyLinkedList& left, SinglyLinkedList& right);
        friend SinglyLinkedList operator - (SinglyLinkedList& left, SinglyLinkedList& right);
        friend std::ostream& operator << (std::ostream& os, SinglyLinkedList& linked_list);

        void push(const int data);
        void append(const int data);
        void insert_node(const int data, const int index);
        void delete_node(const int index);
        void remove_data(const int data);
        bool contains(const int data);
        int find_index(const int data);
        int get_index(const int index);
        void print() const;
};


#endif
