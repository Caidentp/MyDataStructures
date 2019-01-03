#include <assert.h>

#define TESTING

#include "../array_list.h"


class TestArrayList
{
    public:
        TestArrayList() {
            this->test_default_ctor();
            this->test_ctor();
            this->test_append();
            this->test_pop_populated();
            this->test_pop_empty();
            this->test_expand();
            this->test_getitem_in_range();
            this->test_getitem_out_of_range();
            this->test_setitem_in_range();
            this->test_setitem_out_of_range();
            this->test_size();
        }

    private:
        void test_default_ctor() {
            ArrayList array = ArrayList();
            assert(array.size() == 0 &&
                   "TestArrayList::test_default_ctor()");
            assert(array.max_size == 10 &&
                   "TestArrayList::test_default_ctor()");
		    delete array;
        }

        void test_ctor() {
            ArrayList array = ArrayList(5);
            assert(array.size() == 0 &&
                   "TestArrayList::test_ctor()");
            assert(array.max_size == 5 &&
                   "TestArrayList::test_ctor()");
        }

        void test_append() {
            ArrayList array = ArrayList();
            array.append(1);
            array.append(2);
            array.append(3);
            assert(array.size() == 3 &&
                   "TestArrayList::test_append()");
        }

        void test_pop_populated() {
            ArrayList array = ArrayList();
            array.append(1);
            array.append(2);
            assert(array.pop() == 2 &&
                   "TestArrayList::test_pop_populated()");
            assert(array.pop() == 1 &&
                   "TestArrayList::test_pop_populated()");
            assert(array.size() == 0 &&
                   "TestArrayList::test_pop_populated()");
        }

        void test_pop_empty() {
            bool exception = false;
            ArrayList array = ArrayList();
            try {
                array.pop();
            }
            catch (arraylist::EmptyList) {
                exception = true;
            }
            assert(exception == true &&
                   "TestArrayList::test_pop_empty()");
        }

        void test_expand() {
            ArrayList array = ArrayList(1);
            array.append(1);
            array.append(2);
            assert(array.size() == 2 &&
                   "TestArrayList::test_expand()");
            assert(array.max_size == 2 &&
                   "TestArrayList::test_expand()");
        }

        void test_getitem_in_range() {
            ArrayList array = ArrayList();
            array.append(1);
            assert(array[0] == 1 &&
                   "TestArrayList::test_getitem_in_range()");
        }

        void test_getitem_out_of_range() {
            bool exception = false;
            ArrayList array = ArrayList();
            try {
                int test = array[0];
                (void)test;  // ignore unused variable compiler warning
            }
            catch (arraylist::IndexError) {
                exception = true;
            }
            assert(exception == true && 
                   "TestArrayList::test_getitem_out_of_range()");
        }

        void test_setitem_in_range() {
            ArrayList array = ArrayList();
            array.append(1);
            array[0] = 2;
            assert(array[0] == 2 &&
                   "TestArrayList::test_set_item_in_range()");
        }

        void test_setitem_out_of_range() {
            bool exception = false;
            ArrayList array = ArrayList();
            try {
                array[0] = 1;
            }
            catch (arraylist::IndexError) {
                exception = true;
            }
            assert(exception == true &&
                   "TestArrayList::test_setitem_out_of_range()");
        }

        void test_size() {
            ArrayList array = ArrayList();
            array.append(1);
            array.append(2);
            assert(array.size() == 2 &&
                   "TestArrayList::test_size()");
        }
};


int main() {
    TestArrayList test_suite = TestArrayList();
    (void)test_suite;  // ignore unused variable compiler warning
    
    std::cout << std::endl << "All tests passed." << std::endl;
    return 0;
}
