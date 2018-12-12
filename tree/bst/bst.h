#ifndef BST_H
#define BST_H

// #define TEST

#include <iostream>


namespace bst {


template <class T = int>
class Node final
{
    private:
        T data{NULL};
        Node *left{nullptr};
        Node *right{nullptr};

    #ifdef TEST
    public:
    #endif

    #ifndef TEST
    protected:
    #endif
        T get_data() const { return this->data; }
        Node* get_left() const { return this->left; }
        Node* get_right() const { return this->right; }
        void set_data(const T data) { this->data = data; }
        void set_left(Node* left) { this->left = left; }
        void set_right(Node* right) { this->right = right; }

    public:
        Node() { }
        Node(const T data) : data(data) { }
        ~Node();

        void insert(const T data);
        void remove(const T data);
        bool contains(const T data);
        Node* find(const T data);
        int children() const;
        void preorder() const;
        void inorder() const;
        void postorder() const;
};


template <class T>
void Node<T>::~Node() {
    delete left;
    delete right;
}


template <class T>
void Node<T>::insert(const T data) {
    if (this->data) {
        if (data < this->data) {
            if (this->left == nullptr)
                this->left = new Node(data);
            else
                this->left->insert(data);
        }
        else if (data > this->data) {
            if (this->right == nullptr)
                this->right = new Node(data);
            else
                this->right->insert(data);
        }
    }
    else
        this->data = data;
}


template <class T>
bool Node<T>::contains(const T data) {
    if (data < this->data) {
        if (this->left == nullptr)
            return false;
        else
            return this->left->contains(data);
    }
    else if (data > this->data) {
        if (this->right == nullptr)
            return false;
        else
            return this->right->contains(data);
    }
    else
        return true;
}


template <class T>
Node<T>* Node<T>::find(const T data) {
    if (data < this->data) {
        if (this->left == nullptr)
            return nullptr;
        else
            return this->left->find(data);
    }
    else if (data > this->data) {
        if (this->right == nullptr)
            return nullptr;
        else
            return this->right->find(data);
    }
    else
        return this;
}


template <class T>
void Node<T>::preorder() const {
    std::cout << this->data << " ";
    if (this->left != nullptr)
        this->left->preorder();
    if (this->right != nullptr)
        this->right->preorder();
}


template <class T>
void Node<T>::inorder() const {
    if (this->left != nullptr)
        this->left->preorder();
    std::cout << this->data << " ";
    if (this->right != nullptr)
        this->right->preorder();
}


template <class T>
void Node<T>::postorder() const {
    if (this->left != nullptr)
        this->left->preorder();
    if (this->right != nullptr)
        this->right->preorder();
    std::cout << this->data << " ";
}


template <class T>
int Node<T>::children() const {
    int count = 0;
    if (this->left != nullptr)
        count++;
    if (this->right != nullptr)
        count++;
    return count;
}



}  /// namespace bst


typedef bst::Node<int> tree;


#endif  /// BST_H

