#include "Button.hpp"
#include "graphics.hpp"


using namespace genv;


Button::Button(int _x, int _y, int _size_x, int _size_y, string _textOfButton, Field* _F):Widget(_x, _y, _size_x, _size_y)
{
    textOfButton=_textOfButton;
    pushed = false;
    F = _F;
}

void Button::draw()
{
    if (pushed == false)
    {
        gout<<move_to(x,y)<<color(255,216,000)<<box(size_x,size_y);
        gout<<move_to(x+(size_x/2)-gout.twidth(textOfButton)/2, y+(size_y/2)+gout.cdescent());
        gout<<color(0,0,0)<<text(textOfButton);





    }
    if (pushed == true)
    {
        gout<<move_to(x,y)<<color(90,80,000)<<box(size_x,size_y);
        gout<<move_to(x+(size_x/2)-gout.twidth(textOfButton)/2, y+(size_y/2)+gout.cdescent());
        gout<<color(0,0,0)<<text(textOfButton);

    }

}

void Button::handle(event ev)
{
    if(ev.type == ev_mouse && is_selected(ev.pos_x, ev.pos_y))
        {
        if(ev.button==1 && F->get_ready())
            {
                pushed = true;
                F->set_ingame(true);
            }
        }

}

bool Button::get_pushed(){return pushed;}
