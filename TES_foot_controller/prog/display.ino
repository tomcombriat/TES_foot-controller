#include "display.h"

display::display()
{
  previous_score = 0;
  changes_to_apply = false;
}


/*
int display::compute_score(int type, char data1, char data2, char data3)
{
  return type + data1 + data2 * 2 + data3 * 3 + 5 ;
}

int display::compute_score(int type, char data1, char data2, char data3, bool color1, bool color2, bool color3)
{
   return type + data1 + data2 * 2  + data3 * 3   + int(color1) +int(color2)*2 + int(color3)*3;
}
*/
int display::compute_score(int type, char data1, char data2, char data3, bool color1, bool color2, bool color3,bool color4)
{
   return type + data1 + data2 * 2  + data3 * 3   + int(color1) +int(color2)*2 + int(color3)*3 + int(color4)*4;
}




void display::commit(int type, char data1, char data2, char data3, bool color1, bool color2, bool color3, bool color4)
{
  int score = compute_score(type, data1, data2, data3,color1,color2,color3,color4);
  if (score != previous_score)
  {
    previous_score = score;

    displ.clearDisplay();
    displ.setTextSize(2);
    displ.setTextColor(color4);
    displ.drawFastHLine(0, 23, 128, WHITE);
  displ.fillRect(0,0,128,17,!color4);

    switch (type)
    {
      case 0: //looper
        {
          displ.setCursor(40, 0);
          displ.print("loop");
          break;
        }
      case 1: // arpeggio
        {
          displ.setCursor(17, 0);
          displ.print("arpeggio");
          break;
        }
    } //end of switch

  
    displ.setTextSize(4);

    displ.fillRect(0,30,30,63, !color1);
    displ.setTextColor(color1);
    displ.setCursor(5, 35);
    displ.print(data1);

    displ.fillRect(47,30,30,63, !color2);
    displ.setTextColor(color2);
    displ.setCursor(52, 35);
    displ.print(data2);


    displ.fillRect(91,30,30,63, !color3);
    displ.setTextColor(color3);
    displ.setCursor(96, 35);
    displ.print(data3);

    changes_to_apply = true;
  }  //end if previous_score != score
  else changes_to_apply = false;

}



void display::apply()
{
  if (changes_to_apply)
  {
    displ.display();
  }

}

