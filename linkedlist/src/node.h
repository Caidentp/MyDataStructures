#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

namespace node {

/** 
 *  @brief  Defines singly linked list node.
 *  @var  data  Data to be held at this node.
 *  @var  next  Pointer to next node in the list.
 *
 *  @tparam  T1  Data instance variable type
 *
 *  This class is meant to be used as a T2 template type
 *  for the SinglyLinkedList class.
 */
template <class T1 = int>
class SNode
{
    public:
        T1 data;
        SNode<T1>* next{nullptr};

    public:
       /**
        *  @param  data  Data to initialize node with.
        */
        SNode(T1 data = '\0') : data(data) { }

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
 *  @tparam  T1  Data instance variable type
 *
 *  This class is meant to be used as a T2 template type
 *  for the DoublyLinkedList class.
 */
template <class T1 = int>
class DNode
{
    public:
        T1 data;
        DNode* next{nullptr};
        DNode* previous{nullptr};

    public:
       /**
        *  @param  data  Data to initialize node with.
        */
        DNode(T1 data = '\0') : data(data) { }

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
 *  @tparam  T1  Data instance variable type
 *
 *  This class is meant to be used as a T2 template type
 *  for the CircularLinkedList class.
 */
template <class T1 = int>
class CNode
{
    public:
        T1 data;
        CNode* next{this};

    public:
       /**
        *  @param  data  Data to initialize node with.
        */
        CNode(T1 data = '\0') : data(data) { }

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
