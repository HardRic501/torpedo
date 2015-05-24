#include "referee.hpp"

using namespace std;

Referee::Referee(Field* _A, Field* _B, string _state, Button* _Aready, Button* _Bready) : A(_A), B(_B), state(_state), Aready(_Aready), Bready(_Bready)
{
    AScore=0;
    BScore=0;
}

string Referee::get_state(){return state;}
void   Referee::set_state(string newState){state=newState;}
bool   Referee::ready()
{
    if(Aready->get_pushed()==1 && Bready->get_pushed()==1)
    {
        return true;
    }
    else return false;
}

bool Referee::get_AState(){return A->get_enemysTurnOnMyField();}
bool Referee::get_BState(){return B->get_enemysTurnOnMyField();}
void Referee::set_AState(){A->set_enemysTurnOnMyField(!A->get_enemysTurnOnMyField());}
void Referee::set_BState(){B->set_enemysTurnOnMyField(!B->get_enemysTurnOnMyField());}

int Referee::get_AScore(){return AScore;}
int Referee::get_BScore(){return BScore;}
void Referee::read_Scores()
{
    AScore = B->get_opponentScore();
    BScore = A->get_opponentScore();
}


