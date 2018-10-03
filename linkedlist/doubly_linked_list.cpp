#include <iostream>
#include <exception>

#define node Node<T>*


// Index error for throwing exceptions when out of range index is requested in linked list methods
struct IndexError : public std::exception {
    const char* what () const throw () { return "List index out of range."; }
};


template <class T>
class Node
// Defines a node class for singly linked list.
{
    public:
        T data;
        node next = nullptr;
        node previous = nullptr;

        Node(T data) { this->data = data; }

};


template <class T>
class DoublyLinkedList
// Defines a node class for doubly linked list.
{
    private:
        // head node
        node head;

    public:
        // can optionally pass a node to the constructor that will become the head.
        DoublyLinkedList(node head = nullptr)
        {
            this->head = head;
        }

        void printList()
        // prints the contents of a list.
        {
            node temp = head;
            if (temp != nullptr)
            {
                while (temp != nullptr)
                {
                    std::cout << temp->data << " ";
                    temp = temp->next;
                }
            }
        }

        void printListReverse()
        // prints the contents of a list in reverse.
        {
            node temp = head;
            if (temp != nullptr)
            {
                while (temp->next != nullptr)
                    temp = temp->next;

                while (temp != nullptr)
                {
                    std::cout << temp->data << " ";
                    temp = temp->previous;
                }
            }
        }

        int length()
        // returns the length of a list.
        {
            int counter = 0;
            node temp = head;

            if (temp != nullptr)
            {
                while (temp != nullptr)
                {
                    counter++;
                    temp = temp->next;
                }
            }
            return counter;
        }

        void push(T data)
        // add a node to the beginning of a list.
        {
            node new_node = new Node<T>(data);
            if (head == nullptr)
            {
                head = new_node;
                return;
            }

            new_node->next = head;
            head->previous = new_node;
            head = new_node;
        }

        void append(T data)
        // add a node to the end of a list.
        {
            node new_node = new Node<T>(data);
            
            // if list is empty, node becomes head
            if (head == nullptr)
            {
                head = new_node;
                return;
            }

            node temp = head;
            
            // find current last node in the list
            while (temp->next != nullptr)
                temp = temp->next;

            temp->next = new_node;
            new_node->previous = temp;
        }

        void insertIndex(int index, T data)
        // insert a node into a list by position.
        
        // if list is empty or index is out of range
            if (head == nullptr || index > this->length())
                throw IndexError();

            // if node is to be inserted at the head
            if (index == 0)
            {
                this->push(data);
                return;
            }

            node temp = head;
            for (int i = 1; i < index; i++)
                temp = temp->next;

            if (temp->next == nullptr)
            {
                append(data);
                return;
            }

            node new_node = new Node<T>(data);

            new_node->next = temp->next;
            temp->next->previous = new_node;
            temp->next = new_node;
            new_node->previous = temp;
        }

        T getIndex(int index)
        // get the data instance variable of a node object in the list by its position in the list.
        {
            // if list is empty or index is out of range
            if (head == nullptr || index >= this->length())
                throw IndexError();

            node temp = head;
            for (int i = 0; i < index; i++)
                temp = temp->next;

            return temp->data;
        }

        void deleteIndex(int index)
        // delete a node from the list by position.
        {
            // if list is empty or index is out of range
            if (head == nullptr || index >= this->length())
                throw IndexError();

            node temp = head;
            node previous;

            // if head is to be deleted
            if (index == 0)
            {
                head = temp->next;
                delete temp;
                head->previous = nullptr;
                return;
            }

            for (int i = 0; i < index && temp->next != nullptr; i++)
            {
                previous = temp;
                temp = temp->next;
            }

            // if tail is to be deleted
            if (temp->next == nullptr)
            {
                delete temp;
                previous->next = nullptr;
                return;
            }

            previous->next = temp->next;
            previous->next->previous = previous;
            delete temp;
        }
};
