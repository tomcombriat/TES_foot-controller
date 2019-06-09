#ifndef _arp_taker_
#define _arp_taker_

/****************
 *  CLASS TO TAKE CARE OF ALL ARPS
 */


#define N_arp 4

class arp_taker
{
  public:
  arp_taker();
  arp_taker(byte arp0, byte arp1);

  void change_arp(byte arp_channel, int amount);

  byte get_arp_index(byte arp_channel);

  

  private:
  byte current_arps[2];

  
};

#endif
