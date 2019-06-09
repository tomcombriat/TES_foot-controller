#ifndef _midi_event_
#define _midi_event_



/* type:
 *  
 *  0 note ON
 *  1 Note OFF
 *  2 CC
 *  3 PG
 *  4 Pitchbend
 */
class MIDI_event
{
  public:
    MIDI_event();
    MIDI_event(byte type, byte channe, byte data1, byte data2);
    MIDI_event(byte type, byte channe, byte data1, byte data2, unsigned short timing);
    MIDI_event(byte type, byte channe, int _bend);

    bool get_state();
    void set_data(byte channel, byte data1, byte data2);
    void set_data(byte channel, int _bend);
    void set_timing(unsigned short);
    unsigned short get_timing();
    void empty();
    byte get_channel();
    byte get_data1();
    byte get_data2();
    byte get_type();
    int get_bend();
    void set_bend(int);
    void set_type(byte type);
    void activate();
    void deactivate();


  private:
    byte type;
    bool is_active;
    byte channel;
    byte data1, data2;
    unsigned short timing;
    short bend;

};

/*
 * TYPE CONVERSION
 */

 int bytes_to_int(byte,byte);
 byte int_to_first_byte(int);
 byte int_to_second_byte(int);


#endif
