#ifndef _tracking_
#define _tracking_


#include "midi_event.h"
class note_tracking
{
  public:
    note_tracking();
    void add_midi_note(MIDI_event event);

    void remove_note(MIDI_event event);
    bool last_active();
    MIDI_event last();



  private:
    MIDI_event last_event;


};


#endif
