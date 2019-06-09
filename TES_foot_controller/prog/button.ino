#include "button.h"



/***

      INVERSE LOGIC : 0 = PRESSED

*/
button::button() {};

button::button(int _pin)
{
  pinMode(_pin, INPUT_PULLUP);
  delay(20);
  pin = _pin;
  previous_state = digitalRead(pin);
  been_pressed = false;
  been_released = false;
}

bool button::is_pressed()
{
  return pressed;
}

bool button::has_been_pressed()
{
  if (been_pressed)
  {
    been_pressed = false;
    return true;
  }
  return false;
}


bool button::has_been_released()
{
  if (been_released)
  {
    been_released = false;
    return true;
  }
  return false;
}

bool button::has_been_double_pressed()
{
  if (been_double_pressed)
  {
    been_double_pressed = false;
    return true;
  }
  return false;
}

void button::update()
{
  if (millis() - last_event_time > 20)
  {

    bool state = digitalRead(pin);
    if (state != previous_state)     last_event_time = millis();

    if (!state)  // is pressed
    {
      pressed = true;
      if (previous_state) //not pressed before
      {
        if (millis() - last_press_time < 1000)
        {
          been_double_pressed = true;
        }
        been_pressed = true;
        last_press_time = millis();

      }
              been_released = false;
      if (!previous_state && (millis() - last_press_time > 1000)) been_long_pressed = true;  //pressed before and still pressed for 1sec
    }


    else   //not pressed
    {
      pressed = false;
      if (!previous_state) //pressed before
      {
        been_released = true;
      }
      else
      {
        been_released = false;
      }
      been_pressed = false;
      been_double_pressed = false;
      been_long_pressed = false;

    }
    previous_state = state;
  }
}

void button::set_pin(int _pin)
{
  pin = _pin;
  pinMode(_pin, INPUT_PULLUP);
  delay(20);
  previous_state = digitalRead(pin);
  been_pressed = false;
  been_released = false;
}

bool button::has_been_long_pressed()
{
  if (been_long_pressed)
  {
    been_long_pressed = false;
    return true;
  }
  return false;
}

