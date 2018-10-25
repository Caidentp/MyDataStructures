#ifndef BST_H
#define BST_H
#include <iostream>
#include <exception>


template <class T = int>
class Node
{
    private:
        Node<T>* left = nullptr;
        Node<T>* right = nullptr;
        Node<T>* parent;
        T data;

    public:
        Node(const T data = '\0', Node<T>* parent = nullptr);
        virtual ~Node();

        Node<T>* get_left() const { return this->left; }
        void set_left(Node<T>* left) { this->left = left; }
        Node<T>* get_right() const { return this->right; }
        void set_right(Node<T>* right) { this->right = right; }
        Node<T>* get_parent() const { return this->parent; }
        void set_parent(Node<T>* parent) { this->parent = parent; }
        T get_data() const { return this->data; }
        void set_data(T data) { this->data = data; }

        void insert_node(const T data);
        void delete_node(const T data);
        Node<T>* lookup(const T data);
        void preorder() const;
        void inorder() const;
        void postorder() const;
        bool contains(const T data) const;
        int child_count() const;
};


#include "bst.tpp"
#endif // BST_H
