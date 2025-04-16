#include <iostream>

#ifndef BUFFER_H
#define BUFFER_H

struct buf_elem {
    int content {-1}; // integer content
    buf_elem* next;
};

typedef struct {
    int count; // number of present elements
    int capacity; // remaining capacity in the buffer
    buf_elem* front {nullptr}; // ptr to the first element in the buffer
    buf_elem* last {nullptr}; // ptr to the last element in the buffer
} buffer;

class Buffer {
    public:
        /**
         * Buffer constructor, takes size to create a new buffer
         * @param size: total number length of the buffer array
         */
        Buffer(int size);

        /**
         * Buffer destructor
         */
        ~Buffer();

        /**
         * Pops the first element from the front of the buffer
         * @returns int: front element's content
         */
        int pop();

        /**
         * Pushes a new element to the back of the buffer
         * @param elem: new element
         */
        void push(int elem);

        /**
         * Reads the front of the buffer without removing the element
         * @returns buf_elem*: front element
         */
        buf_elem* front();

        /**
         * Queries the buffer for the element at a specific index
         * @param idx: index of element being queried
         * @returns buf_elem*: element at index idx
         */
        buf_elem* query(int idx);

        /**
         * Basic getter for size of the buffer
         */
        int get_size();

        /**
         * Basic getter for number of elements in the buffer
         */
        int get_count();

        /**
         * Basic getter for remaining capacity in the buffer
         */
        int get_capacity();

        /**
         * Cleans up
         */
        void clean();
    
    private:

        buffer* mBuf {nullptr};

        // initializes required memory
        void init(int size) {
            mBuf = (buffer*)malloc(sizeof(buffer)); // allocates overall buffer

            // fills elements
            mBuf->count = 0;
            mBuf->capacity = size;
            mBuf->front = nullptr;
            mBuf->last = nullptr;
        }
};

#endif // BUFFER_H