using namespace linkedlist;


/// Constructor
template <class T1, class T2>
LinkedListABC<T1, T2>::LinkedListABC(const T1 data)
    : len(1)
{
    T2* new_node = new T2(data);
    this->head = new_node;
    this->tail = new_node;
}


/// Destroy a linked lsit
template <class T1, class T2>
void LinkedListABC<T1, T2>::deleteList() {
    // If list is empty
    if (head == nullptr || head == tail) {
        delete head;
        delete tail;
    }
    else {
        T2 *curr = head;
        // Need do while loop so circular linked lists are also properly deleted
        do {
            T2 *temp = curr;
            curr = curr->next;
            delete temp;
        }
        while (curr != nullptr && curr != head);
    }
    head = nullptr;
    tail = nullptr;
    len = 0;
}


/// Get item operator compatibility
template <class T1, class T2>
inline T1& LinkedListABC<T1, T2>::operator [] (const int index) {
    if (head == nullptr || len <= index)
        throw IndexError();
    T2* t = head;
    for (int i = 0; i < index; i++, t = t->next);
        return t->data;
}


/// Returns true if list contains data passed to the function
template <class T1, class T2>
bool LinkedListABC<T1, T2>::contains(const T1 data) const {
    if (head != nullptr) {
        T2* temp = head;
        // Need do while loop for circular linked lists
        do {
            if (temp->data == data)
                return true;
            temp = temp->next;
        }
        while (temp != nullptr && temp != head);
    }
    return false;
}


/// Finds index of data
template <class T1, class T2>
int LinkedListABC<T1, T2>::index(const T1 data) const {

    if (head != nullptr) {
        T2* t = head;
        for (int i = 0; i < len; i++, t = t->next)
            if (t->data == data)
                return i;
    }
    return -1;
}


/// Prints list in ascending order
template <class T1, class T2>
void LinkedListABC<T1, T2>::print() const {

    if (head != nullptr) {
        T2* temp = head;
        // Need do while loop for curcular linked lists
        do {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        while (temp != nullptr && temp != head);
    }
}
