#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H


template <class T = int>
class Stack
{
    static const short MAX_SIZE = 10;

    public:
        T stack[MAX_SIZE];
        int top;

    public:
        Stack() : top(-1) { };

        bool empty() { return top == -1; }
        bool full()  { return top+1 == MAX_SIZE; }

        void push(const T data) {
            if (top+1 < MAX_SIZE)
                stack[++top] = data;
        }

        T pop() {
            if (top > -1)
                return stack[top--];
        }

        T peek() const {
            if (top > -1)
                return stack[top];
        }
};


#endif // ARRAY_STACK_H
