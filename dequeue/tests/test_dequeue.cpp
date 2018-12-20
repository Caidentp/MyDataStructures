#include <assert.h>

#define TESTING

#include "../dequeue.h"


class TestLinkedList
{
    public:
        TestLinkedList() {
            test_push_empty();
            test_push_populated();
            test_append_empty();
            test_append_populated();
            test_leftPop_empty();
            test_leftPop_populated();
            test_rightPop_empty();
            test_rightPop_populated();
            test_leftPeek_empty();
            test_leftPeek_populated();
            test_rightPeek_empty();
            test_rightPeek_populated();
        }

    private:
        void test_push_empty() {
            deq::LinkedList q = deq::LinkedList();
            q.push(1);
            assert(q.head->data == 1 &&
                   "TestLinkedList::test_push_empty()");
            assert(q.tail->data == 1 &&
                   "TestLinkedList::test_push_empty()");
        }

        void test_push_populated() {
            deq::LinkedList q = deq::LinkedList();
            q.push(1);
            q.push(2);
            assert(q.head->data == 2 &&
                   "TestLinkedList::test_push_populated()");
            assert(q.tail->data == 1 &&
                   "TestLinkedList::test_push_populated()");
        }

        void test_append_empty() {
            deq::LinkedList q = deq::LinkedList();
            q.append(1);
            assert(q.head->data == 1 &&
                   "TestLinkedList::test_append_empty()");
            assert(q.tail->data == 1 &&
                   "TestLinkedList::test_append_empty()");
        }

        void test_append_populated() {
            deq::LinkedList q = deq::LinkedList();
            q.append(1);
            q.append(2);
            assert(q.head->data == 1 &&
                   "TestLinkedList::test_append_populated()");
            assert(q.tail->data == 2 &&
                   "TestLinkedList::test_append_populated()");
        }

        void test_leftPop_empty() {
            bool exception = false;
            deq::LinkedList q = deq::LinkedList();
            try {
                q.leftPop();
            }
            catch (dequeue::EmptyDequeue) {
                exception = true;
            }
            assert(exception == true &&
                   "TestLinkedList::test_leftPop_empty()");
        }

        void test_leftPop_populated() {
            deq::LinkedList q = deq::LinkedList();
            q.push(1);
            assert(q.leftPop() == 1 &&
                   "TestLinkedList::test_leftPop_populated()");
        }

        void test_rightPop_empty() {
            bool exception = false;
            deq::LinkedList q = deq::LinkedList();
            try {
                q.rightPop();
            }
            catch (dequeue::EmptyDequeue) {
                exception = true;
            }
            assert(exception == true &&
                   "TestLinkedList::test_rightPop_empty()");
        }

        void test_rightPop_populated() {
            deq::LinkedList q = deq::LinkedList();
            q.push(1);
            assert(q.rightPop() == 1 &&
                   "TestLinkedList::test_leftPop_populated()");
        }

        void test_leftPeek_empty() {
            bool exception = false;
            deq::LinkedList q = deq::LinkedList();
            try {
                q.leftPeek();
            }
            catch (dequeue::EmptyDequeue) {
                exception = true;
            }
            assert(exception == true &&
                   "TestLinkedList::test_leftPeek_empty()");
        }

        void test_leftPeek_populated() {
            deq::LinkedList q = deq::LinkedList();
            q.push(1);
            assert(q.leftPeek() == 1 &&
                   "TestLinkedList::test_leftPeek_populated()");
        }

        void test_rightPeek_empty() {
            bool exception = false;
            deq::LinkedList q = deq::LinkedList();
            try {
                q.rightPeek();
            }
            catch (dequeue::EmptyDequeue) {
                exception = true;
            }
            assert(exception == true &&
                   "TestLinkedList::test_rightPeek_empty()");
        }

        void test_rightPeek_populated() {
            deq::LinkedList q = deq::LinkedList();
            q.push(1);
            assert(q.rightPeek() == 1 &&
                   "TestLinkedList::test_rightPeek_populated()");
        }
};


class TestDequeue
{
    public:
        TestDequeue() {
            test_insertFront_empty();
            test_insertFront_populated();
            test_insertRear_empty();
            test_insertRear_populated();
            test_deleteFront_empty();
            test_deleteFront_one_element();
            test_deleteFront_two_elements();
            test_deleteRear_empty();
            test_deleteRear_one_element();
            test_deleteRear_two_elements();
            test_getFront_empty();
            test_getFront_populated();
            test_getRear_empty();
            test_getRear_populated();
        }

