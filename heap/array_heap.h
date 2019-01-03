#ifndef ARRAY_HEAP_H
#define ARRAY_HEAP_H

#include "../../arraylist/array_list.h"



/** Array heap class to implement methods and variables common to both
 * min and max heaps.
 *
 * template class T : Type of data heap is to be.
 *      -Defaults to int.
 *
 * @var length : Keep track of the last index of the heap.
 * @var heap : ArrayHeap object used for array representation of a heap.g
 */
template <class T = int>
class ArrayHeapABC
{
    private:
        int length;

    protected:
        ArrayList<T> heap;

        /** Move data to appropriate index in heap after insertion.
         */
        virtual void perc_up() = 0;

        /** Move data to appropriate index in heap after deletion.
         */
        virtual void perc_down() = 0;

        void set_length(const int length) { this->length = length; }

    public:
        ArrayHeapABC();
        virtual ~ArrayHeapABC() { delete &heap; }
        T operator [] (const int index) { return this->heap[index]; }

        /** Total number of active heap nodes.
         *
         * @return Total number of nodes in the heap.
         */
        int size() const { return this->length; }

        /** Append data to list, call perc_up to move data to appropriate
         * position in the heap, increment length.
         *
         * @param data : Data to insert into the heap.
         */
        void insert(const T data);

        /** Get the data at the head of the heap, swap the head of the heap
         * with the tail, call perc_down to move head to appropriate position.
         *
         * @return Data that resided at the head of the heap.
         */
        T pop();

        /** Print the contents of the heap instance variable.
         */
        void print();
};



/** Implementation of min heap using a dynamic array.
 * Inherits from ArrayHeapABC.
 *
 * template class T : Type of data heap is to be.
 *      -Defaults to int.
 */
template <class T = int>
class ArrayMinHeap : public ArrayHeapABC<T>
{
    protected:
        void perc_up();
        void perc_down();

    public:
        ArrayMinHeap();
        virtual ~ArrayMinHeap() { };

        /** Find the minimum child node of an index.
         *
         * @param index : Index to find the minimum child of.
         * @return The minimum child of the parent index.
         */
        int min_child(int index);
};



/** Implementation of max heap using a dynamic array.
 * Inherits from ArrayHeapABC.
 *
 * template class T : Type of data heap is to be.
 *      -Defaults to int.
 */
template <class T = int>
class ArrayMaxHeap : public ArrayHeapABC<T>
{
    protected:
        void perc_up();
        void perc_down();

    public:
        ArrayMaxHeap();
        virtual ~ArrayMaxHeap() { };

        /** Find the maximum child node of an index.
         *
         * @param index : Index to find the maximum child of.
         * @return The maximum child of the parent index.
         */
        int max_child(int index);
};



#include "array_heap.tpp"

#endif // ARRAY_HEAP_H
