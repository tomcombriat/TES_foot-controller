#include "arpegio_mono.h"

arpegio_mono::arpegio_mono() {}

arpegio_mono::arpegio_mono(unsigned int N, float * times, int * notes)
{
  N_note_arp = N;
  times_arp = times;
  notes_arp = notes;
}

arpegio_mono::arpegio_mono(unsigned int N, float * times, int * notes, char _name)
{
  N_note_arp = N;
  times_arp = times;
  notes_arp = notes;
  arp_name = _name;
}

void arpegio_mono::set_notes(unsigned int N, float * times, int * notes)
{
  N_note_arp = N;
  times_arp = times;
  notes_arp = notes;
}

void arpegio_mono::set_notes(unsigned int N, float * times, int * notes, char _name)
{
  N_note_arp = N;
  times_arp = times;
  notes_arp = notes;
  arp_name = _name;
}


void arpegio_mono::set_tempo(unsigned long temp)
{
  duration = temp;
}

bool arpegio_mono::change(byte current_note)
{
  if (started)
  {
    float time_in_arp = ((millis() - start_time) % duration) / (duration * 1.0); // compute fraction of time into loop (maybe better not to use floats ?)
    for (unsigned int i = 0; i < N_note_arp - 1; i++)
    {
      if (time_in_arp > times_arp[i] && time_in_arp < times_arp[i + 1] && notes_arp[i] != next_note - current_note )
      {
        previous_note = next_note;
        next_note = notes_arp[i] + current_note;
        return true;
      }
    }
    if (time_in_arp > times_arp[N_note_arp - 1] && notes_arp[N_note_arp - 1] != next_note- current_note)
    {
      previous_note = next_note;
      next_note = notes_arp[N_note_arp - 1] + current_note;
      return true;
    }
  }  // if (started)
  return false;  // arp not started
}

byte arpegio_mono::next()
{
  return next_note;
}

byte arpegio_mono::previous()
{
  return previous_note;
}

void arpegio_mono::start()
{
  start_time = millis();
  started = true;
  paused = false;
}

void arpegio_mono::stop()
{
  next_note = 0;
  started = false;
}

char arpegio_mono::get_name()
{
  return arp_name;
}

bool arpegio_mono::is_started()
{
  return started;
}

void arpegio_mono::pause()
{
  next_note = 0;
  paused = true;
}

bool arpegio_mono::is_paused()
{
  return paused;
}

