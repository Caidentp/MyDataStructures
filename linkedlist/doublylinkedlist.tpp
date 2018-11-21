using namespace list;


/// Default constructor
template <class T1, class T2>
DoublyLinkedList<T1, T2>::DoublyLinkedList()
    : LinkedListABC<T1, T2>()
{ }


/// Constructor
template <class T1, class T2>
DoublyLinkedList<T1, T2>::DoublyLinkedList(const T1 data)
    : LinkedListABC<T1, T2>(data)
{ }


/// initializer_list compatibility
template <class T1, class T2>
DoublyLinkedList<T1, T2>::DoublyLinkedList(const std::initializer_list<T1> il) {

    for (const T1* index = il.begin(); index < il.end(); index++)
        this->append(*index);
}


/// Add item to beginning of a list
template <class T1, class T2>
void DoublyLinkedList<T1, T2>::push(const T1 data) {
    T2* new_node = new T2(data);

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
template <class T1, class T2>
void DoublyLinkedList<T1, T2>::append(const T1 data)
{
    T2* new_node = new T2(data);

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
template <class T1, class T2>
void DoublyLinkedList<T1, T2>::insert(const T1 data, const int index) {

    if (this->get_head() == nullptr || this->size() <= index)
        throw IndexError();

    if (index == 0)
        this->push(data);

    else {
        T2* new_node = new T2(data);
        T2* temp = this->get_head();
        for (int i = 1; i < index; i++, temp = temp->next);

        new_node->next = temp->next;
        temp->next->previous = new_node;
        new_node->previous = temp;
        temp->next = new_node;
        this->set_len(this->size()+1);
    }
}


/// Delete item from list by index
template <class T1, class T2>
void DoublyLinkedList<T1, T2>::delete_node(const int index) {

    if (this->get_head() == nullptr || this->size() <= index)
        throw IndexError();

    if (index == 0) {

        if (this->get_head() == this->get_tail()) {
            this->set_head(nullptr);
            this->set_tail(nullptr);
        }
        else
            this->set_head(this->get_head()->next);
            this->get_head()->previous = nullptr;
    }
    else {
        T2* temp = this->get_head();
        T2* previous;

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
    this->set_len(this->size()-1);
}


/// Print char representation of list with std::cout
std::ostream& operator << (std::ostream& os, DoublyLinkedList<>& linked_list) {
    os << "<DoublyLinkedList object at " << &linked_list
       << "; length: " << linked_list.size() << ">";
    return os;
}
