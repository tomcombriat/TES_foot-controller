#ifndef _button_
#define _button_

class button
{
  public:
  button();
  button(int pin);
  bool has_been_pressed();
  bool has_been_released();
  bool has_been_double_pressed();
  bool has_been_long_pressed();
  bool is_pressed();
  void set_pin(int pin);

  void update();

  

  private:
  bool previous_state;
  int pin;
  bool been_pressed, been_released,pressed,been_double_pressed,been_long_pressed = true;;
  unsigned long last_event_time;
  unsigned long last_press_time;


};



#endif


