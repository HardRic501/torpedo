#ifndef button_hpp
#define button_hpp

#include "graphics.hpp"
#include "widgets.hpp"
#include "field.hpp"

using namespace genv;
using namespace std;

class Button : public Widget {
    protected:
        bool pushed;
        string textOfButton;
        Field* F;


    public:
        Button( int _x, int _y, int _size_x, int _size_y, string _textOfButton, Field* _F);

        virtual void draw();
        virtual void handle( event ev );

        bool get_pushed();
};



#endif // kattdoboz_hpp
