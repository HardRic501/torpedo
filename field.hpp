#ifndef field_hpp
#define field_hpp

#include "graphics.hpp"
#include "widgets.hpp"
#include "square.hpp"
#include <vector>

using namespace genv;
using namespace std;

class Field : public Widget {
    protected:
        vector<Square> squares;
    public:
        Field( int _x, int _y);


        virtual void draw();
        virtual void handle( event ev );
        void loadSqaresVector();
};



#endif
