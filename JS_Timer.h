// timer.ino ~ Copyright 2015-2016 ~ Paul Beaudet MIT licence - see LICENCE
// use "#include <JS_Timer.h>" in your arduino sketch

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

// we need to create a datatype that allows us to point to a function without calling it
typedef void (*funcPointer)(void); // point to our functions

#define MAX_TIMERS 10              // must be less than 255, you'll prob run out of ram w/more anyhow

class JS_Timer {
    public:
        JS_Timer(void);                              // object construtor
        funcPointer todos[MAX_TIMERS];               // todo list
        uint8_t repeat[MAX_TIMERS];                  // does todo repeat?
        uint32_t wait[MAX_TIMERS];                   // how long to wait todo todo
        uint32_t startTime[MAX_TIMERS];              // when todo was first called
            // Exposed functions
        void todoChecker(void);                      // event loop checker
        uint8_t setInterval(funcPointer, uint32_t);  // note function and durration to interval trigger
        uint8_t setTimeout(funcPointer, uint32_t);   // note function and durration to timeout trigger
    private:
        byte addTimer(funcPointer, uint32_t, boolean);
};
