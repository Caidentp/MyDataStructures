#ifndef LINKED_LIST_STACK_H
#define LINKED_LIST_STACK_H

namespace liststack {
    
#include <exception>

/**
 *  @brief  Stack wrapper class using a linked list.
 *  @var  len   Total number of stack nodes.
 *  @var  head  Pointer to first node in the stack.
 *
 *  @tparam T Data type nodes will hold.
 *
 *  This class uses linked list as an internal data structure
 *  to represent a stack. Stack<T> is a wrapper class around
 *  a linked list.
 */
template <class T = int>
class Stack {
    private:
#ifdef TESTING
    public:
#endif
        /**
         *  @brief  Linked list nodes used in the stack.
         *  @var  data  Data held by this node.
         *  @var  next  Pointer to next node in the list.
         */
        class Node {
            public:
                T data;
                Node* next{nullptr};

                Node(const T data) 
                    : data(data) { }
        };

        int len;
        Node* head;

    public:
        Stack() : len(0), head(nullptr) { }
        Stack(const T data) : len(1) { head = new Node(data); }
        ~Stack();

        /**
         *  @brief  Add a node to the head of the stack.
         *  @param  data  Data to add to the head of the stack.
         */
        void push(const T data);

        /**
         *  @brief  Remove and return top of stack.
         *  @return Data instance variable of node at top of stack.
         */
        T pop();

        /**
         *  @brief  View top of stack without removing it.
         *  @return Data instance variable of node at top of stack.
         */
        T peek() const;

        /**
         *  @brief  Check if the stack is empty.
         *  @return True if stack is empty, false otherwise.
         */
        bool empty() const { return head == nullptr; }

        /**
         *  @brief  Return the total number of nodes in the stack.
         *  @return The total number of nodes in the stack.
         */
        int size() const { return len; }

};


struct EmptyStack : public std::exception {
    const char *what() const throw() {
        return "Stack is empty.";
    }
};


template <class T>
Stack<T>::~Stack() {
    Node* temp = head;
    while (temp) {
        Node* next = temp->next;
        delete temp;
        temp = next;
    }
    head = nullptr;
}


template <class T>
void Stack<T>::push(const T data) {
    Node* newNode = new Node(data);

    if (head == nullptr) {
        head = newNode;
    }
    else {
        newNode->next = head;
        head = newNode;
    }
    len++;
}


template <class T>
T Stack<T>::pop() {
    if (head) {
        Node* temp = head;
        T data = temp->data;
        head = head->next;
        len--;
        delete temp;
        return data;
    }
    throw EmptyStack();
}


template <class T>
T Stack<T>::peek() const {
    if (head != nullptr) {
        return head->data;
    }
    throw EmptyStack();
}

}  /// namespace liststack

typedef liststack::Stack<int> stak;

#endif // LINKED_LIST_STACK_H
