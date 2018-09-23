#include <iostream>

struct Node
{
    int data;
    struct Node* next;
    struct Node* previous;
};

// add a node to the beginning of the list
void pushNode(struct Node** head, int new_node_data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_node_data;
    new_node->previous = nullptr;

    // if the list is empty
    if (*head == nullptr)
    {
        *head = new_node;
        new_node->next = nullptr;
        return;
    }

    new_node->next = *head;
    *head = new_node;
}

// add a node in the middle of a list
void insertNode(struct Node* previous, int new_node_data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_node_data;

    new_node->next = previous->next;
    previous->next->previous = new_node;
    new_node->previous = previous;
    previous->next = new_node;
}


// add a node in the middle of a list by position
void insertNodeIndex(struct Node** head, int new_node_data, int index)
{
    // if the item is to be inserted at the head
    if (index == 0)
    {
        pushNode(head, new_node_data);
        return;
    }

    struct Node* temp = *head;
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_node_data;

    for (int i = 1; i < index && temp != nullptr; i++)
        temp = temp->next;

    // if list index is out of range
    if (temp == nullptr)
        return;

    new_node->next = temp->next;
    temp->next->previous = new_node;
    temp->next = new_node;
    new_node->previous = temp;
}

// add a node to the end of a list
void appendNode(struct Node** head, int new_node_data)
{
    struct Node* last_node = *head;
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_node_data;
    new_node->next = nullptr;

    // if the list is empty
    if (*head == nullptr)
    {
        *head = new_node;
        new_node->previous = nullptr;
        return;
    }

    while (last_node->next != nullptr)
        last_node = last_node->next;

    last_node->next = new_node;
    new_node->previous = last_node;
}

// delete a node by its value
void deleteNodeKey(struct Node** head, int key)
{
    struct Node* temp = *head;

    // if first node is to be deleted
    if (temp->data == key)
    {
        temp->next->previous = nullptr;
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp->data != key && temp != nullptr)
        temp = temp->next;

    // if key is not in list
    if (temp == nullptr)
        return;

    temp->previous->next = temp->next;
    temp->next->previous = temp->previous;
    free(temp);
}

// delete a node by position
void deleteNodeIndex(struct Node** head, int index)
{
    struct Node* temp = *head;

    // if head is to be deleted
    if (index == 0)
    {
        temp->next->previous = nullptr;
        *head = temp->next;
        free(temp);
        return;
    }

    for (int i = 0; i < index && temp != nullptr; i++)
        temp = temp->next;

    // if list index is out of range
    if (temp == nullptr)
        return;

    temp->next->previous = temp->previous;
    temp->previous->next = temp->next;
    free(temp);
}

// delete an entire list
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

// print a list
void printList(struct Node* head)
{
    while (head != nullptr)
    {
        std::cout << head->data << " ";
        head = head->next;
    }
}

// print a list n reverse
void printListReverse(struct Node* head)
{
    while (head->next != nullptr)
        head = head->next;

    while (head != nullptr)
    {
        std::cout << head->data << " ";
        head = head->previous;
    }
}

// find the length of a list
int listLength(struct Node* head)
{
    int counter = 0;
    while (head != nullptr)
        counter++;
    return counter;
}

// see if an element is in a list or not
bool searchElement(struct Node* head, int key)
{
    while (head != nullptr)
    {
        if (head->data == key)
            return true;
        head = head->next;
    }
    return false;
}

// count how many  times an element appears in a list
int countElement(struct Node* head, int element)
{
    int counter = 0;
    while (head != nullptr)
    {
        if (head->data == element)
            counter++;
    }
    return counter;
}

// get an element by its position
int getElementByIndex(struct Node* head, int index)
{
    for (int i = 0; i < index && head != nullptr; i++)
        head = head->next;

    // if list index is out of range
    if (head == nullptr)
        return -1;

    return head->data;
}

// check for a loop in the list
bool checkForLoop(struct Node* head)
{
    struct Node* slower = head;
    struct Node* faster = head;

    while (faster != nullptr)
    {
        slower = slower->next;
        faster = faster->next->next;

        if (slower == faster)
            return true;
    }
    return false;
}

// get element n positions away from the end of a list
int getElementFromEnd(struct Node* head, int from_end)
{
    struct Node* temp = head;
    if (temp == nullptr)
        return -1;

    while (temp->next != nullptr)
        temp = temp->next;

    for (int i = 1; i < from_end; i++)
        temp = temp->previous;

    return temp->data;
}

// find pairs that add up to a value x for sorted linked lists
void pairSum(struct Node* head, int x)
{
    // set two pointers, one at the beginning of the list and one at the end
    struct Node* first = head;
    struct Node* second = head;

    while (second->next != nullptr)
        second = second->next;

    bool any_pairs = false;

    // loop continues until either of the pointers becomes nullptr, or if
    // the pointers equal each other, or until the pointers cross
    while (first != nullptr && second != nullptr &&
           first != second && second->next != first)
    {
        // if there is a pair, move pointers one step closer together
        if (first->data + second->data == x)
        {
            any_pairs = true;
            std::cout << "(" << first->data << ", " << second->data << ") ";
            first = first->next;
            second = second->previous;
        }
        // if the sum of the values is not the desired value
        else
        {
            // if the sum is smaller than the desired value
            if ((first->data + second->data) < x)
            {
                first = first->next;
            }
            // if the sum is greater than the desired value
            else
                second = second->previous;
        }
    }

    if (any_pairs == false)
        std::cout << "No pairs found";
}

// insert a node into the correct position in a sorted list
void sortedInsert(struct Node** head, int new_node_data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_node_data;

    // if list is empty
    if (*head == nullptr)
    {
        new_node->next = nullptr;
        new_node->previous = nullptr;
        *head = new_node;
    }
    // if item is to be inserted at the beginning
    else if (new_node_data <= (*head)->data)
    {
        new_node->previous = nullptr;
        new_node->next = *head;
        new_node->next->previous = new_node;
        *head = new_node;
    }
    // if the item is to be inserted somewhere other than the beginning
    else
    {
        struct Node* current = *head;

        while (current->data < new_node_data && current->next != nullptr)
            current = current->next;

        // if item is to be inserted at the end
        if (current->next == nullptr)
        {
            appendNode(head, new_node_data);
            return;
        }

        new_node->next = current->next;
        new_node->previous = current;
        current->next = new_node;
        new_node->next->previous = new_node;
    }
}
