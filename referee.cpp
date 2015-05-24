#include "referee.hpp"

using namespace std;

Referee::Referee(Field* _A, Field* _B, string _state) : A(_A), B(_B), state(_state){}

string Referee::get_state(){return state;}
void   Referee::set_state(string newState){state=newState;}
