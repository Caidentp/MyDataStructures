#include <cassert>
#include <vector>

#define TEST

#include "bst.h"


void test_insert() {
    tree test = tree();
    test.insert(1);
    test.insert(2);
    test.insert(0);
    assert(test.get_data() == 1);
    assert(test.get_left()->get_data() == 0);
    assert(test.get_right()->get_data() == 2);
}


int main() {
    test_insert();
    std::cout << std::endl << "All tests passed." << std::endl;
    return 0;
}
