#include "square.hpp"
#include <iostream>

using namespace genv;
using namespace std;

Square::Square(string _type, int _ship) : type(_type), ship(_ship){}

    string Square::get_type() {return type;}
    void Square::set_type(string newType){type = newType;}



    int Square::get_ship() {return ship;}
    void Square::set_ship(int newValue) {ship=newValue;}

