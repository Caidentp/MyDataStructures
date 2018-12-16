#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <iostream>
#include <exception>

namespace arraylist {

/** Class to implement dynamic array that can grow on demand.
 *
 * template class T : Data type that list will hold.
 *      - Defaults to int.
 *
 * @var length : Number of non-null list members.
 * @var max_size : Total number of members list can hold at a given time.
 * @var array_list : Pointer array that holds data members.
 */
template <class T = int>
class ArrayList final
{
    #ifndef TESTING
    private:
    #endif

    #ifdef TESTING
    public:
    #endif
        int length{0};
        int max_size;
        T *array_list;

    protected:
        /** Doubles size of array_list.
         */
        void expand();

    public:
        /** Default constructor creates array of 10 members.
         */ 
        ArrayList(int max_size = 10) : max_size(max_size) { array_list = new T[max_size](); }
        ~ArrayList() { delete [] array_list; }

        /** Copy constructor.
         * @param rhs : Instance of ArrayList to copy.
         */
        ArrayList(ArrayList& rhs);

        /** Move constructor.
         * @param rhs : Instance of ArrayList to move.
         */
        ArrayList(ArrayList&& rhs);

        /** Move assignment operator.
         * @param rhs : Instance of ArrayList to move.
         * @return ArrayList at new location.
         */
        ArrayList& operator = (ArrayList&& rhs);

        /** Operator overload get item.
         * @param index : Position of data member to retrieve.
         * @return Position of index argument passed in array_list member variable.
         */
        T& operator [] (const int index);

        /** Assignment operator to create deep copy of an instance of ArrayList.
         * @param rhs : ArrayList instance to create a copy of.
         * @return Deep copy of rhs argument.
         */
        ArrayList& operator = (const ArrayList& rhs);

        /** Total number of non-null members in array_list.
         * @return : Running total of members in array_list. 
         */
        int size() const { return length; }

        /** Add a data member to the end of array_list.
         * If the length of the list is equal to the max_size then
         * this method will call expand() to double the size of array_list.
         * @param data : Data member to add to end of array_list.
         */
        void append(const T data);

        /** Remove the last member of array_list and return it.
         * @return Data that resides at last element of array_list.
         */
        T pop();
}; /// ArrayList


struct IndexError : public std::exception {
    const char* what() const throw() {
        return "List index out of range.";
    }
};


struct EmptyList : public std::exception {
    const char* what() const throw() {
        return "List is empty.";
    }
};


/// ====================== PROTECTED ======================

/// expand
template <class T>
void ArrayList<T>::expand() {
    T* new_list = new T[max_size*2]();
    max_size *= 2;

    for (int i = 0; i < length; i++)
        new_list[i] = array_list[i];
    delete [] array_list;
    array_list = new_list;
}

/// ====================== PROTECTED ======================


/// ======================= PUBLIC ========================


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
    rhs.length = 0;
    rhs.max_size = 0;
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

    rhs.length = 0;
    rhs.max_size = 0;
    rhs.array_list = nullptr;

    return *this;
}


/// Get item
template <class T>
T& ArrayList<T>::operator [] (const int index) {
    if (index >= length)
        throw IndexError();
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
    if (length == 0)
        throw EmptyList();
    length--;
    T data = array_list[length];
    array_list[length] = 0;
    return data;
}

/// ======================= PUBLIC ========================

}  /// namespace arraylist

typedef arraylist::ArrayList<int> ArrayList;

#endif // ARRAY_LIST_H
