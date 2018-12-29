using namespace linkedlist;


/// Constructor
template <class TData, class TNode>
LinkedListABC<TData, TNode>::LinkedListABC(const TData data)
    : len(1)
{
    TNode* new_node = new TNode(data);
    this->head = new_node;
    this->tail = new_node;
}


/// Destroy a linked lsit
template <class TData, class TNode>
void LinkedListABC<TData, TNode>::deleteList() {
    // If list is empty
    if (head == nullptr || head == tail) {
        delete head;
        delete tail;
    }
    else {
        TNode *curr = head;
        // Need do while loop so circular linked lists are also properly deleted
        do {
            TNode *temp = curr;
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
template <class TData, class TNode>
inline TData& LinkedListABC<TData, TNode>::operator [] (const int index) {
    if (head == nullptr || len <= index)
        throw IndexError();
    TNode* t = head;
    for (int i = 0; i < index; i++, t = t->next);
        return t->data;
}


/// Returns true if list contains data passed to the function
template <class TData, class TNode>
bool LinkedListABC<TData, TNode>::contains(const TData data) const {
    if (head != nullptr) {
        TNode* temp = head;
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
template <class TData, class TNode>
int LinkedListABC<TData, TNode>::index(const TData data) const {

    if (head != nullptr) {
        TNode* t = head;
        for (int i = 0; i < len; i++, t = t->next)
            if (t->data == data)
                return i;
    }
    return -1;
}


/// Prints list in ascending order
template <class TData, class TNode>
void LinkedListABC<TData, TNode>::print() const {

    if (head != nullptr) {
        TNode* temp = head;
        // Need do while loop for curcular linked lists
        do {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        while (temp != nullptr && temp != head);
    }
}
