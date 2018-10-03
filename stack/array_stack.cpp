#define MAX 10

template <class T>
class Stack
{
    private:
        // if top == -1 then the stack is empty
        int top = -1;
        
        // allocate an array big enough to hold the max size defined
        T arr[MAX];

    public:
        // returns true if a stack is empty: O(1) time
        bool isEmpty() { return (top == -1); }
        
        // returns true if a stack is full: O(1) time
        bool isFull() { return (top == MAX - 1); }

        void push(T data)
        // add an item to the end of a stack: O(1) time
        {
            // if stack is full
            if (top == MAX - 1)
                return;
                
            top++;
            arr[top] = data;
        }

        T pop()
        // return the item at the top of a stack: O(1) time
        {
            // if stack is empty
            if (top == -1)
                return -1;

            T data = arr[top];
            top--;
            return data;
        }
        
        T peek()
        // return the item at the top of a stack without removing it: O(1) time
        {
            // if stack is empty
            if (top == -1)
                return -1;
                
            return arr[top];
        }
};
