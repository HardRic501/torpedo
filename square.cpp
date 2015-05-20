#include "square.hpp"

using namespace genv;

Square::Square(int _xStartCoord, int _yStartCoord, string _state) : xStartCoord(_xStartCoord), yStartCoord(_yStartCoord), state(_state)
{
    xEndCoord = _xStartCoord+30;
    yEndCoord = _yStartCoord+30;
}

void Square::draw()
{
    gout<<color(255,255,255)<<move_to(xStartCoord, yStartCoord)<<line_to(xEndCoord,yStartCoord)
                                                               <<line_to(xEndCoord,yEndCoord)
                                                               <<line_to(xStartCoord,yEndCoord)
                                                               <<line_to(xStartCoord,yStartCoord);


}

string Square::getState()
{
    return state;
}


void Square::setState(string newState)
{
    state=newState;
}
