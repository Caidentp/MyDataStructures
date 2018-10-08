#include <iostream>
#include <exception>


// Exception to throw when queue is empty
struct EmptyQueue : public std::exception {
    const char* what () const throw () { return "Queue is empty."; }
};


// linked list queue node
template <class T>
class Node
{
    public:
        T data;
        Node<T>* next = nullptr;

        Node(T data) { this->data = data; }
};


// Linked list queue
template <class T>
class LinkedListQueue
{
    private:
        Node<T>* head = nullptr;
        Node<T>* tail = nullptr;
        int length = 0;

    public:

        // Returns true if queue is empty
        bool isEmpty()  { return this->length == 0; }
        
        // Returns number of nodes present in queue
        int getLength() { return this->length; }

        void enqueue(T data)
        // Add a node to the end of the queue
        {
            Node<T>* new_node = new Node<T>(data);

            if (this->head == nullptr)
            {
                this->head = new_node;
                this->tail = new_node;
            }
            else
            {
                this->tail->next = new_node;
                this->tail = new_node;
            }
            length++;
        }

        T dequeue()
        // Remove node from front of queue
        {
            if (this->head == nullptr)
                throw EmptyQueue();

            T data = this->head->data;

            if (this->head == this->tail)
            {
                this->head = nullptr;
                this->tail = nullptr;
            }
            else
                this->head = this->head->next;
            length--;
            return data;
        }

        T peek()
        // See node at front of queue without removing it
        {
            if (this->head == nullptr)
                throw EmptyQueue();
            return this->head->data;
        }
};
