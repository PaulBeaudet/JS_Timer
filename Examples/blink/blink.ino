// blink.ino 2016 This is a beginers arduino sketch! Compiled w/ Arduino 1.6.5
// blink without delay using JS_Timer

#include <JS_Timer.h>        // library from - https://github.com/paulbeaudet/JS_Timer
#define LED 13               // find and replace LED with 13: AKA the LED pin
#define TOGGLE_TIME 200      // find and replace TOGGLE_TIME with how often in milliseconds
                             //   the LED should blink

JS_Timer timer = JS_Timer(); // create an instance of our timer object from timer library

void setup(){                // Function: Runs once- called every sketch
    pinMode(LED, OUTPUT);    // tell our LED pin it will be an OUTPUT
    timer.setInterval(toggleLed, TOGGLE_TIME); // set toggle to happen every x amount of time
}

void loop(){                 // Function Runs over and over- called every sketch
    timer.todoChecker();     // Do not block!! blocking changes expected behaviour
                             // delays or lengthy events "block" timer.todoChecker
    //delay(TOGGLE_TIME + TOGGLE_TIME); // go a head, uncomment this line, see what happens 
}

void toggleLed(){                 // Function: Runs when needed: You create these!
    static boolean toggle = true; // Variable: home for a number, Boolean: can be 1 or 0, Static: remember variable
    digitalWrite(LED, toggle);    // write led state! true equals HIGH also equals 1: false equals LOW also equals 0
    toggle = !toggle;             // say toggle was true set it to false and vise versa, toggle equals not toggle
}

