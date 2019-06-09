#include "looper.h"

looper::looper()
{
  playing = false;
  recording = false;
  duration = 0;
  full = false;
  state = 'C';
  for (unsigned int i = 0; i < Nmax; i++) played[i] = false;
}

void looper::set_mode(int _mode)
{
  mode = _mode;
}

void looper::start()
{
  start_time = millis();
  playing = true;
  if (duration == 0)
  {
  recording = true;
  state = 'R';
  }
  else state= 'P';
  want_to_stop = false;
  want_to_start = false;
}

void looper::stop()
{
  state = 'S';
  want_to_stop = true;
}

void looper::record()
{
  state = 'R';
  recording = true;
}

void looper::stop_record()
{
  if (duration == 0) //first recording
  {
    duration = millis() - start_time;
  }
  want_to_stop_record = false;
  recording = false;
  if (!full) state = 'P';
  else state = 'F';

}

void looper::clear()
{
  for (unsigned int i = 0; i < Nmax; i++) events[i].deactivate();
  duration = 0;
  //this->stop();
  playing = false;
  recording = false;
  state = 'C';
  want_to_start = false;
}

void looper::add_event(MIDI_event _event)
{
  if (want_to_start && duration ==0) 
  {
    start();
    first_event_type = _event.get_type();

  }
  if (want_to_stop_record && _event.get_type() == first_event_type)
  {
    stop_record();
  }
  else
  {
    unsigned int i = 0;
    for (i = 0; i < Nmax; i++)
    {
      if (!events[i].get_state())
      {
        if (_event.get_type()!= 4)  events[i].set_data(_event.get_channel(), _event.get_data1(), _event.get_data2());
        else events[i].set_data(_event.get_channel(), _event.get_bend());
        events[i].set_type(_event.get_type());
        events[i].activate();
       unsigned long curr_time = current_time();
       if (!curr_time) curr_time+=2;
        events[i].set_timing(curr_time);
        played[i] = true;
        full = false;
        break;
      }

    }
    if (i == Nmax - 1)
    {
      full = true;
      state = 'F';
      this->stop_record();
    }
  }
}

unsigned long looper::current_time()
{
  unsigned long curr_time = (millis() - start_time) % duration;
  if (curr_time < 500)
  {
    has_start = true;
    if (curr_time < 5) 
    {
      has_just_start = true;
      if (want_to_stop) 
      {
      playing = false;
      }
      if (want_to_start) start();

    }
    else has_just_start = false;
  }
  else has_start = false;
  previous_time = curr_time;
  return curr_time;
}

bool looper::is_next()
{
  unsigned long curr_time = this->current_time();
/*
  if (want_to_stop && has_just_start)
  {
    playing = false;
  }*/
  if (playing)
  {
    for (unsigned int i = 0; i < Nmax; i++)
    {
      if (!played[i] && events[i].get_state()  && (curr_time >= events[i].get_timing()) )
      {
        played[i] = true;
        next_event = i;
        return true;
      }
      else if (played[i] && events[i].get_state() && (events[i].get_timing()) > curr_time)
      {
        played[i] = false;
      }
    }
  }
  return false;
}

MIDI_event looper::next()
{
  return events[next_event];
}

bool looper::is_recording()
{
  return recording;
}

bool looper::is_playing()
{
  return playing;
}

bool looper::has_started()
{
  if (has_start)
  {
    return true;
  }
  return false;
}

bool looper::has_just_started()
{
  return has_just_start;
}

bool looper::is_full()
{

  return full;
}


char looper::get_state()
{
  return state;
}

bool looper::do_want_to_stop()
{
  return want_to_stop;
}

void looper::do_want_to_start()
{
    want_to_start = true;
    //playing = true;
    if (duration == 0) recording = true;
   /*if (duration ==0) state = 'W';
    else state = 'P';*/
    state = 'W';
    want_to_stop = false;
  
}

void looper::do_want_to_stop_record()
{
  if (duration != 0 ) stop_record();
  else  want_to_stop_record = true;
}



