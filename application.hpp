#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "widgets.hpp"
#include <vector>
#include "referee.hpp"


class Application { // grafikus alkalmazás
    protected:
        std::vector<Widget*> widgets;   // az alkalmazás vezérlői
        int focused;                    // megadja, hogy melyik vezérlõn van a fókusz
        bool isExiting;                 // kilépés alatt áll-e a program
        int SX, SY;                     // képernyõ méret
        std::string name;               // az alkalmazás neve
        Referee* Boss;

    public:
        Application( int _SX, int _SY, std::string _name, Referee* _Boss);// ablak méret és név alapján program létrehozása
        void addWidget( Widget *w );    // új vezérlõ felvétele
        void run();                     // futtatás
        void shutdown();                // leállítás

        int width() const { return SX; }
        int height() const { return SY; }

};

#endif // APPLICATION_HPP
