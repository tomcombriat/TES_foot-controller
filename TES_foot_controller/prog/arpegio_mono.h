#ifndef _arpegio_mono_
#define _arpegio_mono_

class arpegio_mono
{
  public:
    arpegio_mono();
    arpegio_mono(unsigned int N, float * times, int * notes);
    arpegio_mono(unsigned int N, float * times, int * notes,char _name);
    void set_notes(unsigned int N, float * times, int * notes);
    void set_notes(unsigned int N, float * times, int * notes,char _name);
    void set_tempo(unsigned long _tempo);
    byte next();
    byte previous();
    void start();
    void stop();
    bool change(byte current_note);
    bool is_started();
    char get_name();
    bool is_paused();
    void pause();


  private:
    unsigned int  N_note_arp;
    float *  times_arp;
    int * notes_arp;
    int  N_played = 0;
    bool started  = false;
    unsigned long start_time = 0, duration = 500;
    char arp_name;
    short next_note;
    short previous_note;
    bool paused;
};


float arp0_times[4] = {0.0,0.25,0.5,0.75};
int arp0_notes[4] = {0,7,0,12};
char arp0_name = 'C';

float arp1_times[4] = {0.0,0.25,0.5,0.75};
int arp1_notes[4] = {0,4,7,4};
char arp1_name = 'M';


float arp2_times[4] = {0.0,0.25,0.5,0.75};
int arp2_notes[4] = {0,3,7,3};
char arp2_name = 'm';

float arp3_times[4] = {0.0,0.25,0.5,0.75};
int arp3_notes[4] = {0,12,-7,7};
char arp3_name = 'W';



#endif

