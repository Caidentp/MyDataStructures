#include <iostream>


template <class T>
class Node
{
    public:
        T data;
        Node<T>* parent;
        Node<T>* left = nullptr;
        Node<T>* right = nullptr;

        Node(T data = '\0', Node<T>* parent = nullptr)
        {
            this->data = data;
            this->parent = parent;
        }

        void insertNode(T data, Node<T>* parent = nullptr)
        {
            if (this->data != '\0')
            {
                if (data < this->data)
                {
                    if (this->left == nullptr)
                    {
                        Node<T>* new_node = new Node<T>(data, this);
                        this->left = new_node;
                    }
                    else
                        this->left->insertNode(data);
                }
                else if (data > this->data)
                {
                    if (this->right == nullptr)
                    {
                        Node<T>* new_node = new Node<T>(data, this);
                        this->right = new_node;
                    }
                    else
                        this->right->insertNode(data);
                }
            }
            else
                this->data = data;
        }

        void deleteNode(T data)
        {
            Node<T>* node = this->lookup(data);
            Node<T>* parent = this->getParent(data);

            if (node != nullptr)
            {
                int children = node->child_count();

                if (children == 0)
                {
                    if (parent != nullptr)
                    {
                        if (parent->left == node)
                            parent->left = nullptr;
                        else
                            parent->right = nullptr;
                    }
                    else
                        this->data = '\0';
                }

                else if (children == 1)
                {
                    Node<T>* n;

                    if (node->left != nullptr)
                        n = node->left;
                    else
                        n = node->right;

                    if (parent != nullptr)
                    {
                        if (parent->left == node)
                            parent->left = n;
                        else
                            parent->right = n;
                    }
                    else
                    {
                        this->data = n->data;
                        this->left = n->left;
                        this->right = n->right;
                    }
                }
                else
                {
                    parent = node;
                    Node<T>* successor = node->right;

                    while (successor->left != nullptr)
                    {
                        parent = successor;
                        successor = successor->left;
                    }

                    node->data = successor->data;

                    if (parent->left == successor)
                        parent->left = successor->right;
                    else
                        parent->right = successor->right;
                }
            }
        }

        Node<T>* lookup(T data)
        {
            if (data < this->data)
            {
                if (this->left == nullptr)
                    return nullptr;
                else
                    this->lookup(data);
            }
            else if (data > this->data)
            {
                if (this->right == nullptr)
                    return nullptr;
                else
                    this->right->lookup(data);
            }
            else
                return this;
        }

        Node<T>* getParent(T data, Node<T>* parent = nullptr)
        {
            if (data < this->data)
            {
                if (this->left == nullptr)
                    return nullptr;
                else
                    this->getParent(data, this);
            }
            else if (data > this->data)
            {
                if (this->right == nullptr)
                    return nullptr;
                else
                    this->right->getParent(data, this);
            }
            else
                return parent;
        }

        int child_count()
        {
            int counter = 0;
            if (this->left != nullptr)
                counter++;
            if (this->right != nullptr)
                counter++;
            return counter;
        }

        void preorder()
        {
            std::cout << this->data << " ";
            if (this->left != nullptr)
                this->left->inorder();
            if (this->right != nullptr)
                this->right->inorder();
        }

        void inorder()
        {
            if (this->left != nullptr)
                this->left->inorder();
            std::cout << this->data << " ";
            if (this->right != nullptr)
                this->right->inorder();
        }

        void postorder()
        {
            if (this->left != nullptr)
                this->left->inorder();
            if (this->right != nullptr)
                this->right->inorder();
            std::cout << this->data << " ";
        }
};
