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
        vector< vector<Square> > squares;
        int fieldSize;
        string placing;
        bool pushed5v;
        bool pushed5h;
        bool pushed5d;
        bool pushed4v;
        bool pushed4h;
        bool pushed4d;
        int count5;


    public:
        Field( int _x, int _y, int _fieldSize);


        virtual void draw();
        virtual void handle( event ev );
        void loadSquaresVector();
        void loadFiveLongVertical(int i, int j);


};



#endif
