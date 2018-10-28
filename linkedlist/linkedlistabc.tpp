/// Default constructor
template <class T1, class T2>
LinkedListABC<T1, T2>::LinkedListABC() { }


/// Constructor
template <class T1, class T2>
LinkedListABC<T1, T2>::LinkedListABC(const T1 data) {
    T2* new_node = new T2(data);
    this->set_head(new_node);
    this->set_tail(new_node);
    this->set_len(1);
}


/// Returns true if list contains data passed to the function
template <class T1, class T2>
bool LinkedListABC<T1, T2>::contains(const T1 data) {

    // If list is not empty
    if (this->get_head() != nullptr) {
        T2* temp = this->get_head();

        do {
            if (temp->get_data() == data)
                return true;
            temp = temp->get_next();
        }
        while (temp != nullptr && temp != this->get_head());
        return false;
    }
    throw IndexError();
}


/// Finds index of data
template <class T1, class T2>
int LinkedListABC<T1, T2>::find_index_of(const T1 data) {

    if (this->get_head() != nullptr) {
        int index = 0;
        T2* temp = this->get_head();

        for (; index < this->length(); index++, temp = temp->get_next()) {
            if (temp->get_data() == data)
                return index;
        }
        return -1;
    }
    throw IndexError();
}


/// Prints list in ascending order
template <class T1, class T2>
void LinkedListABC<T1, T2>::print() const {

    if (this->get_head() != nullptr) {
        T2* temp = this->get_head();

        do {
            std::cout << temp->get_data() << " ";
            temp = temp->get_next();
        }
        while (temp != nullptr && temp != this->get_head());
    }
    else
        throw IndexError();
}
