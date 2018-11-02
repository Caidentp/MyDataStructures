#include "array_list.h"


/// ====================== PROTECTED ======================

/// expand
template <class T>
void ArrayList<T>::expand() {
    T* new_list = new T[max_size*2]();
    max_size *= 2;

    for (int i = 0; i < length; i++)
        new_list[i] = array_list[i];
    delete array_list;
    array_list = new_list;
}

/// ====================== PROTECTED ======================


/// ======================= PUBLIC ========================

/// Default ctor
template <class T>
ArrayList<T>::ArrayList()
    : max_size(10)
{
    T *new_list = new T[max_size]();
    array_list = new_list;
}

/// ctor
template <class T>
ArrayList<T>::ArrayList(int max_size)
    : max_size(max_size)
{
    T *new_list = new T[max_size]();
    array_list = new_list;
}


/// Copy ctor
template <class T>
ArrayList<T>::ArrayList(ArrayList& rhs) {
    T* new_list = new T[rhs.size()]();

    for (int i = 0; i < rhs.size(); i++)
        new_list[i] = rhs[i];

    this->array_list = new_list;
    this->max_size = rhs.size();
    this->length = rhs.size();
}


/// Move ctor
template <class T>
ArrayList<T>::ArrayList(ArrayList&& rhs)
    : length(rhs.length)
    , max_size(rhs.max_size)
    , array_list(rhs.array_list)
{
    rhs.array_list = nullptr;
    rhs.length = NULL;
    rhs.max_size = NULL;
}


/// Move assignment operator
template <class T>
ArrayList<T>& ArrayList<T>::operator = (ArrayList&& rhs) {
    if (this == &rhs)
        return *this;

    delete [] array_list;

    this->length = rhs.length;
    this->max_size = rhs.max_size;
    this->array_list = rhs.array_list;

    rhs.length = NULL;
    rhs.max_size = NULL;
    rhs.array_list = NULL;

    return *this;
}


/// Get item
template <class T>
T& ArrayList<T>::operator [] (const int index) {
    return array_list[index];
}


/// Assignment operator
template <class T>
ArrayList<T>& ArrayList<T>::operator = (const ArrayList& rhs) {
    if (this == &rhs)
        return *this;

    this->array_list = rhs.array_list;
    this->length = rhs.length;
    this->max_size = rhs.max_size;
    delete &rhs;
}


/// append
template <class T>
void ArrayList<T>::append(const T data) {
    if (length == max_size)
        expand();
    array_list[length] = data;
    length++;
}


/// pop
template <class T>
T ArrayList<T>::pop() {
    if (length != 0) {
        length--;
        T data = array_list[length];
        array_list[length] = 0;
        return data;
    }
    return NULL;
}

/// ======================= PUBLIC ========================
