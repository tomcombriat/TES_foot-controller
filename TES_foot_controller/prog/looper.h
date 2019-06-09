#ifndef _looper_
#define _looper_

#include "midi_event.h"
#include <MIDI.h>

#define Nmax 350

class looper
{
  public:
    looper();



    void record();
    void start();
    void stop();
    void clear();
    void stop_record();
    unsigned long current_time();
    void set_mode(int);  //0 stardard, 1 trig on next event

    bool has_started();
    bool has_just_started();
    bool do_want_to_stop();
    void do_want_to_start();
    void do_want_to_stop_record();
    
    
    bool is_full();

    bool is_next();
    MIDI_event next();
    void add_event(MIDI_event);

    bool is_playing();
    bool is_recording();

    char get_state();

    
    




  private:
    MIDI_event events[Nmax];
    bool played[Nmax];
    bool playing, recording,has_start,full,has_just_start,want_to_stop,want_to_stop_record = false;
    unsigned long start_time;
    unsigned long previous_time;
    unsigned long duration;
    byte mode;
    unsigned int next_event; 
    char state;
    byte first_event_type;
    bool want_to_start=false;


};




#endif _looper_
