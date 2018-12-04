#ifndef HASHTABLE_H
#define HASHTABLE_H


namespace hashtable {

/** Hash table of key-value mappings. Avoids collisions by linear
 * probing with linked lists.
 *
 * template V : data type that values should be for key-value pairs.
 *      - Defaults to int.
 *
 * @param table : Array of HashTable::LinkedList objects.
 * @param size : Size of table array.
 */
template <class V = int>
class HashTable
{
    // Keys are strings
    typedef char* K;

    private:
        /** Linked list class used for collision avoidance.
         *
         * @param head : Pointer to first node in list.
         * @param tail : Pointer to last node in list.
         */
        class LinkedList
        {
            public:
                /** Nodes for linked lists have keys and values.
                 * @param key : Key for looking up value.
                 * @param val : Value that can be looked up by key.
                 * @param next : Pointer to next node in list.
                 */
                class Node
                {
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
                LinkedList() : head(nullptr) { }
                ~LinkedList() { delete head; delete tail; }

                /** Insert a node into a linked list. If key already exists
                 * in list, update val instance variable of node.
                 *
                 * @param key : Key to lookup value by.
                 * @param val : Value to be looked up by key.
                 */
                void insert(const K key, const V val);

                /** Find a node's value by its key.
                 *
                 * @param key : Key to lookup node by.
                 * @return Value of key if key exists in list, NULL otherwise.
                 */
                V find(const K key) const;

                /** Remove a node from a linked list if it exists.
                 *
                 * @param key : Key of node to remove from list.
                 */
                void remove(const K key);

        };  /// HashTable::LinkedList


    private:
        LinkedList *table;
        int size;

    protected:
        /** Return a valid index in range of 0 to this->size.
         */
        int hash(const K key) {
            int index = 0;
            int probe = 0;
            for (int i = 0; key[i] != '\0'; i++)
                index += (++probe)*key[i];
            return index % size;
        }

    public:
        HashTable(const int size = 127) : size(size) { table = new LinkedList[size]; }
        ~HashTable() { delete [] table; }

        /** Put a key-value pair into the hash table. If key already
         * exists, value will be written over.
         *
         * @param key : Key to lookup value by.
         * @param val : Value to be looked up by key.
         */
        void put(const K key, const V val) {
            int index = this->hash(key);
            table[index].insert(key, val);
        }

        /** Retrieve a value by its key if it exists in the table.
         *
         * @param key : Key of value to find.
         * @return Value that matches key if it exists.
         */
        V get(const K key) {
            int index = this->hash(key);
            return table[index].find(key);
        }

        /** Remove a key-value pair from the table by key.
         *
         * @param key : Key of key-value pair to remove from table.
         */
        void remove(const K key) {
            int index = this->hash(key);
            table[index].remove(key);
        }

};  /// HashTable


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
    for (Node *i = head; i != nullptr; i = i->next)
        if (i->key == key)
            return i->val;
    return NULL;
}


/// Delete a node from a linked list.
template <class V>
void HashTable<V>::LinkedList::remove(const K key) {
    // if head is to be deleted
    if (head->key == key) {
        // if head is last node in list
        if (head == tail) {
            head = nullptr;
            tail = nullptr;
        }
        else
            head = head->next;
    }
    else {
        Node *prev = head;
        Node *curr = head->next;

        for (; curr != nullptr && curr->next != nullptr;) {
            if (curr->key == key)
                break;
            prev = curr;
            curr = curr->next;
        }

        // if node does not exist in list
        if (curr == nullptr)
            return;
        // if node to be deleted is tail
        else if (curr->next == nullptr && curr->key == key)
            tail = prev;
        prev->next = curr->next;
        curr->next = nullptr;
    }
}

}  /// namespace hashtable


typedef hashtable::HashTable<> HashTable;


#endif  /// HASHTABLE_H
