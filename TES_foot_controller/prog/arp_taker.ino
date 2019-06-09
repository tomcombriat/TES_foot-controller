#include "arp_taker.h"

arp_taker::arp_taker()
{
  current_arps[0] = 0;
  current_arps[1] = 3;
}

arp_taker::arp_taker(byte arp0, byte arp1)
{
  current_arps[0] = arp0;
  current_arps[1] = arp1;
}


void arp_taker::change_arp(byte arp_channel, int amount)
{
  if (amount > 0)
  {
    if (current_arps[arp_channel] + amount >= N_arp) current_arps[arp_channel] = 0;
    else current_arps[arp_channel] += amount;
  }
  else if (amount < 0)
  {
    if (current_arps[arp_channel] + amount < 0) current_arps[arp_channel] = N_arp - 1 ;
    else current_arps[arp_channel] += amount;
  }
}


byte arp_taker::get_arp_index(byte channel)
{
  return current_arps[channel];
}


