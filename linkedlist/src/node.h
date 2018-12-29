#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

namespace node {

/** 
 *  @brief  Defines singly linked list node.
 *  @var  data  Data to be held at this node.
 *  @var  next  Pointer to next node in the list.
 *
 *  @tparam  TData  Data instance variable type
 *
 *  This class is meant to be used as a TNode template type
 *  for the SinglyLinkedList class.
 */
template <class TData = int>
class SNode
{
    public:
        TData data;
        SNode<TData>* next{nullptr};

    public:
       /**
        *  @param  data  Data to initialize node with.
        */
        SNode(TData data = '\0') : data(data) { }

       /**
        *  @brief  Print a char representation of singly linked list node.
        *  @param  os  std::cout.
        *  @param  node  Linked list node to print representation of.
        */
        friend std::ostream& operator << (std::ostream& os, SNode<>* node) {
            os << node->data;
            return os;
        }
};


/** 
 *  @brief  Defines doubly linked list node.
 *  @var  data  Data to be held at this node.
 *  @var  next  Pointer to next node in the list.
 *  @var  previous  Pointer to the previous node in the list.
 *
 *  @tparam  TData  Data instance variable type
 *
 *  This class is meant to be used as a TNode template type
 *  for the DoublyLinkedList class.
 */
template <class TData = int>
class DNode
{
    public:
        TData data;
        DNode* next{nullptr};
        DNode* previous{nullptr};

    public:
       /**
        *  @param  data  Data to initialize node with.
        */
        DNode(TData data = '\0') : data(data) { }

       /**
        *  @brief  Print a char representation of doubly linked list node.
        *  @param  os  std::cout.
        *  @param  node  Linked list node to print representation of.
        */
        friend std::ostream& operator << (std::ostream& os, DNode<>* node) {
            os << node->data;
            return os;
        }
};


/** 
 *  @brief  Defines circular linked list node.
 *  @var  data  Data to be held at this node.
 *  @var  next  Pointer to next node in the list.
 *
 *  @tparam  TData  Data instance variable type
 *
 *  This class is meant to be used as a TNode template type
 *  for the CircularLinkedList class.
 */
template <class TData = int>
class CNode
{
    public:
        TData data;
        CNode* next{this};

    public:
       /**
        *  @param  data  Data to initialize node with.
        */
        CNode(TData data = '\0') : data(data) { }

       /**
        *  @brief  Print a char representation of circular linked list node.
        *  @param  os  std::cout.
        *  @param  node  Linked list node to print representation of.
        */
        friend std::ostream& operator << (std::ostream& os, CNode<>* node) {
            os << node->data;
            return os;
        }

};

} /// namespace node

#endif // NODE_H_INCLUDED
