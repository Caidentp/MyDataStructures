#define TESTING

#include <assert.h>
#include <iostream>
#include "../hashtable.h"


class TestLinkedList {
    public:
        TestLinkedList() {
            test_default_ctor();
            test_insert_empty();
            test_insert_populated();
            test_find_empty();
            test_find_one_element();
            test_find_two_elements();
            test_find_three_elements();
            test_remove_empty();
            test_remove_one_element();
            test_remove_two_elements_head();
            test_remove_two_elements_tail();
        }

    private:
        void test_default_ctor() {
            table::LinkedList list = table::LinkedList();
            assert(list.head == nullptr &&
                   "TestLinkedList::test_linkedlist_default_ctor()");
            assert(list.tail == nullptr &&
                   "TestLinkedList::test_linkedlist_default_ctor()");
        }

        void test_insert_empty() {
            table::LinkedList list = table::LinkedList();
            list.insert("test", 1);
            assert(list.head->key == "test" &&
                   "TestLinkedList::test_insert_empty()");
            assert(list.head->val == 1 &&
                   "TestLinkedList::test_insert_empty()");
            assert(list.tail->key == "test" &&
                   "TestLinkedList::test_insert_empty()");
            assert(list.tail->val == 1 &&
                   "TestLinkedList::test_insert_empty()");
        }

        void test_insert_populated() {
            table::LinkedList list = table::LinkedList();
            list.insert("first", 1);
            list.insert("second", 2);
            assert(list.head->key == "first" &&
                   "TestLinkedList::test_insert_populated()");
            assert(list.head->val == 1 &&
                   "TestLinkedList::test_insert_populated()");
            assert(list.tail->key == "second" &&
                   "TestLinkedList::test_insert_populated()");
            assert(list.tail->val == 2 &&
                   "TestLinkedList::test_insert_populated()");
        }

        void test_find_empty() {
            bool exception = false;
            table::LinkedList list = table::LinkedList();
            try {
                list.find("test");
            }
            catch (hashtable::KeyError){
                exception = true;
            }
            assert(exception = true &&
                   "TestLinkedList::test_find_empty()");
        }

        void test_find_one_element() {
            table::LinkedList list = table::LinkedList();
            list.insert("test", 1);
            assert(list.find("test") == 1 &&
                   "TestLinkedList::test_find_one_element()");
        }

        void test_find_two_elements() {
            table::LinkedList list = table::LinkedList();
            list.insert("first", 1);
            list.insert("second", 2);
            assert(list.find("first") == 1 &&
                   "TestLinkedList::test_find_two_elements()");
            assert(list.find("second") == 2 &&
                   "TestLinkedList::test_find_two_elements()");
        }

        void test_find_three_elements() {
            table::LinkedList list = table::LinkedList();
            list.insert("first", 1);
            list.insert("second", 2);
            list.insert("third", 3);
            assert(list.find("first") == 1 &&
                   "TestLinkedList::test_find_three_elements()");
            assert(list.find("second") == 2 &&
                   "TestLinkedList::test_find_three_elements()");
            assert(list.find("third") == 3 &&
                   "TestLinkedList::test_find_three_elements()");
        }

        void test_remove_empty() {
            table::LinkedList list = table::LinkedList();
            list.remove("test");
            assert(list.head == nullptr &&
                   "TestLinkedList::test_remove_empty()");
            assert(list.tail == nullptr &&
                   "TestLinkedList::test_remove_empty()");
        }

        void test_remove_one_element() {
            table::LinkedList list = table::LinkedList();
            list.insert("test", 1);
            list.remove("test");
            assert(list.head == nullptr &&
                   "TestLinkedList::test_remove_one_element()");
            assert(list.tail == nullptr &&
                   "TestLinkedList::test_remove_one_element()");
        }

