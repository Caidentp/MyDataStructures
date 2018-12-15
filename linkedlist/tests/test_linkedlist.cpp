#include <assert.h>
#include "../linkedlist.h"


class TestSingly
{
    public:
        TestSingly() {
            this->test_default_ctor();
            this->test_ctor();
            this->test_initializer_list();
            this->test_getitem_in_range();
            this->test_getitem_out_of_range();
            this->test_setitem_in_range();
            this->test_setitem_out_of_range();
            this->test_contains_true_and_false();
            this->test_index_true_and_false();
            this->test_push_empty();
            this->test_append_empty();
            this->test_insert_empty();
            this->test_push_populated();
            this->test_append_populated();
            this->test_insert_populated();
            this->test_remove_empty();
            this->test_remove_head();
            this->test_remove_tail();
            this->test_remove_last();
        }

    private:
        void test_default_ctor() {
            sList singly = sList();
            assert(singly.get_head() == nullptr &&
                   "TestSingly::test_default_ctor()");
            assert(singly.get_tail() == nullptr &&
                   "TestSingly::test_default_ctor()");
            assert(singly.size() == 0 &&
                   "TestSingly::test_default_ctor()");
        }

        void test_ctor() {
            sList singly = sList(1);
            assert(singly.get_head()->data == 1 &&
                   "TestSingly::test_ctor()");
            assert(singly.get_tail()->data == 1 &&
                   "TestSingly::test_ctor()");
            assert(singly.size() == 1 &&
                   "TestSingly::test_ctor()");
        }

        void test_initializer_list() {
            sList singly = {1, 2, 3};
            assert(singly.get_head()->data == 1 &&
                   "TestSingly::test_initializer_list()");
            assert(singly.get_tail()->data == 3 &&
                   "TestSingly::test_initializer_list()");
            assert(singly.size() == 3 &&
                   "TestSingly::test_initializer_list()");
        }

        void test_getitem_in_range() {
            sList singly = sList(1);
            assert(singly[0] == 1 && 
                   "TestSingly::test_getitem_in_range()");
        }

        void test_getitem_out_of_range() {
            bool exception = false;
            sList singly = sList();
            try {
                int test = singly[0];
                (void)test;
            }
            catch (IndexError) {
                exception = true;
            }
            assert(exception == true && 
                   "TestSingly::test_getitem_out_of_range()");
        }

        void test_setitem_in_range() {
            sList singly = sList(1);
            singly[0] = 2;
            assert(singly[0] == 2 && 
                   "TestSingly::test_setitem_in_range()");
        }

        void test_setitem_out_of_range() {
            bool exception = false;
            sList singly = sList();
            try {
                singly[0] = 1;
            }
            catch (IndexError) {
                exception = true;
            }
            assert(exception == true && 
                   "TestSingly::test_setitem_out_of_range()");
        }

        void test_contains_true_and_false() {
            sList singly = {1, 2, 3};
            assert(singly.contains(3) == true &&
                   "TestSingly::test_contains_true_and_false()");
            assert(singly.contains(4) == false &&
                   "TestSingly::test_contains_true_and_false()");
        }

        void test_index_true_and_false() {
            sList singly = {1, 2, 3};
            assert(singly.index(1) == 0 &&
                   "TestSingly::test_index_true_and_false()");
            assert(singly.index(2) == 1 &&
                   "TestSingly::test_index_true_and_false()");
            assert(singly.index(3) == 2 &&
                   "TestSingly::test_index_true_and_false()");
            assert(singly.index(4) == -1 &&
                   "TestSingly::test_index_true_and_false()");
        }

        void test_push_empty() {
            sList singly = sList();
            singly.push(1);
            assert(singly.get_head()->data == 1 && 
                   "TestSingly::test_push_empty()");
            assert(singly.get_tail()->data == 1 &&
                   "TestSingly::test_push_empty()");
            assert(singly.size() == 1 &&
                   "TestSingly::test_push_empty()");
        }

        void test_append_empty() {
            sList singly = sList();
            singly.append(1);
            assert(singly.get_head()->data == 1 &&
                   "TestSingly::test_append_empty()");
            assert(singly.get_tail()->data == 1 &&
                   "TestSingly::test_append_empty()");
            assert(singly.size() == 1 &&
                   "TestSingly::test_append_empty()");
        }

        void test_insert_empty() {
            bool exception = false;
            sList singly = sList();
            try {
                singly.insert(1, 0);
            }
            catch (IndexError) {
                exception = true;
            }
            assert(exception == true &&
                   "TestSingly::test_insert_empty()");
        }

        void test_push_populated() {
            sList singly = sList(1);
            singly.push(2);
            assert(singly.get_head()->data == 2 &&
                   "TestSingly::test_push_populated()");
            assert(singly.get_tail()->data == 1 &&
                   "TestSingly::test_push_populated()");
            assert(singly.size() == 2 &&
                   "TestSingly::test_push_populated()");
        }

