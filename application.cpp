#include "application.hpp"
#include "graphics.hpp"
#include "importimage.hpp"
#include <sstream>

using namespace genv;
using namespace std;

Application::Application( int _SX, int _SY, std::string _name , Referee* _Boss) : SX(_SX), SY(_SY), name(_name), Boss(_Boss)
{
    isExiting = false;
    focused = -1;
}

void Application::addWidget( Widget *w )
{
    widgets.push_back( w );
}

void Application::run()
{
    gout.open( SX, SY );
    gout.set_title( name );
    bool whosNext = 1;
    bool firstTime = 0;
    stringstream ss;
    event ev;
    while( gin>>ev && !isExiting )
    {

        if( ev.keycode == key_escape )
            isExiting = true;

        if(Boss->get_state()=="startScreen")
        {
            canvas start;
            kepbeolvas(start,"welcomescreen.kep",SX,SY);
            gout<<stamp(start,0,0);
            gout<<refresh;

            if( ev.type == ev_key && ev.keycode == key_enter )
            {
                Boss->set_state("placing");
            }
            if( ev.type == ev_key && ev.keycode == key_f1 )
            {
                Boss->set_state("help");
            }
        }

        if(Boss->get_state()=="help")
        {
            canvas help;
            kepbeolvas(help,"f1.kep",SX,SY);
            gout<<stamp(help,0,0);
            gout<<refresh;
            if( ev.type == ev_key && ev.keycode == key_enter )
            {
                Boss->set_state("placing");
            }
        }

        if(Boss->ready()==true)
        {
            Boss->set_state("ingame");
        }

        if(Boss->get_state()=="ingame")
        {
            if(firstTime == 0)
            {
                Boss->set_BState();
                firstTime = 1;
            }
            if(Boss->get_AState()==0 && Boss->get_BState()==0)
            {
                if(whosNext == 1)
                {
                    Boss->set_AState();
                }
                if(whosNext == 0)
                {
                    Boss->set_BState();
                }
                whosNext=!whosNext;
            }

            if(Boss->get_AScore()==15)
            {
                Boss->set_state("AWon");
            }
            if(Boss->get_BScore()==15)
            {
                Boss->set_state("BWon");
            }
        }

        if(Boss->get_state()=="AWon")
        {
            canvas EndA;
            kepbeolvas(EndA,"EndA.kep",SX,SY);
            gout<<stamp(EndA,0,0);
            gout<<refresh;
        }
        if(Boss->get_state()=="BWon")
        {
            canvas EndB;
            kepbeolvas(EndB,"EndB.kep",SX,SY);
            gout<<stamp(EndB,0,0);
            gout<<refresh;
        }


        if(Boss->get_state()=="placing" || Boss->get_state()=="ingame")
        {
            /// Fókusz kezelése
            if( ev.type == ev_mouse && ev.button==btn_left  )
            {
                focused = -1;
                for( size_t i=0; i<widgets.size(); i++ )
                {
                    if( widgets[i]->is_selected(ev.pos_x, ev.pos_y) )
                    {
                        focused = i;
                    }
                }
            }

            for( size_t i=0; i<widgets.size(); ++i )
                widgets[i]->set_focus( focused == (int)i );

            /// Eseménykezelés
            if( focused != -1)                                // csak a fókuszban lévő widget kapja meg az eseményeket
                widgets[focused]->handle( ev );

            //for( size_t i=0; i<widgets.size(); ++i )            // a vektorban található összes vezérlõ megkapja az eseményeket
            //    widgets[i]->handle( ev );                       // eseménykezelés widget szinten

            /// Vizualizálás
            gout << move_to(0, 0) << color(70,90,120) << box(SX, SY);// képernyő törlése
            for( size_t i=0; i<widgets.size(); ++i )
                widgets[i]->draw();                             // képernyő újra rajzolása
            gout << refresh;                                    // képernyő frissítése

        }
    }
}

void Application::shutdown()
{
    isExiting = true;                                       // kilépés inicializálása
}
