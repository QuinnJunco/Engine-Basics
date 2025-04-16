#include "buffer.h"

Buffer::Buffer(int size) {
    init(size);
}

void Buffer::push(int elem) {
    
    if (elem == -1) {
        std::cout << "Failed to push element: Null elem\n" << std::endl;
        return;
    }

    // wraps the element
    buf_elem* E = (buf_elem*)malloc(sizeof(buf_elem));
    E->content = elem;
    E->next = nullptr;
    
    if (mBuf->capacity-- == 0) {
        std::cout << "Failed to push element: Buffer full\n" << std::endl;
        return;
    }

    // updates last pointer
    if (mBuf->count++ > 0) {
        mBuf->last->next = E;
    } else {
        mBuf->front = E;
    }
    mBuf->last = E; 

    // std::cout << "Successfully pushed elem." << std::endl;
}

int Buffer::pop() {
    if (mBuf->count == 0) {
        std::cout << "Failed to pop from buffer: Buffer empty\n" << std::endl;
        return -1;
    }

    buf_elem* E = mBuf->front; // stores old value
    int content = E->content; // isolates content

    // updates buffer
    mBuf->front = E->next; // detaches E from buffer
    if (mBuf->count-- == 1) { // handles the tail ptr edge case
        mBuf->last = nullptr;
    }
    mBuf->capacity++;

    // cleans up E
    E->next = nullptr;
    E->content = -1;
    free(E);

    return content;
}

buf_elem* Buffer::front() {
    if (mBuf->count == 0) {
        std::cout << "Failed to read from buffer: Buffer empty\n" << std::endl;
        return nullptr;
    }

    return mBuf->front;
}

buf_elem* Buffer::query(int idx) {
    if (idx >= mBuf->count) { // returns null if index is undefined
        return nullptr;
    }

    buf_elem* E = mBuf->front;
    for (int i = 0; i < idx; i++) { // use sparingly because it's inefficient 
        E = E->next;
    }

    return E; 
}

int Buffer::get_size() {
    return mBuf->capacity + mBuf->count;
}

int Buffer::get_count() {
    return mBuf->count;
}

int Buffer::get_capacity() {
    return mBuf->capacity;
}

void Buffer::clean() {
    while (mBuf->count > 0) {pop();} // clears the buffer

    mBuf->capacity = 0; 

    // each of these should be redundant
    mBuf->count = 0; 
    mBuf->front = nullptr;
    mBuf->last = nullptr;

    mBuf = nullptr;
    free(mBuf);
}