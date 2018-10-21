#include "singlylinkedlist.h"


// Default constructor
SinglyLinkedList::SinglyLinkedList()
{
    this->head = nullptr;
    this->tail = nullptr;
    this->list_length = 0;
}


// Constructor
SinglyLinkedList::SinglyLinkedList(int data)
{
    Node* new_node = new Node(data);
    this->head = new_node;
    this->tail = new_node;
    this->list_length++;
}


// Destructor
SinglyLinkedList::~SinglyLinkedList()
{
    delete head;
    delete tail;
}


// Return the head node of a linked list
Node* SinglyLinkedList::get_head() const { return this->head; }


// Return the tail node of a linked list
Node* SinglyLinkedList::get_tail() const { return this->tail; }


// Return the list_length instance variable of a linked list
int SinglyLinkedList::length() const { return this->list_length; }


// Add the contents of one list to another
SinglyLinkedList& SinglyLinkedList::operator += (SinglyLinkedList& right)
{
    Node* temp = right.get_head();
    while (temp != nullptr)
    {
        this->append(temp->get_data());
        temp = temp->get_next();
    }
}


// Subtract the contents of one list from another
SinglyLinkedList& SinglyLinkedList::operator -= (SinglyLinkedList& right)
{
    Node* temp = right.get_head();
    while (temp != nullptr)
    {
        int data = temp->get_data();
        if (this->contains(data))
            this->remove_data(data);
        temp = temp->get_next();
    }
}


// Operator overload + to add two lists together. Creates new list object
SinglyLinkedList operator + (SinglyLinkedList& left, SinglyLinkedList& right)
{
    SinglyLinkedList new_list = SinglyLinkedList();
    Node* temp = left.get_head();
    while (temp != nullptr)
    {
        new_list.append(temp->get_data());
        temp = temp->get_next();
    }
    temp = right.get_head();
    while (temp != nullptr)
    {
        new_list.append(temp->get_data());
        temp = temp->get_next();
    }
    return  new_list;
}


// Remove items from the left list if they exist in the right list. Creates new list object
SinglyLinkedList operator - (SinglyLinkedList& left, SinglyLinkedList& right)
{
    SinglyLinkedList new_list = SinglyLinkedList();
    Node* temp = left.get_head();
    while (temp != nullptr)
    {
        int data = temp->get_data();
        if (!right.contains(data))
            new_list.append(data);
        temp = temp->get_next();
    }
    return new_list;
}


// Operator overload << to get a readable representation of object when used with cout
std::ostream& operator << (std::ostream& os, SinglyLinkedList& linked_list)
{
    os << "<SinglyLinkedList object at " << &linked_list << "; length: " << linked_list.length() << ">";
    return os;
}


// Add a node to the beginning of a list
void SinglyLinkedList::push(const int data)
{
    Node* new_node = new Node(data);
    if (this->head == nullptr)
    {
        this->head = new_node;
        this->tail = new_node;
    }
    else
    {
        new_node->set_next(this->head);
        this->head = new_node;
    }
    this->list_length++;
}


// Add a node to the end of a list
void SinglyLinkedList::append(const int data)
{
    Node* new_node = new Node(data);
    if (this->head == nullptr)
    {
        this->head = new_node;
        this->tail = new_node;
    }
    else
    {
        tail->set_next(new_node);
        this->tail = new_node;
    }
    this->list_length++;
}


// Insert a node into the list by position
void SinglyLinkedList::insert_node(const int data, const int index)
{
    if (this->head == nullptr || this->list_length <= index)
        throw IndexError();

    if (index == 0)
        this->push(data);
    else
    {
        Node* temp = this->head;
        Node* new_node = new Node(data);
        for (int i = 1; i < index; i++)
            temp = temp->get_next();

        new_node->set_next(temp->get_next());
        temp->set_next(new_node);
        this->list_length++;
    }
}


// Delete a node from the list by position
void SinglyLinkedList::delete_node(int index)
{
    if (this->head == nullptr || this->list_length <= index)
        throw IndexError();

    Node* temp = this->head;
    if (index == 0)
    {
        if (this->list_length == 1)
        {
            delete temp;
            this->head = nullptr;
            this->tail = nullptr;
        }
        else
            this->head = this->head->get_next();
    }
    else
    {
        Node* previous = this->head;
        for (int i = 0; i < index && temp->get_next() != nullptr; i++)
        {
            previous = temp;
            temp = temp->get_next();
        }
        if (temp == this->tail)
            this->tail = previous;
        previous->set_next(temp->get_next());
        delete temp;
    }
    this->list_length--;
}


// Remove a node in a list by its value
void SinglyLinkedList::remove_data(const int data)
{
    Node* temp = this->head;
    int index = 0;
    while (temp != nullptr)
    {
        if (temp->get_data() == data)
        {
            this->delete_node(index);
            break;
        }
        else
        {
            temp = temp->get_next();
            index++;
        }
    }
}


// Return true if list contains a value, false otherwise
bool SinglyLinkedList::contains(const int data)
{
    Node* temp = this->head;
    while (temp != nullptr)
    {
        if (temp->get_data() == data)
            return true;
        else
            temp = temp->get_next();
    }
    return false;
}


// Find the index of a node by passing its value
int SinglyLinkedList::find_index(const int data)
{
    Node* temp = this->head;
    int index = 0;
    while (temp != nullptr)
    {
        if (temp->get_data() == data)
            return index;
        else
        {
            temp = temp->get_next();
            index++;
        }
    }
    return -1;
}


// Return node's instance variable at specified index
int SinglyLinkedList::get_index(const int index)
{
    if (this->head == nullptr || this->list_length <= index)
        throw IndexError();

    Node* temp = this->head;
    for (int i = 0; i < index; i++)
        temp = temp->get_next();
    return temp->get_data();
}


// Print a list in order
void SinglyLinkedList::print() const
{
    if (this->head != nullptr)
    {
        Node* temp = this->head;
        while (temp != nullptr)
        {
            std::cout << temp->get_data() << " ";
            temp = temp->get_next();
        }
    }
}
