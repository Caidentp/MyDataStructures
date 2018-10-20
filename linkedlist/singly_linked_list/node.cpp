#include "test.h"


// Default constructor
Node::Node() { this->data = '\0'; }


// Constructor
Node::Node(int data) { this->data = data; }


// Destructor
Node::~Node() { delete next; }


// Get data instance variable
int Node::get_data() const { return this->data; }


// Set data instance variable
void Node::set_data(const int data) { this->data = data; }


// Get next instance variable
Node* Node::get_next() const { return this->next; }


// Set next instance variable
void Node::set_next(Node* next) { this->next = next; }
