#include <iostream>
#include <exception>


// defines an empty stack exception
struct IndexError : public std::exception {
    const char* what () const throw () { return "Stack is empty."; }
};


template <class T>
class Node
// node class for creating linked list nodes.
{
public:
        T data;
        Node<T>* next = nullptr;

        Node(T data) { this->data = data; }
};

template <class T>
class LinkedListStack
{
    private:
        // head node
        Node<T>* head;

        // if top == -1 then the stack is empty
        int top = -1;

    public:
        LinkedListStack(Node<T>* head = nullptr)
        {
            this->head = head;
        }

        bool isEmpty() { return top == -1; };

        void push(T data)
        // add an item to the front of a stack: O(1) time
        {
            Node<T>* new_node = new Node<T>(data);

            if (head == nullptr)
            {
                head = new_node;
                return;
            }

            new_node->next = head;
            head = new_node;
            top++;
        }

        T pop()
        // return the item at the top of a stack: O(1) time
        {
            top--;
            Node<T>* temp = head;
            head = head->next;
            return temp->data;
        }

        T peek()
        // return the item at the top of a stack without removing it: O(1) time
        {
            if (head == nullptr)
                throw IndexError();
            return head->data;
        }
};