    private:
        void test_insertFront_empty() {
            deq q = deq();
            q.insertFront(1);
            assert(q.dequeue.head->data == 1 &&
                   "TestDequeue::test_insertFront_empty()");
            }

        void test_insertFront_populated() {
            deq q = deq();
            q.insertFront(1);
            q.insertFront(2);
            assert(q.dequeue.head->data == 2 &&
                   "TestDequeue::test_insertFront_populated()");
            assert(q.dequeue.tail->data == 1 &&
                   "TestDequeue::test_insertFront_populated()");
        }

        void test_insertRear_empty() {
            deq q = deq();
            q.insertRear(1);
            assert(q.dequeue.head->data == 1 &&
                   "TestDequeue::test_insertRear_empty()");
        }

        void test_insertRear_populated() {
            deq q = deq();
            q.insertRear(1);
            q.insertRear(2);
            assert(q.dequeue.head->data == 1 &&
                   "TestDequeue::test_insertRear_populated()");
            assert(q.dequeue.tail->data == 2 &&
                   "TestDequeue::test_insertRear_populated()");
        }

        void test_deleteFront_empty() {
            bool exception = false;
            deq q = deq();
            try {
                q.deleteFront();
            }
            catch (dequeue::EmptyDequeue) {
                exception = true;
            }
            assert(exception == true &&
                   "TestDequeue::test_deleteFront_empty()");
        }

        void test_deleteFront_one_element() {
            deq q = deq();
            q.insertFront(1);
            assert(q.deleteFront() == 1 &&
                   "TestDequeue::test_deleteFront_one_element()");
            assert(!(q.dequeue.head) && 
                   "TestDequeue::test_deleteFront_one_element()");
            q.insertFront(1);
            assert(q.dequeue.head->data == 1 &&
                   "TestDequeue::test_deleteFront_one_element()");
        }

        void test_deleteFront_two_elements() {
            deq q = deq();
            q.insertFront(1);
            q.insertFront(2);
            assert(q.deleteFront() == 2 &&
                   "TestDequeue::test_deleteFront_two_elements()");
            assert(q.dequeue.head->data == 1 &&
                   "TestDequeue::test_deleteFront_two_elements()");
        }

        void test_deleteRear_empty() {
            bool exception = false;
            deq q = deq();
            try {
                q.deleteRear();
            }
            catch (dequeue::EmptyDequeue) {
                exception = true;
            }
            assert(exception == true &&
                   "TestDequeue::test_deleteRear_empty()");
        }

        void test_deleteRear_one_element() {
            deq q = deq();
            q.insertFront(1);
            assert(q.deleteRear() == 1 &&
                   "TestDequeue::test_deleteRear_one_element()");
            assert(!(q.dequeue.head) && 
                   "TestDequeue::test_deleteRear_one_element()");
            q.insertFront(1);
            assert(q.dequeue.head->data == 1 &&
                   "TestDequeue::test_deleteRear_one_element()");
        }

        void test_deleteRear_two_elements() {
            deq q = deq();
            q.insertFront(1);
            q.insertFront(2);
            assert(q.deleteRear() == 1 &&
                   "TestDequeue::test_deleteRear_two_elements()");
            assert(q.dequeue.head->data == 2 &&
                   "TestDequeue::test_deleteRear_two_elements()");
        }

        void test_getFront_empty() {
            bool exception = false;
            deq q = deq();
            try {
                q.getFront();
            }
            catch (dequeue::EmptyDequeue) {
                exception = true;
            }
            assert(exception == true &&
                   "TestDequeue::test_getFront_empty()");
        }

        void test_getFront_populated() {
            deq q = deq();
            q.insertFront(1);
            assert(q.getFront() == 1 &&
                   "TestDequeue::test_getFront_populated()");
        }

        void test_getRear_empty() {
            bool exception = false;
            deq q = deq();
            try {
                q.getRear();
            }
            catch (dequeue::EmptyDequeue) {
                exception = true;
            }
            assert(exception == true &&
                   "TestDequeue::test_getRear_empty()");
        }

        void test_getRear_populated() {
            deq q = deq();
            q.insertFront(1);
            assert(q.getRear() == 1 &&
                   "TestDequeue::test_getRear_populated()");
        }
};


int main() {
    TestLinkedList test_linkedlist = TestLinkedList();
    TestDequeue test_dequeue = TestDequeue();
    (void)test_linkedlist;  // ignore unused variable compiler warning
    (void)test_dequeue;  // ignore unused variable compiler warning

    std::cout << std::endl << "All tests passed." << std::endl;
    return 0;
}