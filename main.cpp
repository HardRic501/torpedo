#include "application.hpp"
#include "field.hpp"
#include "shipbutton.hpp"

int main()
{
    Application app(780,660, "Torpedó");

    Field* A = new Field(60,120,10);
    A->loadSquaresVector();

    Field* B = new Field(420,120,10);
    B->loadSquaresVector();

    //ShipButton* five1 = new ShipButton(60,450,5);


    app.addWidget(A);
    app.addWidget(B);
    //app.addWidget(five1);
    app.run();

    return 0;
}
