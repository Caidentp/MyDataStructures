#include <iostream>


struct Node
{
    int data;
    struct Node* next = nullptr;
};


// Prints every element in the list
void printList(struct Node* head)
{
    while (head != nullptr)
    {
        std::cout << head->data << " ";
        head = head->next;
    }
    return;
}


// Insert a node at the front of the linked list
void pushNode(struct Node** head, int new_node_data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_node_data;
    new_node->next = *head;
    *head = new_node;
}


// Insert a node at the end of the linked list
void appendNode(struct Node** head, int new_node_data)
{
    struct Node* temp = *head;
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_node_data;

    if (*head == nullptr)
    {
        *head = new_node;
        return;
    }

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    temp->next = new_node;
    return;
}


// Insert a node after another node
void insertNode(struct Node* previous, int new_node_data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_node_data;
    new_node->next = previous->next;
    previous->next = new_node;
}


// Insert a node by index
void insertNodeIndex(struct Node** head, int new_node_data, int index)
{
   struct Node* temp = *head;

    if (index == 0)
    {
        pushNode(head, new_node_data);
        return;
    }

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_node_data;

    for (int i = 1; i < index && temp != nullptr; i++)
    {
        temp = temp->next;
    }

    if (temp == nullptr) { return; }

    new_node->next = temp->next;
    temp->next = new_node;
}


// Delete a node by value
void deleteNodeKey(struct Node** head, int key)
{
    struct Node* previous = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *head;

    if (temp->data == key)
    {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != nullptr && temp->data != key)
    {
        previous = temp;
        temp = temp->next;
    }

    if (temp == nullptr) { return; }

    previous->next = temp->next;
    free(temp);
}


// Delete a node by position
void deleteNodeIndex(struct Node** head, int index)
{
    struct Node* temp = *head;

    if (index == 0)
    {
        *head = temp->next;
        free(temp);
        return;
    }

    for (int i = 1; i < index && temp != nullptr; i++)
    {
        temp = temp->next;
    }

    if (temp == nullptr) { return; }

    temp->next = temp->next->next;
    free(temp->next);
}


// Find the length of the list
int listLength(struct Node* head)
{
    int counter = 0;
    while (head != nullptr)
    {
        head = head->next;
        counter++;
    }
    return counter;
}


// Find the length of a list recursively
int listLengthRecurse(struct Node* head)
{
    if (head == nullptr) { return 0; }

    return 1 + listLengthRecurse(head->next);
}


// delete an entire linked list
void deleteList(struct Node** head)
{
    struct Node* temp = *head;
    struct Node* next;

    while (temp != nullptr)
    {
        next = temp->next;
        free(temp);
        temp = next;
    }

    *head = nullptr;
}


// Find the node data at a certain index
int findNodeAtIndex(struct Node* head, int index)
{
    int counter = 0;
    while (counter < index && head != nullptr)
    {
        head = head->next;
        counter++;
    }

    if (head == nullptr) { return 0; }

    return head->data;
}


// see if an integer is in the list or not
bool searchNode(struct Node* head, int data)
{
    while (head != nullptr)
    {
        if (head->data == data)
        {
            return true;
        }
        head = head->next;
    }
    return false;
}


// see if an integer is in a list or not recursively
bool searchNodeRecurse(struct Node* head, int data)
{
    if (head == nullptr)
    {
        return false;
    }

    if (head->data == data)
    {
        return true;
    }

    return searchNodeRecurse(head->next, data);
}


// find a node n number of elements from the end of a list
int getNodeFromEnd(struct Node* head, int from_end)
{
    int len = listLength(head);
    int index = len - from_end;

    for (int i = 0; i < index && head != nullptr; i++)
    {
        head = head->next;
    }

    if (head == nullptr) { return -1; }

   return head->data;
}


// count how many times an element occurs in a list
int countElement(struct Node* head, int element)
{
    int counter = 0;
    while (head != nullptr)
    {
        if (head->data == element) { counter++; }
        head = head->next;
    }
    return counter;
}


// prints the middle element of a linked list
void printMiddle(struct Node* head)
{
    struct Node* faster = head;
    struct Node* slower = head;

    while (faster != nullptr && faster->next != nullptr)
    {
        faster = faster->next->next;
        slower = slower->next;
    }
    std::cout << slower->data;
}


bool detectLoop(struct Node* head)
{
    struct Node* faster = head;
    struct Node* slower = head;

    while (slower != nullptr && faster != nullptr && faster->next != nullptr)
    {
        slower = slower->next;
        faster = faster->next->next;

        if (slower == faster)
        {
            return true;
        }
    }
    return false;
}


int main()
{
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));

    head->data = 1;
    second->data = 2;
    head->next = second;

    pushNode(&head, 0);
    pushNode(&head, -1);
    appendNode(&head, 3);
    insertNode(second, 12);
    deleteNodeIndex(&head, 0);
    insertNodeIndex(&head, 99, 0);
    appendNode(&head, 0);
    appendNode(&head, 0);

    std::cout << detectLoop(head);
}
