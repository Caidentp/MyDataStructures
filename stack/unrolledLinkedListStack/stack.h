#ifndef UNROLLED_LINKED_LIST_STACK_H
#define UNROLLED_LINKED_LIST_STACK_H

namespace ustack {

#include <exception>

/** 
 *  @brief  Unrolled linked list stack class.
 *  @var  head  Head node of the linked list.
 *
 *  @tparam T Data held by stack nodes.
 *
 *  An unrolled stack is linked list stack whose
 *  nodes contain arrays of data rather than a single
 *  data instance variable. Unrolled linked list stacks
 *  benifit from the speed of access of array stacks
 *  as well as the dynamic nature of linked lists.
 */
template <class T = int>
class Stack {
    public:
        /** 
         *  @brief  Linked list node.
         *  @var  array  Data member of unrolled linked list node.
         *  @var  next   Pointer to next node.
         *  @var  top    Keep track of the last node in the array.
         *  @var  previous  Pointer to previous node.
         */
        class Node {
            static const short SIZE = 10;

            public:
                T array[SIZE];
                int top{0};
                Node* next{nullptr};
                Node* previous{nullptr};
        };
    
        Node* head;

        Stack() : head(nullptr) { }

        /** 
         *  @brief  Returns true if stack has 0 members.
         *  @return True if stack is empty, false otherwise.
         */
        bool empty() { return head == nullptr; }

        /** 
         *  @brief  Add a data member to the top of the stack.
         *  @param  data  Data to add to the stack.
         */
        void push(const T data);

        /** 
         *  @brief  Remove the top of the stack and return it.
         *  @return Data that resides at the top of the stack.
         */
        T pop();

        /** 
         *  @brief  Return the top of the stack without removing it from the stack.
         *  @return Data that resides at the top of the stack.
         */
        T peek() const;
};


struct EmptyStack : public std::exception {
    const char *what() const throw() {
        return "Stack is empty.";
    }
};


template <class T>
void Stack<T>::push(const T data) {
    if (head == nullptr) {
        head = new Node();
    }
    else if (head->top == 10) {
        head->previous = new Node<T>();
        head->previous->next = head;
        head = head->previous;
    }
    head->array[head->top++] = data;
}


template <class T>
T Stack<T>::pop() {
    if (head != nullptr) {
        T data = head->array[--head->top];
        if (head->top == 0) {
            head = head->next;
            if (head != nullptr) {
                head->previous = nullptr;
            }
        }
        return data;
    }
    throw EmptyStack();
}


template <class T>
T Stack<T>::peek() const {
    if (head != nullptr) {
        return head->array[head->top-1];
    }
    throw EmptyStack();
}

}  ///  namespace ustack

#endif /// UNROLLED_LINKED_LIST_STACK_H
