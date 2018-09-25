#include <iostream>

struct Node
{
    int data;
    struct Node* next;
};

// print all elements in a list
void printList(struct Node* head)
{
    struct Node* temp = head;

    // if list is empty
    if (head == nullptr)
        return;

    do
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    while (temp != head);
}

// get the length of a list
int length(struct Node* head)
{
    struct Node* temp = head;
    int counter = 0;

    // if the list is not empty
    if (head != nullptr)
    {
        do
        {
            temp = temp->next;
            counter++;
        }
        while (temp != head);
    }

    return counter;
}

// add a node to the beginning of a list
void push(struct Node** head, int new_node_data)
{
    struct Node* temp = *head;
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_node_data;

    // if it is the first node in the list
    if (*head == nullptr)
    {
        new_node->next = new_node;
        *head = new_node;
        return;
    }

    // get the last node of the list
    while (temp->next != *head)
        temp = temp->next;

    temp->next = new_node;
    new_node->next = *head;
    *head = new_node;
}

// add a node to the end of a list
void append(struct Node** head, int new_node_data)
{
    struct Node* temp = *head;
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_node_data;

    // if it is the first node in a list
    if (temp == nullptr)
    {
        *head = new_node;
        new_node->next = new_node;
        return;
    }

    // get the last node in the list
    while (temp->next != *head)
        temp = temp->next;

    temp->next = new_node;
    new_node->next = *head;
}

// insert a node by position
void insertIndex(struct Node** head, int new_node_data, int index)
{
    struct Node* temp = *head;

    // if node is to be inserted at the beginning of a list
    if (index == 0)
    {
        push(head, new_node_data);
        return;
    }

    // finds the node one before where we want to insert the new node
    for (int i = 1; i < index && temp->next != *head; i++)
        temp = temp->next;

    // if the index is out of the list range
    if (temp->next == *head)
    {
        append(head, new_node_data);
        return;
    }

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_node_data;

    new_node->next = temp->next;
    temp->next = new_node;
}

// delete a node by value
void deleteKey(struct Node** head, int key)
{
    // if the list is empty
    if (*head == nullptr)
        return;

    struct Node* temp = *head;
    struct Node* previous = *head;

    // if the first node contains the key
    if (temp->data == key)
    {
        // get the last node
        struct Node* last = *head;
        while (last->next != *head)
            last = last->next;

        *head = temp->next;
        last->next = temp->next;
        free(temp);
        return;
    }

    // while current node is not the last node and node data not equal to key
    while (temp->next != *head && temp->data != key)
    {
        previous = temp;
        temp = temp->next;
    }

    previous->next = temp->next;
    free(temp);
}

// delete a node by position
void deleteIndex(struct Node** head, int index)
{
    // if the list is empty
    if (*head == nullptr)
        return;

    struct Node* temp = *head;
    int len = length(*head);

    // if list index is out of range
    if (len <= index)
        return;

    // if index to be deleted is the head
    if (index == 0)
    {
        struct Node* last = *head;
        while (last->next != *head)
            last = last->next;

        *head = temp->next;
        last->next = temp->next;
        free(temp);
        return;
    }

    // finds the node one position before the node to be deleted
    for (int i = 1; i < index && temp->next; i++)
        temp = temp->next;

    temp->next = temp->next->next;
    free(temp->next);
}

void deleteList(struct Node** head)
{
    struct Node* temp = *head;
    struct Node* next;

    // while temp is not equal to head, store the next value in a variable and delete temp
    while (temp != *head)
    {
        next = temp->next;
        free(temp);
        temp = next;
    }

    *head = nullptr;
}










