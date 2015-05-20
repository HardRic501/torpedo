#include "palya.hpp"

using namespace genv;


Palya::Palya( int _x, int _y):Widget( _x, _y)
{

}


void Palya::draw()
{
    gout<<move_to(x,y)<<color(88,116,152)<<box(300,300);

}

void Palya::handle(event ev)
{

}

