#include "linkedlist.h"


/// Default constructor
template <class T1, class T2>
SinglyLinkedList<T1, T2>::SinglyLinkedList()
: LinkedListABC<T1, T2>() { }


/// Constructor
template <class T1, class T2>
SinglyLinkedList<T1, T2>::SinglyLinkedList(const T1 data)
: LinkedListABC<T1, T2>(data) { }


/// Copy constructor
template <class T1, class T2>
SinglyLinkedList<T1, T2>::SinglyLinkedList(const SinglyLinkedList<T1, T2>& other) {

    T2* temp = other.get_head();

    while (temp != nullptr) {
        this->append(temp->get_data());
        temp = temp->get_next();
    }
}


/// initializer_list compatibility
template <class T1, class T2>
SinglyLinkedList<T1, T2>::SinglyLinkedList(const std::initializer_list<T1> il) {

    // For each item in the initialization list, add it to the linked list
    for (const T1* index = il.begin(); index < il.end(); index++)
        this->append(*index);
}


/// Get item operator compatibility
template <class T1, class T2>
T2* SinglyLinkedList<T1, T2>::operator [] (const int index) {

    // If list is empty or index is out of range
    if (this->get_head() == nullptr || this->length() <= index)
        throw IndexError();
    T2* temp = this->get_head();

    // Find appropriate index
    for (int i = 0; i < index; i++)
        temp = temp->get_next();
    return temp;
}


/// Overloading assignment operator
template <class T1, class T2>
SinglyLinkedList<T1, T2>& SinglyLinkedList<T1, T2>::operator = (const SinglyLinkedList& other) {

    // Catch statements such as: list1 = list1
    if (this == &other)
        return *this;
    T2* temp = other->get_head();

    // For each item in the other list, append it to this list
    while (temp != nullptr) {
        this->append(temp->get_data());
        temp = temp->get_next();
    }
    return *this;
}


/// Add item to beginning of a list
template <class T1, class T2>
void SinglyLinkedList<T1, T2>::push(const T1 data) {
    T2* new_node = new T2(data);

    // If list is empty
    if (this->get_head() == nullptr) {
        this->set_head(new_node);
        this->set_tail(new_node);
    }
    else {
        new_node->set_next(this->get_head());
        this->set_head(new_node);
    }
    this->set_len(this->length()+1);
}


/// Add item to end of a list
template <class T1, class T2>
void SinglyLinkedList<T1, T2>::append(const T1 data)
{
    T2* new_node = new T2(data);

    // If list is empty
    if (this->get_head() == nullptr) {
        this->set_head(new_node);
        this->set_tail(new_node);
    }
    else {
        this->get_tail()->set_next(new_node);
        this->set_tail(new_node);
    }
    // Increment list length
    this->set_len(this->length()+1);
}


/// Insert item into a list by index
template <class T1, class T2>
void SinglyLinkedList<T1, T2>::insert_node(const T1 data, const int index) {

    // If list is empty or list index is out of range
    if (this->get_head() == nullptr || this->length() <= index)
        throw IndexError();

    // If position is 0, push data rather than insert it
    if (index == 0)
        this->push(data);
    else {
        T2* temp = this->get_head();
        T2* new_node = new T2(data);

        // Find node before where the new node should be inserted
        for (int i = 1; i < index; i++)
            temp = temp->get_next();

        // Update links of the nodes
        new_node->set_next(temp->get_next());
        temp->set_next(new_node);
        this->set_len(this->length()+1);
    }
}


/// Delete item from list by index
template <class T1, class T2>
void SinglyLinkedList<T1, T2>::delete_node(const int index) {

    // If list is empty or list index is out of range
    if (this->get_head() == nullptr || this->length() <= index)
        throw IndexError();

    // If node is the head
    if (index == 0) {
        // If head is only node in list
        if (this->get_head() == this->get_tail()) {
            this->set_head(nullptr);
            this->set_tail(nullptr);
        }
        else
            this->set_head(this->get_head()->get_next());
    }
    else {
        T2* temp = this->get_head();
        T2* previous;

        // Find node before node to be deleted
        for (int i = 1; i < index && temp->get_next() != nullptr; i++) {
            previous = temp;
            temp = temp->get_next();
        }

        // If node to be deleted is tail
        if (temp->get_next() == nullptr)
            this->set_tail(previous);
        previous->set_next(temp->get_next());
    }
    // Decrement list length
    this->set_len(this->length()-1);
}


/// Print char representation of list with std::cout
std::ostream& operator << (std::ostream& os, SinglyLinkedList<>& linked_list) {
    os << "<SinglyLinkedList object at " << &linked_list
       << "; length: " << linked_list.length() << ">";
    return os;
}
