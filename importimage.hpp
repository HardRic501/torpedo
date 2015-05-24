#ifndef kepbeolvas_hpp
#define kepbeolvas_hpp
#include "graphics.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace genv;
using namespace std;


void kepbeolvas(canvas& kep, string kepnev, int& width, int& height)
{
    unsigned short cr, cg,cb;
    ifstream bef (kepnev.c_str());
    if (bef.fail())
    {
        cerr << "Nincs ilyen file?" << endl;
    }else
    {
        bef >> width >> height;
        kep.open(width, height);
        for (int i = 0; i < height; ++i)
        {
            for(int j=0; j < width; ++j)
            {
                bef >> cr >> cg >>cb;
                kep << move_to(j,i) << color(cr,cg,cb)<<dot;
            }
        }
    }
    bef.close();
}












#endif // kepbeolvas_hpp
