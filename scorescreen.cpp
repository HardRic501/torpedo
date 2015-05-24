#include "scorescreen.hpp"
#include "graphics.hpp"
#include <sstream>


using namespace genv;
using namespace std;


ScoreScreen::ScoreScreen( int _x, int _y, int _size_x, int _size_y, Referee* _Boss, bool _player):Widget(_x, _y, _size_x, _size_y)
{
    Boss=_Boss;
    player=_player;
}

void ScoreScreen::draw()
{
    stringstream ss;
    Boss->read_Scores();
    if(player==0)
    {
        ss<<Boss->get_AScore();
        gout<<move_to(x,y)<<color(255,255,255)<<text("Player A Score: ")<<text(ss.str())<<text(" of 15");
    }
    if(player==1)
    {
        ss<<Boss->get_BScore();
        gout<<move_to(x,y)<<color(255,255,255)<<text("Player B Score: ")<<text(ss.str())<<text(" of 15");
    }

}