        void test_append_populated() {
            sList singly = sList(1);
            singly.append(2);
            assert(singly.get_tail()->data == 2 &&
                   "TestSingly::test_append_populated()");
            assert(singly.size() == 2 &&
                   "TestSingly::test_append_populated()");
        }

        void test_insert_populated() {
            sList singly = sList(1);
            singly.insert(2, 0);
            assert(singly.get_head()->data == 2 &&
                   "TestSingly::test_insert_populated()");
            assert(singly.get_tail()->data == 1 &&
                   "TestSingly::test_insert_populated()");
            assert(singly.size() == 2 &&
                   "TestSingly::test_insert_populated()");
        }

        void test_remove_empty() {
            bool exception = false;
            sList singly = sList();
            try {
                singly.remove(0);
            }
            catch (IndexError) {
                exception = true;
            }
            assert(exception == true &&
                   "TestSingly::test_remove_empty()");
        }

        void test_remove_head() {
            sList singly = {1, 2};
            singly.remove(0);
            assert(singly.get_head()->data == 2 &&
                   "TestSingly::test_remove_head()");
            assert(singly.get_tail()->data == 2 &&
                   "TestSingly::test_remove_head()");
            assert(singly.size() == 1 &&
                   "TestSingly::test_remove_head()");
        }
        
        void test_remove_tail() {
            sList singly = {1, 2};
            singly.remove(1);
            assert(singly.get_head()->data == 1 &&
                   "TestSingly::test_remove_tail()");
            assert(singly.get_tail()->data == 1 &&
                   "TestSingly::test_remove_tail()");
            assert(singly.size() == 1 &&
                   "TestSingly::test_remove_tail()");
        }
        
        void test_remove_last() {
            sList singly = sList(1);
            singly.remove(0);
            assert(singly.get_head() == nullptr &&
                   "TestSingly::test_remove_last()");
            assert(singly.get_tail() == nullptr &&
                   "TestSingly::test_remove_last()");
            assert(singly.size() == 0 &&
                   "TestSingly::test_remove_last()");
        }
};


class TestDoubly
{
    public:
        TestDoubly() {
            this->test_default_ctor();
            this->test_ctor();
            this->test_initializer_list();
            this->test_getitem_in_range();
            this->test_getitem_out_of_range();
            this->test_setitem_in_range();
            this->test_setitem_out_of_range();
            this->test_contains_true_and_false();
            this->test_index_true_and_false();
            this->test_push_empty();
            this->test_append_empty();
            this->test_insert_empty();
            this->test_push_populated();
            this->test_append_populated();
            this->test_insert_populated();
            this->test_remove_empty();
            this->test_remove_head();
            this->test_remove_tail();
            this->test_remove_last();
        }

    private:
        void test_default_ctor() {
            dList doubly = dList();
            assert(doubly.get_head() == nullptr &&
                   "TestDoubly::test_default_ctor()");
            assert(doubly.get_tail() == nullptr &&
                   "TestDoubly::test_default_ctor()");
            assert(doubly.size() == 0 &&
                   "TestDoubly::test_default_ctor()");
        }

        void test_ctor() {
            dList doubly = dList(1);
            assert(doubly.get_head()->data == 1 &&
                   "TestDoubly::test_ctor()");
            assert(doubly.get_tail()->data == 1 &&
                   "TestDoubly::test_ctor()");
            assert(doubly.size() == 1 &&
                   "TestDoubly::test_ctor()");
        }

        void test_initializer_list() {
            dList doubly = {1, 2, 3};
            assert(doubly.get_head()->data == 1 &&
                   "TestDoubly::test_initializer_list()");
            assert(doubly.get_tail()->data == 3 &&
                   "TestDoubly::test_initializer_list()");
            assert(doubly.size() == 3 &&
                   "TestDoubly::test_initializer_list()");
        }

        void test_getitem_in_range() {
            dList doubly = dList(1);
            assert(doubly[0] == 1 && 
                   "TestDoubly::test_getitem_in_range()");
        }

        void test_getitem_out_of_range() {
            bool exception = false;
            dList doubly = dList();
            try {
                int test = doubly[0];
                (void)test;
            }
            catch (IndexError) {
                exception = true;
            }
            assert(exception == true && 
                   "TestDoubly::test_getitem_out_of_range()");
        }

        void test_setitem_in_range() {
            dList doubly = dList(1);
            doubly[0] = 2;
            assert(doubly[0] == 2 && 
                   "TestDoubly::test_setitem_in_range()");
        }

