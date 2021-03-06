#define TESTING

#include <assert.h>
#include <iostream>
#include "../stack.h"


class TestStack {
    public:
        TestStack() {
            test_push_empty();
            test_push_one_element();
            test_push_full();
            test_pop_empty();
            test_pop_one_element();
            test_peek_empty();
            test_peek_one_element();
            test_empty_empty();
            test_empty_not_empty();
            test_full_empty();
            test_full_full();
        }

    private:
        void test_push_empty() {
            stak s = stak();
            s.push(1);
            assert(s.stack[0] == 1 &&
                   "TestStack::test_push_empty()");
            assert(s.top == 0 &&
                   "TestStack::test_push_empty()");
        }

        void test_push_one_element() {
            stak s = stak();
            s.push(1);
            s.push(2);
            assert(s.stack[0] == 1 &&
                   "TestStack::test_push_one_element()");
            assert(s.stack[1] == 2 &&
                   "TestStack::test_push_one_element()");
            assert(s.top == 1 &&
                   "TestStack::test_push_one_element()");
        }

        void test_push_full() {
            stak s = stak();
            s.push(1);
            s.push(2);
            s.push(3);
            s.push(4);
            s.push(5);
            s.push(6);
            s.push(7);
            s.push(8);
            s.push(9);
            s.push(10);
            s.push(11);
            assert(s.stack[0] == 1 &&
                   "TestStack::test_push_full()");
            assert(s.stack[9] == 10 &&
                   "TestStack::test_push_full()");
            assert(s.top == 9 &&
                   "TestStack::test_push_full()");
        }

        void test_pop_empty() {
            bool exception = false;
            stak s = stak();
            try {
                s.pop();
            }
            catch (gstack::EmptyStack) {
                exception = true;
            }
            assert(exception &&
                   "TestStack::test_pop_empty()");
        }

        void test_pop_one_element() {
            stak s = stak();
            s.push(1);
            assert(s.pop() == 1 &&
                   "TestStack::test_pop_one_element()");
            assert(s.top == -1 &&
                   "TestStack::test_pop_one_element()");
        }

        void test_peek_empty() {
            bool exception = false;
            stak s = stak();
            try {
                s.peek();
            }
            catch (gstack::EmptyStack) {
                exception = true;
            }
            assert(exception &&
                   "TestStack::test_peek_empty()");
        }

        void test_peek_one_element() {
            stak s = stak();
            s.push(1);
            assert(s.peek() == 1 &&
                   "TestStack::test_peek_one_element()");
            assert(s.top == 0 &&
                   "TestStack::test_peek_one_element()");
        }

        void test_empty_empty() {
            stak s = stak();
            assert(s.empty() &&
                   "TestStack::test_empty_empty()");
        }

        void test_empty_not_empty() {
            stak s = stak();
            s.push(1);
            assert(!s.empty() &&
                   "TestStack::test_push_full()");
        }

        void test_full_empty() {
            stak s = stak();
            assert(!s.full() &&
                   "TestStack::test_full_empty()");
        }

        void test_full_full() {
            stak s = stak();
            s.push(1);
            s.push(2);
            s.push(3);
            s.push(4);
            s.push(5);
            s.push(6);
            s.push(7);
            s.push(8);
            s.push(9);
            s.push(10);
            s.push(11);
            assert(s.full() &&
                   "TestStack::test_full_full()");
        }
};


int main() {
    TestStack testSuite = TestStack();
    (void)testSuite;  // ignore unused variable compiler warning

    std::cout << std::endl << "All tests passed." << std::endl;
    return 0;
}
