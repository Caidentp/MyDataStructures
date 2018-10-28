#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED



/** Defines singly linked list node.
 *
 * template class t1: Data instance variable type
 *      - Defaults to int.
 */
template <class T1 = int>
class SNode
{
    private:
        /// Data instance variable.
        T1 data;
        
        /// Next instance variable
        SNode<T1>* next = nullptr;

    public:
        SNode(T1 data = '\0') { this->data = data; }

        /// Overloading assignment operator.
        SNode<T1>& operator = (const SNode& other);
        
        /// Overload binary left shift operator for printing string representation of node.
        friend std::ostream& operator << (std::ostream& os, SNode<>* node);

        SNode* get_next() const { return this->next; }
        void set_next(SNode* next) { this->next = next; }
        T1 get_data() const { return this->data; }
        void set_data(T1 data) { this->data = data; }
};



/// Overloading assignment operator for SNode.
template <class T1>
SNode<T1>& SNode<T1>::operator = (const SNode& other)
{
    if (this == &other)
        return *this;

    this->set_next(other.get_next());
    this->set_data(other.get_data);
    return *this;
}


/// Overloading binary left shift operator for SNode.
std::ostream& operator << (std::ostream& os, SNode<>* node) {
    os << node->get_data();
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
    private:
        /// Data instance variable.
        T1 data;
        
        /// Next instance variable.
        DNode* next = nullptr;
        
        /// Previous instance variable.
        DNode* previous = nullptr;

    public:
        DNode(T1 data = '\0') { this->data = data; }
        DNode<T1>& operator = (const DNode& other);
        
        /// Overloading assignment operator.
        DNode<T1>& operator = (const DNode& other);
        
        /// Overload binary left shift operator for printing string representation of node.
        friend std::ostream& operator << (std::ostream& os, DNode<>* node);

        DNode* get_next() const { return this->next; }
        void set_next(DNode* next) { this->next = next; }
        DNode* get_previous() const { return this->previous; }
        void set_previous(DNode* previous) { this->previous = previous; }
        T1 get_data() const { return this->data; }
        void set_data(T1 data) { this->data = data; }
};



/// Overloading assignment operator for DNode.
template <class T1>
DNode<T1>& DNode<T1>::operator = (const DNode& other)
{
    if (this == &other)
        return *this;

    this->set_next(other.get_next());
    this->set_previous(other.get_previous());
    this->set_data(other.get_data());
}


/// Overloading binary left shift operator for DNode.
std::ostream& operator << (std::ostream& os, DNode<>* node) {
    os << node->get_data();
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
    private:
        /// Data instance variable.
        T1 data;
        
        /// Next instance variable.
        CNode* next = this;

    public:
        CNode(T1 data = '\0') { this->data = data; }
        CNode<T1>& operator = (const CNode& other);
        
        /// Overloading assignment operator.
        CNode<T1>& operator = (const CNode& other);
        
        /// Overload binary left shift operator for printing string representation of node.
        friend std::ostream& operator << (std::ostream& os, CNode<>* node);

        CNode* get_next() const { return this->next; }
        void set_next(CNode* next) { this->next = next; }
        T1 get_data() const { return this->data; }
        void set_data(T1 data) { this->data = data; }
};



/// Overloading assignment operator for CNode.
template <class T1>
CNode<T1>& CNode<T1>::operator = (const CNode& other)
{
    if (this == &other)
        return *this;

    this->set_next(other.get_next());
    this->set_data(other.get_data);
    return *this;
}


/// Overloading binary left shift operator for CNode.
std::ostream& operator << (std::ostream& os, CNode<>* node) {
    os << node->get_data();
    return os;
}


#endif // NODE_H_INCLUDED
