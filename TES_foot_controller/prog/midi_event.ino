#include "midi_event.h"

MIDI_event::MIDI_event()
{
  is_active = false;
  channel = 0;
  data1 = 0;
  data2 = 0;
}

MIDI_event::MIDI_event(byte _type, byte _channel, byte _data1, byte _data2)
{
  is_active = true;
  type = _type;
  channel = _channel;
  data1 = _data1;
  data2 = _data2;
}

MIDI_event::MIDI_event(byte _type, byte _channel, byte _data1, byte _data2, unsigned short _timing)
{
  is_active = true;
  type = _type;
  channel = _channel;
  data1 = _data1;
  data2 = _data2;
  timing = _timing;
}

MIDI_event::MIDI_event(byte _type, byte _channel, int _bend)
{
  is_active = true;
  type = _type;
  channel = _channel;
  bend = (short) _bend;

}

void MIDI_event::set_data(byte _channel, byte _data1, byte _data2)
{
  channel = _channel;
  data1 = _data1;
  data2 = _data2;
}

void MIDI_event::set_data(byte _channel, int _bend)
{
  channel = _channel;
bend = (short) _bend;
}

void MIDI_event::set_type(byte _type)
{
  type = _type;
}

void MIDI_event::activate()
{
  is_active = true;
}

void MIDI_event::deactivate()
{
  is_active = false;
}


void MIDI_event::empty()
{
  is_active = false;
  channel = 0;
  data1 = 0;
  data2 = 0;
}

bool MIDI_event::get_state()
{
  return is_active;
}

byte MIDI_event::get_channel()
{
  return channel;
}

byte MIDI_event::get_data1()
{
  return data1;
}

byte MIDI_event::get_data2()
{
  return data2;
}

byte MIDI_event::get_type()
{
  return type;
}

void MIDI_event::set_timing(unsigned short _timing)
{
  timing = _timing;
}

unsigned short MIDI_event::get_timing()
{
  return timing;
}

int MIDI_event::get_bend()
{
  return (int) bend;
}

void MIDI_event::set_bend(int _bend)
{
  bend = (short) _bend;
}



/*
   TYPES CONVERSION
*/


int bytes_to_int(byte high, byte low)
{
return (int) high<<8 + (int) low;
}

byte int_to_first_byte(int integer)  //high
{
  return byte(integer>>8);
}


byte int_to_second_byte(int integer) //low
{
  return byte(integer);
}

