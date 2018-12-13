#include <cassert>
#include <vector>

#define TEST

#include "bst.h"


void test_insert() {
    tree test = tree();
    test.insert(1);
    test.insert(2);
    test.insert(0);
    assert(test.get_data() == 1 && "test_insert()");
    assert(test.get_left()->get_data() == 0 && "test_insert()");
    assert(test.get_right()->get_data() == 2 && "test_insert()");
}


void test_contains() {
    tree test = tree();
    test.insert(1);
    assert(test.contains(1) == true && "test_contains()");
    assert(test.contains(2) == false && "test_contains()");
}


void test_find() {
    tree test = tree();
    test.insert(1);
    assert(test.find(1)->get_data() == 1 && "test_find()");
    assert(test.find(2) == nullptr && "test_find()");
}


void test_parent() {
    tree test = tree();
    test.insert(1);
    test.insert(2);
    assert(test.parent(1) == nullptr && "test_parent()");
    assert(test.parent(2)->get_data() == 1 && "test_parent()");
}


void test_children() {
    tree test = tree();
    test.insert(5);
    test.insert(2);
    test.insert(1);
    test.insert(3);
    assert(test.find(5)->children() == 1 && "test_children()");
    assert(test.find(2)->children() == 2 && "test_children()");
    assert(test.find(1)->children() == 0 && "test_children()");
}


int main() {
    test_insert();
    test_contains();
    test_find();
    test_parent();
    test_children();

    std::cout << std::endl << "All tests passed." << std::endl;
    return 0;
}

