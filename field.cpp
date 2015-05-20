#include "field.hpp"

using namespace genv;
using namespace std;


Field::Field( int _x, int _y):Widget( _x, _y)
{

}


void Field::draw()
{
    gout<<move_to(x,y)<<color(88,116,152)<<box(300,300);
    for(size_t i=0;i<squares.size();++i)
    {
        squares[i].draw();
    }

}

void Field::handle(event ev)
{

}

void Field::loadSqaresVector()
{
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            Square newSquare = Square(x+i*30,y+j*30,"blank");
            squares.push_back(newSquare);
        }
    }
}

