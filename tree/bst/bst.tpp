#include "bst.h"


template <class T>
Node<T>::Node(const T data, Node<T>* parent)
{
    this->data = data;
    this->parent = parent;
}


template <class T>
Node<T>::~Node()
{
    delete parent;
    delete left;
    delete right;
}


template <class T>
void Node<T>::insert_node(const T data)
{
    if (this->data != '\0')
    {
        if (data < this->data)
        {
            if (this->get_left() == nullptr)
            {
                Node<T>* new_node = new Node<T>(data, this);
                this->set_left(new_node);
            }
            else
                this->get_left()->insert_node(data);
        }
        else if (data > this->data)
        {
            if (this->get_right() == nullptr)
            {
                Node<T>* new_node = new Node<T>(data, this);
                this->set_right(new_node);
            }
            else
                this->get_right()->insert_node(data);
        }
    }
    else
        this->set_data(data);
}


template <class T>
void Node<T>::delete_node(const T data)
{
    Node<T>* node = this->lookup(data);
    if (node != nullptr)
    {
        Node<T>* parent = node->get_parent();
        int children = node->child_count();
        if (children == 0)
        {
            if (parent != nullptr)
            {
                if (parent->get_left() == node)
                    parent->set_left(nullptr);
                else
                    parent->set_right(nullptr);
            }
            else
                this->set_data('\0');
        }
        else if (children == 1)
        {
            Node<T>* successor = node->get_left() != nullptr ? node->get_left() : node->get_right();
            if (parent != nullptr)
            {
                successor->set_parent(parent);
                if (parent->get_left() == node)
                    parent->set_left(successor);
                else
                    parent->set_right(successor);
            }
            else
            {
                this->set_data(successor->get_data());
                this->set_left(successor->get_left());
                this->set_right(successor->get_right());

                if (this->get_left() != nullptr)
                    this->get_left()->set_parent(this);
                if (this->get_right() != nullptr)
                    this->get_right()->set_parent(this);
            }
        }
        else
        {
            parent = node;
            Node<T>* successor = node->get_right();
            while (successor->get_left() != nullptr)
            {
                parent = successor;
                successor = successor->get_left();
            }

            node->set_data(successor->get_data());
            if (parent->get_left() == successor)
                parent->set_left(successor->get_right());
            else
                parent->set_right(successor->get_right());

            if (parent->get_right() != nullptr)
                parent->get_right()->set_parent(parent);
            if (parent->get_left() != nullptr)
                parent->get_left()->set_parent(parent);
        }
    }
}


template <class T>
Node<T>* Node<T>::lookup(const T data)
{
    if (data < this->get_data())
    {
        if (this->get_left() == nullptr)
            return nullptr;
        else
            return this->get_left()->lookup(data);
    }
    else if (data > this->get_data())
    {
        if (this->get_right() == nullptr)
            return nullptr;
        else
            return this->get_right()->lookup(data);
    }
    else
        return this;
}


template <class T>
void Node<T>::preorder() const
{
    std::cout << this->get_data() << " ";
    if (this->get_left() != nullptr)
        this->get_left()->preorder();
    if (this->get_right() != nullptr)
        this->get_right()->preorder();
}


template <class T>
void Node<T>::inorder() const
{
    if (this->get_left() != nullptr)
        this->get_left()->inorder();
    std::cout << this->get_data() << " ";
    if (this->get_right() != nullptr)
        this->get_right()->inorder();
}


template <class T>
void Node<T>::postorder() const
{
    if (this->get_left() != nullptr)
        this->get_left()->postorder();
    if (this->get_right() != nullptr)
        this->get_right()->postorder();
    std::cout << this->get_data() << " ";
}


template <class T>
bool Node<T>::contains(const T data) const
{
    if (data < this->get_data())
    {
        if (this->get_left() == nullptr)
            return false;
        else
            return this->get_left()->contains(data);
    }
    else if (data > this->get_data())
    {
        if (this->get_right() == nullptr)
            return false;
        else
            return this->get_right()->contains(data);
    }
    else
        return true;
}


template <class T>
int Node<T>::child_count() const
{
    int counter = 0;
    if (this->get_right() != nullptr)
        counter++;
    if (this->get_left() != nullptr)
        counter++;
    return counter;
}
