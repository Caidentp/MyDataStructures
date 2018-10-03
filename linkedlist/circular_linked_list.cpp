#include <iostream>
#include <exception>

#define node Node<T>*


struct IndexError : public std::exception {
    const char* what () const throw () { return "List index out of range."; }
};


template <class T>
class Node
{
    public:
        T data;
        node next = this;

        Node(T data) { this->data = data; }
};


template <class T>
class CircularLinkedList
{
    private:
        node head;

    public:
        CircularLinkedList(node head = nullptr)
        {
            this->head = head;
        }

        void printList()
        {
            node temp = head;

            if (temp != nullptr)
            {
                do
                {
                    std::cout << temp->data << " ";
                    temp = temp->next;
                }
                while (temp != head);
            }
        }

        int length()
        {
            int counter = 0;

            if (head != nullptr)
            {
                node temp = head;
                do
                {
                    counter++;
                    temp = temp->next;
                }
                while (temp != head);
            }
            return counter;
        }

        void push(T data)
        {
            node new_node = new Node<T>(data);

            if (head == nullptr)
            {
                head = new_node;
                return;
            }

            node temp = head->next;
            while (temp->next != head)
                temp = temp->next;

            temp->next = new_node;
            new_node->next = head;
            head = new_node;
        }

        void append(T data)
        {
            if (head == nullptr)
            {
                push(data);
                return;
            }

            node new_node = new Node<T>(data);
            node temp = head;

            do
                temp = temp->next;
            while (temp->next != head);

            temp->next = new_node;
            new_node->next = head;
        }

        void insertIndex(int index, T data)
        {
            if (head == nullptr || index > this->length())
                throw IndexError();

            node new_node = new Node<T>(data);
            node temp = head;

            if (index == 0)
            {
                do
                    temp = temp->next;
                while (temp->next != head);

                new_node->next = head;
                head = new_node;
                temp->next = new_node;
                return;
            }

            for (int i = 1; i < index; i++)
                temp = temp->next;

            new_node->next = temp->next;
            temp->next = new_node;
        }

        T getIndex(int index)
        {
            if (head == nullptr || index >= this->length())
                throw IndexError();

            node temp = head;
            for (int i = 0; i < index; i++)
                temp = temp->next;

            return temp->data;
        }

        void deleteIndex(int index)
        {
            if (head == nullptr || index >= this->length())
                throw IndexError();

            node temp = head;
            node previous;

            if (index == 0)
            {
                previous = head;
                do
                    temp = temp->next;
                while (temp->next != head);

                head = head->next;
                delete previous;
                temp->next = head;
            }

            for (int i = 0; i < index; i++)
            {
                previous = temp;
                temp = temp->next;
            }

            previous->next = temp->next;
            delete temp;
        }
};
