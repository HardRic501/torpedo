#ifndef scorescreen_hpp
#define scorescreen_hpp

#include "graphics.hpp"
#include "widgets.hpp"
#include "referee.hpp"

using namespace genv;
using namespace std;

class ScoreScreen : public Widget {
    protected:
        Referee* Boss;
        bool player;

    public:
        ScoreScreen( int _x, int _y, int _size_x, int _size_y, Referee* _Boss, bool _player);

        virtual void draw();

};



#endif
