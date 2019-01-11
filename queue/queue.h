#ifndef MYQUEUE_H
#define MYQUEUE_H

#include <exception>

namespace myqueue {

/**
 *  @brief  Queue implimentation using a linked list.
 *  @var  head  Pointer to the first node in the list.
 *  @var  tail  Pointer to the last node in the list.
 *
 *  @tparam  T  Data type held by queue.
 *
 *  This class is a linked list that acts as a queue. New nodes
 *  are inserted at the front of the linked list and nodes are removed
 *  from the rear of the linked list. Insert and remove methods
 *  operate in O(1) time.
 */
template <class T = int>
class Queue {
#ifndef TESTING
    private:
#endif
#ifdef TESTING
    public:
#endif
	    /**
		 *  @brief  Doubly linked list node to hold queue data variables.
		 *  @var  next  Pointer to next node in the list.
		 *  @var  prev  Pointer to the previous node in the list.
		 */
        class Node {
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
        ~Queue();

        /**
		 *  @brief  Insert an item into the queue.
		 *  @param  data  Data to insert into the queue.
		 */
        inline void enqueue(const T data);
		
		/**
		 *  @brief  Remove and return top node in queue.
		 *  @return Data instance variable of top node.
		 */
        inline T dequeue();
		
		/**
		 *  @brief  See top item in queue without removing it.
		 *  @return Data instance variable of top node.
		 */
        inline T peek() const;

        /**
		 *  @brief  Check whether the queue is empty or not.
		 *  @return True if queue is emtty, false otherwise.
		 */
        bool empty() const { return head == nullptr; }
};  /// Queue


struct EmptyQueue : public std::exception {
	const char* what() const throw() {
		return "Queue is empty.";
	}
};


template <class T>
Queue<T>::~Queue() {
	Node* temp = head;
	while (temp) {
		Node* previous = temp;
		temp = temp->next;
		delete previous;
	}
	head = nullptr;
	tail = nullptr;
}


template <class T>
inline void Queue<T>::enqueue(const T data) {
	if (head == nullptr) {
		head = new Node(data);
		tail = head;
	}
	else {
		tail->next = new Node(data);
		tail = tail->next;
	}
}


template <class T>
inline T Queue<T>::dequeue() {
	if (tail != nullptr) {
		Node* temp = head;
		T data = temp->data;
		if (head == tail) {
			head = nullptr;
			tail = nullptr;
		}
		else {
			head = head->next;
		}
		delete temp;
		return data;
	}
	throw EmptyQueue();
}


template <class T>
inline T Queue<T>::peek() const {
	if (head != nullptr) {
		return head->data;
	}
	throw EmptyQueue();
}

}  /// namespace myqueue

typedef myqueue::Queue<int> queue;

#endif  /// MYQUEUE_H
