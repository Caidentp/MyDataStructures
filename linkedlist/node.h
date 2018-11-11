#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED


namespace node {


/** Defines singly linked list node.
 *
 * template class t1: Data instance variable type
 *      - Defaults to int.
 */
template <class T1 = int>
class SNode
{
    public:
        T1 data;
        SNode<T1>* next = nullptr;

    public:
        SNode(T1 data = '\0') { this->data = data; }
        friend std::ostream& operator << (std::ostream& os, SNode<>* node);
};


/// Overloading binary left shift operator for SNode.
std::ostream& operator << (std::ostream& os, SNode<>* node) {
    os << node->data;
    return os;
}



/** Defines doubly linked list node.
 *
 * template class t1: Data instance variable type
 *      - Defaults to int.
 */
template <class T1 = int>
class DNode
{
    public:
        T1 data;
        DNode* next = nullptr;
        DNode* previous = nullptr;

    public:
        DNode(T1 data = '\0') { this->data = data; }
        friend std::ostream& operator << (std::ostream& os, DNode<>* node);
};


/// Overloading binary left shift operator for DNode.
std::ostream& operator << (std::ostream& os, DNode<>* node) {
    os << node->data;
    return os;
}



/** Defines circular linked list node.
 *
 * template class t1: Data instance variable type
 *      - Defaults to int.
 */
template <class T1 = int>
class CNode
{
    public:
        T1 data;
        CNode* next = this;

    public:
        CNode(T1 data = '\0') { this->data = data; }
        friend std::ostream& operator << (std::ostream& os, CNode<>* node);

};


/// Overloading binary left shift operator for CNode.
std::ostream& operator << (std::ostream& os, CNode<>* node) {
    os << node->data;
    return os;
}


} /// namespace node


#endif // NODE_H_INCLUDED
