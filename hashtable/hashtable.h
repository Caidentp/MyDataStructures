#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <exception>
#include <string>

namespace hashtable {

/**
 *  @brief  Hash table of key-value mappings where keys are strings.
 *  @var  table  Array of HashTable::LinkedList objects.
 *  @var  size  Size of table array.
 *
 *  @tparam  V  data type for values.
 *
 *  Flexible data structure where values are easily accesed by their keys.
 *  Values can be a data type of your choice. Values are accesed in O(1)
 *  best and average case and O(n) worst case where n is the length of the
 *  linked list at the index returned by the hash function.
 */
template <class V = int>
class HashTable {
    // Keys are strings
    typedef std::string K;

#ifndef TESTING
    private:
#endif
#ifdef TESTING
    public:
#endif
        /** 
          *  @brief  Linked list class used for collision avoidance.
          *  @var  head  Pointer to first node in list.
          *  @var  tail  Pointer to last node in list.
          */
        class LinkedList {
            public:
                /** 
                   *  @brief  Nodes for linked lists have keys and values.
                   *  @var  key  Key for looking up value.
                   *  @var  val  Value that can be looked up by key.
                   *  @var  next  Pointer to next node in list.
                   */
                class Node {
                    public:
                        K key;
                        V val;
                        Node *next;
                        Node(const K key, const V val, Node *next = nullptr)
                            : key(key)
                            , val(val)
                            , next(next) { }
                };  /// HashTable::LinkedList::Node

                Node *head;
                Node *tail;

            public:
                LinkedList() : head(nullptr), tail(nullptr) { }
                ~LinkedList();

                /** 
                   *  @brief  Insert a node into a linked list. 
                   *  @param  key  Key to lookup value by.
                   *  @param  val  Value to be looked up by key.
                   *
                   *  If the key already exists in the list, the value instance
                   *  variable of the node will be updated to contain the new val.
                   */
                void insert(const K key, const V val);

                /** Find a node's value by its key.
                   *
                   * @param key : Key to lookup node by.
                   * @return Value of key if key exists in list, NULL otherwise.
                   */
                V find(const K key) const;

                /** 
                   *  @brief  Remove a node from a linked list if it exists.
                   *  @param  key  Key of node to remove from list.
                   */
                void remove(const K key);
        };  /// HashTable::LinkedList

#ifndef TESTING
    private:
#endif
#ifdef TESTING
    public:
#endif
        LinkedList *table;
        int size;

#ifndef TESTING
    protected:
#endif
#ifdef TESTING
    public:
#endif
        /** 
          *  @brief  Return a valid index in range of 0 to this->size.
          *  @param  key  Hash is calculated by the key passed to the function.
          */
        inline int hash(const K key);

    private:
        HashTable(const HashTable& table) = delete;
        HashTable& operator =(const HashTable& table) = delete;
        HashTable(HashTable&& table) = delete;
        HashTable& operator =(HashTable&& table) = delete;

    public:
        HashTable(const int size = 127) : size(size) { table = new LinkedList[size]; }
        ~HashTable() { delete [] table; }

        /** 
          *  @brief  Put a key-value pair into the hash table. If key already
          *          exists, value will be written over.
          *  @param  key  Key to lookup value by.
          *  @param  val  Value to be looked up by key.
          */
        void put(const K key, const V val) {
            table[this->hash(key)].insert(key, val);
        }

        /** 
          *  @brief  Retrieve a value by its key if it exists in the table.
          *  @param  key  Key of value to find.
          *  @return Value that matches key if it exists.
          */
        V get(const K key) {
            return table[this->hash(key)].find(key);
        }

        /** 
          *  @brief  Remove a key-value pair from the table by key.
          *  @param  key  Key of key-value pair to remove from table.
          */
        void remove(const K key) {
            table[this->hash(key)].remove(key);
        }
};  /// HashTable


struct KeyError : public std::exception {
    const char *what() const throw() {
        return "Key does not exist.";
    }
};


// ======================= HashTable =======================

template <class V>
inline int HashTable<V>::hash(const K key) {
    int index = 0;
    // Probe is used so that permutations of the same key will
    // generate different hashes
    int probe = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        index += (++probe)*key[i];
    }
    // Ensure index is in range of LinkedList array
    return index % size;
}

// ======================= HashTable =======================


// ================= HashTable::LinkedList =================

template <class V>
HashTable<V>::LinkedList::~LinkedList() {
    Node* temp = head;
    Node* curr = head;
    while (temp != nullptr) {
        temp = temp->next;
        delete curr;
        curr = temp;
    }
    head = nullptr;
    tail = nullptr;
}

/// Insert a node into a linked list
template <class V>
void HashTable<V>::LinkedList::insert(const K key, const V val) {
    // if list is empty
    if (head == nullptr) {
        head = new Node(key, val, head);
        tail = head;
    }
    else {
        // update node value if it already exists
        for (Node *i = head; i != nullptr; i = i->next) {
            if (i->key == key) {
                i->val = val;
                return;
            }
        }
        // append node if it does not exist
        tail->next = new Node(key, val);
        tail = tail->next;
    }
}


/// Find a node's value by its key.
template <class V>
V HashTable<V>::LinkedList::find(const K key) const {
    for (Node *i = head; i != nullptr; i = i->next) {
        if (i->key == key) {
            return i->val;
        }
    }
    throw KeyError();
}


/// Delete a node from a linked list.
template <class V>
void HashTable<V>::LinkedList::remove(const K key) {
    // if table is empty
    if (head == nullptr) {
        return;
    }
    // if head is to be deleted
    if (head->key == key) {
        // if head is last node in list
        if (head == tail) {
            head = nullptr;
            tail = nullptr;
        }
        else {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
    else {
        Node *prev = head;
        Node *curr = head->next;
        for (; curr != nullptr && curr->next != nullptr;) {
            if (curr->key == key) {
                break;
            }
            prev = curr;
            curr = curr->next;
        }
        // if node does not exist in list
        if (curr == nullptr) {
            return;
        }
        // if node to be deleted is tail
        else if (curr->next == nullptr && curr->key == key) {
            tail = prev;
        }
        prev->next = curr->next;
        delete curr;
    }
}

// ================= HashTable::LinkedList =================

}  /// namespace hashtable

typedef hashtable::HashTable<int> table;

#endif  /// HASHTABLE_H
