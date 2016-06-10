/* timer.ino ~ Copyright 2015-2016 ~ Paul Beaudet MIT licence - see LICENCE
 * Javascript style async event handling - gives three main methodes
 * todoChecker();               // checks if todos need to be run place in main loop: NON BLOCKING, event handler
 * setTimeout(callback, time);  // pass function and durration of todo: runs onces, returns timerID
 * setInterval(callback, time); // pass function and durration of todo: runs repetitively, returns timerID
 *
 * todos[timerID] = 0;          // cancels timer
 */
#include <JS_Timer.h>

JS_Timer::JS_Timer(void){                 // object setup
    for(byte i = 0; i < MAX_TIMERS; i++){ // for all timers
        todos[i] = 0;
        repeat[i] = 0;
        wait[i] = 0;
        startTime[i] = 0;
    }                                     // instantiate to zero
}

void JS_Timer::todoChecker(){     // checks timer to see if a timeout or set interval event need to be executed
  uint32_t currentTime = millis();               // measure current time in milliseconds once
  for(byte i = 0; i < MAX_TIMERS; i++){          // for all timers
    if(todos[i]){                                // if there is a todo for this element of list
      if(currentTime - startTime[i] >= wait[i]){ // and time has elapsed from start
        (*todos[i])();                           // run this todo!
        if(repeat[i]){                           // if its repeating
          startTime[i] = currentTime;            // set the clock to do it again
        } else {                                 // run once case
          todos[i] = 0;                          // remove timer data
        }
      }
    }
  }
}

// alias user facing functions to avoid passing extra param 
uint8_t JS_Timer::setTimeout(funcPointer todo, uint32_t durration){return addTimer(todo, durration, false);}
uint8_t JS_Timer::setInterval(funcPointer todo, uint32_t durration){return addTimer(todo, durration, true);}

// --- lower level --
uint8_t JS_Timer::addTimer(funcPointer todo, uint32_t durration, boolean recurring){
  for(byte i = 0; i < MAX_TIMERS; i++){    // for all timers
    if(todos[i] == 0){                     // given this todo is empty
      todos[i] = todo;                     // give this todo a space on todo list
      repeat[i] = recurring;               // note if this todo recurs
      wait[i] = durration;                 // remember what we are counting down to
      startTime[i] = millis();             // need something to countdown against
      return i;                            // return timer ID
    }    
  }
  return 0xff;                          // timer not set case / too many timers (0xff == 255)
}
