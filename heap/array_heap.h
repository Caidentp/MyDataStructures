#ifndef ARRAY_HEAP_H
#define ARRAY_HEAP_H

#include "../arraylist/array_list.h"

namespace heap {
/** 
 *  @brief  Array heap class to implement methods and variables common to both
 *          min and max heaps.
 *  @var  length  Keep track of the last index of the heap.
 *  @var  heap  ArrayHeap object used for array representation of a heap.
 *  
 *  @tparam  T  Type of data heap is to be.
 */
template <class T = int>
class ArrayHeapABC {
    private:
        int length;

    protected:
        arraylist::ArrayList<T> heap;

        /** 
          *  @brief  Move data to appropriate index in heap after insertion.
          */
        virtual void perc_up() = 0;

        /** 
          *  @brief  Move data to appropriate index in heap after deletion.
          */
        virtual void perc_down() = 0;

        /**
          *  @brief  Internal method used to set the length of the heap.
          *  @param  length  New length of heap.
          */
        void set_length(const int length) { this->length = length; }

    public:
        ArrayHeapABC();
        virtual ~ArrayHeapABC() { delete &heap; }
        T operator [](const int index) { return this->heap[index]; }
        int size() const { return this->length; }

        /** 
          *  @brief  Append data to list, call perc_up to move data to appropriate
          *          position in the heap, increment length.
          *  @param data : Data to insert into the heap.
          */
        void insert(const T data);

        /** 
          *  @brief  Get the data at the head of the heap, swap the head of the heap
          *          with the tail, call perc_down to move head to appropriate position.
          *  @return Data that resided at the head of the heap.
          */
        T pop();

        /** 
          *  @brief  Print the contents of the heap.
          */
        void print();
};


/** 
 *  @brief  Implementation of min heap using a dynamic array.
 *
 *  @tparam  T  Type of data heap is to be.
 */
template <class T = int>
class ArrayMinHeap : public ArrayHeapABC<T> {
    protected:
        void perc_up();
        void perc_down();

    public:
        ArrayMinHeap();
        virtual ~ArrayMinHeap() { };

        /**
          *  @brief  Find the minimum child node of an index.
          *  @param  index  Index to find the minimum child of.
          *  @return The minimum child of the parent index.
          */
        int min_child(int index);
};


/** 
 *  @brief  Implementation of max heap using a dynamic array.
 *
 *  @tparam  T  Type of data heap is to be.
 */
template <class T = int>
class ArrayMaxHeap : public ArrayHeapABC<T> {
    protected:
        void perc_up();
        void perc_down();

    public:
        ArrayMaxHeap();
        virtual ~ArrayMaxHeap() { };

        /** 
          *  @brief  Find the maximum child node of an index.
          *  @param  index  Index to find the maximum child of.
          *  @return The maximum child of the parent index.
          */
        int max_child(int index);
};


/// ====================== ARRAY HEAP ABC ======================

/// Default ctor
template <class T>
ArrayHeapABC<T>::ArrayHeapABC()
    : length(0)
{
    this->heap.append(0);
}


/// insert
template <class T>
void ArrayHeapABC<T>::insert(const T data) {
    heap.append(data);
    this->length++;
    this->perc_up();
}


/// pop
template <class T>
T ArrayHeapABC<T>::pop() {
    if (length == 0)
        return NULL;

    T data = this->heap[1];
    this->heap[1] = this->heap[length];
    this->perc_down();
    this->heap.pop();
    this->length--;
    return data;
}


/// print
template <class T>
void ArrayHeapABC<T>::print() {
    for (int i = 1; i < length+1; i++)
        std::cout << heap[i] << " ";
}

/// ====================== ARRAY HEAP ABC ======================



/// ====================== ARRAY MIN HEAP ======================

/// Default ctor
template <class T>
ArrayMinHeap<T>::ArrayMinHeap()
    : ArrayHeapABC<T>()
{ }


/// min child
template <class T>
int ArrayMinHeap<T>::min_child(int index) {
    if (index*2+1 > this->size())
        return index*2;
    int smallest_child_index = this->heap[index*2] < this->heap[index*2+1] ? index*2 : index*2+1;
    return smallest_child_index;
}


/// perc up
template <class T>
void ArrayMinHeap<T>::perc_up() {
    int parent_index = this->size() / 2;
    int child_index = this->size();

    while (parent_index > 0 && this->heap[child_index] < this->heap[parent_index]) {
        T temp = this->heap[child_index];
        this->heap[child_index] = this->heap[parent_index];
        this->heap[parent_index] = temp;
        child_index = parent_index;
        parent_index /= 2;
    }
}


/// perc down
template <class T>
void ArrayMinHeap<T>::perc_down() {
    int parent_index = 1;
    int child_index = min_child(parent_index);

    while (child_index <= this->size() && this->heap[parent_index] > this->heap[child_index]) {
        T temp = this->heap[parent_index];
        this->heap[parent_index] = this->heap[child_index];
        this->heap[child_index] = temp;

        parent_index = child_index;
        child_index = min_child(parent_index);
    }
}

/// ====================== ARRAY MIN HEAP ======================



/// ====================== ARRAY MAX HEAP ======================

/// Default ctor
template <class T>
ArrayMaxHeap<T>::ArrayMaxHeap()
    : ArrayHeapABC<T>()
{ }


/// max child
template <class T>
int ArrayMaxHeap<T>::max_child(int index) {
    if (index*2+1 > this->size())
        return index*2;
    int largest_child_index = this->heap[index*2] > this->heap[index*2+1] ? index*2 : index*2+1;
    return largest_child_index;
}


/// perc up
template <class T>
void ArrayMaxHeap<T>::perc_up() {
    int parent_index = this->size() / 2;
    int child_index = this->size();

    while (parent_index > 0 && this->heap[child_index] > this->heap[parent_index]) {
        T temp = this->heap[child_index];
        this->heap[child_index] = this->heap[parent_index];
        this->heap[parent_index] = temp;
        child_index = parent_index;
        parent_index /= 2;
    }
}


/// perc down
template <class T>
void ArrayMaxHeap<T>::perc_down() {
    int parent_index = 1;
    int child_index = max_child(parent_index);

    while (child_index <= this->size() && this->heap[parent_index] < this->heap[child_index]) {
        T temp = this->heap[parent_index];
        this->heap[parent_index] = this->heap[child_index];
        this->heap[child_index] = temp;

        parent_index = child_index;
        child_index = max_child(parent_index);
    }
}

/// ====================== ARRAY MAX HEAP ======================

}  /// namespace heap

#endif // ARRAY_HEAP_H
