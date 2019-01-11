#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

namespace gstack {

/**
 *  @brief  Stack using an array.
 *  @var  stack  Array used as a stack
 *  @var  top  Top index in stack.
 *
 *  @tparam  T  Data type that stack will hold.
 *
 *  This is a wrapper class that uses stack methods on
 *  an array.
 */
template <class T = int>
class Stack {
    static const short MAX_SIZE = 10;

    private:
        T *stack[MAX_SIZE];
        int top;

    public:
        Stack() : top(-1) { };
        ~Stack() { delete [] stack; }

        /**
         *  @brief  Test if the stack is empty.
         *  @return True if stack is empty, false otherwise.
         */
        bool empty() const { return top == -1; }

        /**
         *  @brief  Test if the stack is full.
         *  @return True if stack is full, false otherwise.
         */
        bool full() const { return top+1 == MAX_SIZE; }

        /**
         *  @brief  Add a node to the top of the stack.
         *  @param  data  Data to add to the top of the stack.
         */
        void push(const T data) { if (top+1 < MAX_SIZE) { stack[++top] = data; } }

        /**
         *  @brief  Return top of stack and removing it.
         *  @return Top of stack if it exists.
         */
        T pop() { if (top > -1) { return stack[top--]; } }

        /**
         *  @brief  Return top of stack and remove it.
         *  @return Top of stack if it exists.
         */
        T peek() const { if (top > -1) { return stack[top]; } }
};

}  /// namespace gstack

#endif // ARRAY_STACK_H
