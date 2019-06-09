#ifndef _display_
#define _display_




class display
{
  public:
    display();
    //void commit(int type, char data1, char data2, char data3);
    //void commit(int type, char data1, char data2, char data3, bool color1, bool color2, bool color3);
    void commit(int type, char data1, char data2, char data3, bool color1=1, bool color2=1, bool color3=1, bool color4=1);

    void apply();


  private:
    int previous_score;
    int compute_score(int, char, char, char);
    int compute_score(int, char, char, char, bool, bool, bool);
    int compute_score(int, char, char, char, bool, bool, bool,bool);
    bool changes_to_apply;



};



#endif
