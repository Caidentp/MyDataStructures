#include "bst.h"


// Default constructor
Node::Node()
{
    this->data = '\0';
    this->parent = nullptr;
}


// Constructor
Node::Node(int data, Node* parent = nullptr)
{
    this->data = data;
    this->parent = parent;
}


// Get or set data instance variable
int Node::get_data() { return this->data; }
void Node::set_data(int new_data) { this->data = new_data; }


// Get or set parent instance variable
Node* Node::get_parent() { return this->parent; }
void Node::set_parent(Node* new_parent) { this->parent = new_parent; }


// Get or set left instance variable
Node* Node::get_left() { return this->left; }
void Node::set_left(Node* new_left) { this->left = new_left; }


// Get or set right instance variable
Node* Node::get_right() { return this->right; }
void Node::set_right(Node* new_right) { this->right = new_right; }


// Insert a node int the tree at the appropriate position
void Node::insertNode(int data)
{
    if (this->data != '\0')
    {
        if (data < this->data)
        {
            if (this->get_left() == nullptr)
            {
                Node* new_node = new Node(data, this);
                this->set_left(new_node);
            }
            else
                this->get_left()->insertNode(data);
        }
        else if (data > this->data)
        {
            if (this->get_right() == nullptr)
            {
                Node* new_node = new Node(data, this);
                this->set_right(new_node);
            }
            else
                this->get_right()->insertNode(data);
        }
    }
    else
        this->set_data(data);
}


// Remove a node from the tree if it exists
void Node::deleteNode(int data)
{
    Node* node = this->lookup(data);
    Node* parent = node->get_parent();

    if (node != nullptr)
    {
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
            Node* temp = node->get_left() != nullptr ? node->get_left() : node->get_right();
            if (parent != nullptr)
            {
                if (parent->get_left() == node)
                    parent->set_left(temp);
                else
                    parent->set_right(temp);
                temp->set_parent(parent);
            }
            else
            {
                this->set_left(temp->get_left());
                this->set_right(temp->get_right());
                this->set_data(temp->get_data());

                if (this->get_left() != nullptr)
                    this->left->set_parent(this);

                if (this->get_right() != nullptr)
                    this->right->set_parent(this);
            }
        }
        else
        {
            Node* parent = node;
            Node* successor = node->get_right();

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


// Return a node if it exists in the tree
Node* Node::lookup(int data)
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


// Check whether a node exists in the tree or not
bool Node::contains(int data)
{
    if (data < this->get_data())
    {
        if (this->get_left() == nullptr)
            return false;
        else
            return this->get_left()->lookup(data);
    }
    else if (data > this->get_data())
    {
        if (this->get_right() == nullptr)
            return false;
        else
            return this->get_right()->lookup(data);
    }
    else
        return true;
}


// Return how many children a node has
int Node::child_count()
{
    int counter = 0;
    if (this->left != nullptr)
        counter++;
    if (this->right != nullptr)
        counter++;
    return counter;
}


// Preorder traversal
void Node::preorder()
{
    std::cout << this->get_data() << " ";
    if (this->get_left() != nullptr)
        this->left->preorder();
    if (this->get_right() != nullptr)
        this->right->preorder();
}


// Inorder traversal
void Node::inorder()
{
    if (this->get_left() != nullptr)
        this->left->inorder();
    std::cout << this->get_data() << " ";
    if (this->get_right() != nullptr)
        this->right->inorder();
}


// Postorder traversal
void Node::postorder()
{
    if (this->get_left() != nullptr)
        this->left->postorder();
    if (this->get_right() != nullptr)
        this->right->postorder();
    std::cout << this->get_data() << " ";
}


// Destructor
Node::~Node()
{
    delete  left;
    delete right;
    delete parent;
}
