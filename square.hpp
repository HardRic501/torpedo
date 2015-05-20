#ifndef square_hpp
#define square_hpp

#include "graphics.hpp"

using namespace genv;
using namespace std;

class Square
{
protected:
    int xStartCoord, yStartCoord, xEndCoord, yEndCoord;
    string state;

public:
    Square( int _xStartCoord, int _yStartCoord, string _state);

    void draw();
    string getState();
    void setState(string newState);


};



#endif
