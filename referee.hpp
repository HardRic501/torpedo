#ifndef referee_hpp
#define referee_hpp

#include "field.hpp"
#include "button.hpp"
using namespace std;

class Referee
{
protected:
    Field* A;
    Field* B;
    string state;
    Button* Aready;
    Button* Bready;
    int AScore;
    int BScore;

public:
    Referee(Field* _A, Field* _B, string _state, Button* _Aready, Button* _Bready);

    string get_state();
    void   set_state(string newState);
    bool ready();
    bool get_AState();
    bool get_BState();
    void set_AState();
    void set_BState();
    int get_AScore();
    int get_BScore();
    void read_Scores();

};



#endif
