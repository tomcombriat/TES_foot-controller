#ifndef _tempo_
#define _tempo_


#include "button.h"




class tap_tempo
{
  public:
    tap_tempo();
    tap_tempo(button * _but);
    void re_init_tap_tempo();
    void update();
    unsigned long get_tempo();

  private:
    int N_tap = 0, last_entered = 0;
    static const int N_tap_max = 5;
    unsigned long taps[N_tap_max];
    unsigned long delay_before_reinit = 2000;
    unsigned long tap_time = 500;

    button * but;


};


#endif
