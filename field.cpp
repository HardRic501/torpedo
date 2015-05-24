#include "field.hpp"
#include <iostream>

using namespace genv;
using namespace std;


Field::Field( int _x, int _y, int _fieldSize):Widget( _x, _y), fieldSize(_fieldSize)
{
    size_x=fieldSize*30;
    size_y=fieldSize*30+240;
    placing = "0";
    pushed5v = 0;
    pushed5h = 0;
    pushed5d=0;
    pushed4v = 0;
    pushed4h = 0;
    pushed4d=0;
    count5 = 0;
}


void Field::draw()
{
    gout<<move_to(x-1,y-1)<<color(255,255,255)<<box(fieldSize*30+2,fieldSize*30+2);
    gout<<move_to(x,y)<<color(88,116,152)<<box(fieldSize*30,fieldSize*30);
    if(pushed5v==0)
    {
        gout<<move_to(x,y+fieldSize*30+30)<<color(255,255,255)<<box(30,30);
        gout<<color(0,0,0)<<move_to(x+15-(gout.twidth("5v")/2),y+fieldSize*30+45+gout.cdescent())<<text("5v");
    }
    if(pushed5v==1)
    {
        gout<<move_to(x,y+fieldSize*30+30)<<color(0,0,0)<<box(30,30);
        gout<<color(255,255,255)<<move_to(x+15-(gout.twidth("5v")/2),y+fieldSize*30+45+gout.cdescent())<<text("5v");
    }
    if(pushed5h==0)
    {
        gout<<move_to(x,y+fieldSize*30+90)<<color(255,255,255)<<box(30,30);
        gout<<color(0,0,0)<<move_to(x+15-(gout.twidth("5h")/2),y+fieldSize*30+105+gout.cdescent())<<text("5h");
    }
    if(pushed5h==1)
    {
        gout<<move_to(x,y+fieldSize*30+90)<<color(0,0,0)<<box(30,30);
        gout<<color(255,255,255)<<move_to(x+15-(gout.twidth("5h")/2),y+fieldSize*30+105+gout.cdescent())<<text("5h");
    }

    if(pushed5d==0)
    {
        gout<<move_to(x,y+fieldSize*30+150)<<color(255,255,255)<<box(30,30);
        gout<<color(0,0,0)<<move_to(x+15-(gout.twidth("5d")/2),y+fieldSize*30+165+gout.cdescent())<<text("5d");
    }
    if(pushed5d==1)
    {
        gout<<move_to(x,y+fieldSize*30+150)<<color(0,0,0)<<box(30,30);
        gout<<color(255,255,255)<<move_to(x+15-(gout.twidth("5d")/2),y+fieldSize*30+165+gout.cdescent())<<text("5d");
    }
    if(pushed4v==0)
    {
        gout<<move_to(x+60,y+fieldSize*30+30)<<color(255,255,255)<<box(30,30);
        gout<<color(0,0,0)<<move_to(x+75-(gout.twidth("4v")/2),y+fieldSize*30+45+gout.cdescent())<<text("4v");
    }
    if(pushed4v==1)
    {
        gout<<move_to(x+60,y+fieldSize*30+30)<<color(0,0,0)<<box(30,30);
        gout<<color(255,255,255)<<move_to(x+75-(gout.twidth("4v")/2),y+fieldSize*30+45+gout.cdescent())<<text("4v");
    }
    if(pushed4h==0)
    {
        gout<<move_to(x+60,y+fieldSize*30+90)<<color(255,255,255)<<box(30,30);
        gout<<color(0,0,0)<<move_to(x+75-(gout.twidth("4h")/2),y+fieldSize*30+105+gout.cdescent())<<text("4h");
    }
    if(pushed4h==1)
    {
        gout<<move_to(x+60,y+fieldSize*30+90)<<color(0,0,0)<<box(30,30);
        gout<<color(255,255,255)<<move_to(x+75-(gout.twidth("4h")/2),y+fieldSize*30+105+gout.cdescent())<<text("4h");
    }

    if(pushed4d==0)
    {
        gout<<move_to(x+60,y+fieldSize*30+150)<<color(255,255,255)<<box(30,30);
        gout<<color(0,0,0)<<move_to(x+75-(gout.twidth("4d")/2),y+fieldSize*30+165+gout.cdescent())<<text("4d");
    }
    if(pushed4d==1)
    {
        gout<<move_to(x+60,y+fieldSize*30+150)<<color(0,0,0)<<box(30,30);
        gout<<color(255,255,255)<<move_to(x+75-(gout.twidth("4d")/2),y+fieldSize*30+165+gout.cdescent())<<text("4d");
    }


    for(size_t i=0; i<squares.size(); i++)
    {
        for(size_t j=0; j<squares[i].size(); j++)
        {

            gout<<move_to(x+j*30,y+i*30)<<color(255,255,255)<<box(30,30);
            if(squares[i][j].get_type()=="water")
            {
                gout<<move_to(x+j*30+1,y+i*30+1)<<color(88,116,152)<<box(28,28);
            }
            if(squares[i][j].get_type()=="fiveLong")
            {
                gout<<move_to(x+j*30+1,y+i*30+1)<<color(255,216,0)<<box(28,28);
            }
            if(squares[i][j].get_type()=="fourLong")
            {
                gout<<move_to(x+j*30+1,y+i*30+1)<<color(232,104,80)<<box(28,28);
            }

        }
    }
}

