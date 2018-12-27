#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <exception>
#include "src/node.h"

namespace linkedlist
{

/**
 *  @brief  Abstract Base Class for Singly, Doubly, and Circular linked lists.
 *  @var  head  First node in the list.
 *  @var  tail  List node in the list.
 *  @var  len  Total number of nodes in list.
 *
 *  @tparam  T1  Data type nodes will hold.
 *  @tparam  T2  Type of node used for linked list.
 *
 *  Three of the main kinds of linked lists are singly, doubly, and circular. These
 *  types of linked lists have operations that can be written in code the same way.
 *  This abstract class defines methods that are common to the three different types
 *  of linked lists, as well as what methods must be defined by the linked lists.
 */
template <class T1, class T2>
class LinkedListABC
{
    private:
        T2* head{nullptr};
        T2* tail{nullptr};
        unsigned int len;

    public:
        T2* get_head() const    { return this->head; }
        void set_head(T2* head) { this->head = head; }
        T2* get_tail() const    { return this->tail; }
        void set_tail(T2* tail) { this->tail = tail; }
        void set_len(int len)   { this->len = len;   }

    public:
        LinkedListABC() : len(0) { }
        LinkedListABC(const T1 data);
        virtual ~LinkedListABC() { this->deleteList(); }
        
       /**
        *  @brief  Deletes all nodes in a list.
        */
        void deleteList();
        
       /**
        *  @brief  Retirieve data variable from node in list by position.
        *          Indexing starts at zero.
        *  @param  index  Position of node to print data of.
        *  @return Data instance variable of node at position index.
        */
        T1& operator [](const int index);

       /**
        *  @brief  Count number of nodes in a list.
        *  @return  len instance variable.
        */
        int size() const { return this->len; }

       /** 
        *  @brief  Check to see if a node exists in a list by its data instance variable.
        *  @param  data  The data instance variable to search the list for.
        *  @return  True if a node in the list contains the data, false otherwise.
        */
        bool contains(const T1 data) const;

       /** 
        *  @brief  Find the index of a node by its data instance variable.
        *  @param  data  Data to search the list for.
        *  @return  Index of node that contains data.
        */
        int index(const T1 data) const;

       /** 
        *  @brief  Print the list in order starting at the head and ending at the tail.
        */
        void print() const;

       /** 
        *  @brief  Add a node to the beginning of a list.
        *  @param  data  Data instance variable of new node.
        */
        virtual void push(const T1 data) = 0;

       /** 
        *  @brief  Add a node to the end of a list.
        *  @param  data  Data instance variable of new node.
        */
        virtual void append(const T1 data) = 0;

       /** 
        *  @brief  Insert a node into a list by index; index counting starts at 0.
        *  @param  data  Data instance variable of new node.
        *  @param  index  Position in list to insert new node at.
        */
        virtual void insert(const T1 data, const int index) = 0;

       /** 
        *  @brief  Remove a node from a list by index; index counting starts at 0.
        *  @param  index  Position of node to remove from list.
        */
        virtual void remove(const int index) = 0;

        class iterator
        {
            public:
                typedef T2* node;
                typedef iterator self;
                typedef std::forward_iterator_tag iterator_category;

                iterator(node iter)
                    : iter(iter) { }
                ~iterator() { delete iter; }
                self operator ++() {
                    iter = iter->next;
                    return *this;
                }
                self operator ++(int) {
                    self i = *this;
                    iter = iter->next;
                    return i;
                }
                node operator ->()                { return iter; }
                bool operator ==(const self& rhs) { return iter == rhs.iter; }
                bool operator !=(const self& rhs) { return iter != rhs.iter; }

            private:
                node iter;
        };

        iterator begin() {
            return iterator(head);
        }

        iterator end() {
            return iterator(nullptr);
        }
};  /// LinkedListABC


/** 
 *  @brief  Singly linked list class. Inherits from LinkedListABC.
 *  @var  head  First node in the list. (LinkedListABC)
 *  @var  tail  List node in the list. (LinkedListABC)
 *  @var  len  Total number of nodes in list. (LinkedListABC)
 *
 *  @tparam  T1  Data type nodes will hold.
 *  @tparam  T2  Type of node used for linked list.
 *
 *  Implementation of a singly linked list. Constructor, default
 *  constructor. and operators are inherited from LinkedListABC.
 *  other implementation details are defined within this class.
 */
template <class T1 = int, class T2 = node::SNode<>>
class SinglyLinkedList final : public LinkedListABC<T1, T2>
{
    public:
        SinglyLinkedList() : LinkedListABC<T1, T2>() { }
        SinglyLinkedList(const T1 data) : LinkedListABC<T1, T2>(data) { }
        SinglyLinkedList(const std::initializer_list<T1> il);

