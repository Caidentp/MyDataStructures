using namespace linkedlist;


/// initializer_list compatibility
template <class TData, class TNode>
SinglyLinkedList<TData, TNode>::SinglyLinkedList(const std::initializer_list<TData> il) {
    for (const TData* index = il.begin(); index < il.end(); index++)
        this->append(*index);
}


/// Copy constructor
template <class TData, class TNode>
SinglyLinkedList<TData, TNode>::SinglyLinkedList(const SinglyLinkedList& list) {
    for (TNode* i = list.get_head(); i; this->append(i->data), i = i->next);
}


/// Copy assignment
template <class TData, class TNode>
SinglyLinkedList<TData, TNode>& SinglyLinkedList<TData, TNode>::operator =(const SinglyLinkedList& list) {
    this->deleteList();
    for (TNode* i = list.get_head(); i; this->append(i->data), i = i->next);
    return *this;
}


/// Move constructor
template <class TData, class TNode>
SinglyLinkedList<TData, TNode>::SinglyLinkedList(SinglyLinkedList&& list) {
    for (TNode* i = list.get_head(); i; this->append(i->data), i = i->next);
    list.deleteList();
}


/// Move assignment
template <class TData, class TNode>
SinglyLinkedList<TData, TNode>& SinglyLinkedList<TData, TNode>::operator =(SinglyLinkedList&& list) {
    this->deleteList();
    for (TNode* i = list.get_head(); i; this->append(i->data), i = i->next);
    list.deleteList();
    return *this;
}


/// Add item to beginning of a list
template <class TData, class TNode>
void SinglyLinkedList<TData, TNode>::push(const TData data) {
    TNode* new_node = new TNode(data);

    if (this->get_head() == nullptr)
        this->set_tail(new_node);
    else
        new_node->next = this->get_head();
    this->set_head(new_node);
    this->set_len(this->size()+1);
}


/// Add item to end of a list
template <class TData, class TNode>
void SinglyLinkedList<TData, TNode>::append(const TData data)
{
    TNode* new_node = new TNode(data);

    if (this->get_head() == nullptr) {
        this->set_head(new_node);
        this->set_tail(new_node);
    }
    else {
        this->get_tail()->next = new_node;
        this->set_tail(new_node);
    }
    this->set_len(this->size()+1);
}


/// Insert item into a list by index
template <class TData, class TNode>
void SinglyLinkedList<TData, TNode>::insert(const TData data, const int index) {

    if (this->get_head() == nullptr || this->size() <= index)
        throw IndexError();

    if (index == 0)
        this->push(data);

    else {
        TNode* new_node = new TNode(data);
        TNode* temp = this->get_head();
        for (int i = 1; i < index; i++, temp = temp->next);

        new_node->next = temp->next;
        temp->next = new_node;
        this->set_len(this->size()+1);
    }
}


/// Delete item from list by index
template <class TData, class TNode>
void SinglyLinkedList<TData, TNode>::remove(const int index) {

    if (this->get_head() == nullptr || this->size() <= index)
        throw IndexError();
    TNode *temp = this->get_head();

    if (index == 0) {
        if (this->get_head() == this->get_tail()) {
            TNode *tail_temp = this->get_tail();
            this->set_head(nullptr);
            this->set_tail(nullptr);
            delete tail_temp;
        }
        else {
            this->set_head(this->get_head()->next);
        }
    }
    else {
        TNode* previous;
        for (int i = 0; i < index && temp != this->get_tail(); i++) {
            previous = temp;
            temp = temp->next;
        }
        previous->next = temp->next;
        if (temp == this->get_tail())
             this->set_tail(previous);
    }
    delete temp;
    this->set_len(this->size()-1);
}


/// Print char representation of list with std::cout
std::ostream& operator << (std::ostream& os, 
                           SinglyLinkedList<>& linked_list) {
    os << "<SinglyLinkedList object at " << &linked_list
       << "; length: " << linked_list.size() << ">";
    return os;
}
