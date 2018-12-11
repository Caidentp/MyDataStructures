using namespace linkedlist;


/// Constructor
template <class T1, class T2>
LinkedListABC<T1, T2>::LinkedListABC(const T1 data)
    : len(1)
{
    T2* new_node = new T2(data);
    this->set_head(new_node);
    this->set_tail(new_node);
}


/// Destructor
template <class T1, class T2>
LinkedListABC<T1, T2>::~LinkedListABC() {
    // If list is empty
    if (head == nullptr) {
        delete head;
        delete tail;
    }
    else {
        T2 *curr = head;
        while (curr != nullptr) {
            T2 *temp = curr;
            curr = curr->next;
            delete temp;
        }
    }
}


/// Get item operator compatibility
template <class T1, class T2>
T1& LinkedListABC<T1, T2>::operator [] (const int index) {
    if (this->get_head() == nullptr || this->size() <= index)
        throw IndexError();
    T2* t = this->get_head();
    for (int i = 0; i < index; i++, t = t->next);
        return t->data;
}


/// Returns true if list contains data passed to the function
template <class T1, class T2>
bool LinkedListABC<T1, T2>::contains(const T1 data) const {

    if (this->get_head() != nullptr) {
        T2* temp = this->get_head();

        do {
            if (temp->data == data)
                return true;
            temp = temp->next;
        }
        while (temp != nullptr && temp != this->get_head());
    }
    return false;
}


/// Finds index of data
template <class T1, class T2>
int LinkedListABC<T1, T2>::index(const T1 data) {

    if (this->get_head() != nullptr) {
        T2* t = this->get_head();
        for (int i = 0; i < this->size(); i++, t = t->next) {
            if (t->data == data)
                return i;
        }
    }
    return -1;
}


/// Prints list in ascending order
template <class T1, class T2>
void LinkedListABC<T1, T2>::print() const {

    if (this->get_head() != nullptr) {
        T2* temp = this->get_head();

        do {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        while (temp != nullptr && temp != this->get_head());
    }
}
