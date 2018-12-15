#include <cassert>
#include "../linkedlist.h"


void test_push_empty_list() {
	sList singly = sList();
	dList doubly = dList();
	cList circular = cList();
	singly.push(1);
	doubly.push(1);
	circular.push(1);
	assert(singly.get_head()->data == 1);
	assert(singly.get_tail()->data == 1);
	assert(doubly.get_head()->data == 1);
	assert(doubly.get_tail()->data == 1);
	assert(circular.get_head()->data == 1);
	assert(circular.get_tail()->data == 1);
}


void test_append_empty_list() {
	sList singly = sList();
	dList doubly = dList();
	cList circular = cList();
	singly.append(1);
	doubly.append(1);
	circular.append(1);
	assert(singly.get_head()->data == 1);
	assert(singly.get_tail()->data == 1);
	assert(doubly.get_head()->data == 1);
	assert(doubly.get_tail()->data == 1);
	assert(circular.get_head()->data == 1);
	assert(circular.get_tail()->data == 1);
}


int main() {
	test_push_empty_list();
	test_append_empty_list();
}
