#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <iostream>



/** Class to implement dynamic array that can grow on demand.
 *
 * template class T : Data type that list will hold
 *      - Defaults to int.
 *
 * @var length : Number of non-null list members.
 * @var max_size : Total number of members list can hold at a given time.
 * @var array_list : Pointer array that holds data members.
 */
template <class T = int>
class ArrayList
{
    private:
        int length = 0;
        int max_size;
        T *array_list;

    protected:
        /** Doubles size of array_list.
         */
        void expand();

    public:
        /** Default constructor creates array of 10 members.
         */ 
        ArrayList();

        /** Constructor to set default max_size.
         *
         * @param max_size : Initial array_list size.
         */
        ArrayList(int max_size);

        ArrayList(ArrayList& rhs);
        virtual ~ArrayList() { delete [] array_list; }

        /** Move constructor.
         *
         * @param rhs : Instance of ArrayList to move.
         */
        ArrayList(ArrayList&& rhs);

        /** Move assignment operator.
         *
         * @param rhs : Instance of ArrayList to move.
         * @return ArrayList at new location.
         */
        ArrayList& operator = (ArrayList&& rhs);

        /** Operator overload get item.
         *
         * @param index : Position of data member to retrieve.
         * @return Position of index argument passed in array_list member variable.
         */
        T& operator [] (const int index);

        /** Assignment operator to create deep copy of an instance of ArrayList.
         *
         * @param rhs : ArrayList instance to create a copy of.
         * @return Deep copy of rhs argument.
         */
        ArrayList& operator = (const ArrayList& rhs);

        /** Total number of non-null members in array_list.
         *
         * @return : Running total of members in array_list. 
         */
        int size() const { return length; }

        /** Add a data member to the end of array_list.
         *
         * If the length of the list is equal to the max_size then
         * this method will call expand() to double the size of array_list.
         *
         * @param data : Data member to add to end of array_list.
         */
        void append(const T data);

        /** Remove the last member of array_list and return it.
         *
         * @return Data that resides at last element of array_list.
         */
        T pop();
};



#include "array_list.tpp"

#endif // ARRAY_LIST_H
