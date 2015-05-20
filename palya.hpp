#ifndef palya_hpp
#define palya_hpp

#include "graphics.hpp"
#include "widgets.hpp"

using namespace genv;
using namespace std;

class Palya : public Widget {
    protected:

    public:
        Palya( int _x, int _y);


        virtual void draw();
        virtual void handle( event ev );
};



#endif
