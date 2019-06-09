#include "note_tracking.h"


note_tracking::note_tracking()
{

}

void note_tracking::add_midi_note(MIDI_event _event)
{
  last_event.set_data(_event.get_channel(), _event.get_data1(), _event.get_data2());
  last_event.set_type(_event.get_type());
  last_event.activate();
  //Serial.println(_event.get_data1());
}

void note_tracking::remove_note(MIDI_event event)
{
  if (event.get_data1() == last_event.get_data1()) last_event.deactivate();
}

bool note_tracking::last_active()
{
  return last_event.get_state();
}

MIDI_event note_tracking::last()
{
  return last_event;
}

