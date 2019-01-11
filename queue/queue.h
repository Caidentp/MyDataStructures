#ifndef MYQUEUE_H
#define MYQUEUE_H


namespace myqueue {

template <class T = int>
class Queue
{
    private:
        class Node
        {
            public:
                T data;
                Node *next;
                Node *prev;
                Node(const T data, Node *next = nullptr)
                    : data(data)
                    , next(next) { }
        };  /// Queue::Node

        Node *head;
        Node *tail;

    public:
        Queue() : head(nullptr) , tail(nullptr) { }
        ~Queue() { delete head; }

        void enqueue(const T data) {
            if (head == nullptr) {
                head = new Node(data);
                tail = head;
            }
            else {
                tail->next = new Node(data);
                tail = tail->next;
            }
        }

        T dequeue() {
            if (tail != nullptr) {
                T data = head->data;
                if (head == tail) {
                    head = nullptr;
                    tail = nullptr;
                }
                else
                    head = head->next;
                return data;
            }
            return NULL;
        }

        T peek() const {
            if (head != nullptr)
                return head->data;
            return NULL;
        }

        bool empty() const {
            return head == nullptr;
        }
};  /// Queue

}  /// namespace myqueue


#endif  /// MYQUEUE_H
