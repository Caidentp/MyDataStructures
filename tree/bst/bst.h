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

        int get_data() const;
        void set_data(int new_data);
        Node* get_parent() const;
        void set_parent(Node* new_parent);
        Node* get_left() const;
        void set_left(Node* new_left);
        Node* get_right() const;
        void set_right(Node* new_right);

        void insertNode(const int data);
        void deleteNode(const int data);
        Node* lookup(const int data);
        void preorder() const;
        void inorder() const;
        void postorder() const;
        bool contains(const int data) const;
        int child_count() const;

        virtual ~Node();
};


#endif
