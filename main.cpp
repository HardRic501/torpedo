#include "application.hpp"
#include "field.hpp"

int main()
{
    Application app(780,660, "Torpedó");

    Field* A = new Field(60,120);
    A->loadSqaresVector();


    app.addWidget(A);
    app.run();

    return 0;
}