        void test_remove_two_elements_head() {
            table::LinkedList list = table::LinkedList();
            list.insert("first", 1);
            list.insert("second", 2);
            list.remove("first");
            assert(list.head->key == "second" &&
                   "TestLinkedList::test_remove_two_elements_head()");
            assert(list.head->val == 2 &&
                   "TestLinkedList::test_remove_two_elements_head()");
            assert(list.tail->key == "second" &&
                   "TestLinkedList::test_remove_two_elements_head()");
            assert(list.tail->val == 2 &&
                   "TestLinkedList::test_remove_two_elements_head()");
        }

        void test_remove_two_elements_tail() {
            table::LinkedList list = table::LinkedList();
            list.insert("first", 1);
            list.insert("second", 2);
            list.remove("second");
            assert(list.head->key == "first" &&
                   "TestLinkedList::test_remove_two_elements_tail()");
            assert(list.head->val == 1 &&
                   "TestLinkedList::test_remove_two_elements_tail()");
            assert(list.tail->key == "first" &&
                   "TestLinkedList::test_remove_two_elements_tail()");
            assert(list.tail->val == 1 &&
                   "TestLinkedList::test_remove_two_elements_tail()");
        }
};


class TestHashTable {
    public:
        TestHashTable() {
            test_put_one_element();
            test_put_two_elements();
            test_get_empty();
            test_get_populated();
            test_remove_empty();
            test_remove_one_element();
        }

    private:
        void test_put_one_element() {
            table t = table(1);
            t.put("first", 1);
            assert(t.table[0].head->key == "first" &&
                   "TestHashTable::test_put_one_element()");
            assert(t.table[0].head->val == 1 &&
                   "TestHashTable::test_put_one_element()");
            assert(t.table[0].tail->key == "first" &&
                   "TestHashTable::test_put_one_element()");
            assert(t.table[0].tail->val == 1 &&
                   "TestHashTable::test_put_one_element()");
        }

        void test_put_two_elements() {
            table t = table(1);
            t.put("first", 1);
            t.put("second", 2);
            assert(t.table[0].head->key == "first" &&
                   "TestHashTable::test_put_two_elements()");
            assert(t.table[0].head->val == 1 &&
                   "TestHashTable::test_put_two_elements()");
            assert(t.table[0].tail->key == "second" &&
                   "TestHashTable::test_put_two_elements()");
            assert(t.table[0].tail->val == 2 &&
                   "TestHashTable::test_put_two_elements()");
        }

        void test_get_empty() {
            bool exception = false;
            table t = table(1);
            try {
                t.get("test");
            }
            catch (hashtable::KeyError) {
                exception = true;
            }
            assert(exception == true &&
                   "TestHashTable::test_get_empty()");
        }

        void test_get_populated() {
            table t = table(1);
            t.put("test", 1);
            assert(t.get("test") == 1 &&
                   "TestHashTable::test_get_populated()");
        }

        void test_remove_empty() {
            table t = table(1);
            t.remove("test");
            bool exception = false;
            try {
                t.get("test");
            }
            catch (hashtable::KeyError) {
                exception = true;
            }
            assert(exception == true &&
                   "TestHashTable::test_remove_empty()");
        }

        void test_remove_one_element() {
            table t = table(1);
            t.put("test", 1);
            t.remove("test");
            assert(t.table[0].head == nullptr &&
                   "TestHashTable::test_remove_one_element()");
            assert(t.table[0].tail == nullptr &&
                   "TestHashTable::test_remove_one_element()");
            bool exception = false;
            try {
                t.get("test");
            }
            catch (hashtable::KeyError) {
                exception = true;
            }
            assert(exception == true &&
                   "TestHashTable::test_remove_one_element()");
        }
};


int main() {
    TestLinkedList testLinkedListSuite = TestLinkedList();
    TestHashTable testHashTableSuite =  TestHashTable();
    (void)testLinkedListSuite;  //  ignore unused compiler warning
    (void)testHashTableSuite;   //  ignore unused compiler warning

    std::cout << std::endl << "All tests passed." << std::endl;
    return 0;
}
