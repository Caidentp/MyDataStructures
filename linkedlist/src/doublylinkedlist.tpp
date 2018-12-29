using namespace linkedlist;


/// initializer_list compatibility
template <class TData, class TNode>
DoublyLinkedList<TData, TNode>::DoublyLinkedList(const std::initializer_list<TData> il) {

    for (const TData* index = il.begin(); index < il.end(); index++)
        this->append(*index);
}


/// Copy constructor
template <class TData, class TNode>
DoublyLinkedList<TData, TNode>::DoublyLinkedList(const DoublyLinkedList& list) {
    for (TNode* i = list.get_head(); i; this->append(i->data), i = i->next);
}


/// Copy assignment
template <class TData, class TNode>
DoublyLinkedList<TData, TNode>& DoublyLinkedList<TData, TNode>::operator =(const DoublyLinkedList& list) {
    this->deleteList();
    for (TNode* i = list.get_head(); i; this->append(i->data), i = i->next);
    return *this;
}


/// Move constructor
template <class TData, class TNode>
DoublyLinkedList<TData, TNode>::DoublyLinkedList(DoublyLinkedList&& list) {
    for (TNode* i = list.get_head(); i; this->append(i->data), i = i->next);
    list.deleteList();
}


/// Move assignment
template <class TData, class TNode>
DoublyLinkedList<TData, TNode>& DoublyLinkedList<TData, TNode>::operator =(DoublyLinkedList&& list) {
    this->deleteList();
    for (TNode* i = list.get_head(); i; this->append(i->data), i = i->next);
    list.deleteList();
    return *this;
}


/// Add item to beginning of a list
template <class TData, class TNode>
void DoublyLinkedList<TData, TNode>::push(const TData data) {
    TNode* new_node = new TNode(data);

    if (this->get_head() == nullptr) {
        this->set_head(new_node);
        this->set_tail(new_node);
    }
    else {
        new_node->next = this->get_head();
        new_node->next->previous = new_node;
        this->set_head(new_node);
    }
    this->set_len(this->size()+1);
}


/// Add item to end of a list
template <class TData, class TNode>
void DoublyLinkedList<TData, TNode>::append(const TData data)
{
    TNode* new_node = new TNode(data);

    if (this->get_head() == nullptr) {
        this->set_head(new_node);
        this->set_tail(new_node);
    }
    else {
        new_node->previous = this->get_tail();
        this->get_tail()->next = new_node;
        this->set_tail(new_node);
    }
    this->set_len(this->size()+1);
}


/// Insert item into a list by index
template <class TData, class TNode>
void DoublyLinkedList<TData, TNode>::insert(const TData data, const int index) {

    if (this->get_head() == nullptr || this->size() <= index)
        throw IndexError();

    if (index == 0)
        this->push(data);

    else {
        TNode* new_node = new TNode(data);
        TNode* temp = this->get_head();
        for (int i = 1; i < index; i++, temp = temp->next);

        new_node->next = temp->next;
        temp->next->previous = new_node;
        new_node->previous = temp;
        temp->next = new_node;
        this->set_len(this->size()+1);
    }
}


/// Delete item from list by index
template <class TData, class TNode>
void DoublyLinkedList<TData, TNode>::remove(const int index) {

    if (this->get_head() == nullptr || this->size() <= index)
        throw IndexError();
    TNode* temp = this->get_head();

    if (index == 0) {
        if (this->get_head() == this->get_tail()) {
            TNode *tail_temp = this->get_tail();
            this->set_head(nullptr);
            this->set_tail(nullptr);
            delete tail_temp;
        }
        else {
            this->set_head(this->get_head()->next);
            this->get_head()->previous = nullptr;
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
        else
            previous->next->previous = previous;
    }
    delete temp;
    this->set_len(this->size()-1);
}


/// Print char representation of list with std::cout
std::ostream& operator << (std::ostream& os,
                           DoublyLinkedList<>& linked_list) {
    os << "<DoublyLinkedList object at " << &linked_list
       << "; length: " << linked_list.size() << ">";
    return os;
}
