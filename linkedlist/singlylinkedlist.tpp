#include "linkedlist.h"


/// initializer_list compatibility
template <class T1, class T2>
SinglyLinkedList<T1, T2>::SinglyLinkedList(const std::initializer_list<T1> il) {

    for (const T1* index = il.begin(); index < il.end(); index++)
        this->append(*index);
}


/// Get item operator compatibility
template <class T1, class T2>
T1& SinglyLinkedList<T1, T2>::operator [] (const int index) {

    if (this->get_head() == nullptr || this->size() <= index)
        throw IndexError();
    T2* t = this->get_head();

    for (int i = 0; i < index; i++, t = t->next);
    return t->data;
}


/// Add item to beginning of a list
template <class T1, class T2>
void SinglyLinkedList<T1, T2>::push(const T1 data) {
    T2* new_node = new T2(data);

    if (this->get_head() == nullptr) {
        this->set_head(new_node);
        this->set_tail(new_node);
    }
    else {
        new_node->next = this->get_head();
        this->set_head(new_node);
    }
    this->set_len(this->size()+1);
}


/// Add item to end of a list
template <class T1, class T2>
void SinglyLinkedList<T1, T2>::append(const T1 data)
{
    T2* new_node = new T2(data);

    if (this->get_head() == nullptr) {
        this->set_head(new_node);
        this->set_tail(new_node);
    }
    else {
        this->get_tail()->next = new_node;
        this->set_tail(new_node);
    }
    this->set_len(this->size()+1);
}


/// Insert item into a list by index
template <class T1, class T2>
void SinglyLinkedList<T1, T2>::insert(const T1 data, const int index) {

    if (this->get_head() == nullptr || this->size() <= index)
        throw IndexError();

    if (index == 0)
        this->push(data);

    else {
        T2* new_node = new T2(data);
        T2* temp = this->get_head();
        for (int i = 1; i < index; i++, temp = temp->next);

        new_node->next = temp->next;
        temp->next = new_node;
        this->set_len(this->size()+1);
    }
}


/// Delete item from list by index
template <class T1, class T2>
void SinglyLinkedList<T1, T2>::delete_node(const int index) {

    if (this->get_head() == nullptr || this->size() <= index)
        throw IndexError();

    if (index == 0) {

        if (this->get_head() == this->get_tail()) {
            this->set_head(nullptr);
            this->set_tail(nullptr);
        }
        else
            this->set_head(this->get_head()->next);
    }
    else {
        T2* temp = this->get_head();
        T2* previous;

        for (int i = 0; i < index && temp != this->get_tail(); i++) {
            previous = temp;
            temp = temp->next;
        }
        previous->next = temp->next;

        if (temp == this->get_tail())
            this->set_tail(previous);
    }
    this->set_len(this->size()-1);
}


/// Print char representation of list with std::cout
std::ostream& operator << (std::ostream& os, SinglyLinkedList<>& linked_list) {
    os << "<SinglyLinkedList object at " << &linked_list
       << "; length: " << linked_list.size() << ">";
    return os;
}