void Field::handle(event ev)
{
    if(ev.type==ev_mouse)
    {
        if(ev.button==1)
        {
            if(ev.pos_x>=x && ev.pos_x<x+30 && ev.pos_y>=y+fieldSize*30+30 && ev.pos_y < y+fieldSize*30+60)
            {
                pushed5v = true;
                placing = "5v";
            }
            if(ev.pos_x>=x && ev.pos_x<x+30 && ev.pos_y>=y+fieldSize*30+90 && ev.pos_y < y+fieldSize*30+120)
            {
                pushed5h = true;
                placing = "5h";
            }
            if(ev.pos_x>=x && ev.pos_x<x+30 && ev.pos_y>=y+fieldSize*30+150 && ev.pos_y < y+fieldSize*30+180)
            {
                pushed5d = true;
                placing = "5d";
            }

            if(ev.pos_x>=x+60 && ev.pos_x<x+90 && ev.pos_y>=y+fieldSize*30+30 && ev.pos_y < y+fieldSize*30+60)
            {
                pushed4v = true;
                placing = "4v";
            }
            if(ev.pos_x>=x+60 && ev.pos_x<x+90 && ev.pos_y>=y+fieldSize*30+90 && ev.pos_y < y+fieldSize*30+120)
            {
                pushed4h = true;
                placing = "4h";
            }
            if(ev.pos_x>=x+60 && ev.pos_x<x+90 && ev.pos_y>=y+fieldSize*30+150 && ev.pos_y < y+fieldSize*30+180)
            {
                pushed4d = true;
                placing = "4d";
            }

        }

        if(ev.button == -1)
        {
            pushed5v = false;
            pushed5h = false;
            pushed5d = false;
            pushed4v = false;
            pushed4h = false;
            pushed4d = false;
        }

        if(ev.button == 1)
        {
            for(size_t i=0; i<squares.size(); i++)
            {
                for(size_t j=0; j<squares[i].size(); j++)
                {
                    int r = i;
                    int c = j;
                    if(ev.pos_x>=x+c*30 && ev.pos_x<x+(c+1)*30 &&
                            ev.pos_y>=y+r*30 && ev.pos_y<y+(r+1)*30
                      )
                    {
                        if(
                            placing == "5v" &&
                            count5 == 0 &&
                            r<6 &&
                            squares[i][j].get_type()=="water" &&
                            squares[i+1][j].get_type()=="water" &&
                            squares[i+2][j].get_type()=="water" &&
                            squares[i+3][j].get_type()=="water" &&
                            squares[i+4][j].get_type()=="water"
                        )
                        {
                            for(int k=0; k<5; k++)
                            {
                                squares[i+k][j].set_type("fiveLong");
                                squares[i+k][j].set_ship(1);
                            }
                            placing = "0";
                            count5++;
                        }
                        if(
                            placing == "5h" &&
                            count5 == 0 &&
                            c<6 &&
                            squares[i][j].get_type()=="water" &&
                            squares[i][j+1].get_type()=="water" &&
                            squares[i][j+2].get_type()=="water" &&
                            squares[i][j+3].get_type()=="water" &&
                            squares[i][j+4].get_type()=="water"
                        )
                        {
                            for(int k=0; k<5; k++)
                            {
                                squares[i][j+k].set_type("fiveLong");
                                squares[i][j+k].set_ship(1);
                            }
                            placing = "0";
                            count5++;
                        }
                    }
                }
            }
        }
        if(ev.button == 1 && (placing == "5d"))
        {
            string deleting;
            if(placing == "5d")
            {
                deleting = "fiveLong";
                count5 = 0;
            }
            for(size_t i=0; i<squares.size(); i++)
            {
                for(size_t j=0; j<squares[i].size(); j++)
                {
                    if(squares[i][j].get_type()==deleting)
                    {
                        squares[i][j].set_type("water");
                        squares[i][j].set_ship(0);
                    }
                }
            }
        }
    }

}






void Field::loadSquaresVector()
{
    vector<Square> sorok;
    for(int j=0; j<fieldSize; j++)
    {
        Square newSquare("water",0);
        sorok.push_back(newSquare);
    }
    for(int i=0; i<fieldSize; i++)
    {
        squares.push_back(sorok);
    }
}
