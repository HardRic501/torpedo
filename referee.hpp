#ifndef referee_hpp
#define referee_hpp

#include "field.hpp"
using namespace std;

class Referee
{
protected:
    Field* A;
    Field* B;
    string state;
public:
    Referee(Field* _A, Field* _B, string _state);

    string get_state();
    void   set_state(string newState);


};



#endif
