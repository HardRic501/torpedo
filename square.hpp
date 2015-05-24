#ifndef square_hpp
#define square_hpp

#include "graphics.hpp"

using namespace genv;
using namespace std;

class Square
{
protected:
    string type;
    int ship;



public:
    Square(string _type, int _ship);

    string get_type();
    void set_type(string newType);

    //string get_rotation();
    //void set_rotation(string newRotation);


    int get_ship();
    void set_ship(int newValue);

};



#endif
