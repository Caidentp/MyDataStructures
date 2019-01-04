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

#ifndef TESTING
    protected:
#endif
#ifdef TESTING
    public:
#endif
        arraylist::ArrayList<T> heap;

        /**
          *  @brief  Move data to appropriate index in heap after insertion.
          */
        virtual void percUp() = 0;

        /**
          *  @brief  Move data to appropriate index in heap after deletion.
          */
        virtual void percDown() = 0;

        /**
          *  @brief  Internal method used to set the length of the heap.
          *  @param  length  New length of heap.
          */
        void setLength(const int length) { this->length = length; }

    public:
        ArrayHeapABC() : length(0) { this->heap.append(0); }
        virtual ~ArrayHeapABC() { heap.deleteList(); }
        T operator [](const int index) { return this->heap[index]; }
        int size() const { return this->length; }

        /**
          *  @brief  Append data to list, call percUp to move data to appropriate
          *          position in the heap, increment length.
          *  @param data : Data to insert into the heap.
          */
        void insert(const T data);

        /**
          *  @brief  Get the data at the head of the heap, swap the head of the heap
          *          with the tail, call percDown to move head to appropriate position.
          *  @return Data that resided at the head of the heap.
          */
        T pop();

        /**
          *  @brief  Print the contents of the heap.
          */
        void print() const;
};


/**
 *  @brief  Implementation of min heap using a dynamic array.
 *  @tparam  T  Type of data heap is to be.
 */
template <class T = int>
class ArrayMinHeap : public ArrayHeapABC<T> {
    protected:
        void percUp();
        void percDown();

    public:
        ArrayMinHeap() : ArrayHeapABC() { }
        virtual ~ArrayMinHeap() { };

        /**
          *  @brief  Find the minimum child node of an index.
          *  @param  index  Index to find the minimum child of.
          *  @return The minimum child of the parent index.
          */
        int minChild(int index);
};


/**
 *  @brief  Implementation of max heap using a dynamic array.
 *  @tparam  T  Type of data heap is to be.
 */
template <class T = int>
class ArrayMaxHeap : public ArrayHeapABC<T> {
    protected:
        void percUp();
        void percDown();

    public:
        ArrayMaxHeap() : ArrayHeapABC() { }
        virtual ~ArrayMaxHeap() { };

        /**
          *  @brief  Find the maximum child node of an index.
          *  @param  index  Index to find the maximum child of.
          *  @return The maximum child of the parent index.
          */
        int maxChild(int index);
};


/// ====================== ARRAY HEAP ABC ======================

/// insert
template <class T>
void ArrayHeapABC<T>::insert(const T data) {
    heap.append(data);
    this->length++;
    this->percUp();
}


/// pop
template <class T>
T ArrayHeapABC<T>::pop() {
    if (length == 0) {
        return NULL;
    }
    T data = this->heap[1];
    this->heap[1] = this->heap[length];
    this->percDown();
    this->heap.pop();
    this->length--;
    return data;
}


/// print
template <class T>
void ArrayHeapABC<T>::print() {
    for (int i = 1; i < length+1; i++) {
        std::cout << heap[i] << " ";
    }
}

/// ====================== ARRAY HEAP ABC ======================


/// ====================== ARRAY MIN HEAP ======================

/// min child
template <class T>
int ArrayMinHeap<T>::minChild(int index) {
    if (index*2+1 > this->size()) {
        return index*2;
    }
    int smallestChildIndex = this->heap[index*2] < this->heap[index*2+1] ? index*2 : index*2+1;
    return smallestChildIndex;
}


/// perc up
template <class T>
void ArrayMinHeap<T>::percUp() {
    int parentIndex = this->size() / 2;
    int childIndex = this->size();
    while (parentIndex > 0 && this->heap[childIndex] < this->heap[parentIndex]) {
        T temp = this->heap[childIndex];
        this->heap[childIndex] = this->heap[parentIndex];
        this->heap[parentIndex] = temp;
        childIndex = parentIndex;
        parentIndex /= 2;
    }
}


/// perc down
template <class T>
void ArrayMinHeap<T>::percDown() {
    int parentIndex = 1;
    int childIndex = minChild(parentIndex);
    while (childIndex <= this->size() && this->heap[parentIndex] > this->heap[childIndex]) {
        T temp = this->heap[parentIndex];
        this->heap[parentIndex] = this->heap[childIndex];
        this->heap[childIndex] = temp;
        parentIndex = childIndex;
        childIndex = minChild(parentIndex);
    }
}

/// ====================== ARRAY MIN HEAP ======================


/// ====================== ARRAY MAX HEAP ======================

/// max child
template <class T>
int ArrayMaxHeap<T>::maxChild(int index) {
    if (index*2+1 > this->size()) {
        return index*2;
    }
    int largestChildIndex = this->heap[index*2] > this->heap[index*2+1] ? index*2 : index*2+1;
    return largestChildIndex;
}


/// perc up
template <class T>
void ArrayMaxHeap<T>::percUp() {
    int parentIndex = this->size() / 2;
    int childIndex = this->size();
    while (parentIndex > 0 && this->heap[childIndex] > this->heap[parentIndex]) {
        T temp = this->heap[childIndex];
        this->heap[childIndex] = this->heap[parentIndex];
        this->heap[parentIndex] = temp;
        childIndex = parentIndex;
        parentIndex /= 2;
    }
}


/// perc down
template <class T>
void ArrayMaxHeap<T>::percDown() {
    int parentIndex = 1;
    int childIndex = maxChild(parentIndex);
    while (childIndex <= this->size() && this->heap[parentIndex] < this->heap[childIndex]) {
        T temp = this->heap[parentIndex];
        this->heap[parentIndex] = this->heap[childIndex];
        this->heap[childIndex] = temp;
        parentIndex = childIndex;
        childIndex = maxChild(parentIndex);
    }
}

/// ====================== ARRAY MAX HEAP ======================

}  /// namespace heap

#endif // ARRAY_HEAP_H
