/*
  STM32 adaption by Matthias Diro, tested with maple mini and heltec OLED 12864 I2c; adress: 0x3C (SPI should work, but I didn't own one)
  Things to know:
  This adaption uses hardware I2C (now Wire.h), Port: I2c2. SDA=0, SCL=1 on maple mini
  further details: STM32_README.txt
*/
/*********************************************************************
  This is an example for our Monochrome OLEDs based on SSD1306 drivers

  Pick one up today in the adafruit shop!
  ------> http://www.adafruit.com/category/63_98

  This example is for a 128x64 size display using I2C to communicate
  3 pins are required to interface (2 I2C and one reset)

  Adafruit invests time and resources providing this open source code,
  please support Adafruit and open-source hardware by purchasing
  products from Adafruit!

  Written by Limor Fried/Ladyada  for Adafruit Industries.
  BSD license, check license.txt for more information
  All text above, and the splash screen must be included in any redistribution
*********************************************************************/

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306_STM32.h>

#include <MIDI.h>


#include "midi_event.h"
#include "looper.h"
#include "button.h"
#include "display.h"
#include "tap_tempo.h"
#include "arpegio_mono.h"
#include "note_tracking.h"
#include "arp_taker.h"
#include "menu.h"

MIDI_CREATE_INSTANCE(HardwareSerial, Serial1, MIDI);

#define OLED_RESET 4

Adafruit_SSD1306 displ(OLED_RESET);

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2

/***** MODES ******/
#define LOOPER_MODE 0
#define ARP_MONO_MODE 1
#define ARP_POLY_MODE 2

byte global_mode = LOOPER_MODE;
bool done_something = false;



/*
  button b1(PA5);
  button b2(PA6);
  button b3(PA7);
*/
button bup(PB0);
button bdown(PB1);

button b[3];




looper loopers[3];

display dis;

tap_tempo tap(&b[2]);  //link button 3 to tap tempo

note_tracking tracking;

arpegio_mono arp[4];

//arp[0].set_notes(4, arp0_times, arp0_notes, 'C');


/*
  arpegio_mono arp0(4, arp0_times, arp0_notes, 'C');
  arpegio_mono arp1(6, arp1_times, arp1_notes, 'W');

*/

arp_taker taker;


/* type:

    0 note ON
    1 Note OFF
    2 CC
    3 PG
*/








void setup()   {
  Wire.begin();
  uint32_t i2c_speed = 400000L;
  Wire.setClock(i2c_speed);
  Serial.begin(115200);
  displ.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  displ.clearDisplay();

  displ.setTextSize(3);
  displ.setTextColor(WHITE);
  displ.setCursor(40, 0);
  displ.print("TES");

  displ.setTextSize(2);
  displ.setCursor(15, 40);
  displ.print("FC 1.0");

  displ.display();


  b[0].set_pin(PA5);
  b[1].set_pin(PA6);
  b[2].set_pin(PA7);


  MIDI.setHandleNoteOn(HandleNoteOn);
  MIDI.setHandleNoteOff(HandleNoteOff);
  MIDI.setHandleControlChange(HandleControlChange);
  MIDI.setHandleProgramChange(HandleProgramChange);
  MIDI.setHandlePitchBend(HandlePitchBend);


  MIDI.begin(MIDI_CHANNEL_OMNI);

  /* Arp init */
  arp[0].set_notes(4, arp0_times, arp0_notes, arp0_name);
  arp[1].set_notes(4, arp1_times, arp1_notes, arp1_name);
  arp[2].set_notes(4, arp2_times, arp2_notes, arp2_name);
  arp[3].set_notes(4, arp3_times, arp3_notes, arp3_name);


  MIDI.turnThruOff ();



  delay(1000);

}