        SinglyLinkedList(const SinglyLinkedList& list);
        SinglyLinkedList& operator =(const SinglyLinkedList& list);
        SinglyLinkedList(SinglyLinkedList&& list);
        SinglyLinkedList& operator =(SinglyLinkedList&& list);

       /**
        *  @brief  Print a char representation of singly linked list.
        *  @param  os  std::cout.
        *  @param  linked_List  Linked list to print representation of.
        */
        friend std::ostream& operator <<(std::ostream& os, SinglyLinkedList<>& linked_list);

        void push(const T1 data);
        void append(const T1 data);
        void insert(const T1 data, const int index);
        void remove(const int index);
};  /// SinglyLinkedList


/** 
 *  @brief  Doubly linked list class. Inherits from LinkedListABC.
 *  @var  head  First node in the list. (LinkedListABC)
 *  @var  tail  List node in the list. (LinkedListABC)
 *  @var  len  Total number of nodes in list. (LinkedListABC)
 *
 *  @tparam  T1  Data type nodes will hold.
 *  @tparam  T2  Type of node used for linked list.
 *
 *  Implementation of a doubly linked list. Constructor, default
 *  constructor. and operators are inherited from LinkedListABC.
 *  other implementation details are defined within this class.
 */
template <class T1 = int, class T2 = node::DNode<>>
class DoublyLinkedList final : public LinkedListABC<T1, T2>
{
    public:
        DoublyLinkedList() : LinkedListABC<T1, T2>() { }
        DoublyLinkedList(const T1 data) : LinkedListABC<T1, T2>(data) { }
        DoublyLinkedList(const std::initializer_list<T1> il);

        DoublyLinkedList(const DoublyLinkedList& list);
        DoublyLinkedList& operator =(const DoublyLinkedList& list);
        DoublyLinkedList(DoublyLinkedList&& list);
        DoublyLinkedList& operator =(DoublyLinkedList&& list);

       /**
        *  @brief  Print a char representation of doubly linked list.
        *  @param  os  std::cout.
        *  @param  linked_List  Linked list to print representation of.
        */
        friend std::ostream& operator <<(std::ostream& os, DoublyLinkedList<>& linked_list);

        void push(const T1 data);
        void append(const T1 data);
        void insert(const T1 data, const int index);
        void remove(const int index);
};  /// DoublyLinkedList


/** 
 *  @brief  Circular linked list class. Inherits from LinkedListABC.
 *  @var  head  First node in the list. (LinkedListABC)
 *  @var  tail  List node in the list. (LinkedListABC)
 *  @var  len  Total number of nodes in list. (LinkedListABC)
 *
 *  @tparam  T1  Data type nodes will hold.
 *  @tparam  T2  Type of node used for linked list.
 *
 *  Implementation of a circular linked list. Constructor, default
 *  constructor. and operators are inherited from LinkedListABC.
 *  other implementation details are defined within this class.
 */
template <class T1 = int, class T2 = node::CNode<>>
class CircularLinkedList final : public LinkedListABC<T1, T2>
{
    public:
        CircularLinkedList() : LinkedListABC<T1, T2>() { }
        CircularLinkedList(const T1 data) : LinkedListABC<T1, T2>(data) { }
        CircularLinkedList(const std::initializer_list<T1> il);

        CircularLinkedList(const CircularLinkedList& list);
        CircularLinkedList& operator =(const CircularLinkedList& list);
        CircularLinkedList(CircularLinkedList&& list);
        CircularLinkedList& operator =(CircularLinkedList&& list);

       /**
        *  @brief  Print a char representation of circular linked list.
        *  @param  os  std::cout.
        *  @param  linked_List  Linked list to print representation of.
        */
        friend std::ostream& operator <<(std::ostream& os, CircularLinkedList<>& linked_list);

        void push(const T1 data);
        void append(const T1 data);
        void insert(const T1 data, const int index);
        void remove(const int index);
};  /// CircularLinkedList


struct IndexError : public std::exception {
    const char* what() const throw() { 
        return "List index out of range."; 
    }
};

} /// namespace linkedlist

#include "src/linkedlistabc.tpp"
#include "src/singlylinkedlist.tpp"
#include "src/doublylinkedlist.tpp"
#include "src/circularlinkedlist.tpp"

typedef linkedlist::SinglyLinkedList<int, node::SNode<int>>   sList;
typedef linkedlist::DoublyLinkedList<int, node::DNode<int>>   dList;
typedef linkedlist::CircularLinkedList<int, node::CNode<int>> cList;

#endif  /// LINKEDLIST_H
