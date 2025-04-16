
#ifndef EVENTS_H
#define EVENTS_H
#include "input_events.h"
#include <thread>
#include <iostream>
#include <windows.h>

class Events {
    public:
    
        /**
         * Basic Events constructor
         */
        Events();

        /**
         * Basic Events destructor
         */
        ~Events();

        /**
         * Updates the keyStatus map
         */
        void update();

        /**
         * Returns whether the specified key is in the pressed state
         * @param key
         * @returns bool
         */
        bool Pressed(InputEvents::KeyCode key) {
            return m_keyStatus[key] == EVENT_PRESS;
        }

        /**
         * Returns whether the specified key is in the down state
         * @param key
         * @returns bool
         */
        bool Down(InputEvents::KeyCode key) {
            return m_keyStatus[key] == EVENT_DOWN;
        }

        /**
         * Returns whether the specified key is in the released state
         * @param key
         * @returns bool
         */
        bool Released(InputEvents::KeyCode key) {
            return m_keyStatus[key] == EVENT_RELEASE;
        }

        /**
         * Polls for new keyboard input until engine closes
         */
        void poll();

    private:

        enum status {
            EVENT_NONE = 0,
            EVENT_PRESS,
            EVENT_DOWN,
            EVENT_RELEASE
        };

        status m_keyStatus[Q_KEY_EVENT_COUNT] = {EVENT_NONE};

};

#endif