#include "events.h"

Events::Events() {}

Events::~Events() {}

void Events::update() {
    BYTE keys[256];
    if (!GetKeyboardState(keys)) { // reads the current keyboard state
        std::cout << "FAILED TO GET KEYBOARD STATE." << std::endl;
        return; 
    }

    std::cout << static_cast<int>(keys[InputEvents::KEYCODE_A]) << std::endl;

    for (int i = Q_FIRST_KEY_OFFSET; i < Q_FIRST_KEY_OFFSET+Q_KEY_EVENT_COUNT; i++) {
        switch (m_keyStatus[i]) {

            case Events::EVENT_PRESS : // PRESS state
                if (keys[i] & 0x80) {
                    m_keyStatus[i] = Events::EVENT_DOWN; // PRESS -> DOWN
                } else {
                    m_keyStatus[i] = Events::EVENT_RELEASE; // PRESS -> RELEASE
                }
                break;
            
            case Events::EVENT_DOWN : // DOWN state
                if (!(keys[i] & 0x80)) {
                    m_keyStatus[i] = Events::EVENT_RELEASE; // DOWN -> RELEASE
                } 
                break;
            
            case Events::EVENT_RELEASE : // RELEASE state
                m_keyStatus[i] = Events::EVENT_NONE; // RELEASE -> NONE
                break;
            
            default : // NONE state
                if (keys[i] & 0x80) {
                    m_keyStatus[i] = Events::EVENT_PRESS; // NONE -> PRESS
                }
                break;
        }
        
    }
    
}

void Events::poll() {
    bool exit {false};

    while (!exit) {
        if (Events::m_keyStatus[InputEvents::KEYCODE_ESCAPE]) {
            exit = true;
        }

        Events::update();
    }

}