        void test_setitem_out_of_range() {
            bool exception = false;
            dList doubly = dList();
            try {
                doubly[0] = 1;
            }
            catch (IndexError) {
                exception = true;
            }
            assert(exception == true && 
                   "TestDoubly::test_setitem_out_of_range()");
        }

        void test_contains_true_and_false() {
            dList doubly = {1, 2, 3};
            assert(doubly.contains(3) == true &&
                   "TestDoubly::test_contains_true_and_false()");
            assert(doubly.contains(4) == false &&
                   "TestDoubly::test_contains_true_and_false()");
        }

        void test_index_true_and_false() {
            dList doubly = {1, 2, 3};
            assert(doubly.index(1) == 0 &&
                   "TestDoubly::test_index_true_and_false()");
            assert(doubly.index(2) == 1 &&
                   "TestDoubly::test_index_true_and_false()");
            assert(doubly.index(3) == 2 &&
                   "TestDoubly::test_index_true_and_false()");
            assert(doubly.index(4) == -1 &&
                   "TestDoubly::test_index_true_and_false()");
        }

        void test_push_empty() {
            dList doubly = dList();
            doubly.push(1);
            assert(doubly.get_head()->data == 1 && 
                   "TestDoubly::test_push_empty()");
            assert(doubly.get_tail()->data == 1 &&
                   "TestDoubly::test_push_empty()");
            assert(doubly.size() == 1 &&
                   "TestDoubly::test_push_empty()");
        }

        void test_append_empty() {
            dList doubly = dList();
            doubly.append(1);
            assert(doubly.get_head()->data == 1 &&
                   "TestDoubly::test_append_empty()");
            assert(doubly.get_tail()->data == 1 &&
                   "TestDoubly::test_append_empty()");
            assert(doubly.size() == 1 &&
                   "TestDoubly::test_append_empty()");
        }

        void test_insert_empty() {
            bool exception = false;
            dList doubly = dList();
            try {
                doubly.insert(1, 0);
            }
            catch (IndexError) {
                exception = true;
            }
            assert(exception == true &&
                   "TestDoubly::test_insert_empty()");
        }

        void test_push_populated() {
            dList doubly = dList(1);
            doubly.push(2);
            assert(doubly.get_head()->data == 2 &&
                   "TestDoubly::test_push_populated()");
            assert(doubly.get_tail()->data == 1 &&
                   "TestDoubly::test_push_populated()");
            assert(doubly.size() == 2 &&
                   "TestDoubly::test_push_populated()");
        }

        void test_append_populated() {
            dList doubly = dList(1);
            doubly.append(2);
            assert(doubly.get_tail()->data == 2 &&
                   "TestDoubly::test_append_populated()");
            assert(doubly.size() == 2 &&
                   "TestDoubly::test_append_populated()");
        }

        void test_insert_populated() {
            dList doubly = dList(1);
            doubly.insert(2, 0);
            assert(doubly.get_head()->data == 2 &&
                   "TestDoubly::test_insert_populated()");
            assert(doubly.get_tail()->data == 1 &&
                   "TestDoubly::test_insert_populated()");
            assert(doubly.size() == 2 &&
                   "TestDoubly::test_insert_populated()");
        }

        void test_remove_empty() {
            bool exception = false;
            dList doubly = dList();
            try {
                doubly.remove(0);
            }
            catch (IndexError) {
                exception = true;
            }
            assert(exception == true &&
                   "TestDoubly::test_remove_empty()");
        }

        void test_remove_head() {
            dList doubly = {1, 2};
            doubly.remove(0);
            assert(doubly.get_head()->data == 2 &&
                   "TestDoubly::test_remove_head()");
            assert(doubly.get_tail()->data == 2 &&
                   "TestDoubly::test_remove_head()");
            assert(doubly.size() == 1 &&
                   "TestDoubly::test_remove_head()");
        }

        void test_remove_tail() {
            dList doubly = {1, 2};
            doubly.remove(1);
            assert(doubly.get_head()->data == 1 &&
                   "TestDoubly::test_remove_tail()");
            assert(doubly.get_tail()->data == 1 &&
                   "TestDoubly::test_remove_tail()");
            assert(doubly.size() == 1 &&
                   "TestDoubly::test_remove_tail()");
        }

        void test_remove_last() {
            dList doubly = dList(1);
            doubly.remove(0);
            assert(doubly.get_head() == nullptr &&
                   "TestDoubly::test_remove_last()");
            assert(doubly.get_tail() == nullptr &&
                   "TestDoubly::test_remove_last()");
            assert(doubly.size() == 0 &&
                   "TestDoubly::test_remove_last()");
        }
};


int main() {
    TestSingly singly_test_suite = TestSingly();
    TestDoubly doubly_test_suite = TestDoubly();
    (void)singly_test_suite;
    (void)doubly_test_suite;

    std::cout << std::endl << "All tests passed." << std::endl;
    return 0;
}