void loop() {
  while (MIDI.read())
  {
    done_something = true;
  }

bup.update();
bdown.update();
if (bup.is_pressed() && bdown.is_pressed()) menu();

  /*****************************************
                 LOOPER
   *****************************************/

  if (global_mode == LOOPER_MODE)
  {
    for (unsigned int i = 0; i < 3; i++)
    {
      b[i].update();
      if (b[i].has_been_pressed() )
      {
        //if (!loopers[i].is_playing()) loopers[i].start();
        if (!loopers[i].is_playing() && loopers[i].get_state() != 'S' && loopers[i].get_state() != 'W') loopers[i].do_want_to_start();
        //else if (loopers[i].is_recording()) loopers[i].stop_record();  
        else if (loopers[i].is_recording() && loopers[i].get_state() != 'W') loopers[i].do_want_to_stop_record();  //loopers[i].get_state() != 'W' ajouté 
        else if (loopers[i].is_playing() && !loopers[i].is_recording()) loopers[i].record();
        else if (!loopers[i].is_playing() && loopers[i].get_state() == 'W') loopers[i].start();
        
      }

      if (b[i].has_been_released() && !loopers[i].is_playing() && loopers[i].get_state() == 'S') loopers[i].do_want_to_start();
      if (b[i].has_been_double_pressed() && !loopers[i].has_just_started())    loopers[i].stop();
      //if (loopers[i].do_want_to_stop() && loopers[i].has_just_started()) loopers[i].clear(); // want to stop and it has just started// mettre cela dans le looper
      if (b[i].has_been_long_pressed()) loopers[i].clear();
      if (loopers[i].is_next())
      {
        done_something = true;
        sendMidiEvent(loopers[i].next());
      }
    }


    /*
        b2.update();
        if (b2.has_been_pressed() )
        {
          if (!loopers[1].is_playing()) loopers[1].start();
          else if (loopers[1].is_recording()) loopers[1].stop_record();
          else if (loopers[1].is_playing() && !loopers[1].is_recording()) loopers[1].record();
        }
        if (b2.has_been_double_pressed())    loopers[1].stop();
        if (loopers[1].do_want_to_stop() && loopers[1].has_just_started()) loopers[1].clear();
        if (loopers[1].is_next())
        {
          done_something = true;
          sendMidiEvent(loopers[1].next());
        }


        b3.update();
        if (b3.has_been_pressed() )
        {
          if (!loopers[2].is_playing()) loopers[2].start();
          else if (loopers[2].is_recording()) loopers[2].stop_record();
          else if (loopers[2].is_playing() && !loopers[2].is_recording()) loopers[2].record();
        }
        if (b3.has_been_double_pressed())    loopers[2].stop();
        if (loopers[2].do_want_to_stop() && loopers[2].has_just_started()) loopers[2].clear();
        if (loopers[2].is_next())
        {
          done_something = true;
          sendMidiEvent(loopers[2].next());
        }
    */

    if (loopers[0].has_started()) dis.commit(0, loopers[0].get_state(), loopers[1].get_state(), loopers[2].get_state(), 0, 1, 1);
    else if (loopers[1].has_started()) dis.commit(0, loopers[0].get_state(), loopers[1].get_state(), loopers[2].get_state(), 1, 0, 1);
    else if (loopers[2].has_started()) dis.commit(0, loopers[0].get_state(), loopers[1].get_state(), loopers[2].get_state(), 1, 1, 0);
    else    dis.commit(0, loopers[0].get_state(), loopers[1].get_state(), loopers[2].get_state(), 1, 1, 1);
  }






  /*****************************************
                 ARP MONO
   *****************************************/





  else if (global_mode == ARP_MONO_MODE)
  {

    /****** TEMPO ******/
    tap.update();


    arp[taker.get_arp_index(0)].set_tempo(tap.get_tempo());
    arp[taker.get_arp_index(1)].set_tempo(tap.get_tempo());


    /****** ARP 0 ******/



    for (unsigned int i = 0; i < 2; i++)
    {
      b[i].update();
      if (b[i].has_been_pressed())
      {
        arp[taker.get_arp_index(0)].start();
      }

      if (b[i].has_been_released())
      {
        MIDI_event previous_event(1, tracking.last().get_channel(), arp[taker.get_arp_index(i)].next(), tracking.last().get_data2());
        if (arp[taker.get_arp_index(i)].next() != 0 )sendMidiEvent(previous_event); //stop previous note
        arp[taker.get_arp_index(i)].stop();
        if (tracking.last_active()) sendMidiEvent(tracking.last()); //restore note before started
      }
      if (tracking.last_active() && arp[taker.get_arp_index(i)].is_started()) // a note is played now and this arp is working
      {
        if (arp[taker.get_arp_index(i)].is_paused())
        {
          arp[taker.get_arp_index(i)].start();
        }
        if (arp[taker.get_arp_index(i)].change(tracking.last().get_data1()) )
        {
          MIDI_event previous_event(1, tracking.last().get_channel(), arp[taker.get_arp_index(i)].previous(), tracking.last().get_data2());
          sendMidiEvent(previous_event);  //stop previous note
          MIDI_event new_event(0, tracking.last().get_channel(), arp[taker.get_arp_index(i)].next(), tracking.last().get_data2());
          sendMidiEvent(new_event); //send new note
        }
      }
      else if (arp[taker.get_arp_index(i)].is_started() && b[i].is_pressed() && !arp[taker.get_arp_index(i)].is_paused())
      {
        MIDI_event previous_event(1, tracking.last().get_channel(), arp[taker.get_arp_index(i)].next(), tracking.last().get_data2());
        if (arp[taker.get_arp_index(i)].next() != 0 ) sendMidiEvent(previous_event); //stop previous note
        arp[taker.get_arp_index(i)].pause();
      }


    }



    /****** ARP 1 ******/

    /*
      b2.update();
      if (b2.has_been_pressed())
      {
      arp[taker.get_arp_index(1)].start();
      //Serial.println("pressed!");
      }

      if (b2.has_been_released())
      {
      MIDI_event previous_event(1, tracking.last().get_channel(), arp[taker.get_arp_index(1)].next(), tracking.last().get_data2());
      if (arp[taker.get_arp_index(1)].next() != 0 ) sendMidiEvent(previous_event); //stop previous note
      arp[taker.get_arp_index(1)].stop();
      if (tracking.last_active()) sendMidiEvent(tracking.last()); //restore note before started
      }
      //Serial.println(tracking.last_active());
      if (tracking.last_active() && arp[taker.get_arp_index(1)].is_started()) // a note is played now and this arp is working
      {
      if (arp[taker.get_arp_index(1)].is_paused())
      {
        arp[taker.get_arp_index(1)].start();
      }
      // Serial.println("got hear");
      if (arp[taker.get_arp_index(1)].change(tracking.last().get_data1()) )
      {
        MIDI_event previous_event(1, tracking.last().get_channel(), arp[taker.get_arp_index(1)].previous(), tracking.last().get_data2());
        sendMidiEvent(previous_event);  //stop previous note
        MIDI_event new_event(0, tracking.last().get_channel(), arp[taker.get_arp_index(1)].next(), tracking.last().get_data2());
        sendMidiEvent(new_event); //send new note
      }
      }
      else if (arp[taker.get_arp_index(1)].is_started() && b1.is_pressed() && !arp[taker.get_arp_index(1)].is_paused())
      {
      MIDI_event previous_event(1, tracking.last().get_channel(), arp[taker.get_arp_index(1)].next(), tracking.last().get_data2());
      if (arp[taker.get_arp_index(1)].next() != 0 ) sendMidiEvent(previous_event); //stop previous note
      arp[taker.get_arp_index(1)].pause();
      }


    */
    /*
      if ((arp[taker.get_arp_index(1)].is_started() || arp[taker.get_arp_index(0)].is_started()) && MIDI.getThruState()) MIDI.turnThruOff ();
      if ((!arp[taker.get_arp_index(0)].is_started() && !arp[taker.get_arp_index(1)].is_started() && !MIDI.getThruState())) MIDI.turnThruOn ();
    */
    //Serial.println(tap.get_tempo());
    // dis.commit(1, arp[taker.get_arp_index(0)].get_name(), arp[taker.get_arp_index(1)].get_name(), 'T');
    dis.commit(1, arp[taker.get_arp_index(0)].get_name(), arp[taker.get_arp_index(1)].get_name(), 'T', 1, 1, 1);

  }




  if (!done_something) dis.apply();
  done_something = false;
}


