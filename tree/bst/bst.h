#ifndef NODE_H
#define NODE_H
#include <iostream>


class Node
{
    private:
        int data;
        Node* parent;
        Node* left = nullptr;
        Node* right = nullptr;

    public:
        Node();  // complete
        Node(int data, Node* parent);  // complete

        int get_data();  // complete
        void set_data(int new_data);  // complete
        Node* get_parent();  // complete
        void set_parent(Node* new_parent);  // complete
        Node* get_left();  // complete
        void set_left(Node* new_left);  // complete
        Node* get_right();  // complete
        void set_right(Node* new_right);  // complete

        void insertNode(int data);  // complete
        void deleteNode(int data);  // complete
        Node* lookup(int data);  // complete
        void preorder();  // complete
        void inorder();  // complete
        void postorder();  // complete
        bool contains(int data);  // complete
        int child_count();  // complete

        virtual ~Node();  // complete
};


#endif
