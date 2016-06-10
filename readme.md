# JS_Timer

This is an Arduino library that replicates the functionality of setInterval and setTimeout in Javascript

Note: max amount of timers is set to 10

Use:
    
    JS_Timer yourtimer = JS_Timer(); // create a timer object
    
    yourtimer.setInterval(yourFunction, durrationDesired); // run continualy every x milliseconds
    yourtimer.setTimeout(yourFunction, durrationDesired);  // run once in x milliseconds
    // hold parenthesis on your function we are just pointing to its existance, not executing the thing
    
    yourtimer.todoChecker() // check for when to run yourFunction
    // IMPORTANT do not block todoChecker with delays, whiles, or exhustive fors
    // todoChecker needs a consistent chance to check in order to run yourFunction
    
Installation: 
* Download zip 
* extract it into libraries folder within arduino sketchbook folder
* make sure extracted folder is named JS_Timer
* restart Arduino IDE if running
    
Alternitively: look up git clone, use it in sketchbook/libraries, then restart the IDE 

Copyright(c) 2016 Paul Beaudet ~ MIT License
