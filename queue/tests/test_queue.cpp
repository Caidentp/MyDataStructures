#define TESTING

#include <assert.h>
#include <iostream>
#include "../queue.h"


class TestQueue {
    public:
        TestQueue() {
            test_enqueue_empty();
            test_enqueue_one_item();
            test_enqueue_two_items();
            test_dequeue_empty();
            test_dequeue_one_element();
            test_dequeue_two_elements();
            test_peek_empty();
            test_peek_one_element();
            test_peek_two_elements();
        }

    private:
        void test_enqueue_empty() {
            queue q = queue();
            q.enqueue(1);
            assert(q.head->data == 1 &&
                   "TestQueue::test_enqueue_empty()");
            assert(q.tail->data == 1 &&
                   "TestQueue::test_enqueue_empty()");
        }

        void test_enqueue_one_item() {
            queue q = queue();
            q.enqueue(1);
            q.enqueue(2);
            assert(q.head->data == 1 &&
                   "TestQueue::test_enqueue_one_item()");
            assert(q.tail->data == 2 &&
                   "TestQueue::test_enqueue_one_item()");
        }

        void test_enqueue_two_items() {
            queue q = queue();
            q.enqueue(1);
            q.enqueue(2);
            q.enqueue(3);
            assert(q.head->data == 1 &&
                   "TestQueue::test_enqueue_one_item()");
            assert(q.tail->data == 3 &&
                   "TestQueue::test_enqueue_one_item()");
        }

        void test_dequeue_empty() {
            bool exception = false;
            queue q = queue();
            try {
                q.dequeue();
            }
            catch (myqueue::EmptyQueue) {
                exception = true;
            }
            assert(exception == true &&
                   "TestQueue::test_dequeue_empty()");
        }

        void test_dequeue_one_element() {
            queue q = queue();
            q.enqueue(1);
            assert(q.dequeue() == 1 &&
                   "TestQueue::test_dequeue_one_element()");
            assert(!(q.head) &&
                   "TestQueue::test_dequeue_one_element()");
            assert(!(q.tail) &&
                   "TestQueue::test_dequeue_one_element()");
        }

        void test_dequeue_two_elements() {
            queue q = queue();
            q.enqueue(1);
            q.enqueue(2);
            assert(q.dequeue() == 1 &&
                   "TestQueue::test_dequeue_two_elements()");
            assert(q.head->data == 2 &&
                   "TestQueue::test_dequeue_two_elements()");
            assert(q.tail->data == 2 &&
                   "TestQueue::test_dequeue_two_elements()");
            assert(q.dequeue() == 2 &&
                   "TestQueue::test_dequeue_two_elements()");
        }

        void test_peek_empty() {
            bool exception = false;
            queue q = queue();
            try {
                q.dequeue();
            }
            catch (myqueue::EmptyQueue) {
                exception = true;
            }
            assert(exception == true &&
                   "TestQueue::test_peek_empty()");
        }

        void test_peek_one_element() {
            queue q = queue();
            q.enqueue(1);
            assert(q.peek() == 1 &&
                   "TestQueue::test_peek_one_element()");
            assert(q.head->data == 1 &&
                   "TestQueue::test_peek_one_element()");
            assert(q.tail->data == 1 &&
                   "TestQueue::test_peek_one_element()");
        }

        void test_peek_two_elements() {
            queue q = queue();
            q.enqueue(1);
            q.enqueue(2);
            assert(q.peek() == 1 &&
                   "TestQueue::test_peek_one_element()");
            assert(q.head->data == 1 &&
                   "TestQueue::test_peek_one_element()");
            assert(q.tail->data == 2 &&
                   "TestQueue::test_peek_one_element()");
        }
};


int main() {
    TestQueue testSuite = TestQueue();
    (void)testSuite;

    std::cout << std::endl << "All tests passed." << std::endl;
    return 0;
}
