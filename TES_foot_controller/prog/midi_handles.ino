#include "midi_event.h"
#include "looper.h"


void HandleNoteOn(byte channel, byte note, byte velocity) // type 0
{
  if (global_mode == LOOPER_MODE)
  {
    sendMidiEvent(MIDI_event(0, channel, note, velocity));
    for (byte i = 0; i < 3; i++)
    {
      if (loopers[i].is_recording())
      {
        loopers[i].add_event(MIDI_event(0, channel, note, velocity));
      }
    }
  }
  else if (global_mode == ARP_MONO_MODE)
  {
    if (!arp[taker.get_arp_index(0)].is_started() && !arp[taker.get_arp_index(1)].is_started()) sendMidiEvent(MIDI_event(0, channel, note, velocity));
    tracking.add_midi_note(MIDI_event(0, channel, note, velocity));
  }
}

void HandleNoteOff(byte channel, byte note, byte velocity) // type 1
{
  if (global_mode == LOOPER_MODE)
  {
    sendMidiEvent(MIDI_event(1, channel, note, velocity));
    for (byte i = 0; i < 3; i++)
    {
      if (loopers[i].is_recording()) loopers[i].add_event(MIDI_event(1, channel, note, velocity));
    }
  }
  else if (global_mode == ARP_MONO_MODE)
  {
    if (!arp[taker.get_arp_index(0)].is_started() && !arp[taker.get_arp_index(1)].is_started()) sendMidiEvent(MIDI_event(1, channel, note, velocity));
    tracking.remove_note(MIDI_event(0, channel, note, velocity));
  }
}

void HandleControlChange(byte channel, byte note, byte value) // type 2
{
  sendMidiEvent(MIDI_event(2, channel, note, value));
  for (byte i = 0; i < 3; i++)
  {
    if (loopers[i].is_recording()) loopers[i].add_event(MIDI_event(2, channel, note, value));
  }
}

void HandleProgramChange(byte channel, byte number) // type 3
{
  sendMidiEvent(MIDI_event(3, channel, number, 0));
  for (byte i = 0; i < 3; i++)
  {
    if (loopers[i].is_recording()) loopers[i].add_event(MIDI_event(3, channel, number, 0));
  }
}

void HandlePitchBend(byte channel, int bend) // type 4
{
 
 /* Serial.print(bend);
  Serial.print(" ");
  Serial.print(int_to_first_byte(bend));
  Serial.print(" ");
    Serial.print(int_to_second_byte(bend));
  Serial.print(" ");
  Serial.println(bytes_to_int(int_to_first_byte(bend), int_to_second_byte(bend)));*/
  sendMidiEvent(MIDI_event(4, channel, bend));
  /*Serial.print(bend);
  Serial.print(" ");
  Serial.println((short) bend);*/
  for (byte i = 0; i < 3; i++)
  {
    if (loopers[i].is_recording()) loopers[i].add_event(MIDI_event(4, channel, bend));
  }
}

void sendMidiEvent(MIDI_event ev)
{
  /* type:

    0 note ON
    1 Note OFF
    2 CC
    3 PG
    4 pitchbend
  */

  switch (ev.get_type())
  {
    case 0:
      {
        MIDI.sendNoteOn(ev.get_data1(), ev.get_data2(), ev.get_channel());
        break;
      }
    case 1:
      {
        MIDI.sendNoteOff(ev.get_data1(), ev.get_data2(), ev.get_channel());
        break;
      }
    case 2:
      {
        MIDI.sendControlChange(ev.get_data1(), ev.get_data2(), ev.get_channel());
        break;
      }
    case 3:
      {
        MIDI.sendProgramChange(ev.get_data1(), ev.get_channel());
        break;
      }
    case 4:
      {
        MIDI.sendPitchBend(ev.get_bend(), ev.get_channel());
        break;
      }

  }
}

