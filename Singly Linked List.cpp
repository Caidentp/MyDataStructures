#include <iostream>

struct Node
{
    int data;
    struct Node* next = nullptr;
};

// print the contents of a list: O(n) time
void printList(struct Node* head)
{
    if (head == nullptr)
        return;

    while (head != nullptr)
    {
        std::cout << head->data << " ";
        head = head->next;
    }
}

// returns the number of nodes in a list: O(n) time
int length(struct Node* head)
{
    int counter = 0;

    if (head != nullptr)
    {
        while (head != nullptr)
        {
            counter++;
            head = head->next;
        }
    }
    return counter;
}

// creates a new node and adds it to the beginning of a list: O(1) time
void push(struct Node*& head, int new_node_data)
{
    // creates new node
    struct Node* new_node = new Node;
    new_node->data = new_node_data;

    // if list is empty
    if (head == nullptr)
    {
        head = new_node;
        return;
    }

    new_node->next = head;
    head = new_node;
}

// add existing node to the beginning of a list: O(1) time
void push(struct Node*& head, struct Node* new_node)
{
    // if list is empty
    if (head == nullptr)
    {
        head = new_node;
        return;
    }

    new_node->next = head;
    head = new_node;
}

// creates a new node and adds it to the end of a list: O(n) time
void append(struct Node*& head, int new_node_data)
{
    // create new node
    struct Node* new_node = new Node;
    new_node->data = new_node_data;

    // find the last node of the list
    struct Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = new_node;
}

// add existing node to the end of a list: O(n) time
void append(struct Node*& head, struct Node* new_node)
{
    // find the last node of the list
    struct Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = new_node;
}

// creates new node and inserts it into the list after a given node: O(1) time
void insertAfter(struct Node* previous, int new_node_data)
{
    // create new node
    struct Node* new_node = new Node;
    new_node->data = new_node_data;

    new_node->next = previous->next;
    previous->next = new_node;
}

// inserts existing node into the list after a given node: O(1) time
void insertAfter(struct Node* previous, struct Node* new_node)
{
    new_node->next = previous->next;
    previous->next = new_node;
}

// create a new node and insert it into the list by position: O(n) time
void insertIndex(struct Node*& head, int new_node_data, int index)
{
    // if list is empty or node is to be inserted at head
    if (head == nullptr || index == 0)
    {
        push(head, new_node_data);
        return;
    }

    struct Node* temp = head;

    // create new node
    struct Node* new_node = new Node;
    new_node->data = new_node_data;

    // find the node before the index that we want to insert the new node at
    for (int i = 1; i < index && temp != nullptr; i++)
        temp = temp->next;

    // if index is out of list range
    if (temp == nullptr)
    {
        append(head, new_node_data);
        return;
    }

    new_node->next = temp->next;
    temp->next = new_node;
}

// insert existing node into the list by position: O(n) time
void insertIndex(struct Node*& head, struct Node* new_node, int index)
{
    // if list is empty or node is to be inserted at head
    if (head == nullptr || index == 0)
    {
        push(head, new_node);
        return;
    }

    struct Node* temp = head;

    // find the node before the index that we want to insert the new node at
    for (int i = 1; i < index && temp != nullptr; i++)
        temp = temp->next;

    // if index is out of list range
    if (temp == nullptr)
    {
        append(head, new_node);
        return;
    }

    new_node->next = temp->next;
    temp->next = new_node;
}

// delete node by value: O(n) time
void deleteByValue(struct Node*& head, int value)
{
    // create two nodes, one to equal the current node (temp) and one to equal the previous node (previous)
    struct Node* temp = head;
    struct Node* previous;

    // if the head is to be deleted
    if (head->data == value)
    {
        head = temp->next;
        delete temp;
        return;
    }

    // find the appropriate node to be deleted (temp)
    while (temp->data != value && temp != nullptr)
    {
        previous = temp;
        temp = temp->next;
    }

    // if the value to be deleted is not in the list
    if (temp == nullptr)
        return;

    previous->next = temp->next;
    delete temp;
}

// delete a node by position: O(n) time
void deleteNodeByIndex(struct Node*& head, int index)
{
    // create two nodes, one to equal the current node (temp) and one to equal the previous node (previous)
    struct Node* temp = head;
    struct Node* previous;

    // if the head is to be deleted
    if (index == 0)
    {
        head = temp->next;
        delete temp;
        return;
    }

    // find the appropriate node to be deleted (temp)
    for (int i = 0; i < index && temp != nullptr; i++)
    {
        previous = temp;
        temp = temp->next;
    }

    // if the list index is out of range
    if (temp == nullptr)
        return;

    previous->next = temp->next;
    delete temp;
}

// delete an entire list: O(n) time
void deleteList(struct Node*& head)
{
    struct Node* temp = head;
    struct Node* next;

    while (temp != nullptr)
    {
        next = temp->next;
        delete temp;
        temp = next;
    }

    head = nullptr;
}
