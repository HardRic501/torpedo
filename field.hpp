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
        bool ingame;
        bool enemysTurnOnMyField;
        int opponentScore;

        bool pushed5v;
        bool pushed5h;
        bool pushed5d;
        bool pushed4v;
        bool pushed4h;
        bool pushed4d;
        bool pushed3v;
        bool pushed3h;
        bool pushed3d;
        bool pushed2v;
        bool pushed2h;
        bool pushed2d;
        bool pushed1;
        bool pushed1d;
        int count1;
        int count2;
        int count3;
        int count4;
        int count5;

        bool ready;



    public:
        Field( int _x, int _y, int _fieldSize);


        virtual void draw();
        virtual void handle( event ev );
        void loadSquaresVector();
        void loadFiveLongVertical(int i, int j);
        bool get_ready();
        bool get_ingame();
        void set_ingame(bool newValue);
        bool get_enemysTurnOnMyField();
        void set_enemysTurnOnMyField(bool newValue);
        int get_opponentScore();




};



#endif
