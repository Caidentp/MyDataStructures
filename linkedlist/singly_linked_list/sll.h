#ifndef TEST_H
#define TEST_H
#include <iostream>
#include <exception>


struct IndexError : public std::exception
{
    const char* what() const throw();
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

        int get_data() const;
        void set_data(const int data);
        Node* get_next() const;
        void set_next(Node* next);
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

        Node* get_head() const;
        Node* get_tail() const;
        int length();

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
