#ifndef UNROLLED_LINKED_LIST_STACK_H
#define UNROLLED_LINKED_LIST_STACK_H



/** Linked list node.
 *
 * @var array : Data member of unrolled linked list node.
 * @var next : Pointer to next node.
 * @var top : Keep track of the last node in the array.
 * @var previous : Pointer to previous node.
 */
template <class T = int>
class Node
{
    static const short SIZE = 10;

    public:
        T array[SIZE];
        int top = 0;
        Node* next = nullptr;
        Node* previous = nullptr;
};



/** Unrolled linked list stack class.
 *
 * @var head : Head node of the linked list.
 */
template <class T = int>
class Stack
{
    public:
        Node<T>* head;

    public:
        Stack() : head(nullptr) { }

        /** Returns true if stack has 0 members.
         */
        bool empty() { return head == nullptr; }
        
        /** Add a data member to the top of the stack. Create new node
         * if head node's array is full.
         *
         * @param data : Data to add to the stack.
         */
        void push(const T data);
        
        /** Remove the top of the stack and return it. Updates the head
         * node if the current head node's array is empty.
         *
         * @return : Data that resides at the top of the stack.
         */
        T pop();
        
        /** Return the top of the stack without removing it from the stack.
         *
         * @return : Data that resides at the top of the stack.
         */
        T peek();
};



template <class T>
void Stack<T>::push(const T data) {
    if (head == nullptr)
        head = new Node<T>();

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

            if (head != nullptr)
                head->previous = nullptr;
        }
        return data;
    }
}


template <class T>
T Stack<T>::peek() {
    if (head != nullptr)
        return head->array[head->top-1];
}



#endif // UNROLLED_LINKED_LIST_STACK_H
