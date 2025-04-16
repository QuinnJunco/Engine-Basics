#include "tests.h"
#include <string.h>
#include "../buffer.h"
#include "../input_events.h"
#include "../events.h"
#include "../window.h"

// test that constructor creates the correct size buffer
int create() {
    int code = 0x0;

    Buffer* B = new Buffer(10);

    if (B->get_size() != 10) {
        std::cout << "Size not equal to 10\n" << std::endl;
        code += 0x1;
    }

    if (B->get_count() != 0) {
        std::cout << "Count not equal to 0\n" << std::endl;
        code += 0x10;
    }

    if (B->get_capacity() != 10) {
        std::cout << "Capacity not equal to 10\n" << std::endl;
        code += 0x100;
    }

    B->clean();
    return code;
}

// tests the push functionality
int push() {
    int code = 0x0;

    Buffer* B = new Buffer(10);

    B->push(atoi("a"));

    if (B->get_size() != 10) {
        std::cout << "Size not equal to 10\n" << std::endl;
        code += 0x1;
    }

    if (B->get_count() != 1) {
        std::cout << "Count not equal to 0\n" << std::endl;
        code += 0x10;
    }

    if (B->get_capacity() != 9) {
        std::cout << "Capacity not equal to 10\n" << std::endl;
        code += 0x100;
    }

    B->clean();
    return code;
}

// tests the pop functionality
int pop() {
    int code = 0x0;

    Buffer* B = new Buffer(10);

    B->push(atoi("a"));

    int A = B->pop();

    if (B->get_size() != 10) {
        std::cout << "Size not equal to 10\n" << std::endl;
        code += 0x1;
    }

    if (B->get_count() != 0) {
        std::cout << "Count not equal to 0\n" << std::endl;
        code += 0x10;
    }

    if (B->get_capacity() != 10) {
        std::cout << "Capacity not equal to 10\n" << std::endl;
        code += 0x100;
    }

    if (A != atoi("a")) {
        std::cout << A << std::endl;
        std::cout << "Popped content did not return correct value\n" << std::endl;
        code += 0x1000;
    }

    B->clean();
    return code;
}

int stress() {
    int code = 0x0;

    Buffer* B = new Buffer(10);

    B->push(atoi("a"));
    B->push(atoi("b"));
    B->push(atoi("c"));
    B->push(atoi("d"));
    B->push(atoi("e"));
    B->push(atoi("f"));
    B->push(atoi("g"));
    B->push(atoi("h"));
    B->push(atoi("i"));

    int A = B->pop();

    if (B->get_size() != 10) {
        std::cout << "Size not equal to 10\n" << std::endl;
        code += 0x1;
    }

    if (B->get_count() != 8) {
        std::cout << "Count not equal to 8\n" << std::endl;
        code += 0x10;
    }

    if (B->get_capacity() != 2) {
        std::cout << "Capacity not equal to 2\n" << std::endl;
        code += 0x100;
    }
    
    if (A != atoi("a")) {
        std::cout << A << std::endl;
        std::cout << "Popped content did not return correct value\n" << std::endl;
        code += 0x1000;
    }

    B->push(atoi("a"));
    B->push(atoi("a"));

    if (B->get_size() != 10) {
        std::cout << "Size not equal to 10\n" << std::endl;
        code += 0x1;
    }

    if (B->get_count() != 10) {
        std::cout << "Count not equal to 10\n" << std::endl;
        code += 0x10;
    }

    if (B->get_capacity() != 0) {
        std::cout << "Capacity not equal to 0\n" << std::endl;
        code += 0x100;
    }

    A = B->pop();
    if (A != atoi("b")) {
        std::cout << A << std::endl;
        std::cout << "Popped content did not return correct value\n" << std::endl;
        code += 0x1000;
    }

    A = B->pop();
    if (A != atoi("c")) {
        std::cout << A << std::endl;
        std::cout << "Popped content did not return correct value\n" << std::endl;
        code += 0x1000;
    }

    A = B->pop();
    if (A != atoi("d")) {
        std::cout << A << std::endl;
        std::cout << "Popped content did not return correct value\n" << std::endl;
        code += 0x1000;
    }

    if (B->get_count() != 7) {
        std::cout << "Count not equal to 7\n" << std::endl;
        code += 0x10;
    }

    if (B->get_capacity() != 3) {
        std::cout << "Capacity not equal to 3\n" << std::endl;
        code += 0x100;
    }

    B->clean();
    return code;
}

void eProcess(void* e) {
    Events* E = (Events*) e;

    E->poll();
}

int main() {
    // std::cout << "Create test: " << std::hex << create() << std::dec << std::endl;
    // std::cout << "Push test: " << std::hex << push() << std::dec << std::endl;
    // std::cout << "Pop test: " << std::hex << pop() << std::dec << std::endl;
    // std::cout << "Stress test: " << std::hex << stress() << std::dec << std::endl;

    // std::cout << "Starting Events testing..." << std::endl;
    
    // Events E = Events();
    // std::cout << "Events object created." << std::endl;

    // std::thread T (eProcess, &E);
    // E.update();
    
    Window* W = new Window("main");

    bool quit = false;
    while(!quit) {
        if (!W->process_messages()) {
            quit = true;
        }
        // render everything
        W->swap_buffers();
        Sleep(5);
    }

    delete W;
    return 0;
}
