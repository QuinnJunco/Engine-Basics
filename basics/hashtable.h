#include <iostream>
#include <string.h>

#ifndef HASHTABLE_H
#define HASHTABLE_H

typedef struct {
    const char* path {nullptr}; // filepath to act as the key
    // will potentially need a type enum to help with initialization
    void* asset {nullptr}; // loaded asset
} Table_Item;

typedef struct {
    Table_Item** arr;
    int size;
    int count;
} Hash_Table;

class HashTable {
    public:

        /**
         * Constructor based on the necessary size of the table
         */
        HashTable(int size);

        ~HashTable();

        /**
         * Search method to find items in the table based on their asset path
         * @return voidptr with the loaded object
         */
        void* find(std::string path);

        /**
         * Insert method to add elements to the table 
         * @return false if anything goes wrong, true otherwise
         */
        bool insert(std::string path);

        /**
         * Delete method to remove items from the table
         * typically only called when cleaning up for deallocation
         * @return false if anything goes wrong, true otherwise
         */
        void remove(Table_Item* item);

        /**
         * Clean method to free memory for all assets then the table
         */
        void clean();

        /** FUTURE NEEDS
         * Expansion method with load factor addressing
         * Rehashing
         */

    private:

        Hash_Table* table {nullptr};

        // initializes all of the memory
        void init(int size) {
            table = (Hash_Table*) malloc(sizeof(Hash_Table)); // not doing error handling, I know how bad that is
            
            table->arr = (Table_Item**) malloc(sizeof(Table_Item)*size);
            table->count = 0;
            table->size = size;

            for (int i = 0; i < size; i++) {
                table->arr[i] = nullptr;
            }
        }

        // implementing the FNV-1 hashing algorithm
        uint32_t hash_code(std::string path) {
            uint32_t hash = 0x811c9dc5;

            for (char c : path) {
                hash = hash * 0x01000193;
                hash = hash xor c;
            }

            return hash % table->size;
        }

};


#endif