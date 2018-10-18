#ifndef BST_H
#define BST_H
#include <iostream>


class Node
{
    private:
        int data;
        Node* parent;
        Node* left = nullptr;
        Node* right = nullptr;

    public:
        Node();
        Node(int data, Node* parent);

        int get_data();
        void set_data(int new_data);
        Node* get_parent();
        void set_parent(Node* new_parent);
        Node* get_left();
        void set_left(Node* new_left);
        Node* get_right();
        void set_right(Node* new_right);

        void insertNode(int data);
        void deleteNode(int data);
        Node* lookup(int data);
        void preorder();
        void inorder();
        void postorder();
        bool contains(int data);
        int child_count();

        virtual ~Node();
};


#endif
