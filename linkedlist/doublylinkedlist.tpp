#include "linkedlist.h"


/// Default constructor
template <class T1, class T2>
DoublyLinkedList<T1, T2>::DoublyLinkedList()
: LinkedListABC<T1, T2>() { }


/// Constructor
template <class T1, class T2>
DoublyLinkedList<T1, T2>::DoublyLinkedList(const T1 data)
: LinkedListABC<T1, T2>(data) { }


/// Copy constructor
template <class T1, class T2>
DoublyLinkedList<T1, T2>::DoublyLinkedList(const DoublyLinkedList<T1, T2>& other) {

    T2* temp = other.get_head();

    while (temp != nullptr) {
        this->append(temp->get_data());
        temp = temp->get_next();
    }
}


/// initializer_list compatibility
template <class T1, class T2>
DoublyLinkedList<T1, T2>::DoublyLinkedList(const std::initializer_list<T1> il) {

    // For each item in the initialization list, add it to the linked list
    for (const T1* index = il.begin(); index < il.end(); index++)
        this->append(*index);
}


/// Get item operator compatibility
template <class T1, class T2>
T2* DoublyLinkedList<T1, T2>::operator [] (const int index) {

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
DoublyLinkedList<T1, T2>& DoublyLinkedList<T1, T2>::operator = (const DoublyLinkedList& other) {
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
void DoublyLinkedList<T1, T2>::push(const T1 data) {
    T2* new_node = new T2(data);

    // If list is empty
    if (this->get_head() == nullptr) {
        this->set_head(new_node);
        this->set_tail(new_node);
    }
    else {
        new_node->set_next(this->get_head());
        this->get_head()->set_previous(new_node);
        this->set_head(new_node);
    }
    // Increment length
    this->set_len(this->length()+1);
}


/// Add item to end of list
template <class T1, class T2>
void DoublyLinkedList<T1, T2>::append(const T1 data)
{
    T2* new_node = new T2(data);

    // If list is empty
    if (this->get_head() == nullptr) {
        this->set_head(new_node);
        this->set_tail(new_node);
    }
    else {
        this->get_tail()->set_next(new_node);
        new_node->set_previous(this->get_tail());
        this->set_tail(new_node);
    }
    // Increment length
    this->set_len(this->length()+1);
}


/// Insert node into list by position
template <class T1, class T2>
void DoublyLinkedList<T1, T2>::insert_node(const T1 data, const int index) {

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
        new_node->set_next(temp->get_next());

        // Update links
        new_node->set_previous(temp);
        temp->set_next(new_node);
        this->set_len(this->length()+1);
    }
}


/// Remove node from list by position
template <class T1, class T2>
void DoublyLinkedList<T1, T2>::delete_node(const int index) {

    // If list is empty or list index is out of range
    if (this->get_head() == nullptr || this->length() <= index)
        throw IndexError();
    
    // If node is the head
    if (index == 0) {
        // If head is only item in list
        if (this->length() == 1) {
            this->set_head(nullptr);
            this->set_tail(nullptr);
        }
        else {
            this->set_head(this->get_head()->get_next());
            this->get_head()->set_previous(nullptr);
        }
    }
    else {
        T2* temp = this->get_head();
        T2* previous = this->get_head();

        // Find node before node to be deleted
        for (int i = 0; i < index && temp != this->get_tail(); i++) {
            previous = temp;
            temp = temp->get_next();
        }
        
        // If node to be deleted is tail
        if (temp == this->get_tail()) {
            this->set_tail(previous);
        }
        previous->set_next(temp->get_next());

        if (previous->get_next() != nullptr)
            previous->get_next()->set_previous(previous);
    }
    // Decrement length
    this->set_len(this->length()-1);
}


/// Print list in reverse order
template <class T1, class T2>
void DoublyLinkedList<T1, T2>::print_reverse() const {

    if (this->get_tail() != nullptr) {
        T2* temp = this->get_tail();

        while (temp != nullptr) {
            std::cout << temp->get_data() << " ";
            temp = temp->get_previous();
        }
    }
}


/// Print char representation of list with std::cout
std::ostream& operator << (std::ostream& os, DoublyLinkedList<>& linked_list) {
    os << "<DoublyLinkedList object at " << &linked_list 
       << "; length: " << linked_list.length() << ">";
    return os;
}
