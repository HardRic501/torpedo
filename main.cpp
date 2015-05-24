#include "application.hpp"
#include "field.hpp"
#include "shipbutton.hpp"
#include "button.hpp"
#include "scorescreen.hpp"

int main()
{
    Field* A = new Field(60,120,10);
    A->loadSquaresVector();

    Field* B = new Field(420,120,10);
    B->loadSquaresVector();

    Button* AReady = new Button(270,60,90,30,"A ready!",A);
    Button* BReady = new Button(630,60,90,30,"B ready!",B);

    Referee* Boss = new Referee(A, B, "startScreen", AReady, BReady);

    ScoreScreen* AScore = new ScoreScreen(60,90,100,20,Boss,0);
    ScoreScreen* BScore = new ScoreScreen(420,90,100,20,Boss,1);

    Application app(780,660, "Torpedó", Boss);


    app.addWidget(A);
    app.addWidget(B);
    app.addWidget(AReady);
    app.addWidget(BReady);
    app.addWidget(AScore);
    app.addWidget(BScore);
    app.run();

    return 0;
}
