/// https://gist.github.com/jeetsukumaran/307264


#include <iostream>

template <class T = int>
class Node
{
    public:
        T data;
        Node* next;
        Node(const T data, Node* next = nullptr)
            : data(data)
            , next(next) { }
};


template <class T = int>
class LinkedList
{
    public:
    class iterator
    {
        public:
        typedef iterator self_type;
            typedef T value_type;
            typedef T& reference;
            typedef Node<T>* pointer;
            typedef std::forward_iterator_tag iterator_category;
            typedef int difference_type;
            iterator(pointer ptr) : ptr_(ptr) { }
            self_type operator++() { self_type i = *this; ptr_ = ptr_->next; return i; }
            self_type operator++(int junk) { ptr_ = ptr_->next; return *this; }
            reference operator*() { return *ptr_; }
            pointer operator->() { return ptr_; }
            bool operator==(const self_type& rhs) { return ptr_ == rhs.ptr_; }
            bool operator!=(const self_type& rhs) { return ptr_ != rhs.ptr_; }
        private:
            pointer ptr_;
    };


    private:
        Node<T>* head;

    public:
        LinkedList(const T data = NULL) {
            if (data)
                head = new Node<T>(data);
            else
                head = nullptr;
        }
        void push(const T data) {
            Node<T>* new_node = new Node<T>(data);
            new_node->next = head;
            head = new_node;
        }
        void print() const {
            for (Node<T>* i = head; i != nullptr; i = i->next)
                std::cout << i->data << " ";
        }

        iterator begin() {
            return iterator(head);
        }

        iterator end() {
            return nullptr;
        }
};



#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cassert>

template <typename T>
class fixed_array
{
    public:

        typedef int size_type;

        class iterator
        {
            public:
                typedef iterator self_type;
                typedef T value_type;
                typedef T& reference;
                typedef T* pointer;
                typedef std::forward_iterator_tag iterator_category;
                typedef int difference_type;
                iterator(pointer ptr) : ptr_(ptr) { }
                self_type operator++() { self_type i = *this; ptr_++; return i; }
                self_type operator++(int junk) { ptr_++; return *this; }
                reference operator*() { return *ptr_; }
                pointer operator->() { return ptr_; }
                bool operator==(const self_type& rhs) { return ptr_ == rhs.ptr_; }
                bool operator!=(const self_type& rhs) { return ptr_ != rhs.ptr_; }
            private:
                pointer ptr_;
        };

        class const_iterator
        {
            public:
                typedef const_iterator self_type;
                typedef T value_type;
                typedef T& reference;
                typedef T* pointer;
                typedef int difference_type;
                typedef std::forward_iterator_tag iterator_category;
                const_iterator(pointer ptr) : ptr_(ptr) { }
                self_type operator++() { self_type i = *this; ptr_++; return i; }
                self_type operator++(int junk) { ptr_++; return *this; }
                const reference operator*() { return *ptr_; }
                const pointer operator->() { return ptr_; }
                bool operator==(const self_type& rhs) { return ptr_ == rhs.ptr_; }
                bool operator!=(const self_type& rhs) { return ptr_ != rhs.ptr_; }
            private:
                pointer ptr_;
        };


        /// constructor
        fixed_array(size_type size) : size_(size) {
            data_ = new T[size_];
        }

        size_type size() const { return size_; }

        T& operator[](size_type index) {
            assert(index < size_);
            return data_[index];
        }

        const T& operator[](size_type index) const {
            assert(index < size_);
            return data_[index];
        }

        iterator begin() {
            return iterator(data_);
        }

        iterator end() {
            return iterator(data_ + size_);
        }

        const_iterator begin() const {
            return const_iterator(data_);
        }

        const_iterator end() const {
            return const_iterator(data_ + size_);
        }

    private:
        T* data_;
        size_type size_;
};


int main()
{
    LinkedList<> test = LinkedList<>();
    test.push(1);
    test.push(2);
    test.push(3);
    for(LinkedList<int>::iterator i = test.begin(); i != test.end(); i++)
        std::cout << i->data << " ";
}
