#include "array_heap.h"


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
